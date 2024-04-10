#include<iostream>
#include<string>
using namespace std;

bool zad1(string test){
    int index_of = test.find('-');
    if(index_of != 2){
        return false;
    }
    if(test.length() != 6){
        return false;
    }
    string to_test = test.substr(0,2) + test.substr(3);

    for(int i = 0; i < 5; i++){
           if(int(to_test[i]) < 48 || int(to_test[i]) > 57 ){
            return false;
           }


    }

    return true;
}

class Produkt{
private:
    string name;
    double cena;
    int ilosc;
public:
    Produkt(){}
    Produkt(string na, double ce, int il){
        name = na;
        cena = ce;
        ilosc = il;
    }
    Produkt(string wszystko){
        int first_space = wszystko.find(' ');
        int last_space = wszystko.find_last_of(' ');
        name = wszystko.substr(0, first_space);
        cena = stod(wszystko.substr(first_space+1, last_space-first_space));
        ilosc = stoi(wszystko.substr(last_space+1));
    }
    Produkt(string name, double cena):name(name), cena(cena), ilosc(1){}
    ~Produkt(){}
    void wyswietl(){
        cout << "Nazwa: " << name << endl;
        cout << "Cena: " << cena << endl;
        cout << "Ilosc: " << ilosc << endl;
    }
    double getCena(){
        return cena;
    }
    void setCena(double nowaCena){
        cena = nowaCena;
    }
    void dokup(int ile){
        ilosc += ile;
    }

};

class Auto{
private:
    string nazwa;
    int pojemnosc;
public:
    Auto(){}
    Auto(string n, int p){ nazwa=n;     pojemnosc=p; }
    ~Auto(){
        cout << "\nsprzatam po sobie" << endl;
    }
    virtual void wypisz(){
        cout << nazwa << ", pojemnosc " << pojemnosc << ", ";
    }
    void addPojem(int val){
        pojemnosc += val;
    }
    int getPojem(){
        return pojemnosc;
    }
    string getName(){
        return nazwa;
    }
    friend void changePojem(Auto& car);
};

class AutoCiezarowe: public Auto{
private:
    float ladownosc;
public:
    AutoCiezarowe(string n, int p, float lad):Auto(n, p){
        ladownosc = lad;
    }
    ~AutoCiezarowe(){
        cout << "\nsprzatam po sobie" << endl;
    }
    void wypisz(){
        Auto:: wypisz();
        cout << "ladownosc " << ladownosc << " tony" << endl;
    }
    bool ladownosc_a_b(int a, int b){
        return ladownosc > a && ladownosc < b;
    }

};

void changePojem(Auto& car){
    int pojem;
    cout << "Podaj nowa pojemnosc: ";
    cin >> pojem;
    while(pojem <= 0){
        cout<< "Wartosc musi byc dodatnia: ";
        cin >> pojem;
    }
    car.pojemnosc = pojem;
}

int main(){
    cout << "\nzad 1 przetestowanie " << zad1("123-12");
    cout << " " << zad1("12-009");
    cout << " " << zad1("12-0b1");
    cout << " " << zad1("17-200") << endl;

    cout << "\nzadanie 2" << endl;
    Produkt wszystkow("pomidorfdsj 433.4 2346");
    wszystkow.wyswietl();
    Produkt p1("test zwykly", 30, 10);
    Produkt *p2 = new Produkt("dynamiczny", 100);
    p1.wyswietl();
    cout << "cena p1: " << p1.getCena() << endl;
    p1.setCena(43278327);
    p1.dokup(30);
    p1.wyswietl();
    p2->wyswietl();
    cout << "cena p2: " << p2->getCena() << endl;
    p2->setCena(89);
    p2->dokup(30);
    p2->wyswietl();
    delete p2;

    cout << "\nzadanie 3" << endl;
    Auto * star=new AutoCiezarowe("Kamas",3000,3.4);
    star->wypisz();
    star=new Auto("Toyota",2000);
    star->wypisz();
    delete star;

    cout << "\nzadanie 4" << endl;
    Auto cars[3];
    cars[0] = Auto("Bmw", 20);
    cars[1] = Auto("Test", 100);
    cars[2] = Auto("MEc", 2890);
    int length_max = 0;
    int lenght_min = cars[0].getName().length();
    int index_of_min = 0;
    int index_of_max;
    for(int i = 0; i < 3; i ++){
        cars[i].addPojem(cars[i].getPojem()/2);
        if(cars[i].getName().length() > length_max){
            length_max = cars[i].getName().length();
            index_of_max = i;
        }
        if(cars[i].getName().length() < lenght_min){
            lenght_min = cars[i].getName().length();
            index_of_min = i;
        }
        cars[i].wypisz();
    }
    cout << "najdluzsza nazwa auta to " << cars[index_of_max].getName() << endl;
    cout << "Najkrotsza nazwa auta to " << cars[index_of_min].getName() << endl;

    AutoCiezarowe *ac1 = new AutoCiezarowe("test", 200, 4);
    cout << "test ladownosc: " << ac1->ladownosc_a_b(2, 4) << endl;

    delete ac1;


    return 0;
}
