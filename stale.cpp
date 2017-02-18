#pragma once
#include"stdafx.h"
#include"klasy.h"

Stale *Stale::stale = 0;

void Stale::ustaw_parametry(int optimum, int dokladnosc, double stala, int ilosc_bitow_x, int ilosc_bitow_y,
    int ilosc_populacji, int ilosc_iteracji, int prawdopodobienstwo_mutacji, int prawdopodobienstwo_krzyzowania,
    int prawdopodobienstwo_inwersji, int ile_elitarnych, int jakie_krzyzowanie, int jaka_mutacja, int jaka_selekcja,
    bool unikalne_potomstwo, int ilosc_najlepszych, int wielkosc_turnieju, int jakie_skalowanie, int potega,
    double lewa_x, double prawa_x, double lewa_y, double prawa_y, int jaka_funkcja)
{
    this->optimum = optimum;
    this->dokladnosc = dokladnosc;
    this->stala = stala;
    //this->ilosc_przedzialow = static_cast<int>(p.dlugosc * pow(10, dokladnosc));
    this->ilosc_bitow_x = ilosc_bitow_x;
    this->ilosc_bitow_y = ilosc_bitow_y;
    this->ilosc_populacji = ilosc_populacji;
    this->ilosc_iteracji = ilosc_iteracji;
    this->prawdopodobienstwo_mutacji = prawdopodobienstwo_mutacji;
    this->jakie_krzyzowanie = jakie_krzyzowanie;
    this->jaka_mutacja = jaka_mutacja;
    this->unikalne_potomstwo = unikalne_potomstwo;
    this->ile_elitarnych = ile_elitarnych;
    this->ilosc_przeniesionych = (static_cast<double>(ile_elitarnych) / 100) * this->ilosc_populacji;
    this->prawdopodobienstwo_krzyzowania = prawdopodobienstwo_krzyzowania;
    this->jaka_selekcja = jaka_selekcja;
    this->ilosc_najlepszych = ilosc_najlepszych;
    this->wielkosc_turnieju = wielkosc_turnieju;
    this->jakie_skalowanie = jakie_skalowanie;
    this->potega = potega;
    this->prawdopodobienstwo_inwersji = prawdopodobienstwo_inwersji;
    this->lewa_x = lewa_x;
    this->prawa_x = prawa_x;
    dlugosc_x = prawa_x - lewa_x;
    this->lewa_y = lewa_y;
    this->prawa_y = prawa_y;
    dlugosc_y = prawa_y - lewa_y;
    this->jaka_funkcja = jaka_funkcja;
}
