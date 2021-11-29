#include <iostream>
#include "Savest.h"
#include <string>
#include <vector>
using namespace std;


// inicialización de constructores
Savest::Savest() {
    nameFund = " ";
    valueFund = 0;

}
Savest::Savest(string _name, float _value) {
    nameFund = _name;
    valueFund = _value;
}


// esta función muestra los fondos que tiene el usuario
void Savest::show() {
    cout << nameFund << ": $ " << valueFund << endl;
}


// con esta función se obtiene el valor del fondo y sirve para restar éste al dinero total ingresado al inicio
float Savest::getAmount() {
    return valueFund;
}


// esta función regresa a un constrcutor de un fondo de inversión, dicho constructor contiene el nombre del fondo y su respectivo valor
Savest Savest::dataInvestments(int i) {
    cout << "Type the name of the fund " << i << ": ";
    cin >> nameFund;
    cout << "Enter the fund value " << nameFund << ": ";
    cin >> valueFund;
    Savest myInvestmentsFund(nameFund, valueFund);
    return myInvestmentsFund;
}


// esta función regresa a un constructor de un fondo de ahorro, dicho constructor contiene el nombre del fondo y su respectivo valor
Savest Savest::dataSavings(int i) {
    cout << "Type the name of the fund " << i << ": ";
    cin >> nameFund;
    cout << "Enter the fund value " << nameFund << ": ";
    cin >> valueFund;
    Savest mySavingFund(nameFund, valueFund);
    return mySavingFund;
}


