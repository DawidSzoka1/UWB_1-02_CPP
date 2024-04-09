#include<iostream>

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

int main(){
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
