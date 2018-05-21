from flask import Flask,render_template

app=Flask(__name__)

@app.route("/")
def hello():
#return "hello"
#return "<html><body><h1>Hello world</h1></body></html>"
return render_template('hello.html')

@app.route("/members")
def members():return "Members"
@app.route("/members/<string:name>/")
def getMember(name):
return "당신의 이름은"+name+"입니다"

if__name__=="__main__":
app.run(debug=True)
