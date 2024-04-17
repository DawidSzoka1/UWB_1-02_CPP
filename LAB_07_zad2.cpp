#include<iostream>
#include<string>

using namespace std;

class Figura{
protected:
    float pole;
public:
    virtual void obliczPole() = 0;
    void wyswietlPole(){
        cout << "Pole: " << pole << endl;
    }
};

class Kwadrat: public Figura{
private:
    float a;
public:
    void obliczPole(){
        pole = a*a;
    }
    Kwadrat(float a): a(a){
        obliczPole();
    }
};
class Kolo: public Figura{
private:
    float r;
public:
    void obliczPole(){
        pole = r*r*3.14;
    }
    Kolo(float r): r(r){
        obliczPole();
    }
};


int main(){

    Kwadrat k1(10);
    Kolo ko1(9);


    k1.wyswietlPole();
    ko1.wyswietlPole();

    return 0;
}
