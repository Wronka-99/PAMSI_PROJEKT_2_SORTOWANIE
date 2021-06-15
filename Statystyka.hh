#ifndef Statystyka__hh
#define Statystyka__hh

#include <iostream>
#include "film.hh"

using namespace std;


void statystyka(film *lista_kubelkowa,int rozmiar)
{
   
    int liczba_powtorzen=0;
    int tablica[11]={0,0,0,0,0,0,0,0,0,0,0};
    int dominanta=0;
    int mediana = 0;
    float srednia= 0;
    int suma =0;
    

    for(int a=0; a<rozmiar; a++)
    {
        for(int b=0; b<11;b++)
        {
            if(lista_kubelkowa[a].ocena_konwersja==b)
            {
                tablica[b]++;
            }
        }
        suma=suma+lista_kubelkowa[a].ocena_konwersja;
    }

    
    srednia=float(suma)/float(rozmiar);

    for(int c=0; c<11;c++)
    {
        if(liczba_powtorzen<=tablica[c])
        {
            liczba_powtorzen=tablica[c];
             dominanta++;
        }
    }

    mediana= lista_kubelkowa[(rozmiar/2)-1].ocena_konwersja;

   
 cout<<"Dominanta rankingu dla tego algorytmu wyniosła:"<<dominanta<<", a wystapiła ona:"<<liczba_powtorzen<<", natomiast srednia rankingu to "<<srednia<<"a mediana:"<<mediana<<"."<<endl<<endl;
    

}

#endif