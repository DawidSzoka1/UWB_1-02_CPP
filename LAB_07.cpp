#include<iostream>
#include<string>
using namespace std;

class Figura{
protected:
    string typ;
    double pole;
    double obwod;
public:
    void wypisz(){
        cout << "ta figura to " << typ << " o obwodzie " << obwod << ", polu " << pole << endl;
    }
    virtual string nazwaFigury() = 0;
    virtual double policzPole() = 0;

};
class Kolo: public Figura{
private:
    double promien;
public:
    double policzPole(){
        return promien * promien * 3.14;
    }
    double policzObwod(){
        return 2*promien * 3.14;
    }
    Kolo(double promien): promien(promien){
        typ = "kolo";
        pole = policzPole();
        obwod = policzObwod();
    }
    string nazwaFigury(){
        return typ;
    }
};

class Kwadrat: public Figura{
private:
    double bok;
public:
    double policzPole(){
        return bok * bok;
    }
    double policzObwod(){
        return 4*bok;
    }
    Kwadrat(double bok):bok(bok){
        typ = "kwadrat";
        pole = policzPole();
        obwod = policzObwod();
    }
    string nazwaFigury(){
        return typ;
    }
};

class Prostokat: public Figura{
private:
    double a;
    double b;
public:
    double policzPole(){
        return a*b;
    }
    double policzObwod(){
        return 2*a + 2*b;
    }
    Prostokat(double a, double b):a(a), b(b){
        typ = "prostokat";
        pole = policzPole();
        obwod = policzObwod();
    }
    string nazwaFigury(){
        return typ;
    }
};

int main(){
    Prostokat p1(5, 7);
    Kwadrat k1(10);
    Kolo ko1(9);

    p1.wypisz();
    k1.wypisz();
    ko1.wypisz();

    Figura *scena[4];
    scena[0] = new Kwadrat(2);
    scena[1] = new Kwadrat(4);
    scena[2] = new Kolo(2);
    scena[3] = new Kolo(4);

    for(int i = 0; i < 4; i++){
        cout << "Figura " << scena[i]->nazwaFigury() << " pole: " << scena[i]->policzPole() << endl;
        delete scena[i];
    }

    return 0;
}
