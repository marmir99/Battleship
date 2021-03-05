#ifndef GRACZ_H
#define GRACZ_H

#include <iostream>
#include <cmath>

using namespace std;

class Gracz{
private:
    string nick;
    int zatopione_statki;
    bool zwyciezca;
    int liczba_strzalow;
    int ustawione_statki;
public:
    Gracz();
    void set_nick();
    string get_nick();
    void set_zatopione_statki();
    int get_zatopione_statki();
    void set_zwyciezca();
    bool get_zwyciezca();
    void set_liczba_strzalow();
    int get_liczba_strzalow();
    int get_ustawione_statki();
    void set_ustawione_statki();

};



#endif
