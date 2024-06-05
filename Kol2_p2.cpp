#include<iostream>
#include<string>

using namespace std;

class Osoba{
private:
    string name = "brak danych";
    int wiek = -1;
public:
    Osoba(){}
    Osoba(string name, int wiek): name(name), wiek(wiek){}

    string getName(){
        return name;
    }
    int getWiek(){
        return wiek;
    }
    void setName(string nowe){
        name = nowe;
    }
    void setWiek(int nowy){
        wiek = nowy;
    }
};

class Punkty{
private:
    int liczba = -1;
public:
    Punkty(){}
    Punkty(int liczba): liczba(liczba){}
    int getLiczba(){
        return liczba;
    }
};

class Wynik{
private:
    Osoba o;
    Punkty p;
public:
    Wynik(){}
    Wynik(Osoba &o, Punkty &p): o(o), p(p){}
    void wypisz(){
        cout << o.getName() << " " << o.getWiek() <<  " " << p.getLiczba() << endl;
    }
    Osoba& getO(){
        return o;
    }
    Punkty& getP(){
        return p;
    }
    void setP(Punkty p){
        this->p = p;
    }
    void setO(Osoba o){
        this->o = o;
    }
};

class Figura{
protected:
    string typ;
    double pole;
    double obwod;
public:
    void wypisz(){
        cout << "typ: " << typ << " pole: " << pole << " obwod: " << obwod << endl;
    }
};

class Kolo: public Figura{
private:
    double promien;
public:
    double policzPole(){
        return promien * promien * 3.14;
    }
    double policzObwod(){
        return 2 * 3.14 * promien;
    }
    Kolo(){}
};


int main(){
    Wynik wyniki[5];
    wyniki[0].wypisz();
    wyniki[0].getO().setName("test");
    wyniki[0].wypisz();

    Osoba o1("Sprawdzenie", 32);
    wyniki[1].setO(o1);
    wyniki[1].wypisz();
    cout << wyniki[1].getO().getName() << endl;
    return 0;
}



