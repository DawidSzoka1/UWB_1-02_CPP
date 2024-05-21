#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Miasto{
public:
    int liczba;
    string nazwa;
    Miasto(){}
    Miasto(int liczba, string nazwa): liczba(liczba), nazwa(nazwa){}
    void wypisz(){
        cout << nazwa << " " << liczba << endl;
    }
};

bool porownaj(Miasto m1, Miasto m2){
    if(m1.nazwa == m2.nazwa){
        return m1.liczba > m2.liczba;
    }
    return m1.nazwa > m2.nazwa;
}

class Liczba{
protected:
    int liczba;
public:
    Liczba(){}
    Liczba(int liczba): liczba(liczba){}
    void wypisz(){
        cout << liczba << endl;
    }
};

class Nazwa: public Liczba{
protected:
    string nazwa;
public:
    void wypisz(){
        Liczba::wypisz();
        cout << nazwa << endl;
    }
    Nazwa(){}
    Nazwa(string nazwa, int liczba): nazwa(nazwa){
        this->liczba=liczba;

    }
};
class Klasa: public Nazwa{
public:
    double x;
    Klasa(){}
    Klasa(double x, string nazwa, int liczba): x(x){
        this->nazwa = nazwa;
        this->liczba = liczba;
    }
    void wypisz(){
        Nazwa::wypisz();
        cout << x << endl;
    }
    void setNazwa(string nazwa){
        this->nazwa = nazwa;
    }
};

int main(){
    Klasa k1(20, "klasa", 32);
    k1.wypisz();
    k1.setNazwa("nowa nazwa");
    k1.wypisz();

    vector <Miasto> miasta;
    Miasto m1(42143, "zadlaw sie");
    miasta.push_back(m1);

    Miasto m2(43, "aadlaw sie");
    miasta.push_back(m2);

    Miasto m3(42143, "sie");
    miasta.push_back(m3);

    Miasto m4(4213232323, "zadlaw sie");
    miasta.push_back(m4);

    vector <Miasto>:: iterator it;
    for(it = miasta.begin(); it != miasta.end(); it++){
        it->wypisz();
    }
    sort(miasta.begin(), miasta.end(), porownaj);
    for(it = miasta.begin(); it != miasta.end(); it++){
        it->wypisz();
    }
    return 0;
}
