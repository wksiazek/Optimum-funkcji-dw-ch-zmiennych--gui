#pragma once
#include"stdafx.h"
#include"Mutacja_trzypunktowa.h"
#include"Mutacja.h"
#include"Stale.h"
void Mutacja_trzypunktowa::mutacja(Chromosom &temp)
{
    int losowanie = rand() % 100;
    if (losowanie == 1)
    {
        set<int>miejsce_mutacji;
        int suma_bitow = Stale::instance()->getIlosc_bitow_x() + Stale::instance()->getIlosc_bitow_y();
        while (miejsce_mutacji.size() != 3)
        {
            miejsce_mutacji.insert(rand() % suma_bitow);
        }
        auto tempek = *(++miejsce_mutacji.begin());//dostep do drugiego elementu zbioru

        temp.getGeny()[*miejsce_mutacji.begin()] = abs(temp.getGeny()[*miejsce_mutacji.begin()] - 1);
        temp.getGeny()[tempek] = abs(temp.getGeny()[tempek] - 1);
        temp.getGeny()[*(miejsce_mutacji.rbegin())] = abs(temp.getGeny()[*(miejsce_mutacji.rbegin())] - 1);
    }
}
