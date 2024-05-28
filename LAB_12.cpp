#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
int rok_teraz = 2024;

class Adres{
private:
    string miast;
    string ulica;
    int numer_domu;
public:
    Adres(){}
    Adres(string miast, string ulica, int numer_domu): miast(miast), ulica(ulica), numer_domu(numer_domu){}
};

class Osoba{
private:
    string imie;
    int rok_urodzenia;
    Adres ad;
public:
    Osoba(){}
    Osoba(string imie, int rok_urodzenia, Adres ad): imie(imie), rok_urodzenia(rok_urodzenia), ad(ad){}
    string toString(){
        return imie + " lat " + to_string(rok_urodzenia);
    }
    int getRok(){
        return rok_urodzenia;
    }
    string getImie(){
        return imie;
    }
    void setRok(int rok){
        rok_urodzenia = rok;
    }
    int wiek(){
        return rok_teraz - rok_urodzenia;
    }
};

ostream& operator<<(ostream& o,Osoba* os){
    o<< os->wiek() << endl;
    return o;
}

class Pracownik: public Osoba{
private:
    double zarobki;
public:
    Pracownik(){}
    Pracownik(string name, int rok, Adres ad, double zarobki):Osoba(name, rok, ad), zarobki(zarobki){}
};
class Student: public Osoba{
private:
    float srednia;
public:
    Student(){}
    Student(string name, int rok, Adres ad, float srednia): Osoba(name, rok, ad), srednia(srednia){}
};

class Kierownik: public Pracownik{
private:
    string czego;
public:
    Kierownik(){}
    Kierownik(string name, int rok, Adres ad, double zarobki, string czego): Pracownik(name, rok, ad, zarobki), czego(czego){}

};

bool sort_by(Osoba o1, Osoba o2){
    return o1.getRok() <= o2.getRok();
}

void wiek_plus_1(Osoba o1){
    o1.setRok(o1.getRok() - 1);
}
int main(){
    Adres ad1("cos", "cos2", 23);
    Osoba *o1 = new Osoba("Ala", 2000, ad1);
    Osoba *o2 = new Pracownik("Ewa", 1995, ad1, 3456.67);
    Osoba *o3 = new Student("Kuba", 2000, ad1, 3.89);
    Pracownik *p1 = new Kierownik("Adam", 1990, ad1, 4128.78, "Informatyk");
    cout << o1->wiek() << endl;
    cout << p1->wiek() << endl;
    cout<<o1;  //wyœwietli siê wiek
    cout<<p1;
    vector <Osoba> osoby;
    for(int i = 0; i<5; i++){
        Osoba o("osoba"+to_string(i), 2000-i, ad1);
        osoby.push_back(o);
    }
    cout << "Pierwszy sposoby " << endl;
    for(Osoba x: osoby){
        cout << x.toString() << endl;
    }
    cout << "Drugi sposob " << endl;
    int oldest = osoby.begin()->getRok();
    int youngest = osoby.begin()->getRok();
    string name_yo = osoby.begin()->getImie();
    vector<Osoba>::iterator it;
    for(it = osoby.begin(); it != osoby.end(); it++){
        cout << it->toString() << endl;
        if(it->getRok() > oldest){
            oldest = it->getRok();
        }
        if(it->getRok() < youngest){
            youngest = it->getRok();
            name_yo = it->getImie();
        }
    }
    cout << "najstarsza ma lat: " << oldest << endl;
    cout << "Najmlodsza ma na imie: " << name_yo << endl;
    sort(osoby.begin(),osoby.end(), sort_by);
     for(it = osoby.begin(); it != osoby.end(); it++){
        cout << it->toString() << endl;
    }
    return 0;
}
