#ifndef HARMONOGRAM_H
#define HARMONOGRAM_H

#include "Czas.h"

class Harmonogram
{
private:
    Czas* czasy;
    int liczbaCzasow;
    int pojemnosc;

public:
    Harmonogram();
    Harmonogram(const Harmonogram& inny);
    ~Harmonogram();

    Harmonogram& operator=(const Harmonogram& inny);

    void dodajCzas(Czas& nowyCzas);
    int podajLiczbeCzasow();
    Czas& podajCzas(int indeks);
    void wypisz();

    Harmonogram kopiujDoZakresu(Czas& zakres);
    void usunCzas(int n);
};

#endif
