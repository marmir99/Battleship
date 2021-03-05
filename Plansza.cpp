#include <iostream>
#include <cmath>
#include "Plansza.h"

using namespace std;

    Plansza :: Plansza()
    {
    tablica = new char* [10];
        for (int i=0; i<10; i++)
            tablica[i] = new char[10];
        for (int i=0; i<10; i++){
            for (int j=0; j<10; j++)
            {
                tablica[i][j] = '  ';
            }
        }
        przyzwolenie = 0;
        aktualny_strzal=-1;
    }
    void Plansza :: set_statek(int wspolrzedna)
    {
        int ind1 = wspolrzedna/10;
        int ind2 = wspolrzedna % 10;
        tablica[ind1][ind2] = 'X';
    }
    void Plansza :: wyswietl()
    {
        cout << "   ";
        for (int i=0; i<10; i++) cout << i << "   ";
        cout << endl;
        for (int m=0; m<10; m++) cout << "----";
                cout << "--" << endl;
        for (int i=0; i<10; i++){
            cout << i;
            for (int j=0; j<10; j++){
                cout << "|";
                cout << ' ' << tablica[i][j] << ' ';
                }
            cout << "|" << endl;
            for (int m=0; m<10; m++) cout << "----";
                cout << "--" << endl;
        }
    }
    int Plansza :: czy_mozna (int indeks, int indeks2) {
        int ind10 = indeks/10;
        int ind11 = indeks%10;
        int ind20 = indeks2/10;
        int ind21 = indeks2%10;
        if (ind10 != 0 && ind20 != 9 && ind11 != 0 && ind21 != 9){
            for (int i=ind10-1; i<=ind20+1; i++){
                for (int j=ind11-1; j<=ind21+1; j++) {
                    if (tablica[i][j] == 'X') return 0;
                }
            }
        }
        else if (ind10 == 0 && ind20 != 9 && ind11 != 0 && ind21 != 9){
            for (int i=ind10; i<=ind20+1; i++){
                for (int j=ind11-1; j<=ind21+1; j++) {
                    if (tablica[i][j] == 'X') return 0;
                }
            }
        }
        else if (ind10 != 0 && ind20 == 9 && ind11 != 0 && ind21 != 9){
            for (int i=ind10-1; i<=ind20; i++){
                for (int j=ind11-1; j<=ind21+1; j++) {
                    if (tablica[i][j] == 'X') return 0;
                }
            }
        }
        else if (ind10 != 0 && ind20 != 9 && ind11 == 0 && ind21 != 9){
            for (int i=ind10-1; i<=ind20+1; i++){
                for (int j=ind11; j<=ind21+1; j++) {
                    if (tablica[i][j] == 'X') return 0;
                }
            }
        }
        else if (ind10 != 0 && ind20 != 9 && ind11 != 0 && ind21 == 9){
            for (int i=ind10-1; i<=ind20+1; i++){
                for (int j=ind11-1; j<=ind21; j++) {
                    if (tablica[i][j] == 'X') return 0;
                }
            }
        }
        else if (ind10 == 0 && ind20 != 9 && ind11 == 0 && ind21 != 9){
            for (int i=ind10; i<=ind20+1; i++){
                for (int j=ind11; j<=ind21+1; j++) {
                    if (tablica[i][j] == 'X') return 0;
                }
            }
        }
        else if (ind10 != 0 && ind20 == 9 && ind11 != 0 && ind21 == 9){
            for (int i=ind10-1; i<=ind20; i++){
                for (int j=ind11-1; j<=ind21; j++) {
                    if (tablica[i][j] == 'X') return 0;
                }
            }
        }
    return 1;
    }
    int Plansza :: strzelaj(Plansza p)
    {
        int x=-1; // wspolrzedna strzalu
        cout << "Podaj wspolrzedna strzalu: ";
        while(x <0 || x >99)  cin >> x;
        int ind1 = x/10;
        int ind2 = x % 10;
        while (p.tablica[ind1][ind2] != ' '){
            cout << "Juz strzelales w to miejsce, strzelaj w inne" << endl;
            cin >> x;
            ind1 = x/10;
            ind2 = x % 10;
            }
        aktualny_strzal = x;
        if (tablica[ind1][ind2] == 'X') {
            p.tablica[ind1][ind2] = 'X';
            return 1;
            }
        else {
            p.tablica[ind1][ind2] = 'O';
            return 0;
        }
    }
    void Plansza :: ustaw_jednomasztowiec (Jednomasztowiec *j)
        {
        int mozna = 0;
        while (mozna==0){
            cout << "Podaj wspolrzedna: ";
            cin >> j->wspolrzedna[0];
            if (j->wspolrzedna[0] == 11111) throw string ("reset planszy");
            while ( j->wspolrzedna[0] >= 100 || j->wspolrzedna[0] <0 ) {
                cout << "wartosc musi zawierac sie miedzy 0 a 99" << endl;
                cin >> j->wspolrzedna[0];
                if (j->wspolrzedna[0] == 11111) throw string ("reset planszy");
        }
        mozna = czy_mozna(j->wspolrzedna[0], j->wspolrzedna[0]);
        if (mozna==0) cout << "Statek jest za blisko" << endl;
        }
        set_statek(j->wspolrzedna[0]);
    }
        void Plansza :: ustaw_dwumasztowiec(Dwumasztowiec *d)
    {
        int mozna = 0;
        while (mozna==0){
            cout << "Podaj wspolrzedna poczatkowa statku: " << endl;
            cin >> d->wspolrzedna[0];
            if (d->wspolrzedna[0] == 11111) throw string ("reset planszy");
            while ( d->wspolrzedna[0] >= 100 || d->wspolrzedna[0] <0 ) {
                cout << "Wartosc wspolrzednej musi zawierac sie miedzy 0 a 99" << endl;
                cin >> d->wspolrzedna[0];
                if (d->wspolrzedna[0] == 11111) throw string ("reset planszy");
                }
            cout << "Podaj wspolrzedna koncowa statku: " << endl;
            cin >> d->wspolrzedna[1];
            if (d->wspolrzedna[1] == 11111) throw string ("reset planszy");
                while (abs(d->wspolrzedna[1] - d->wspolrzedna[0]) != d->wielkosc-1 && abs(d->wspolrzedna[1] - d->wspolrzedna[0]) != (d->wielkosc-1)*10){
                    cout << "Podana zla wspolrzedna 2" << endl;
                    cin >> d->wspolrzedna[1];
                    if (d->wspolrzedna[1] == 11111) throw string ("reset planszy");
                while ( d->wspolrzedna[1] >= 100 || d->wspolrzedna[1] <0 ) {
                    cout << "Wartosc wspolrzednej musi zawierac sie miedzy 0 a 99" << endl;
                    cin >> d->wspolrzedna[1];
                    if (d->wspolrzedna[1] == 11111) throw string ("reset planszy");
                    }
                }
            if (d->wspolrzedna[0] < d->wspolrzedna[1]) mozna = czy_mozna(d->wspolrzedna[0], d->wspolrzedna[1]);
            else mozna = czy_mozna(d->wspolrzedna[1], d->wspolrzedna[0]);
            if (mozna == 0) cout << "statek jest za blisko" << endl;
        }
        set_statek(d->wspolrzedna[0]);
        set_statek(d->wspolrzedna[1]);
    }
    void Plansza :: ustaw_trzymasztowiec (Trzymasztowiec *t)
    {
        int mozna = 0;
        while (mozna == 0){
            cout << "Podaj wspolrzedna poczatkowa statku: " << endl;
            cin >> t->wspolrzedna[0];
            if (t->wspolrzedna[0] == 11111) throw string ("reset planszy");
            while ( t->wspolrzedna[0] >= 100 || t->wspolrzedna[0] <0 ) {
                cout << "Wartosc wspolrzednej musi zawierac sie miedzy 0 a 99" << endl;
                cin >> t->wspolrzedna[0];
                if (t->wspolrzedna[0] == 11111) throw string ("reset planszy");
                }
            cout << "Podaj wspolrzedna koncowa statku: " << endl;
            cin >> t->wspolrzedna[2];
            if (t->wspolrzedna[2] == 11111) throw string ("reset planszy");
            while (abs(t->wspolrzedna[2] - t->wspolrzedna[0]) != t->wielkosc-1 && abs(t->wspolrzedna[2] - t->wspolrzedna[0]) != (t->wielkosc-1)*10){
                cout << "Podana zla wspolrzedna 2" << endl;
                cin >> t->wspolrzedna[2];
                if (t->wspolrzedna[2] == 11111) throw string ("reset planszy");
                while ( t->wspolrzedna[2] >= 100 || t->wspolrzedna[2] <0 ) {
                    cout << "Wartosc wspolrzednej musi zawierac sie miedzy 0 a 99" << endl;
                    cin >> t->wspolrzedna[2];
                    if (t->wspolrzedna[2] == 11111) throw string ("reset planszy");
                    }
            }
            if (t->wspolrzedna[0] < t->wspolrzedna[2]) mozna = czy_mozna(t->wspolrzedna[0], t->wspolrzedna[2]);
            else mozna = czy_mozna(t->wspolrzedna[2], t->wspolrzedna[0]);
            if (mozna == 0) cout << "statek jest za blisko" << endl;
        }
        if (abs(t->wspolrzedna[2] - t->wspolrzedna[0]==t->wielkosc-1)){
            t->wspolrzedna[1] = (t->wspolrzedna[0] + t->wspolrzedna[2])/2;
        }
        else {
            t->wspolrzedna[1] = (t->wspolrzedna[0] + t->wspolrzedna[2])/2;
        }
        for (int i=0; i<3; i++){
            set_statek(t->wspolrzedna[i]);
        }
    }
    void Plansza :: ustaw_czteromasztowiec (Czteromasztowiec *c)
    {
        int mozna = 0;
        while (mozna == 0){
            cout << "Podaj wspolrzedna poczatkowa statku: " << endl;
            cin >> c->wspolrzedna[0];
            if (c->wspolrzedna[0] == 11111) {throw string ("reset planszy");}
            while ( c->wspolrzedna[0] >= 100 || c->wspolrzedna[0] <0 ) {
                cout << "Wartosc wspolrzednej musi zawierac sie miedzy 0 a 99" << endl;
                cin >> c->wspolrzedna[0];
                if (c->wspolrzedna[0] == 11111) throw string ("reset planszy");
                }
            cout << "Podaj wspolrzedna koncowa statku: " << endl;
            cin >> c->wspolrzedna[3];
            if (c->wspolrzedna[3] == 11111) throw string ("reset planszy");
            while (abs(c->wspolrzedna[3] - c->wspolrzedna[0]) != c->wielkosc-1 && abs(c->wspolrzedna[3] - c->wspolrzedna[0]) != (c->wielkosc-1)*10){
                cout << "Podana zla wspolrzedna 2" << endl;
                cin >> c->wspolrzedna[3];
                if (c->wspolrzedna[3] == 11111) throw string ("reset planszy");
                while ( c->wspolrzedna[3] >= 100 || c->wspolrzedna[3] <0 ) {
                    cout << "Wartosc wspolrzednej musi zawierac sie miedzy 0 a 99" << endl;
                    cin >> c->wspolrzedna[3];
                    if (c->wspolrzedna[3] == 11111) throw string ("reset planszy");
                    }
                }
        if (c->wspolrzedna[0] < c->wspolrzedna[3]) mozna = czy_mozna(c->wspolrzedna[0], c->wspolrzedna[3]);
        else mozna = czy_mozna(c->wspolrzedna[3], c->wspolrzedna[0]);
        if (mozna == 0) cout << "statek jest za blisko" << endl;
        }
        if (c->wspolrzedna[0] < c->wspolrzedna[3]){
            if (c->wspolrzedna[3] - c->wspolrzedna[0] == c->wielkosc - 1){
                c->wspolrzedna[1] = c->wspolrzedna[0] + 1;
                c->wspolrzedna[2] = c->wspolrzedna[1] + 1;
            }
            else {
                c->wspolrzedna[1] = c->wspolrzedna[0] + 10;
                c->wspolrzedna[2] = c->wspolrzedna[1] + 10;
            }
        }
        else {
            if (c->wspolrzedna[0] - c->wspolrzedna[3] == c->wielkosc - 1){
                c->wspolrzedna[1] = c->wspolrzedna[0] - 1;
                c->wspolrzedna[2] = c->wspolrzedna[1] - 1;
            }
            else {
                c->wspolrzedna[1] = c->wspolrzedna[0] - 10;
                c->wspolrzedna[2] = c->wspolrzedna[1] - 10;
            }
        }
        for (int i=0; i<4; i++) set_statek(c->wspolrzedna[i]);
    }
    void Plansza :: ustaw_pieciomasztowiec (Pieciomasztowiec *p)
    {
        int mozna = 0;
        while (mozna == 0){
            cout << "Podaj wspolrzedna poczatkowa statku: " << endl;
            cin >> p->wspolrzedna[0];
            if (p->wspolrzedna[0] == 11111) throw string ("reset planszy");
            while ( p->wspolrzedna[0] >= 100 || p->wspolrzedna[0] <0 ) {
                cout << "Wartosc wspolrzednej musi zawierac sie miedzy 0 a 99" << endl;
                cin >> p->wspolrzedna[0];
                if (p->wspolrzedna[0] == 11111) throw string ("reset planszy"); }
            cout << "Podaj wspolrzedna koncowa statku: " << endl;
            cin >> p->wspolrzedna[4];
            if (p->wspolrzedna[4] == 11111) throw string ("reset planszy");
            while (abs(p->wspolrzedna[4] - p->wspolrzedna[0]) != p->wielkosc-1 && abs(p->wspolrzedna[4] - p->wspolrzedna[0]) != (p->wielkosc-1)*10){
                cout << "Podana zla wspolrzedna 2" << endl;
                cin >> p->wspolrzedna[4];
                if (p->wspolrzedna[4] == 11111) throw string ("reset planszy");
                while ( p->wspolrzedna[4] >= 100 || p->wspolrzedna[4] <0 ) {
                    cout << "Wartosc wspolrzednej musi zawierac sie miedzy 0 a 99" << endl;
                    cin >> p->wspolrzedna[4];
                    if (p->wspolrzedna[4] == 11111) throw string ("reset planszy");
                    }
                }
            if (p->wspolrzedna[0] < p->wspolrzedna[4]) mozna = czy_mozna(p->wspolrzedna[0], p->wspolrzedna[4]);
            else mozna = czy_mozna(p->wspolrzedna[4], p->wspolrzedna[0]);
            if (mozna == 0) cout << "statek jest za blisko" << endl;
        }
        if (p->wspolrzedna[0] < p->wspolrzedna[4]){
            if (p->wspolrzedna[4] - p->wspolrzedna[0] == p->wielkosc - 1){
                p->wspolrzedna[1] = p->wspolrzedna[0] + 1;
                p->wspolrzedna[2] = p->wspolrzedna[1] + 1;
                p->wspolrzedna[3] = p->wspolrzedna[2] + 1;
            }
            else {
                p->wspolrzedna[1] = p->wspolrzedna[0] + 10;
                p->wspolrzedna[2] = p->wspolrzedna[1] + 10;
                p->wspolrzedna[3] = p->wspolrzedna[2] + 10;
            }
        }
        else {
            if (p->wspolrzedna[0] - p->wspolrzedna[4] == p->wielkosc - 1){
                p->wspolrzedna[1] = p->wspolrzedna[0] - 1;
                p->wspolrzedna[2] = p->wspolrzedna[1] - 1;
                p->wspolrzedna[3] = p->wspolrzedna[2] - 1;
            }
            else {
                p->wspolrzedna[1] = p->wspolrzedna[0] - 10;
                p->wspolrzedna[2] = p->wspolrzedna[1] - 10;
                p->wspolrzedna[3] = p->wspolrzedna[2] - 10;
            }
        }
        for (int i=0; i<5; i++) set_statek(p->wspolrzedna[i]);
    }
    int Plansza :: inkrementuj_obrazenia( Jednomasztowiec **tab_jednomasztowcow,
                               Dwumasztowiec **tab_dwumasztowcow,
                               Trzymasztowiec **tab_trzymasztowcow,
                               Czteromasztowiec **tab_czteromasztowcow,
                               Pieciomasztowiec **tab_pieciomasztowcow,
                               int numer_gracza )
    {
        int i_wspolrzednej, i1, i2, i3, i4, i5, ostatnia_iteracja1, ostatnia_iteracja2, ostatnia_iteracja3, ostatnia_iteracja4, ostatnia_iteracja5;
        if (numer_gracza == 1)
        {
            i1 =0; i2 = 0; i3 =0; i4 = 0; i5 =0;
            ostatnia_iteracja1 = 5; ostatnia_iteracja2 = 4; ostatnia_iteracja3 = 3; ostatnia_iteracja4 = 2; ostatnia_iteracja5 = 1;
        }
        if( numer_gracza == 2 )
        {
            i1 = 5; i2=4; i3 =3; i4 = 2; i5 = 1;
            ostatnia_iteracja1 = 10; ostatnia_iteracja2 = 8; ostatnia_iteracja3 = 6; ostatnia_iteracja4 = 4; ostatnia_iteracja5 =2;
        }
        for( i1 ; i1 < ostatnia_iteracja1; i1++ )
        {
            for ( i_wspolrzednej=0; i_wspolrzednej < 1; i_wspolrzednej++)
            {
                if( aktualny_strzal == tab_jednomasztowcow[i1]->wspolrzedna[i_wspolrzednej] )
                {
                    tab_jednomasztowcow[i1]->obrazenia++;
                    if (tab_jednomasztowcow[i1]->obrazenia==1) return 1;
                }
            }
        }

        for( i2; i2 < ostatnia_iteracja2; i2++ )
        {
            for (i_wspolrzednej=0; i_wspolrzednej < 2; i_wspolrzednej++)
                if( aktualny_strzal == tab_dwumasztowcow[i2]->wspolrzedna[i_wspolrzednej] )
                {
                    tab_dwumasztowcow[i2]->obrazenia++;
                    if (tab_dwumasztowcow[i2]->obrazenia==2 ) return 1;
                }
        }
        for( i3 ; i3 < ostatnia_iteracja3; i3++ )
        {
            for ( i_wspolrzednej=0; i_wspolrzednej < 3; i_wspolrzednej++)
                if( aktualny_strzal == tab_trzymasztowcow[i3]->wspolrzedna[i_wspolrzednej] )
                {
                    tab_trzymasztowcow[i3]->obrazenia++;
                    if (tab_trzymasztowcow[i3]->obrazenia==3) return 1;
                }
        }
        for( i4 ; i4 < ostatnia_iteracja4; i4++ )
        {
            for (i_wspolrzednej=0; i_wspolrzednej < 4; i_wspolrzednej++)
                if( aktualny_strzal == tab_czteromasztowcow[i4]->wspolrzedna[i_wspolrzednej] )
                {
                    tab_czteromasztowcow[i4]->obrazenia++;
                    if (tab_czteromasztowcow[i4]->obrazenia==4 ) return 1;
                }
        }
        for ( i_wspolrzednej=0; i_wspolrzednej < 5; i_wspolrzednej++)
            if( aktualny_strzal == tab_pieciomasztowcow[i5]->wspolrzedna[i_wspolrzednej] )
            {
                tab_pieciomasztowcow[i5]->obrazenia++;
                if (tab_pieciomasztowcow[i5]->obrazenia==5 )
                {
                    return 1;
                }
            }

        return 0;
}

    void Plansza :: reset_planszy()
    {
            for (int i=0; i<10; i++){
                for (int j=0; j<10; j++)
                {
                    tablica[i][j] = '  ';
                }
            }
    }
    void Plansza :: set_przyzwolenie(bool p)
    {
        przyzwolenie = p;
    }
    bool Plansza :: get_przyzwolenie()
    {
        return przyzwolenie;
    }
