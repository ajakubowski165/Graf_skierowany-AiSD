#include <iostream>
#include <fstream>
#include "opracujgraf.h"

using namespace std;
ofstream plik;


void sasiedzi(int n, lista *p, lista **A)
{
    plik.open("wyniki.txt");
    plik << endl << endl;
    plik<<"1. Sasiedzi kazdego wierzcholka grafu:"<<endl;
    for( int i = 0; i < n; i++ )
    {
        plik<< "W" << i << " - sasiedzi: ";
        p = A [ i ];
        while( p )
        {
            plik<< " W"<< p->v; //wyswietlamy liste danego wierzcholka
            p = p->next;
        }
        plik<< endl;
    }
}

//jesli ilosc elementow na liscie jest rowna liczbie wierzcholkow
void sasiedziKazdegoWierzcholka(int n, lista *p, lista**A)
{

    plik << endl<<endl;
    plik<<"2. Wierzcholki, ktore sa sasiadami kazdego wierzcholka"<<endl;

    for( int i = 0; i < n; i++ )
    {
        int licznik=0;
        for(int j=0; j<n; j++){
        p = A [ j ];
        bool istnieje = false;

        while( p )
        {
            if(p->v == i)istnieje=true;
            p= p->next;
        }
         if(istnieje==true)licznik++;

        }
        if(licznik==n)
            plik<<"W"<<i<<" - jest sasiadem kazdego wierzcholka"<<endl;
    }
}


// stopieñ wychodz¹cy wierzcho³ka v[i]  jest równy liczbie elementów na liœcie A [i]
void stopnieWychodzace(int n, lista *p, lista **A)
{

    plik << endl << endl;
    plik<<"3. Stopnie wychodzace wierzcholkow"<<endl;
    for( int i = 0; i < n; i++ )
    {
        plik << "W" << i << " - stopien wychodzacy: ";
        p = A [ i ];

        int licznik = 0;
        while( p )
        {
            if( p->v != -1) licznik++; //jesli na liscie istnieje liczba, to zwiekszamy stopien wychodzacy
            p = p->next;
        }
        plik<<licznik<<endl;
    }

}

// stopieñ wchodz¹cy wierzcho³ka v[i]  jest równy liczbie elementów o wartoœci i we wszystkich listach
void stopnieWchodzace(int n, lista *p,lista**A)
{
    plik << endl<<endl;
    plik<<"4. Stopnie wchodzace wierzcholkow"<<endl;

    for( int i = 0; i < n; i++ )
    {
        plik << "W" << i<< " - stopien wchodzacy: ";
        int licznik = 0;
        for( int j = 0; j < n; j++ )
        {
            p = A [ j ];
            while( p )
            {
                if( p->v == i) licznik++; //jesli na liscie znajduje sie element o wartosci j, zwiekszamy stopien wchodzacy
                p = p->next;
            }
        }
        plik<<licznik<<endl;
    }

}


//wierzcholek izolowany jest wtedy, gdy lista jest pusta
void wierzcholkiIzolowane(int n, lista *p, lista **A)
{
    plik << endl << endl;
    plik<<"5. Wierzcholki izolowane"<<endl;


    //sprawdzamy czy lista jest pusta
    for( int i = 0; i < n; i++ )
    {
        int licznik=0;
        p = A [ i ];
        while( p )
        {
            if(p->v >=0 && p->v <= n) licznik++; //zliczamy ilosc elementow na liscie wierzcholka i
            p = p->next;
        }

        if(licznik==0) //jesli licznik elementow na liscie jest rowny zero to spelniony jest pierwszy warunek
            {           //teraz sprawdzamy czy na element i wystepuje na innych listach, jesli nie - jest wierzcholkiem izolowanym

            bool izolowany=true;
            for(int j=0; j<n; j++)
            {
                p = A [ j ];
                while( p )
                {
                    if(p->v == i) izolowany = false;
                    p = p->next;
                }
            }
            if(izolowany)
                plik <<"W"<<i<<" - jest wierzcholkiem  izolowanym"<<endl;
            }
    }

}


// Wierzcholek v[i]  posiada pêtlê, jeœli na liœcie A [ i ] znajduje siê element o wartoœci i.
void petle(int n, lista *p, lista**A)
{

    plik << endl<<endl;
    plik<<"6. Petle"<<endl;
    for( int i = 0; i < n; i++ )
    {
        bool istnieje=false;
        p = A [ i ];
        while( p ) //przeszukujemy liste danego wierzcholka i
        {
            if( p->v == i) istnieje=true;
            p = p->next;
        }
        if(istnieje==true)plik<<"W"<< i <<" - posiada petle"<<endl;
    }
}


// W grafie skierowanym wierzcho³ki v[i]  i v[j]  s¹ po³¹czone krawêdzi¹ dwukierunkow¹,
// jeœli lista A [ i  ] zawiera element o wartoœci j, a lista A [ j  ] zawiera element o wartoœci i.
void krawedzieDwukierunkowe(int n, lista *p,lista **A)
{

    plik << endl<<endl;
    plik<<"7. Krawedzie dwukierunkowe"<<endl;
    for( int i = 0; i < n; i++ )
    {
        bool warunek1=false;
        bool warunek2=false;

        for(int j = 0; j < n; j++ )
        {
            p = A [ i ];
            while( p )
            {
                if( p->v == j && p->v != i) warunek1=true; //sprawdzamy czy na liscie wierzcholka i znajduje sie element j - warunek1
                else warunek1=false;
                p = p->next;
            }

            p = A [ j ];
            while( p )
            {
                if(p->v == i && p->v != j)warunek2=true; //sprawdzamy czy na liscie wierzcholka j znajduje sie element i - warunek2
                else warunek2=false;
                p = p->next;
            }

            //jesli spelnione sa dwa warunki - wywolaj:
            if(warunek1 && warunek2) plik<<"Krawedz dwukierunkowa laczy wierzcholek W"<<i<<" z wierzcholkiem W"<<j<<endl;
        }
    }
       plik.close();
}






