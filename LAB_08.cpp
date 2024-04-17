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
    LiczbyZespolone operator+=(LiczbyZespolone &li){
        return LiczbyZespolone(re + li.getRe(), im + li.getIm());
    }

};

int main(){
    LiczbyZespolone z1(2,3), z2(1,4),z3; z3=(z1/z2)+z2;
    z3=z1+4;
    if(z1==z2)
        z3+=z1;

    return 0;
}
