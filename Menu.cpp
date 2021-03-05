#include <fstream>
#include<string>
#include<iostream>
#include<cmath>
#include "Menu.h"

Menu :: Menu()
{
    gra = true;
    liczba_statkow = 15;
}
int Menu :: get_liczba_statkow()
{
    return liczba_statkow;
}
void Menu :: set_gra()
{
    gra = false;
}
bool Menu :: get_gra()
{
    return gra;
}
void Menu :: wyswietl_instrukcje()
{
    string linia;
    fstream plik;
    plik.open("instrukcja.txt", ios::in);
    if(plik.good()==true)
    {
        while(!plik.eof())
        {
            getline(plik,linia);
            cout << linia << endl;
        }
    }
    plik.close();
}
void Menu :: ranking(string zwyciezca_nick, int zwyciezca_liczba_strzalow)
{
    fstream wejscie, wyjscie;
    wejscie.open("ranking.txt",ios::in);
    int licznik = 0, n, buf;
    string nazwa, buf_str;
    wejscie>>nazwa;
    while(!wejscie.eof())
        {
            wejscie>>buf;
            wejscie>>buf_str;
            wejscie>>buf;
            licznik++;
        }
    wejscie.close();
    wejscie.open("ranking.txt",ios::in);
    n = licznik+1;
    string * nicki = new string[n];
    int * ranking = new int[n];
    wejscie >> nazwa;

    //zapisanie danych do tablicy
    for(int i=0; i<n-1; i++)
    {
        wejscie >> buf;
        wejscie >> nicki[i];
        wejscie >> ranking[i];
    }
    nicki[n-1] = zwyciezca_nick;
    ranking[n-1] = zwyciezca_liczba_strzalow;

    // sortowanko

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if( ranking[j] > ranking[j+1] )
            {
                swap(nicki[j],nicki[j+1]);
                swap(ranking[j],ranking[j+1]);
            }
        }
    }
    int d = nicki[n-1].length();
    for(int i=0; i<d; i++)
    {
        if( nicki[n-1][i] == ' ' )
            nicki[n-1][i] = '_';
    }
    //zapis do pliku
    wyjscie.open("ranking.txt",ios::out | ios::trunc);
    wyjscie << nazwa<<endl;
    for(int i = 0; i<n-1; i++)
    {
        wyjscie << i+1 << ' ' << nicki[i] << ' ' << ranking[i] << endl;
    }
    wyjscie << n << ' ' << nicki[n-1] << ' ' << ranking[n-1];

    wejscie.close();
    wyjscie.close();

}
void Menu :: wyswietl_ranking()
{
    string linia;
    fstream plik;
    plik.open("ranking.txt", ios::in);
    if(plik.good()==true)
    {
        while(!plik.eof())
        {
            getline(plik,linia);
            cout << linia << endl;
        }
    }
    plik.close();
}
