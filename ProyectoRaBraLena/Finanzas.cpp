#include "Finanzas.h"
#include "Savest.h"
#include <iostream>
using namespace std;


//Inicialización de variables
Finanzas::Finanzas(){
    decision = ' ';
    a = " ";
    b = 0;
    iter = 0;
    numFund = 0;
    DineroTotal = 0;
};

//esta función llena los sobres, que corresponden a los gastos del usuario
void Finanzas::LlenarSobre(float &DineroTotal){

    cout << "Enter the name of your envelope\n";
    cin >> a;
    enve_names.push_back(a);
    cout << "Enter the total sum you want to add to this envelope\n";
    cin >> b;
    envelopes.push_back(b);
    DineroTotal -= envelopes[iter];

    cout << "Do you want to create a new envelope? (Y for yes, N for no)" << endl;
    cin >> decision;
    if (decision == 'Y' && DineroTotal > envelopes[iter]){
        iter++;
        LlenarSobre(DineroTotal);
    }
    else if (DineroTotal < envelopes[iter]){
        cout << "Sorry, for the moment you do not have enough money\n";
    }

    if (decision == 'N'){
        Investments(DineroTotal);
    }
}

// Esta función almacena en un arreglo los constructores de inversión
void Finanzas::Investments(float &DineroTotal){
    Savest I;
    cout << "Do you want to invest? (Y for yes, N for no)" << endl;
    cin >> decision;
    if (decision == 'Y'){
        cout << "You have $ " << DineroTotal << " to invest\n";
        cout << "How many funds do you want to have?\n";
        cin >> numFund;
        vector < Savest > funds(numFund);
        for (int i = 0; i < numFund; i++){
            funds[i] = I.dataInvestments(i);
            DineroTotal -= I.getAmount();
        }

        cout << "Your investments funds are\n";
        for(int i = 0; i < numFund; i++){
            funds[i].show();
        }
    }
    if (decision == 'N'){
        Savings(DineroTotal);
    }
}

// Esta función almacena en un arreglo los constructores de ahorro
void Finanzas::Savings(float &DineroTotal){
    Savest S;
    cout << "Do you want to save? (Y for yes, N for no)" << endl;
    cin >> decision;
    if (decision == 'Y'){
        cout << "You have $ " << DineroTotal << " to saving\n";
        cout << "How many funds do you want to have?\n";
        cin >> numFund;
        vector < Savest > funds(numFund);
        for (int i = 0; i < numFund; i++){
            funds[i] = S.dataSavings(i);
            DineroTotal -= S.getAmount();
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


// Esta función calcula los impuestos a pagar dependiendo de tus ingresos
void Finanzas::Impuestos(float &DineroTotal) {

    if (DineroTotal > 1, 0 < DineroTotal && DineroTotal < 578){ DineroTotal *= .9808;}
    if (DineroTotal > 1, 578 < DineroTotal && DineroTotal < 4910){ DineroTotal *= .936;}
    if (DineroTotal > 1, 4910 < DineroTotal && DineroTotal < 8629){ DineroTotal *= .8912;}
    if (DineroTotal > 1, 8269 < DineroTotal && DineroTotal < 10031){ DineroTotal *= .84;}
    if (DineroTotal > 1, 10031 < DineroTotal && DineroTotal < 12009){ DineroTotal *= .8208;}
    if (DineroTotal > 1, 12009 < DineroTotal && DineroTotal < 24222){ DineroTotal *= .7864;}
    if (DineroTotal > 1, 24222 < DineroTotal && DineroTotal < 38177){ DineroTotal *= .7648;}
    if (DineroTotal > 1, 38177 < DineroTotal && DineroTotal < 72887){ DineroTotal *= .70;}
    if (DineroTotal > 1, 72887 < DineroTotal && DineroTotal < 97183){ DineroTotal *= .68;}
    if (DineroTotal > 1, 97183 < DineroTotal && DineroTotal < 291550){ DineroTotal *= .66;}
    if (DineroTotal > 1, 291550 < DineroTotal && DineroTotal < 1000000000){ DineroTotal *= .65;}

    cout << "Substranting taxes, you have $ " << DineroTotal << endl;
}

//Esta función realiza conversión de moneda
int Finanzas::exchange(float &DineroTotal){
    float dolar = 21.27;
    float euro = 24.07;
    float conversiondolares = 0;
    float conversioneuros = 0;
    int opcion = 0;

    cout << "Do you want to convert your money into foreign currency? (Y for yes, N for no)" << endl;
    cin >> decision;

    if (decision == 'N')
        return (EXIT_SUCCESS);

    if (decision == 'Y');

    cout << "What currency would you like to use?\n(1) dollars\n(2) euros" << endl;
    cin >> opcion;


    if (opcion == 1)
    {
        conversiondolares = DineroTotal / dolar;
        printf ("Now, you have: %.2f dollars",conversiondolares);

    }

    else
    {
        conversioneuros = DineroTotal / euro;
        printf ("Now, you have: %.2f euros",conversioneuros);
    }

    getchar();

    return (EXIT_SUCCESS);
}


// Esta función vincula las demás funciones del programa
int Finanzas::Interconectividad(float &DineroTotal){
    cout << "Do you need anything more?\nUser settings (1)\nInvestments (2)\nSavings (3)\nFinish (4)\n";
    cin >> decision;
    switch (decision) {
        case '1':
            IngresarUsuario();
            case '2':
                Investments(DineroTotal);
                case '3':
                    Savings(DineroTotal);
                    case '4':
                        break;
                    default:
                        break;
    }
    return 0;
}


void Finanzas::IngresarUsuario(){
    /* Fecha Hoy;
    */
}