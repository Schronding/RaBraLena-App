#ifndef PROYECTO2_FINANZAS_H
#define PROYECTO2_FINANZAS_H
#include <string>
#include <vector>
using namespace std;

class Finanzas {
private:
    vector<string> enve_names;
    vector<double> envelopes;
    char decision;
    string a;
    double b;
    int iter;
    int numFund;
    float DineroTotal;

public:
    Finanzas();
    void LlenarSobre(float &DineroTotal);
    void Investments(float &DineroTotal);
    void Savings(float &DineroTotal);
    void Impuestos(float &DineroTotal);
    int Interconectividad(float &DineroTotal);
    void IngresarUsuario();
    int exchange(float &DineroTotal);
};

//Estas estructuras aún no son implementadas en el código principal, se espera incluirlas en el proyecto final
struct Fecha{
    int dia = 00;
    int mes = 00;
    int year = 0000;
    int hora = 0000;
};

struct Telefono{
    int lada = 52;
    long numero = 4421512017; // Existe alguna manera de dar espacios?
};

struct Tarjeta{
    string nPersona = "John Doe";
    long nTarjeta = 0000111122223333;
    int CVV = 000;
    int cMonth = 00; // Puedo limitar cuantos numeros son ingresados?
    int cYear = 21;
    string bank;
};

struct Usuario{
    string nombres = "John";
    string apellidos = "Doe";
    Telefono celular;
    Tarjeta credito;
    Tarjeta debito;
    string pais = "Mexico";
    Fecha bDay;
    string password;
};

#endif //PROYECTO2_FINANZAS_H
