#include<iostream>
#include<vector>
#include<time.h>
#include<string>


using namespace std;

class Pacjent{
protected:
    string imie;
    string nazwisko;
    double PESEL;
    string nazwaOddzialu;
    int liczbaDniPobytu;
    int wiek;
public:
    Pacjent(string imie, string nazwisko, double pesel, string nazwaOddzialu, int wiek){
        this->imie = imie;
        this->nazwisko = nazwisko;
        PESEL = pesel;
        this->nazwaOddzialu = nazwaOddzialu;
        liczbaDniPobytu = 0;
        this->wiek = wiek;
    }
    string getImie(){
        return imie;
    }
    string getNazwisko(){
        return nazwisko;
    }
    double getPesel(){
        return PESEL;
    }
    string getNazwaOddzialu(){
        return nazwaOddzialu;
    }
    int getLiczbaDniPobytu(){
        return liczbaDniPobytu;
    }
    int getWiek(){
        return wiek;
    }

    bool sprawdzCzyPowyzej(int liczba){
        return liczbaDniPobytu > liczba;
    }
    void dodajKolejnyDzien(){
        liczbaDniPobytu++;
    }
    bool sprawdzOddzial(string nazwa){
        return nazwaOddzialu == nazwa;
    }
    void wyswietl(){
        cout << "Imie: " << imie << " Nazwisko: " << nazwisko << endl;
        cout << "pesel: " << PESEL << " Nazwa oddzialu: " << nazwaOddzialu << endl;
        cout << "liczba dni pobytu: " << liczbaDniPobytu << " wiek:" << wiek << endl;
    }
};


void wyswietl(vector <int> vec1){
    for(int i = 0; i<vec1.size(); i++){
        cout << vec1.at(i) << endl;
    }
}

int main(){
    srand(time(NULL));
    vector <int> lista;

    for(int i = 0; i<10; i++){
        lista.push_back(rand() % 100 + 1);
    }
    wyswietl(lista);
  //  lista.erase(lista.begin()+3);
  //lista.erase(lista.begin());//usuwa pierwszy jak damy + 4 to usunie 5 element
   // lista.erase(lista.end()); //ostatni
   // lista.erase(lista.begin(), lista.begin()+2);//usuwa przedzial
   // lista.insert(lista.begin()+3, 550);//wstawia wartosc
   // wyswietl(lista);
    cout << "Nowy sposob" << endl;
    for(int x: lista){
        cout << x << endl;
    }
    cout<<"ITERATORE" << endl;
    vector <int>:: iterator it;
    for(it = lista.begin(); it != lista.end(); it++){
        if(*it % 2 == 0){
                cout << *it << endl;
        }
    }
    // #include<alponthnw>
    // sortowanie sort(vec.begin(), vec.end());

    return 0;
}
