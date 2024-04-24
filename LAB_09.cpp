#include<iostream>
#include<string>
#include<fstream>
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
    void add(int amount){
        this->amount += amount;
    }
    void setId(int newid){
        id = newid;
    }
};

class Automat{
private:
    Produkt *produkty;
    int licznik = 0;
public:
    Automat(int ile){
        produkty = new Produkt[ile];
    }
    void addProdukt(Produkt p1){
        int idTaken[licznik];

        for(int i = 0; i < licznik; i++){
                idTaken[i] = produkty[i].getId();
        }

        p1.setId(idTaken[licznik]+1);
        produkty[licznik] = p1;
        licznik+=1;

    }
    void buyProdukt(int id, int amount){
        for(int i = 0; i< licznik; i++){
            if(produkty[i].getId() == id){
                produkty[i].add(amount);
            }
        }
    }
    void whatBuy(int amount){
        cout << "Mozesz kupic: " << endl;
        for(int i =0; i< licznik; i++){
            if(produkty[i].getAmount() > 0 && produkty[i].getPrice() <= amount){
                cout << "nazwa: " << produkty[i].getName() << endl;
            }
        }
    }
    bool getFromFIle(string file_name){
        fstream plik;
        plik.open(file_name, ios::in);
        if(!plik.good()){
                cout << "Cos poszlo nie tak";
                return 0;
        }
        string name, price, amount ,id;


        while(!plik.eof()){
            getline(plik, name, ' ');
            getline(plik, price, ' ');
            getline(plik, amount, ' ');
            getline(plik, id);
            Produkt p(name, stof(price), stoi(amount), stoi(id));
            addProdukt(p);

        }
        plik.close();
        cout << "Dodano porpawnie" << endl;
        return 1;
    }
    bool saveToFile(string file_name){
        fstream plik;
        plik.open(file_name, ios::out);
        if(!plik.good()){
                cout << "Cos poszlo nie tak";
                return 0;
        }
        for(int i =0; i< licznik; i++){

            if(produkty[i].getAmount() < 5){
                plik << produkty[i].getId() << " " << produkty[i].getName();
            }

        }
        plik.close();

    }



};

int main(){
    Automat a1(10);
    Produkt p1("test", 20.3, 10, 1);
    a1.addProdukt(p1);

    a1.getFromFIle("produkty.txt");
    a1.whatBuy(130);
    return 0;
}