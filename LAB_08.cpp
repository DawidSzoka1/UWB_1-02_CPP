#include<iostream>

using namespace std;

class LiczbyZespolone{
private:
    float re;
    float im;
public:
    float getRe(){
        return re;
    }
    float getIm(){
        return im;
    }
    LiczbyZespolone(float re, float im): re(re), im(im){}
    LiczbyZespolone(){}
    LiczbyZespolone operator+(LiczbyZespolone &li){
        return LiczbyZespolone(re + li.getRe(), im + li.getIm());
    }
    LiczbyZespolone operator+(float liczba){
        return LiczbyZespolone(re + liczba, im);
    }
    LiczbyZespolone operator/(LiczbyZespolone &li){
        return LiczbyZespolone(re / li.getRe(), im / li.getIm());
    }
    bool operator==(LiczbyZespolone &li){
        return re == li.getRe() && im == li.getIm();
    }
    void operator+=(LiczbyZespolone &li){
        re += li.getRe();
        im += li.getIm();
    }
    LiczbyZespolone operator!(){
        return LiczbyZespolone(re, -im);
    }
    friend LiczbyZespolone operator*(float skalar, LiczbyZespolone &li);
    friend LiczbyZespolone operator+(float skalar, LiczbyZespolone &li);


};

LiczbyZespolone operator*(float skalar, LiczbyZespolone &li){
    return LiczbyZespolone(li.getRe() * skalar, li.getIm() * skalar);
}
LiczbyZespolone operator+(float skalar, LiczbyZespolone &li){
    return LiczbyZespolone(li.getRe() + skalar, li.getIm() + skalar);
}

ostream& operator<<(ostream& o,LiczbyZespolone &li){
    if(li.getIm() < 0)
        o<< li.getRe() << li.getIm() << "j" << endl;
    else
        o<< li.getRe() << " + " << li.getIm() << "j" << endl;

    return o;
}

class PustaKlasa{
private:
    static int ilosc;
public:
    PustaKlasa(){
        ilosc++;
    }
    ~PustaKlasa(){
        ilosc--;
    }
    static int getIlosc(){
        return ilosc;
    }
};

int PustaKlasa:: ilosc = 0;

int main(){

    PustaKlasa p1;
    cout << "Ilosc: " << p1.getIlosc() << endl;
    PustaKlasa p2;
    cout << "Ilosc: " << p1.getIlosc() << endl;
    PustaKlasa *p3 = new PustaKlasa();
    cout << "Ilosc: " << p1.getIlosc() << endl;
    PustaKlasa *p4 = new PustaKlasa();
    cout << "Ilosc: " << p1.getIlosc() << endl;
    delete p3;
    cout << "Ilosc: " << p1.getIlosc() << endl;
    delete p4;
    cout << "Ilosc: " << p1.getIlosc() << endl;


    LiczbyZespolone z1(2,3), z2(2,3),z3; z3=(z1/z2)+z2;
    cout << z3;
    z3=z1+4;
    cout << z3;
    if(z1==z2)
        z3+=z1;
    else
        z3=!z1;
    cout << z3;
    z3 = 2.5 * z1;
    cout << z3;
    z3 = 2 + z1;
    cout << z3;


    return 0;
}
