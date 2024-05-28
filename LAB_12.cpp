#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
class Osoba{
private:
    static int rok_teraz;
    string imie;
    int rok_urodzenia;
public:
    Osoba(){}
    Osoba(string imie, int rok_urodzenia): imie(imie), rok_urodzenia(rok_urodzenia){}
    string toString(){
        return imie + " lat " + to_string(rok_urodzenia);
    }
    int getRok(){
        return rok_urodzenia;
    }
    string getImie(){
        return imie;
    }
    int wiek(){
        return 2024 - rok_urodzenia;
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
    Pracownik(string name, int rok, double zarobki):Osoba(name, rok), zarobki(zarobki){}
};
class Student: public Osoba{
private:
    float srednia;
public:
    Student(){}
    Student(string name, int rok, float srednia): Osoba(name, rok), srednia(srednia){}
};

class Kierownik: public Pracownik{
private:
    string czego;
public:
    Kierownik(){}
    Kierownik(string name, int rok, double zarobki, string czego): Pracownik(name, rok, zarobki), czego(czego){}

};

bool sort_by(Osoba o1, Osoba o2){
    return o1.getRok() <= o2.getRok();
}
int main(){
    Osoba *o1 = new Osoba("Ala", 2000);
    Osoba *o2 = new Pracownik("Ewa", 1995, 3456.67);
    Osoba *o3 = new Student("Kuba", 2000, 3.89);
    Pracownik *p1 = new Kierownik("Adam", 1990, 4128.78, "Informatyk");
    cout << o1->wiek() << endl;
    cout << p1->wiek() << endl;
    cout<<o1;  //wyœwietli siê wiek
    cout<<p1;
    vector <Osoba> osoby;
    for(int i = 0; i<5; i++){
        Osoba o("osoba"+to_string(i), 2000-i);
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
