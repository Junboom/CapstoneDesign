from flask import Flask, render_template
app=Flask(__name__)

@app.route("/")
def hello_world():
return 'Hello WOrld'

@app.route("/run")
def template_test():
my_string="스파이더맨"
my_list=[0,1,2,3,4,5]
return render_template('template.html',my_string=my_string,my_list=my_list)

if__name__=='__main__':
app.run(host='0.0.0.0',debug=True)
