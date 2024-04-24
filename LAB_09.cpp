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
    int getId(){
        return id;
    }
    int getAmount(){
        return amount;
    }
    string getName(){
        return name;
    }
    float getPrice(){
        return price;
    }
};

class Automat{
private:
    Produkt *produkty;
    int licznik = 0;
public:
    Automat(int ile){
        produkty = new Produkt[ile];
        licznik += ile;
    }
    void addProdukt(){

    }
    void buyProdukt(int id, int amount){
    }
    void whatBuy(int amount){
        cout << "Mozesz kupic: " << endl;
        for(int i =0; i< licznik; i++){
            if(produkty[i].getAmount() > 0 && produkty[i].getPrice() <= amount){
                cout << "nazwa: " << produkty[i].getName() << endl;
            }
        }
    }


};

int main(){


    return 0;
}
