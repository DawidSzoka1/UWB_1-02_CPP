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

int main(){
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
