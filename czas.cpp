#include <iostream>
#include "Czas.h"

Czas::Czas()
{
    godziny = 0;
    minuty = 0;
    sekundy = 0;
}

Czas::Czas(int g, int m, int s)
{
    godziny = 0;
    minuty = 0;
    sekundy = 0;
    ustawCzas(g, m, s);
}

Czas::Czas(int m, int s)
{
    godziny = 0;
    minuty = 0;
    sekundy = 0;
    ustawCzas(m, s);
}

Czas::Czas(int s)
{
    godziny = 0;
    minuty = 0;
    sekundy = 0;
    ustawCzas(s);
}

int Czas::podajGodziny()
{
    return godziny;
}

int Czas::podajMinuty()
{
    return minuty;
}

int Czas::podajSekundy()
{
    return sekundy;
}

void Czas::ustawGodziny(int g)
{
    if (g >= 0)
    {
        godziny = g;
    }
}

void Czas::ustawMinuty(int m)
{
    if (m >= 0 && m <= 59)
    {
        minuty = m;
    }
}

void Czas::ustawSekundy(int s)
{
    if (s >= 0 && s <= 59)
    {
        sekundy = s;
    }
}

void Czas::ustawCzas(int g, int m, int s)
{
    if (g == 0 && m == 0 && s == 0)
    {
        std::cout << "Blad: czas 0:0:0 jest niedozwolony." << std::endl;
    }
    else if (g >= 0 && m >= 0 && m <= 59 && s >= 0 && s <= 59)
    {
        ustawGodziny(g);
        ustawMinuty(m);
        ustawSekundy(s);
    }
    else
    {
        std::cout << "Blad: niepoprawne wartosci czasu." << std::endl;
    }
}

void Czas::ustawCzas(int m, int s)
{
    if (m == 0 && s == 0)
    {
        std::cout << "Blad: czas 0:0:0 jest niedozwolony." << std::endl;
    }
    else if (m >= 0 && m <= 59 && s >= 0 && s <= 59)
    {
        ustawGodziny(0);
        ustawMinuty(m);
        ustawSekundy(s);
    }
    else
    {
        std::cout << "Blad: niepoprawne wartosci czasu." << std::endl;
    }
}

void Czas::ustawCzas(int s)
{
    if (s == 0)
    {
        std::cout << "Blad: czas 0:0:0 jest niedozwolony." << std::endl;
    }
    else if (s >= 0 && s <= 59)
    {
        ustawGodziny(0);
        ustawMinuty(0);
        ustawSekundy(s);
    }
    else
    {
        std::cout << "Blad: niepoprawne wartosci czasu." << std::endl;
    }
}

void Czas::wypisz()
{
    std::cout << "Czas: " << godziny << ":" << minuty << ":" << sekundy << std::endl;
}

Czas Czas::operator+(Czas& innyCzas)
{
    Czas temp;

    int sumaGodzin = godziny + innyCzas.godziny;
    int sumaMinut = minuty + innyCzas.minuty;
    int sumaSekund = sekundy + innyCzas.sekundy;

    if (sumaSekund >= 60)
    {
        sumaMinut = sumaMinut + 1;
        sumaSekund = sumaSekund - 60;
    }

    if (sumaMinut >= 60)
    {
        sumaGodzin = sumaGodzin + 1;
        sumaMinut = sumaMinut - 60;
    }

    temp.ustawGodziny(sumaGodzin);
    temp.ustawMinuty(sumaMinut);
    temp.ustawSekundy(sumaSekund);

    return temp;
}

Czas& Czas::operator+=(Czas& innyCzas)
{
    godziny = godziny + innyCzas.godziny;
    minuty = minuty + innyCzas.minuty;
    sekundy = sekundy + innyCzas.sekundy;

    if (sekundy >= 60)
    {
        minuty = minuty + 1;
        sekundy = sekundy - 60;
    }

    if (minuty >= 60)
    {
        godziny = godziny + 1;
        minuty = minuty - 60;
    }

    return *this;
}

bool Czas::operator==(Czas& innyCzas)
{
    if (godziny == innyCzas.godziny &&
        minuty == innyCzas.minuty &&
        sekundy == innyCzas.sekundy)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Czas::operator<(Czas& innyCzas)
{
    int tenCzas = godziny * 3600 + minuty * 60 + sekundy;
    int drugiCzas = innyCzas.godziny * 3600 + innyCzas.minuty * 60 + innyCzas.sekundy;

    if (tenCzas < drugiCzas)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Czas::operator>(Czas& innyCzas)
{
    return !(*this < innyCzas) && !(*this == innyCzas);
}

bool Czas::operator<=(Czas& innyCzas)
{
    return (*this < innyCzas) || (*this == innyCzas);
}

bool Czas::operator>=(Czas& innyCzas)
{
    return !(*this < innyCzas);
}

bool Czas::operator!=(Czas& innyCzas)
{
    return !(*this == innyCzas);
}
