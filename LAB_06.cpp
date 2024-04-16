#include<iostream>
#include<string>
using namespace std;

class Osoba{
private:

public:
    string imie;
    string nazwisko;
    int wiek;
    Osoba(){
        imie = "<brak danych>";
        nazwisko = "<brak danych>";
        wiek = -1;
    }
    Osoba(string im, string nazw, int wi){
        if(im.length()>= 3){
                imie = im;
        }
        if(nazw.length() >= 3)
            nazwisko = nazw;
        if(wi >= 18 ){
            wiek = wi;
        }
    }
    Osoba(Osoba &x){
        imie = x.imie;
        nazwisko = x.nazwisko;
        wiek = x.wiek;
    }
    virtual void wypisz(){
        cout<< "Imie: " << imie << "\nNazwisko: " << nazwisko << "\nwiek: " << wiek << endl;

    }

};

class Punkt{
private:
public:
    int liczba;

    Punkt(){
        liczba = 0;
    }
    Punkt(int licz){
        if(licz  >= 0 && licz <= 100){
            liczba = licz;
        }
    }
    Punkt(Punkt &x){
        liczba = x.liczba;
    }
    void wypisz(){
        cout << "liczba punktow: " << liczba << endl;
    }
    int getLiczba(){
        return liczba;
    }
    void setLiczba(int newLicz){
        if(newLicz  >= 0 && newLicz <= 100){
            liczba = newLicz;
        }
    }

    void addLiczba(int addL){
        liczba += addL;
    }
};
class Wynik{
private:

public:
    Osoba o;
    Punkt p;
    Wynik(){}
    Wynik(Osoba o, Punkt p): o(o), p(p){}

    void wypisz(){
        o.wypisz();
        p.wypisz();
    }
    Punkt getPunkt(){
        return p;
    }
    Osoba getOsoba(){
        return o;
    }

};
class Zawody{
public:
    Wynik w[100];
    int length;
    Zawody();
    Zawody(Wynik wy[], int length){
        this->length = length;
        for(int i = 0; i < length; i ++ ){
            w[i] = wy[i];
        }
    }
    void wypisz(){
        for(int i = 0; i < length; i++){
            w[i].wypisz();
            cout<< "testuje " << i << endl;
        }
    }
    void MaxPoints(){
        int maxP = 0;
        for(int i = 0; i < length; i++){
            if(w[i].p.liczba > maxP){
                maxP = w[i].p.liczba;
            }
        }
        cout<< "MAx liczba punktow to " <<  maxP << endl;
    }
    float SredniaPunktow(){
        int suma = 0;
        for(int i = 0; i < length; i++){
                suma += w[i].p.liczba;

        }
        return suma/length;
    }
    Osoba OsobaMaxPo(){
        int maxP = w[0].p.liczba;
        int indeks_of = 0;
        for(int i = 1; i < length; i++){
            if(w[i].p.liczba > maxP){
                maxP = w[i].p.liczba;
                indeks_of = i;
            }
        }

        return w[indeks_of].o;

    }

};

int main(){


    Wynik tab[20];
    tab[0].p.liczba = 20;
    Zawody zaw(tab, 20);
    zaw.wypisz();
    zaw.MaxPoints();

    Osoba test;
    test = zaw.OsobaMaxPo();
    test.wypisz();

    tab[0].wypisz();
    int sum = 0;
    int longest_surname = 3;
    int index_lon_sur = 0;
    cout << tab[0].getPunkt().getLiczba() << endl;
    cout << "Imiona osoba co najmniej 50 punktow: " << endl;
    for(int i = 0; i < 20; i++){

        if((i + 1) % 2 == 0){

            tab[i].p.liczba = 20;
        }
        else{
            if(tab[i].p.liczba >= 20){
                tab[i].p.liczba -= 20;
                }
            else{
                tab[i].p.liczba = 0;
            }
        }
        sum += tab[i].p.liczba;

        if(tab[i].p.liczba >= 50){
            cout << tab[i].o.imie << endl;
        }
        if(tab[i].o.nazwisko.length() > longest_surname){
            longest_surname = tab[i].o.nazwisko.length();
            index_lon_sur = i;
        }


    }
    tab[index_lon_sur].wypisz();
    cout << tab[1].getPunkt().getLiczba() << endl;
    tab[0].o.nazwisko = "test";
    tab[0].o.imie = "TEst";
    char leter;
    cout << "POdaj litere " << endl;
    cin >> leter;
    cout << "Nazwiska osob na podana litere" << endl;

    for(int i = 0; i< 20; i++){
        if(tab[i].o.nazwisko[0] == leter){
            cout << tab[i].o.nazwisko << endl;
        }
    }

    char letter_name;
    cout << "Podaj litere: " << endl;
    cin >> letter_name;
    cout << "Imie osob konczace sie na litere podana" << endl;
    for(int i = 0; i< 20; i++){
        if(tab[i].o.imie.back() == leter){
            cout << tab[i].o.imie << endl;
        }
    }
    return 0;
}

