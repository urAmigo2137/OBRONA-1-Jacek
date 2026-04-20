#include <iostream>
#include "Czas.h"
#include "Harmonogram.h"

int main()
{
    Czas c1(0, 5, 0);
    Czas c2(0, 10, 0);
    Czas c3(0, 15, 0);
    Czas c4(0, 20, 0);
    Czas c5(0, 30, 0);

    Harmonogram h1;
    h1.dodajCzas(c1);
    h1.dodajCzas(c2);
    h1.dodajCzas(c3);
    h1.dodajCzas(c4);
    h1.dodajCzas(c5);

    std::cout << "h1 przed usunieciem:" << std::endl;
    h1.wypisz();

    int n = 2;   // tutaj zmieniasz indeks

    if (h1.usunCzas(n))
    {
        std::cout << std::endl;
        std::cout << "h1 po usunieciu elementu o indeksie " << n << ":" << std::endl;
        h1.wypisz();
    }

    return 0;
}
