from flask import Flask,render_template, request
from wordgames import wordsgame
import time;

app=Flask(__name__)

@app.route('/login')
def diplay_login()->'html';
return render_template('login.html',title='Login')
