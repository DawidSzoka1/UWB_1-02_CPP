#include<iostream>
#include<cmath>
using namespace std;

class Liczba{
int liczba;
public:
Liczba(int i) { liczba =i; }
int GetLiczba() { return liczba; }
int Dodaj(int b);
};
int Liczba::Dodaj(int b){return liczba+b;}


class Wektor3D{
private:
    float x;
    float y;
    float z;
public:
    Wektor3D():x(1), y(0), z(0){}
    Wektor3D(float x, float y, float z): x(x), y(y), z(z){}
    Wektor3D(float x): x(x), y(x), z(x){}
    bool Wersor(){
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)) == 1;
    }
    void wypisz(){
        cout << "[" << x << "," << y << "," << z << "]" << endl;
    }
    Wektor3D operator+(Wektor3D &w2){
        return Wektor3D(x + w2.x, y + w2.y, z + w2.z);
    }

};

int main(){
    Liczba l1(5);
    Liczba *l2 = new Liczba(10);

    cout << "Liczba 1: " << l1.GetLiczba() << " " << "liczba 1 + 20 = " << l1.Dodaj(20) << endl;
    cout << "Liczba 2: " << l2->GetLiczba() << " " << "liczba 2 + 20 = " << l2 ->Dodaj(20) << endl;


    return 0;
}
