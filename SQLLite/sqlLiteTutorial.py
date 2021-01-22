import sqlite3
from sqlite3 import Error

def sql_connection():
	try:
		con = sqlite3.connect('mydatabase.db')
		print("Connection esstablished")
		return con
	except Error:
		print(Error)


def sql_table(con):
	cursor = con.cursor()
	cursor.execute("CREATE TABLE sensores(id integer PRIMARY KEY, ph integer, ppm integer, temperature integer)")
	con.commit()


def addData(con,ph,ppm,temperature):
	cursor = con.cursor()
	cursor.execute('SELECT MAX(id) FROM sensores')
	id = cursor.fetchone()
	new_id = id[0] + 1
	data = (new_id, ph, ppm, temperature)
	cursor.execute("INSERT INTO sensores(id, ph, ppm, temperature) VALUES (?, ?, ?, ?)", data)
	con.commit()

def getLatestData(con):
	cursor = con.cursor()
	cursor.execute("SELECT * FROM sensores ORDER BY id DESC LIMIT 1")
	data = cursor.fetchone()
	print(data)

def getAllDB(con):
	cursor = con.cursor()
	cursor.execute("SELECT * FROM sensores")
	data = cursor.fetchall()
	print(data)

con = sql_connection()
# addData(con, 23, 600, 12)
getLatestData(con)
# getAllDB(con)