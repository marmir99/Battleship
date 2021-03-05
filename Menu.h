#ifndef MENU_H
#define MENU_H
#include <fstream>
#include<string>
#include<iostream>
#include<cmath>

using namespace std;
class Menu
{
private:
    bool gra;
    int liczba_statkow;
public:
    Menu();
    void wyswietl_instrukcje();
    void ranking(string zwyciezca_nick, int zwyciezca_liczba_strzalow);
    void wyswietl_ranking();
    bool get_gra();
    void set_gra();
    int get_liczba_statkow();
};



#endif // MENU_H
