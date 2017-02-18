#pragma once
#include"stdafx.h"


class Stale
{
private:
    Stale() {};
    static Stale *stale;
    int dokladnosc;//10^-dokladosc
    int optimum; //MAKSIMUM lub MINIMUM
    double stala; //dodawania przy skalowaniu wyniku
    int ilosc_przedzialow; //dziedzina zmiennosci
    int ilosc_bitow_x;
    int ilosc_bitow_y;
    int ilosc_populacji;
    int ilosc_iteracji;
    int prawdopodobienstwo_mutacji;
    int prawdopodobienstwo_krzyzowania;
    int prawdopodobienstwo_inwersji;
    int jakie_krzyzowanie;
    int jaka_mutacja;
    int ile_elitarnych;
    int jaka_selekcja;
    int ilosc_najlepszych;//do selekcji najlepszych
    double ilosc_przeniesionych; //rodzicow do nowej populacji
    bool unikalne_potomstwo;
    int wielkosc_turnieju;
    int jakie_skalowanie;
    int potega;
    //przedzial
    double lewa_x;
    double prawa_x;
    double dlugosc_x;
    double lewa_y;
    double prawa_y;
    double dlugosc_y;
    int jaka_funkcja;
public:

    static Stale* instance()
    {
        if (!stale)
        {
            stale = new Stale;
        }
        return stale;
    }
    void ustaw_parametry(int optimum, int dokladnosc, double stala, int ilosc_bitow_x, int ilosc_bitow_y,
        int ilosc_populacji, int ilosc_iteracji, int prawdopodobienstwo_mutacji,
        int prawdopodobienstwo_krzyzowania, int prawdopodobienstwo_inwersji,
        int ile_elitarnych, int jakie_krzyzowanie, int jaka_mutacja, int jaka_selekcja, bool unikalne_potomstwo,
        int ilosc_najlepszych, int wielkosc_turnieju, int jakie_skalowanie, int potega, double lewa, double prawa,
        double lewa_y, double prawa_y, int jaka_funkcja);

    //gettery
    int getDokladnosc() { return dokladnosc; }
    int getOptimum() { return optimum; }
    double getStala() { return stala; }
    int getIlosc_przedzialow() { return ilosc_przedzialow; }
    int getIlosc_bitow_x() { return ilosc_bitow_x; }
    int getIlosc_bitow_y() { return ilosc_bitow_y; }
    int getIlosc_populacji() { return ilosc_populacji; }
    int getIlosc_iteracji() { return ilosc_iteracji; }
    int getPrawdopodobienstwo_mutacji() { return prawdopodobienstwo_mutacji; }
    int getPrawdopodobienstwo_krzyzowania() { return prawdopodobienstwo_krzyzowania; }
    int getPrawdopodobienstwo_inwersji() { return prawdopodobienstwo_inwersji; }
    int getJakie_krzyzowanie() { return jakie_krzyzowanie; }
    int getJaka_mutacja() { return jaka_mutacja; }
    int getIle_elitarnych() { return ile_elitarnych; }
    int getJaka_selekcja() { return jaka_selekcja; }
    int getIlosc_najlepszych() { return ilosc_najlepszych; }
    double getIlosc_przeniesionych() { return ilosc_przeniesionych; }
    bool getUnikalne_potomstwo() { return unikalne_potomstwo; }
    int getWielkosc_turnieju() { return wielkosc_turnieju; }
    int getJakie_skalowanie() { return jakie_skalowanie; }
    int getPotega() { return potega; }
    double getLewa_x() { return lewa_x; }
    double getPrawa_x() { return prawa_x; }
    double getDlugosc_x() { return dlugosc_x; }
    double getLewa_y() { return lewa_y; }
    double getPrawa_y() { return prawa_y; }
    double getDlugosc_y() { return dlugosc_y; }
    int getJaka_funkcja() { return jaka_funkcja; }
};

enum optimum
{
    MAKSIMUM,
    MINIMUM
};
