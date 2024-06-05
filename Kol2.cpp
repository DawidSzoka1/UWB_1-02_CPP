#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
class Liczba{
private:
    int ilosc;
public:
    Liczba(){}
    Liczba(int ilosc): ilosc(ilosc){}
    int getIlosc(){
        return ilosc;
    }
    void setIlosc(int newIlosc){
        ilosc = newIlosc;
    }
    Liczba operator+(Liczba l2){
        return Liczba(ilosc+l2.getIlosc());
    }
};

ostream& operator<<(ostream& o, Liczba l1){
    o << l1.getIlosc();
    return o;
}

class Nazwa{
private:
    string nazwa;
public:
    Nazwa(){}
    Nazwa(string nazwa): nazwa(nazwa){}
    string getNazwa(){
        return nazwa;
    }
};

class Miasto{
private:
    Liczba iloscM;
    Nazwa nazwaM;
public:
    Miasto(){}
    Miasto(Liczba ilosc, Nazwa nazwa): iloscM(ilosc), nazwaM(nazwa){}
    Miasto(string nazwa, int ilosc){
        Liczba l1(ilosc);
        iloscM = l1;
        Nazwa m1(nazwa);
        nazwaM = m1;
    }
    ~Miasto(){}
    Liczba& getIloscM(){
        return iloscM;
    }
    Nazwa& getNazwaM(){
        return nazwaM;
    }
    void wypisz(){
        cout << nazwaM.getNazwa() << " " << iloscM.getIlosc() << endl;
    }
    string toString(){
        return nazwaM.getNazwa() + " " + to_string(iloscM.getIlosc());
    }

};

bool sortMiasta(Miasto m1, Miasto m2){
    if(m1.getNazwaM().getNazwa() == m2.getNazwaM().getNazwa())
        return m1.getIloscM().getIlosc() > m2.getIloscM().getIlosc();
    return m1.getNazwaM().getNazwa() < m2.getNazwaM().getNazwa();
}
void F(vector<Miasto> k){
    vector<Miasto>::iterator j;
    if(k.size() % 2 == 0){
        for(j = k.end()-1; j >= k.begin(); j--){
            j->wypisz();
        }
        cout << endl;
    }else{
        for(j = k.begin(); j < k.end(); j++){
            j->wypisz();
        }
        cout << endl;
    }
}

void doubleLiczba(Liczba &l1){
    l1.setIlosc(l1.getIlosc() * 2);
    cout << "Zwiekszono ilosc " << endl;
}

class KlasaA{
protected:
    string nazwa;
    int ilosc;
public:
    KlasaA(){}
    KlasaA(string nazwa, int ilosc): nazwa(nazwa), ilosc(ilosc){}
    virtual string f(){
        return nazwa + " " + to_string(ilosc);
    }
};

class KlasaB: public KlasaA{
private:
    float liczba;
public:
    KlasaB(){}
    KlasaB(string nazwa, float liczba, int ilosc): KlasaA(nazwa, ilosc), liczba(liczba){}

};

class KlasaC: public KlasaA{
private:
    float liczba;
    char litera;
public:
    KlasaC(){}
    KlasaC(string nazwa, int ilosc, float liczba, char litera): KlasaA(nazwa, ilosc), liczba(liczba), litera(litera){}
    string f(){
        return nazwa + " " + litera + " " +  to_string(ilosc*liczba);
    }

};

int main(){
    vector<Miasto> kraj;
    Miasto m1("Bialystok", 2);
    kraj.push_back(m1);
    Miasto m2("Bialystok", 4334);
    kraj.push_back(m2);
    Miasto m3("War", 5483458);
    kraj.push_back(m3);
    Miasto m4("Krak", 432);
    kraj.push_back(m4);
    Miasto m5("Poz", 4324234);
    kraj.push_back(m5);
    Miasto m6("Poz", 4);
    kraj.push_back(m6);
    sort(kraj.begin(), kraj.end(), sortMiasta);
    F(kraj);
    vector<Miasto>::iterator i;
    int sum = 0;
    for(i = kraj.begin(); i < kraj.end(); i ++ ){
        i->wypisz();
        cout << "Metoda toString " << endl;
        cout << i->toString() << endl;
        sum += i->getIloscM().getIlosc();
    }
    cout << "SUma mieszkancow w vektorze kraj to: " << sum << endl;

    Liczba l1(23), l2(34);
    cout << l1+l2;
    cout << endl;
    doubleLiczba(l1);
    cout << l1 << endl;
    cout << l1+l2 << endl;
    KlasaA *o1 = new KlasaA("kot", 20);
    KlasaA *o2 = new KlasaB("laptop", 1900.5, 30);
    KlasaA *o3 = new KlasaC("Kubek", 10, 3.89, 'A');

    cout << o1->f() << endl;
    cout << o3->f() << endl;

    delete o1;
    delete o2;
    delete o3;


    return 0;
}
