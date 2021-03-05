#include <iostream>
#include <cmath>
#include "Plansza.h"
#include "Jednomasztowiec.h"
#include "Statek.h"
#include "Dwumasztowiec.h"
#include "Trzymasztowiec.h"
#include "Czteromasztowiec.h"
#include "Pieciomasztowiec.h"
#include "Gracz.h"
#include "Menu.h"

using namespace std;


//wyswietlanie
int main()
{
    Menu m;
    m.wyswietl_instrukcje();
    //m.set_liczba_statkow();

    Gracz gracz1;
    Gracz gracz2;
    gracz1.set_nick();
    gracz2.set_nick();
    while (gracz1.get_nick() == gracz2.get_nick()){
    gracz2.set_nick();
    }

    //tworzenie objektow statkow i tablic statkow
    Plansza planszaGracza1;
    Plansza planszaGracza2;
    Plansza zgadujGracz1;
    Plansza zgadujGracz2;

    //tablica wskaznikow na statki
    Jednomasztowiec **tab_jednomasztowcow = new Jednomasztowiec*[10];
    Dwumasztowiec **tab_dwumasztowcow = new Dwumasztowiec*[8];
    Trzymasztowiec **tab_trzymasztowcow = new Trzymasztowiec*[6];
    Czteromasztowiec **tab_czteromasztowcow = new Czteromasztowiec*[4];
    Pieciomasztowiec **tab_pieciomasztowcow = new Pieciomasztowiec*[2];

    //tworzymy statki
    Jednomasztowiec j1, j2, j3, j4, j5, j6, j7, j8, j9, j10;
    Dwumasztowiec d1, d2, d3, d4, d5, d6, d7, d8;
    Trzymasztowiec t1, t2, t3, t4, t5, t6;
    Czteromasztowiec c1, c2, c3, c4;
    Pieciomasztowiec p1, p2;

    // kazdy statek ma swoj wskaznik
    Jednomasztowiec* wj1=&j1;
    Jednomasztowiec* wj2=&j2;
    Jednomasztowiec* wj3=&j3;
    Jednomasztowiec* wj4=&j4;
    Jednomasztowiec* wj5=&j5;
    Jednomasztowiec* wj6=&j6;
    Jednomasztowiec* wj7=&j7;
    Jednomasztowiec* wj8=&j8;
    Jednomasztowiec* wj9=&j9;
    Jednomasztowiec* wj10=&j10;
    Dwumasztowiec* wd1=&d1;
    Dwumasztowiec* wd2=&d2;
    Dwumasztowiec* wd3=&d3;
    Dwumasztowiec* wd4=&d4;
    Dwumasztowiec* wd5=&d5;
    Dwumasztowiec* wd6=&d6;
    Dwumasztowiec* wd7=&d7;
    Dwumasztowiec* wd8=&d8;
    Trzymasztowiec* wt1=&t1;
    Trzymasztowiec* wt2=&t2;
    Trzymasztowiec* wt3=&t3;
    Trzymasztowiec* wt4=&t4;
    Trzymasztowiec* wt5=&t5;
    Trzymasztowiec* wt6=&t6;
    Czteromasztowiec* wc1=&c1;
    Czteromasztowiec* wc2=&c2;
    Czteromasztowiec* wc3=&c3;
    Czteromasztowiec* wc4=&c4;
    Pieciomasztowiec* wp1=&p1;
    Pieciomasztowiec* wp2=&p2;

    //przypisujemy wskazniki statkow do tablicy
    tab_jednomasztowcow[0] = wj1;
    tab_jednomasztowcow[1] = wj2;
    tab_jednomasztowcow[2] = wj3;
    tab_jednomasztowcow[3] = wj4;
    tab_jednomasztowcow[4] = wj5;
    tab_jednomasztowcow[5] = wj6;
    tab_jednomasztowcow[6] = wj7;
    tab_jednomasztowcow[7] = wj8;
    tab_jednomasztowcow[8] = wj9;
    tab_jednomasztowcow[9] = wj10;

    tab_dwumasztowcow[0] = wd1;
    tab_dwumasztowcow[1] = wd2;
    tab_dwumasztowcow[2] = wd3;
    tab_dwumasztowcow[3] = wd4;
    tab_dwumasztowcow[4] = wd5;
    tab_dwumasztowcow[5] = wd6;
    tab_dwumasztowcow[6] = wd7;
    tab_dwumasztowcow[7] = wd8;

    tab_trzymasztowcow[0] = wt1;
    tab_trzymasztowcow[1] = wt2;
    tab_trzymasztowcow[2] = wt3;
    tab_trzymasztowcow[3] = wt4;
    tab_trzymasztowcow[4] = wt5;
    tab_trzymasztowcow[5] = wt6;

    tab_czteromasztowcow[0] = wc1;
    tab_czteromasztowcow[1] = wc2;
    tab_czteromasztowcow[2] = wc3;
    tab_czteromasztowcow[3] = wc4;

    tab_pieciomasztowcow[0] = wp1;
    tab_pieciomasztowcow[1] = wp2;



    //int ustawione_statki = 0;
    while (gracz1.get_ustawione_statki() < m.get_liczba_statkow())
    {
        try {
            //ustawione_statki = 0;
            cout << "Teraz ustawia ";
            cout << gracz1.get_nick() <<endl;
            cout << "Ustaw pieciomasztowiec" << endl;
            planszaGracza1.wyswietl();
            planszaGracza1.ustaw_pieciomasztowiec(tab_pieciomasztowcow[0]); gracz1.set_ustawione_statki();
            planszaGracza1.wyswietl();
            cout << "Ustaw 2 czteromasztowce" << endl;
            planszaGracza1.wyswietl();
            planszaGracza1.ustaw_czteromasztowiec(tab_czteromasztowcow[0]); gracz1.set_ustawione_statki();
            planszaGracza1.wyswietl();
            planszaGracza1.ustaw_czteromasztowiec(tab_czteromasztowcow[1]); gracz1.set_ustawione_statki();

            cout << "Ustaw 3 trzymasztowce" << endl;
            for (int i=0; i<3; i++){
                planszaGracza1.wyswietl();
                planszaGracza1.ustaw_trzymasztowiec(tab_trzymasztowcow[i]); gracz1.set_ustawione_statki();
            }
            cout << "Ustaw 4 dwumasztowce:" << endl;
            for (int i=0; i<4; i++){
                planszaGracza1.wyswietl();
                planszaGracza1.ustaw_dwumasztowiec(tab_dwumasztowcow[i]); gracz1.set_ustawione_statki();
            }
            cout << "Ustaw 5 jednomasztowcow" << endl;
            for (int i=0; i<5; i++){
                planszaGracza1.wyswietl();
                planszaGracza1.ustaw_jednomasztowiec(tab_jednomasztowcow[i]); gracz1.set_ustawione_statki();
            }
        }
        catch (string e)
        {
            planszaGracza1.reset_planszy();
            cout << e << endl;
        }
        catch (...)
        {
            cout << "Nieznasz mnie" << endl;
        }
    }

    //int ustawione_statki2 = 0;
    while (gracz2.get_ustawione_statki()<m.get_liczba_statkow())
    {
        try{
            //ustawione_statki2 = 0; // czy to bylo potrzebne !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            cout << "Teraz ustawia: " ;
            cout << gracz2.get_nick() <<endl;
            cout << "Ustaw pieciomasztowiec" << endl;
            planszaGracza2.wyswietl();
            planszaGracza2.ustaw_pieciomasztowiec(tab_pieciomasztowcow[1]); gracz2.set_ustawione_statki();
            planszaGracza2.wyswietl();
            cout << "Ustaw 2 czteromasztowce" << endl;
            planszaGracza2.wyswietl();
            planszaGracza2.ustaw_czteromasztowiec(tab_czteromasztowcow[2]); gracz2.set_ustawione_statki();
            planszaGracza2.wyswietl();
            planszaGracza2.ustaw_czteromasztowiec(tab_czteromasztowcow[3]); gracz2.set_ustawione_statki();
            cout << "Ustaw 3 trzymasztowce" << endl;
            for (int i=3; i<6; i++){
                planszaGracza2.wyswietl();
                planszaGracza2.ustaw_trzymasztowiec(tab_trzymasztowcow[i]); gracz2.set_ustawione_statki();
            }
            cout << "Ustaw 4 dwumasztowce" << endl;
            for (int i=4; i<8; i++){
                planszaGracza2.wyswietl();
                planszaGracza2.ustaw_dwumasztowiec(tab_dwumasztowcow[i]); gracz2.set_ustawione_statki();
            }
            cout << "Ustaw 5 jednomasztowcow" << endl;
            for (int i=5; i<10; i++){
                planszaGracza2.wyswietl();
                planszaGracza2.ustaw_jednomasztowiec(tab_jednomasztowcow[i]); gracz2.set_ustawione_statki();
            }
        }
        catch (string e)
        {
            planszaGracza2.reset_planszy();
            cout << e << endl;
        }
        catch (...)
        {
            cout << "Nieznasz mnie" << endl;
        }
    }
    int zatopiony = 0;
    zgadujGracz1.set_przyzwolenie(true);
    while( m.get_gra() )
    {
        while(zgadujGracz1.get_przyzwolenie() == true)
        {
            gracz1.set_liczba_strzalow();
            zatopiony = 0;
            cout << "Strzelaj "<<gracz1.get_nick() <<endl;
            zgadujGracz1.wyswietl();

            if(planszaGracza2.strzelaj(zgadujGracz1)==1)
            {
                cout << "Trafiony!!! Brawo " << gracz1.get_nick() <<endl;
                zatopiony = 0;
                zatopiony = planszaGracza2.inkrementuj_obrazenia(tab_jednomasztowcow,tab_dwumasztowcow,tab_trzymasztowcow,tab_czteromasztowcow,tab_pieciomasztowcow,2);
                if (zatopiony==1)
                {
                    cout << "ZATOPIONY!!!!!!!!!" << endl;
                    gracz1.set_zatopione_statki();

                    zatopiony = 0;
                    if (gracz1.get_zatopione_statki()==m.get_liczba_statkow())
                    {
                        gracz1.set_zwyciezca();
                        zgadujGracz1.set_przyzwolenie(false);
                        zgadujGracz2.set_przyzwolenie(false);
                    }
                }
            }
            else
            {
                cout << "Pudlo :("<<endl;
                zgadujGracz1.set_przyzwolenie(false);
                zgadujGracz2.set_przyzwolenie(true);
            }
        }
        if (gracz1.get_zwyciezca() == true)
        {
             m.set_gra();
        }
        while(zgadujGracz2.get_przyzwolenie() == true)
        {
            gracz2.set_liczba_strzalow();
            cout << "Strzelaj "<<gracz2.get_nick() <<endl;
            zgadujGracz2.wyswietl();
            if(planszaGracza1.strzelaj(zgadujGracz2)==1)
            {
                cout << "Trafiony!!! Brawo " << gracz2.get_nick() <<endl;
                zatopiony = 0;
                zatopiony = planszaGracza1.inkrementuj_obrazenia(tab_jednomasztowcow,tab_dwumasztowcow,tab_trzymasztowcow,tab_czteromasztowcow,tab_pieciomasztowcow,1);

                if (zatopiony==1)
                {
                    cout << "ZATOPIONY!!!!!!!!" << endl;
                    gracz2.set_zatopione_statki();
                    if (gracz2.get_zatopione_statki()==m.get_liczba_statkow())
                    {
                        gracz2.set_zwyciezca();
                        zgadujGracz2.set_przyzwolenie(false);
                        zgadujGracz1.set_przyzwolenie(false);
                    }
                }
            }
            else
            {
            cout << "Pudlo :("<<endl;
            zgadujGracz1.set_przyzwolenie(true);// = 1;
            zgadujGracz2.set_przyzwolenie(false);// = 0;
            }
        }
        if (gracz2.get_zwyciezca() == true)
        {
             m.set_gra();
        }
    }
    if (gracz1.get_zwyciezca()==true)
        {
            m.ranking(gracz1.get_nick(),gracz1.get_liczba_strzalow());
            cout << "Wygral/a " <<gracz1.get_nick()<<endl;
            cout << "GRATULACJE!" << endl;
        }
    if (gracz2.get_zwyciezca()==true)
        {
            m.ranking(gracz2.get_nick(),gracz2.get_liczba_strzalow());
            cout << "Wygral/a " <<gracz2.get_nick()<<endl;
            cout << "GRATULACJE!" << endl;
        }
    m.wyswietl_ranking();
    return 0;
}
