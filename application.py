
from flask import Flask, render_template, request, url_for, redirect, jsonify
app = Flask(__name__)
from flask_sqlalchemy import SQLAlchemy
from sqlalchemy import Table
import json


app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///data.db' #delcaring location
db = SQLAlchemy(app) #declaring database variable


class Book(db.Model): #class for the database model
    id = db.Column(db.Integer, primary_key = True)
    book_name = db.Column(db.String(120), unique=True, nullable=False)
    author = db.Column(db.String(120), nullable=False)
    publisher = db.Column(db.String(120), nullable=False)


    def __repr__(self):
        return f"{self.book_name} - {self.author} - {self.publisher}"

@app.route('/') #front page method
def index():
    return 'Hello!'


@app.route('/books') #output the books method
def get_books():
    books = Book.query.all()

    output = []
    for book in books:
        book_data = {'book_name': book.book_name, 'author': book.author, 'publisher': book.publisher}
        output.append(book_data)
    return {"books": output}


@app.route('/drinks/<id>')
def get_book(id):
    book = Book.query.get_or_404(id)
    return jsonify({"book_name": book.book_name, "author": book.author, "publisher": book.publisher})

@app.route('/books', methods=['POST']) #Post method to the Database
def add_book(): #definition of add book
    book = Book(book_name=request.json['book'], author=request.json['author'], publisher=request.json['publisher']) #get the values
    db.session.add(book) #add the book
    db.session.commit() #commit to the database
    return{'id': book.id} #return the id



@app.route('/books/<id>', methods=['DELETE']) #delete method declaration
def delete_book(id): #delete method
    book = Book.query.get(id) #gets the id
    if book is None: #if none is there
        return{"error": "not found"}
    db.session.delete(book) #delete the item
    db.session.commit() #commit
    return {"message": "yeet"}