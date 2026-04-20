#include <iostream>
#include "Harmonogram.h"

Harmonogram::Harmonogram()
{
    czasy = nullptr;
    liczbaCzasow = 0;
    pojemnosc = 0;
}

Harmonogram::Harmonogram(const Harmonogram& inny)
{
    liczbaCzasow = inny.liczbaCzasow;
    pojemnosc = inny.pojemnosc;

    if (pojemnosc > 0)
    {
        czasy = new Czas[pojemnosc];

        for (int i = 0; i < liczbaCzasow; i = i + 1)
        {
            czasy[i] = inny.czasy[i];
        }
    }
    else
    {
        czasy = nullptr;
    }
}

Harmonogram::~Harmonogram()
{
    delete[] czasy;
}

Harmonogram& Harmonogram::operator=(const Harmonogram& inny)
{
    if (this == &inny)
    {
        return *this;
    }

    delete[] czasy;

    liczbaCzasow = inny.liczbaCzasow;
    pojemnosc = inny.pojemnosc;

    if (pojemnosc > 0)
    {
        czasy = new Czas[pojemnosc];

        for (int i = 0; i < liczbaCzasow; i = i + 1)
        {
            czasy[i] = inny.czasy[i];
        }
    }
    else
    {
        czasy = nullptr;
    }

    return *this;
}

void Harmonogram::dodajCzas(Czas& nowyCzas)
{
    if (liczbaCzasow == pojemnosc)
    {
        int nowaPojemnosc;

        if (pojemnosc == 0)
        {
            nowaPojemnosc = 1;
        }
        else
        {
            nowaPojemnosc = pojemnosc + 1;
        }

        Czas* noweCzasy = new Czas[nowaPojemnosc];

        for (int i = 0; i < liczbaCzasow; i = i + 1)
        {
            noweCzasy[i] = czasy[i];
        }

        delete[] czasy;
        czasy = noweCzasy;
        pojemnosc = nowaPojemnosc;
    }

    czasy[liczbaCzasow] = nowyCzas;
    liczbaCzasow = liczbaCzasow + 1;
}

int Harmonogram::podajLiczbeCzasow()
{
    return liczbaCzasow;
}

Czas& Harmonogram::podajCzas(int indeks)
{
    return czasy[indeks];
}

void Harmonogram::wypisz()
{
    for (int i = 0; i < liczbaCzasow; i = i + 1)
    {
        std::cout << i << ": ";
        czasy[i].wypisz();
    }
}

Harmonogram Harmonogram::kopiujDoZakresu(Czas& zakres)
{
    Harmonogram nowyHarmonogram;
    Czas suma;

    for (int i = 0; i < liczbaCzasow; i = i + 1)
    {
        Czas nowaSuma = suma + czasy[i];

        if (nowaSuma <= zakres)
        {
            nowyHarmonogram.dodajCzas(czasy[i]);
            suma = nowaSuma;
        }
        else
        {
            break;
        }
    }

    return nowyHarmonogram;
}

bool Harmonogram::usunCzas(int n)
{
    // zabezpieczenie przed niepoprawnym N
    if (n < 0 || n >= liczbaCzasow)
    {
        std::cout << "Blad: niepoprawny indeks N." << std::endl;
        return false;
    }

    // gdy po usunieciu nie zostanie nic
    if (liczbaCzasow == 1)
    {
        delete[] czasy;
        czasy = nullptr;
        liczbaCzasow = 0;
        pojemnosc = 0;
        return true;
    }

    // nowa tablica mniejsza o 1
    Czas* noweCzasy = new Czas[liczbaCzasow - 1];

    int j = 0;
    for (int i = 0; i < liczbaCzasow; i = i + 1)
    {
        if (i != n)
        {
            noweCzasy[j] = czasy[i];
            j = j + 1;
        }
    }

    delete[] czasy;
    czasy = noweCzasy;
    liczbaCzasow = liczbaCzasow - 1;
    pojemnosc = liczbaCzasow;

    return true;
}
