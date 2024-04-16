#include<iostream>
using namespace std;

class Liczba{
int liczba;
public:
Liczba(int i) { liczba =i; }
int GetLiczba() { return liczba; }
int Dodaj(int b);
};
int Liczba::Dodaj(int b){return liczba+b;}


int main(){
    Liczba l1(5);
    Liczba *l2 = new Liczba(10);

    cout << "Liczba 1: " << l1.GetLiczba() << " " << "liczba 1 + 20 = " << l1.Dodaj(20) << endl;
    cout << "Liczba 2: " << l2->GetLiczba() << " " << "liczba 2 + 20 = " << l2 ->Dodaj(20) << endl;


    return 0;
}
