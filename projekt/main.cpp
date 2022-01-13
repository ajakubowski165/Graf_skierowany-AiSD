#include <iostream>
#include "opracujgraf.h"
#include <fstream>

using namespace std;



int main( )
{
    int n, m, v1, v2;

    lista ** A;
    lista *p;

    //Wczytujemy liczbe wierzcholkow oraz krawedzi
    cout<<"Podaj liczbe wierzcholkow"<<endl;
    cin >> n;
    cout<<"Podaj liczbe krawedzi"<<endl;
    cin >> m;

    //tworzymy tablice list
    A = new lista * [ n ];

    //zerujemy tablice, do ktorej bedziemy wstawiac listy
    for(int  i = 0; i < n; i++ ) A [ i ] = NULL;

    //wprowadzamy graf
    cout<<"Wprowadz graf za pomoca listy krawedzi (wierzcholek startowy, wierzcholek koncowy)"<<endl;
    for(int  i = 0; i < m; i++ )
    {
        cin >> v1 >> v2;     // Wierzcholek startowy i koñcowy krawêdzi
        p = new lista;       // Tworzymy nowy element
        p->v = v2;           // Numerujemy go jako v2
        p->next = A [ v1 ];  // Dodajemy go na poczatek listy A [ v1 ]
        A [ v1 ] = p;
    }

    cout << endl;


    // wywolujemy funkcje
    sasiedzi(n,p,A);
    sasiedziKazdegoWierzcholka(n,p,A);
    stopnieWychodzace(n,p,A);
    stopnieWchodzace(n,p,A);
    wierzcholkiIzolowane(n,p,A);
    petle(n,p,A);
    krawedzieDwukierunkowe(n,p,A);


    delete [ ] A;

    return 0;
}
