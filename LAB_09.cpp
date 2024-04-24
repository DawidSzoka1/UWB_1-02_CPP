#include<iostream>
#include<string>
using namespace std;

class Produkt{
private:
    string name;
    float price;
    int amount;
    int id;
public:
    Produkt(){}
    Produkt(string name, float price, int amount, int id):name(name), price(price), amount(amount), id(id){}



};

class Automat{
private:
    Produkt *produkty;
    int licznik = 0;
public:
    Automat(int ile){
        produkty = new Produkt[ile];
    }
};

int main(){


    return 0;
}
