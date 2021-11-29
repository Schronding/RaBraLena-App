#ifndef PROYECTO2_SAVEST_H
#define PROYECTO2_SAVEST_H
#include <string>

using namespace std;

class Savest {

private:
    string nameFund;
    float valueFund;

public:
    //Constructores
    Savest();
    Savest(string _name, float _value);

    //Funciones
    void show();
    float getAmount();
    Savest dataInvestments(int i);
    Savest dataSavings(int i);
};

#endif //PROYECTO2_SAVEST_H
