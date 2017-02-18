#pragma once
#include"stdafx.h"
#include"Mutacja_jednopunktowa.h"
#include"Mutacja.h"
#include"Stale.h"
void Mutacja_jednopunktowa::mutacja(Chromosom &temp)
{
    int losowanie = rand() % 100;
    int suma_bitow = Stale::instance()->getIlosc_bitow_x() + Stale::instance()->getIlosc_bitow_y();
    if (losowanie == 1)
    {
        int miejsce_mutacji = rand() % suma_bitow;
        temp.getGeny()[miejsce_mutacji] = abs(temp.getGeny()[miejsce_mutacji] - 1);
    }
}
