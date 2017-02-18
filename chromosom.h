#pragma once
#include"stdafx.h"
class Chromosom
{
private:
    vector<int>geny;
    unsigned int reprezentacja10_x;
    double przeskalowana_wartosc_x;
    unsigned int reprezentacja10_y;
    double przeskalowana_wartosc_y;
    double wartosc_funkcji_celu;
    double przeskalowana_funkcja_celu;
    double prawdopodobienstwo;
    int ranga;
public:
    //konstruktory
    Chromosom();

    //funkcja ktorej optimum szukamy
    double funkcja(double x,double y);

    //metody do pracy na pojedyncznym chromosomie
    void wyswietl_geny();
    bool nieunikalny(vector<Chromosom> &tab);
    void oblicz_reprezentacje10();
    void przeskaluj();
    void oblicz_funkcje_celu();
    void oblicz_przeskalowana_funkcje_celu(vector<Chromosom> &tab);
    //gettery
    vector<int>& getGeny() { return geny; }
    int getReprezentacja10_x() { return reprezentacja10_x; }
    int getReprezentacja10_y() { return reprezentacja10_y; }
    double getPrzeskalowana_wartosc_x() { return przeskalowana_wartosc_x; }
    double getPrzeskalowana_wartosc_y() { return przeskalowana_wartosc_y; }
    double getWartosc_funkcji_celu() { return wartosc_funkcji_celu; }
    double getPrawdopodobienstwo() { return prawdopodobienstwo; }
    double getRanga() { return ranga; }
    double getPrzeskalowana_funkcja_celu() { return przeskalowana_funkcja_celu; }

    //setter
    void setPrawdopodobienstwo(double prawdopodobienstwo) { this->prawdopodobienstwo = prawdopodobienstwo; }
    void setRanga(int ranga) { this->ranga = ranga; }
};

enum ktore_skalowanie
{
    SKALOWANIE_LINIOWE,
    SKALOWANIE_POTEGOWE,
    SKALOWANIE_OBCINAJACE_TYPU_SIGMA
};
