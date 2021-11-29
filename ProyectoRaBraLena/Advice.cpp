/* Las funiones de este archivo .cpp, perteneciente a la clase Advice, tienen la misma metodología que algunas funciones
 * de la clase Finanzas, sin embargo, en esta clase se le recomienda al usuario como organizar su dinero*/

#include "Advice.h"
#include "Savest.h"
#include <iostream>
#include <vector>
using namespace std;


void Advice::suggestionExpenses(float &expenses, float &invest, float &save, float &entertainment){
    vector<string> enve_names;
    vector<double> envelopes;
    string a;
    double b;
    int iter = 0;

    cout << "You have $ " << expenses << " to your essential expenses\n";
    cout << "Enter the name of your envelope\n";
    cin >> a;
    enve_names.push_back(a);
    cout << "Enter the total sum you want to add to this envelope\n";
    cin >> b;
    envelopes.push_back(b);
    expenses -= envelopes[iter];

    cout << "Do you want to create a new envelope? (Y for yes, N for no)" << endl;
    cin >> decision;
    if (decision == 'Y' && expenses > envelopes[iter]){
        iter++;
        suggestionExpenses(expenses, invest, save, entertainment);
    }
    else if (expenses < envelopes[iter]){
        cout << "Sorry, for the moment you do not have enough money\n";
    }

    if (decision == 'N'){
        suggestionLeisure(expenses, invest, save, entertainment);
    }
}


void Advice::suggestionLeisure(float &expenses, float &invest, float &save, float &entertainment) {

    vector<string> enve_names;
    vector<double> envelopes;
    string a;
    double b;
    int iter = 0;

    cout << "You have $ " << entertainment << " to spend on your leisure activities\n";
    cout << "Enter the name of your envelope\n";
    cin >> a;
    enve_names.push_back(a);
    cout << "Enter the total sum you want to add to this envelope\n";
    cin >> b;
    envelopes.push_back(b);
    entertainment -= envelopes[iter];

    cout << "Do you want to create a new envelope? (Y for yes, N for no)" << endl;
    cin >> decision;
    if (decision == 'Y' && entertainment > envelopes[iter]){
        iter++;
        suggestionExpenses(expenses, invest, save, entertainment);
    }
    else if (entertainment < envelopes[iter]){
        cout << "Sorry, for the moment you do not have enough money\n";
    }

    if (decision == 'N'){
        suggestionInvestments(expenses, invest, save, entertainment);
    }
}


void Advice::suggestionInvestments(float &expenses, float &invest, float &save, float &entertainment) {
    Savest I;
    cout << "Do you want to invest? (Y for yes, N for no)" << endl;
    cin >> decision;
    if (decision == 'Y'){
        cout << "You have $ " << invest << " to invest\n";
        cout << "How many funds do you want to have? You can insert up to 7 investment funds.\n";
        cin >> numFund;
        vector < Savest > funds(numFund);
        for (int i = 0; i < numFund; i++){
            funds[i] = I.dataInvestments(i);
            invest -= I.getAmount();
        }

        cout << "Your investments funds are\n";
        for(int i = 0; i < numFund; i++){
            funds[i].show();
        }
    }
    if (decision == 'N'){
        suggestionSavings(expenses, invest, save, entertainment);
    }
}


void Advice::suggestionSavings(float &expenses, float &invest, float &save, float &entertainment){
    Savest S;
    cout << "Do you want to save? (Y for yes, N for no)" << endl;
    cin >> decision;
    if (decision == 'Y'){
        cout << "You have $ " << save << " to saving\n";
        cout << "How many funds do you want to have? You can insert up to 5 savings funds.\n";
        cin >> numFund;
        vector < Savest > funds(numFund);
        for (int i = 0; i < numFund; i++){
            funds[i] = S.dataSavings(i);
            save -= S.getAmount();
        }

        cout << "Your savings funds are\n";
        for(int i = 0; i < numFund; i++){
            funds[i].show();
        }
    }

    if (decision == 'N'){
        int Interconectividad();
    }
}

int Advice::Interconectividad(float &expenses, float &invest, float &save, float &entertainment){
    cout << "Do you need anything more?\nUser settings (1)\nInvestments (2)\nSavings (3)\nFinish (4)\n";
    cin >> decision;
    switch (decision) {
        case '1':
            IngresarUsuario();
            case '2':
                suggestionInvestments(expenses, invest, save, entertainment);
                case '3':
                    suggestionSavings(expenses, invest, save, entertainment);
                    case '4':
                        break;
                    default:
                        break;
    }
    return 0;
}


void Advice::IngresarUsuario(){
    /* Fecha Hoy;
    */
}