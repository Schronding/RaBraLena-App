#ifndef PROYECTO2_ADVICE_H
#define PROYECTO2_ADVICE_H


class Advice {
private:
    char decision;
    int numFund;
    float expenses;
    float invest;
    float save;
    float entertainment;
public:
    void suggestionExpenses(float &expenses, float &invest, float &save, float &entertainment);
    void suggestionLeisure(float &expenses, float &invest, float &save, float &entertainment);
    void suggestionInvestments(float &expenses, float &invest, float &save, float &entertainment);
    void suggestionSavings(float &expenses, float &invest, float &save, float &entertainment);
    int Interconectividad(float &expenses, float &invest, float &save, float &entertainment);
    void IngresarUsuario();
};


#endif //PROYECTO2_ADVICE_H
