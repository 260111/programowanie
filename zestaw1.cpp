#include <iostream>
#include <cstring>
#include <stdio.h>
#include <vector>

using namespace std;

struct Produkt
{
    char Nazwa[20];
    double CenaNettoPLN;
    double CenaBruttoPLN()
            {return CenaNettoPLN*1.22;}
    char * Opis(){
        char * x = new char[100];
        sprintf(x, "%s %f", Nazwa, CenaBruttoPLN());
        return x;
    }
    Produkt (char *a, double b){
        strcpy(Nazwa, a);
        CenaNettoPLN=b;
    }
};

struct Telewizor:Produkt{
    int Przekatna;
    Telewizor (char *a, double b, int c):Produkt(a, b){
        Produkt(a, b);
        Przekatna=c;
    }
    char * Opis(){
        char * x = new char[100];
        sprintf(x, "%s %f %d\"", Nazwa, CenaBruttoPLN(), Przekatna);
        return x;
    }
};

struct Sklep {
    vector <Produkt *> ListaPr;
    void DodajProdukt(Produkt *a){
        ListaPr.push_back(a);
    }
    void WypiszProdukty() {
        for (int i=0; i<ListaPr.size(); i++)
        {
            char * opis = ListaPr[i]->Opis();
            cout << opis << endl;
        }
    }
};


int main (void)
{
    char a[20];
    double b;
    cout << "Nazwa: ";
    cin >> a;
    cout << "Cena netto: ";
    cin >> b;

    Produkt rzecz (a, b);
    Telewizor nowy("Sonny", 1200, 56);

    Sklep stoore;
    stoore.DodajProdukt(&rzecz);
    stoore.DodajProdukt(&nowy);
    stoore.WypiszProdukty();
}
