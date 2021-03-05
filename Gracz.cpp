#include <iostream>
#include <cmath>
#include "Gracz.h"

using namespace std;

    Gracz :: Gracz()
    {
        nick = ' ';
        zatopione_statki = 0;
        ustawione_statki = 0;
        liczba_strzalow = 0;
        zwyciezca = false;
    }
    void Gracz ::  set_nick()
    {
        cout<< "Podaj nick gracza " <<endl;
        getline(cin,nick);
    }
    string Gracz :: get_nick()
    {
        return nick;
    }
    int Gracz :: get_ustawione_statki()
    {
        return ustawione_statki;
    }
    void Gracz :: set_ustawione_statki()
    {
        ustawione_statki++;
    }
    int Gracz :: get_zatopione_statki()
    {
        return zatopione_statki;
    }
    void Gracz :: set_zatopione_statki()
    {
        zatopione_statki++;
    }
    void Gracz :: set_zwyciezca()
    {
        zwyciezca = true;
    }
    bool Gracz :: get_zwyciezca()
    {
        return zwyciezca;
    }
    void Gracz :: set_liczba_strzalow()
    {
        liczba_strzalow++;
    }
    int Gracz :: get_liczba_strzalow()
    {
        return liczba_strzalow;
    }
