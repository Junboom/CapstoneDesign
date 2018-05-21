


from flask import Flask, render_template,abort
app=Flask(__name__)

class School:
def__init__(self,key,name,lat,lng):self.key=key 
self.name=name
self.lat=lat
self.lng=lng

schools=(
School('hv','Happy valley',37.9045286,-122.1445772),
School('stanley','Stanley Middle',37.8884474,-122.1155922)
)
schools_by_key={school.key:school for school in schools}

@app.route("/")
def index(): return render_template('index.html',schools=schools)

@app.route("/<shool_code>")
def show school(school code):school=schools_by_key.get(school_code)
if school:return:return render_template('map.html',school=school)
else:
abort(404)

app.run(debug=True)
