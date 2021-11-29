#include <iostream>
#include "Finanzas.h"
#include "Advice.h"
using namespace std;

float DineroTotal = 0;
char decision = 'Y';
float expenses = 0;
float entertainment = 0;
float invest = 0;
float save = 0;
Finanzas Llenar;
Finanzas Invest;
Finanzas Save;
Finanzas Tax;
Finanzas Inter;
Advice Expenses;
Advice Leisure;
Advice InvestS;
Advice SaveS;
Advice aInter;


int main() {
    cout << "Welcome to the RaBraLena finances app" << endl;
    cout << "Please enter the total money you have" << endl;
    cin >> DineroTotal;
    Tax.Impuestos(DineroTotal);
    expenses = DineroTotal * 0.5;
    entertainment = DineroTotal * 0.3;
    invest = DineroTotal * 0.1;
    save = DineroTotal * 0.1;

    cout << "How would you like to use our app?\n(1) In a perzonalized way\n(2) With our suggestion\n";
    cin >> decision;
    switch (decision) {
        case '1':
            Llenar.LlenarSobre(DineroTotal);
            Save.Savings(DineroTotal);
            Inter.Interconectividad(DineroTotal);
            cout << "You have $ " << DineroTotal << " to spend freely." << endl;
            break;

            case '2':
                Expenses.suggestionExpenses(expenses, invest, save, entertainment);
                SaveS.suggestionSavings(expenses, invest, save, entertainment);
                aInter.Interconectividad(expenses, invest, save, entertainment);
                DineroTotal = expenses + entertainment + invest + save;
                cout << "You had $ " << DineroTotal << " left over." << endl;
                break;

                default:
                    break;
    }
    return 0;
}


