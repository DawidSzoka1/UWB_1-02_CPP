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
};

int main(){
    Prostokat p1(5, 7);
    Kwadrat k1(10);
    Kolo ko1(9);

    p1.wypisz();
    k1.wypisz();
    ko1.wypisz();


    return 0;
}
