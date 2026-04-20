#ifndef CZAS_H
#define CZAS_H

class Czas
{
private:
    int godziny;
    int minuty;
    int sekundy;

    void ustawGodziny(int g);
    void ustawMinuty(int m);
    void ustawSekundy(int s);

public:
    Czas();
    Czas(int g, int m, int s);
    Czas(int m, int s);
    Czas(int s);

    int podajGodziny();
    int podajMinuty();
    int podajSekundy();

    void ustawCzas(int g, int m, int s);
    void ustawCzas(int m, int s);
    void ustawCzas(int s);

    void wypisz();

    Czas operator+(Czas& innyCzas);
    Czas& operator+=(Czas& innyCzas);

    bool operator==(Czas& innyCzas);
    bool operator<(Czas& innyCzas);
    bool operator>(Czas& innyCzas);
    bool operator<=(Czas& innyCzas);
    bool operator>=(Czas& innyCzas);
    bool operator!=(Czas& innyCzas);
};

#endif
