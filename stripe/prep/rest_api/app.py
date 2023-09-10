from crypt import methods
from flask import Flask, jsonify, request
from typing import List, Tuple
from datetime import datetime
import re

app = Flask(__name__)

class Object:
    name: str
    vertices: List[int]
    edges: List[Tuple[int, int]]

    def __init__(self, name):
        self.name = name

def Cube(Object):
    def __init__(self, name):
        Object.__init__(self, name)

        self.vertices = [0, 1, 2, 4] # Not actually gonna do a cube
        self.edges = [(0, 1), (2, 4)]

def Prism(Object):
    def __init__(self, name):
        Object.__init__(self, name)

        self.vertices = [0, 1]
        self.edges = [(0, 1)]

# Database just held in memory for testing
# objects = [
#     Cube("Cube1"),
#     Cube("Cube2"),
#     Prism("Prism1")
# ]

db = [
    { 'name': 'Cian' }
]

@app.route("/")
def hello_world():
    return "Hello, World!"

@app.route("/hello/<name>")
def get_test(name):
    now = datetime.now()
    formatted_now = now.strftime("%A, %d %B, %Y at %X")

    # Filter the name argument to letters only using regular expressions. URL arguments
    # can contain arbitrary text, so we restrict to safe characters only.
    match_object = re.match("[a-zA-Z]+", name)

    if match_object:
        clean_name = match_object.group(0)
    else:
        clean_name = "Friend"

    content = "Hello there, " + clean_name + "! It's " + formatted_now
    return content

@app.route("/headers")
def get_headers_test():
    print(request.headers)
    print(request.args)
    return ('', 200)

@app.route('/db')
def get_db():
    return jsonify(db)

@app.route('/db', methods=["PUT"])
def add_db():
    db.append(request.get_json())
    return '', 204