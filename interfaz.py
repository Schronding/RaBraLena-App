
from tkinter import *
from tkinter import messagebox
import pymysql


def menu_pantalla():
    global menu
    menu = Tk()
    menu.title('Calculadora financiera RaBraLena')
    menu.geometry('300x250')

    Label(text='System access', bg='navy', fg='white', width='300', height='3', font=('Arial', 15)).pack()
    Label(text=' ').pack()

    Button(text='Log in', height='3', width='30', command = inicio_sesion).pack()
    Label(text=' ').pack()

    Button(text='Register', height='3', width='30', command = register).pack()

    menu.mainloop()

def inicio_sesion():
    global pantalla1
    pantalla1 = Toplevel(menu)
    pantalla1.geometry('400x250')
    pantalla1.title('Log in')

    Label(pantalla1, text = 'Please, enter your username and password'). pack()
    Label(pantalla1, text = ' '). pack()

    global username_verify
    global  password_verify

    username_verify =  StringVar()
    password_verify = StringVar()

    global username_entry
    global password_entry

    Label(pantalla1, text = 'Username').pack()
    username_entry = Entry(pantalla1, textvariable = username_verify)
    username_entry.pack()
    Label(pantalla1).pack()

    Label(pantalla1, text = 'Password').pack()
    password_entry = Entry(pantalla1, textvariable = password_verify,  show = '*')
    password_entry.pack()
    Label(pantalla1).pack()

    Button(pantalla1, text = 'Log in', command = data_validation).pack()

def register():
    global pantalla2
    pantalla2 = Toplevel(menu)
    pantalla2.geometry('400x450')
    pantalla2.title('Register')

    global username
    global creditCard
    global debitCard
    global country
    global salary
    global password


    username = StringVar()
    creditCard = StringVar()
    debitCard = StringVar()
    country = StringVar()
    salary = StringVar()
    password = StringVar()

    Label(pantalla2, text = 'Please, enter your details').pack()
    Label (pantalla2, text = ' ').pack()

    Label(pantalla2, text = 'Username').pack()
    username = Entry(pantalla2)
    username.pack()
    Label(pantalla2).pack()

    Label(pantalla2, text = 'Credit Card').pack()
    creditCard = Entry(pantalla2)
    creditCard.pack()
    Label(pantalla2).pack()

    Label(pantalla2, text = 'Debit Card').pack()
    debitCard = Entry(pantalla2)
    debitCard.pack()
    Label(pantalla2).pack()

    Label(pantalla2, text = 'Country').pack()
    country = Entry(pantalla2)
    country.pack()
    Label(pantalla2).pack()

    Label(pantalla2, text = 'Salary').pack()
    salary = Entry(pantalla2)
    salary.pack()
    Label(pantalla2).pack()

    Label(pantalla2, text = 'Password').pack()
    password = Entry(pantalla2,  show = '*')
    password.pack()
    Label(pantalla2).pack()

    Button(pantalla2, text = "Register", command = data_insert).pack()

def data_insert():
    bd = pymysql.connect(
        host='localhost',
        user='root',
        passwd='',
        db='bd2'
    )

    fcursor = bd.cursor()

    sql = "INSERT INTO login (username, creditCard, debitCard, country, salary, password) VALUES ('{0}','{1}','{2}','{3}','{4}','{5}')".format(username.get(), creditCard.get(), debitCard.get(), country.get(), salary.get(), password.get(),)

    try:
        fcursor.execute(sql)
        bd.commit()
        messagebox.showinfo(message='Successful registration', title='notice')

    except:
        bd.rollback()
        messagebox.showinfo(message='Not registered', title='notice')

    bd.close()

def data_validation():
    bd = pymysql.connect(
        host='localhost',
        user='root',
        passwd='',
        db='bd2'
    )

    fcursor = bd.cursor()

    fcursor.execute("SELECT password FROM login WHERE username = '"+username_verify.get()+"' and password = '"+password_verify.get()+"'")

    if fcursor.fetchall():
        messagebox.showinfo(title = 'successful login', message = 'correct username and password')

    else:
        messagebox.showinfo(title='wrong login', message='incorrect username and password')

    bd.close()

menu_pantalla()




