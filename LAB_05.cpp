#include<iostream>
#include<string>
using namespace std;

class Telewizor{
protected:

private:
  int glosnosc;
    int jasnosc;
    int kontrast;
    bool wieksze0mniejsze100(int x){
        return x > 0 && x < 100;
    }
public:
    Telewizor(){
        glosnosc = 50;
        jasnosc = 50;
        kontrast = 50;
    }
    Telewizor(int glos, int jas, int kon){
        if(wieksze0mniejsze100(glos)){
            glosnosc = glos;
        }
        if(wieksze0mniejsze100(jas)){
            jasnosc = jas;
        }
        if(wieksze0mniejsze100(kon)){
            kontrast = kon;
        }
    }
    virtual void wypisz(){
        cout << "\nglosnosc: " << glosnosc << "\nJasnosc: " << jasnosc  << "\nkontrast: " << kontrast << endl;

    }
};

class TelewizorKolorowy: public Telewizor{
private:
    int nasycenie;
public:
    TelewizorKolorowy(): Telewizor(){
        nasycenie = 50;
    }
    TelewizorKolorowy(int nas, int glos, int jasn, int kont): Telewizor(glos, jasn, kont){
        if(nas > 0 && nas < 100){
            nasycenie = nas;

        }
    }
    void wypisz(){
        Telewizor:: wypisz();

        cout<< "nasycenie: " << nasycenie << endl;
    }

};

class Osoba{
private:
    string imie;
    string nazwisko;
    int rokUr;
public:
    Osoba(){
        imie = "<brak danych>";
        nazwisko = "<brak danych>";
        rokUr = 1900;
    }
    Osoba(string im, string nazw, int rok){
        imie = im;
        nazwisko = nazw;
        if(rok >= 1950 && rok <= 2004){
            rokUr = rok;
        }
    }
    virtual void wypisz(){
        cout<< "Imie: " << imie << "\nNazwisko: " << nazwisko << "\nrokUr: " << rokUr << endl;

    }

};

class Pracownik: public Osoba{
private:
    string stanowisk;
public:
    Pracownik(): Osoba(){
        stanowisk = "pomoc";
    }
    Pracownik(string im, string nazw, int rok, string stan): Osoba(im ,nazw, rok){
        stanowisk = stan;
    }
    void wypisz(){
        Osoba:: wypisz();
        cout << "Stanowisko: " << stanowisk << endl;
    }
};

class Kierownik: public Pracownik{
public:
    Kierownik(string im, string nazw, int rok): Pracownik(im, nazw, rok, "szef"){
    }
};
int main(){
//    Telewizor tab[3];
//    tab[1].wypisz();
//    Telewizor *t = new TelewizorKolorowy(20, 30, 60, 80);
//    t->wypisz();// bierze z klasy telewizor chyba ze przed metoda jest virtual

//    Telewizor *tablica[3];
//    tablica[0] = new Telewizor();
//    tablica[1] = new TelewizorKolorowy();
//    tablica[1]->wypisz();
//
//    TelewizorKolorowy test;
//    test.wypisz();
//
//
//    Osoba person("dawid", "s", 2002);
//    person.wypisz();
//
//    Pracownik pracownik("fds", "fds", 1999, "pomoc");
//    pracownik.wypisz();
//    Kierownik kierownik("sd", "asd", 1999);
//    kierownik.wypisz();
    Pracownik *dynPra = new Pracownik();
    Pracownik *dynPra2 = new Pracownik("daw", "fds", 1999, "br");
    dynPra->wypisz();
    dynPra2->wypisz();
    Osoba *dynOsPrac = new Pracownik();
    dynOsPrac->wypisz();
    Osoba *tab[5];
    tab[0] = new Pracownik();
    tab[1] = new Pracownik("fsd", "dsfsd", 1999, "fds");
    tab[2] = new Osoba();
    tab[3] = new Osoba();
    tab[4] = new Kierownik("fdsf", "fdss", 1324);
    cout << "Tablic:\n";
    for(int i =0; i<5; i++){
        tab[i]->wypisz();
        delete tab[i];
    }

    return 0;
}
