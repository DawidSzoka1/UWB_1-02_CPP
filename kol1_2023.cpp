#include<iostream>
#include<cmath>
using namespace std;
class Liczba{
private:
    int liczba;
public:
    Liczba(int i) { liczba =i; }
    int GetLiczba() { return liczba; }
    void Dodaj(int b);
};
void Liczba::Dodaj(int b){liczba+=b;}

class Wektor3d{
private:
    float x;
    float y;
    float z;
public:
    Wektor3d():x(1), y(1), z(1){}
    Wektor3d(float x, float y, float z): x(x), y(y), z(z){}
    Wektor3d(float x):x(x), y(x), z(x){}
    void wypisz(){
        cout << "[" << x << ", " << y << ", " << z << "]" << endl;
    }
    Wektor3d operator+(Wektor3d& v){
        return Wektor3d(x+v.x, y + v.y, z + v.z);
    }
    Wektor3d operator-(Wektor3d& v){
        return Wektor3d(x-v.x, y-v.y, z - v.z);
    }
    bool wersor(){
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }
};

int main(){
    Wektor3d w1,w2;
    Wektor3d sum = w1 + w2;
    Wektor3d diff = w1 - w2;
    diff.wypisz();
    sum.wypisz();

    Liczba l1(5);
    Liczba *l2 = new Liczba(10);
    cout << "l1 liczba = " << l1.GetLiczba() << endl;

    l1.Dodaj(10);
    cout << "l1 liczba = " << l1.GetLiczba() << endl;

    cout << "l2 liczba = " << l2->GetLiczba()  << endl;

    l2->Dodaj(10);
    cout << "l2 liczba = " << l2->GetLiczba()  << endl;
    return 0;
}
