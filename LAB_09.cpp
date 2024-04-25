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
        if(licznik > 0){
             p1.setId(produkty[licznik-1].getId()+1);
        }else{
            p1.setId(1);
        }

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
                plik << produkty[i].getId() << " " << produkty[i].getName()<<endl;;
            }

        }
        plik.close();

    }
    Produkt getProdukt(int index){
        return produkty[index];
    }
    int getLicznik(){
        return licznik;
    }

    float buy(int numer_id, int amount, float cash){
        if(licznik >= numer_id){
            cout << "nie ma takiego produktu" << endl;
            return 0;
        }
        if(amount <= 0 ){
            cout << "nie da sie tak" << endl;
            return 0;
        }
        if(amount > produkty[numer_id].getAmount()){
            cout << "Nie mamy tyle produktow" << endl;
            return 0;
        }
        if(cash < produkty[numer_id].getPrice()*amount){
            cout << "Masz za malo kasy" << endl;
            return 0;
        }
        float reszta = produkty[numer_id].getPrice()*amount - cash;
        produkty[numer_id].add(-amount);
        cout << "Prosze odebrac reszta w wysokosci: " << reszta << endl;
        return 1;

    }


};

int main(){
    Automat a1(10);
    Produkt p1("test", 20.3, 10, 1);
    a1.addProdukt(p1);

    a1.getFromFIle("produkty.txt");
    a1.whatBuy(130);
    a1.saveToFile("zapisProduktow.txt");

    fstream plik;
    plik.open("stanAktualny.txt", ios::out);
    if(!plik.good()){
        cout << "Nie uzyskano dostepu do pliku" << endl;
        return 1;
    }
    for(int i = 0; i < a1.getLicznik(); i++){
        plik << a1.getProdukt(i).getId()<< " " << a1.getProdukt(i).getName();
        plik << " " << a1.getProdukt(i).getAmount() << endl;

    }


    return 0;
}
