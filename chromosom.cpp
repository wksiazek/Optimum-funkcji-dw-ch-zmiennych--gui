#pragma once
#define _USE_MATH_DEFINES
#include"stdafx.h"
#include"Chromosom.h"
#include"Stale.h"

//konstruktor
Chromosom::Chromosom()
{
    /*geny.push_back(0);
    geny.push_back(1);
    geny.push_back(0);
    geny.push_back(0);
    geny.push_back(0);
    geny.push_back(1);
    geny.push_back(0);
    geny.push_back(0);
    geny.push_back(1);

    geny.push_back(0);
    geny.push_back(1);
    geny.push_back(1);
    geny.push_back(0);
    geny.push_back(1);
    geny.push_back(0);
    geny.push_back(0);
    geny.push_back(0);
    geny.push_back(0);

    geny.push_back(1);
    geny.push_back(1);
    geny.push_back(1);
    geny.push_back(1);
    geny.push_back(1);
    geny.push_back(0);
    geny.push_back(0);
    geny.push_back(1);
    geny.push_back(0);
    geny.push_back(1);
    geny.push_back(0);
    geny.push_back(0);
    geny.push_back(0);
    geny.push_back(1);
    geny.push_back(0);*/

}
//funkcje operujace na pojedynczym chromosomie
void Chromosom::oblicz_reprezentacje10()
{
    reprezentacja10_x = 0;
    reprezentacja10_y = 0;
    for (int j = Stale::instance()->getIlosc_bitow_x(); j >0; --j)
    {
        reprezentacja10_x += static_cast<int>(pow(2.0, static_cast<double>(Stale::instance()->getIlosc_bitow_x() - j))*geny[j - 1]);//uwaga na wzór nie jestem pewny
    }

    int potega= Stale::instance()->getIlosc_bitow_y();
    for (int i = Stale::instance()->getIlosc_bitow_y(), j = Stale::instance()->getIlosc_bitow_y() +
        Stale::instance()->getIlosc_bitow_x(); j > Stale::instance()->getIlosc_bitow_x(); --j,--i)
    {
        reprezentacja10_y += static_cast<int>(pow(2.0, static_cast<double>(potega-i))*geny[j - 1]);//uwaga na wzór nie jestem pewny
    }
}

void Chromosom::przeskaluj()
{
    przeskalowana_wartosc_x = static_cast<double>(Stale::instance()->getLewa_x()) + (Stale::instance()->getDlugosc_x()*static_cast<double>(reprezentacja10_x)) / (pow(2.0, static_cast<double>(Stale::instance()->getIlosc_bitow_x())) - 1.0);
    przeskalowana_wartosc_y = static_cast<double>(Stale::instance()->getLewa_y()) + (Stale::instance()->getDlugosc_y()*static_cast<double>(reprezentacja10_y)) / (pow(2.0, static_cast<double>(Stale::instance()->getIlosc_bitow_y())) - 1.0);
}

void Chromosom::oblicz_funkcje_celu()
{
    wartosc_funkcji_celu = funkcja(przeskalowana_wartosc_x,przeskalowana_wartosc_y);
}

void Chromosom::oblicz_przeskalowana_funkcje_celu(vector<Chromosom> &tab)
{
    //skalowanie funkcji celu
    if (Stale::instance()->getJakie_skalowanie() == SKALOWANIE_LINIOWE)
    {
        if (Stale::instance()->getOptimum() == MAKSIMUM)
        {
            przeskalowana_funkcja_celu = wartosc_funkcji_celu + Stale::instance()->getStala();
        }
    }
    else if (Stale::instance()->getJakie_skalowanie() == SKALOWANIE_POTEGOWE)
    {
        przeskalowana_funkcja_celu = pow(wartosc_funkcji_celu, Stale::instance()->getPotega());
    }
    else if (Stale::instance()->getJakie_skalowanie() == SKALOWANIE_OBCINAJACE_TYPU_SIGMA)
    {
        double srednia_funkcja_celu = 0.0;
        double odchylenie_standardowe;
        double suma = 0.0;
        int c = 3; //liczba z zakresu (1,5)
                   //licze srednia
        for (size_t i = 0; i < tab.size(); ++i)
        {
            srednia_funkcja_celu += tab[i].wartosc_funkcji_celu;
        }
        srednia_funkcja_celu /= tab.size();
        //licze odchylenie standardowe
        for (size_t i = 0; i < tab.size(); ++i)
        {
            suma += pow(tab[i].wartosc_funkcji_celu - srednia_funkcja_celu, 2);
        }

        odchylenie_standardowe = sqrt(suma / tab.size());
        przeskalowana_funkcja_celu = wartosc_funkcji_celu + (srednia_funkcja_celu + c*odchylenie_standardowe);
    }
}

bool Chromosom::nieunikalny(vector<Chromosom> &tab)
{
    for (auto i = tab.begin(); i != tab.end(); ++i)
    {
        //static int a = 0;
        if (equal(geny.begin(), geny.end(), i->geny.begin()))
        {
            //a++;
            //cout << "geny nieunikalne, losujemy raz jeszcze: " << a<< endl;
            return true;
        }
    }
    return false;
}

void Chromosom::wyswietl_geny()
{
    for (vector<int>::iterator it = geny.begin(); it != geny.end(); ++it)
    {
        cout << *it;
    }
}

//funkcja ktorej optimum liczymy
double Chromosom::funkcja(double x,double y)
{
    if (Stale::instance()->getJaka_funkcja() == 0)
    {
        if (Stale::instance()->getOptimum() == MAKSIMUM)
            return 21.5 + x*sin(4.0*M_PI*x) + y*sin(20.0*M_PI*y);
        else
            return -(21.5 + x*sin(4.0*M_PI*x) + y*sin(20.0*M_PI*y));
    }
    else if (Stale::instance()->getJaka_funkcja() == 1)
    {
        if (Stale::instance()->getOptimum() == MAKSIMUM)
            return pow(x + 2.0*y - 7.0, 2.0) + pow(2.0*x + y - 5.0, 2.0);
        else
            return -(pow(x + 2.0*y - 7.0, 2.0) + pow(2.0*x + y - 5.0, 2.0));
    }
    return 0;
}
