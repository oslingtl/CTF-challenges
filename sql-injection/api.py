from flask import Flask, request, render_template
from flask_cors import CORS
import sqlite3

app = Flask(__name__)
CORS(app)


@app.route("/get")
def get():
    conn = sqlite3.connect("data.db")
    c = conn.cursor()
    c.execute("select * from data")
    data = c.fetchall()
    return "<br>".join([str(i[0]) for i in data])


@app.route("/register")
def register():
    code = request.args.get('code')
    conn = sqlite3.connect("data.db")
    c = conn.cursor()
    try:
        c.execute("INSERT INTO data VALUES (?)", (code,))
        conn.commit()
        return f"Successfully added {code}"
    except sqlite3.Error as e:
        return str(e)


@app.route("/search")
def search():
    code = request.args.get('code')
    conn = sqlite3.connect("data.db")
    c = conn.cursor()
    try:
        c.execute('CREATE TEMP TABLE "fullback_powerrankings" ( "Rank" INTEGER, "Name" TEXT )')
        c.execute("INSERT INTO fullback_powerrankings VALUES (4, 'SA_FLAG{KALyN_P0ngA}')")
        c.execute("INSERT INTO fullback_powerrankings VALUES (6, 'SA_FLAG{CL1nT_GUthERsON}')")
    except:
        pass
    try:
        statement = "select * from data where data='" + code + "'"
        c.execute(statement)
        found = c.fetchall()
        c.close()
        if found == []:
            return f"Invalid Code<br>{statement}"
        else:
            return f"Wifi Connection Established<br>{statement}<br>" + "<br>".join([str(i[0]) for i in found]) + "<!--<br><br><br><br><br><br><br><br><br><br><br>SA_FLAG{{LATr3LL_M1tCheLL}}-->"
    except sqlite3.Error as e:
        return str(e) + f"<br>{statement}"


@app.route("/login")
def login():
    return open("login.html").read()


@app.route("/")
def main():
    return open("403.html").read()


if __name__ == "__main__":
    app.run(host="0.0.0.0")
