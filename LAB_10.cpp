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
    void setImie(string nowe){
        imie = nowe;
    }
    void setNazwisko(string nowe){
        nazwisko = nowe;
    }
    void setPesel(double nowe){
        PESEL = nowe;
    }
    void setNazwaOddzialu(string nowe){
        nazwaOddzialu = nowe;
    }
    void setLiczbaDniPobytu(int nowe){
        liczbaDniPobytu = nowe;
    }
    void setWiek(int nowe){
        wiek = nowe;
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
    string toString(){
        return imie + " " + nazwisko + " " + to_string(PESEL) + " " + nazwaOddzialu + " " + to_string(liczbaDniPobytu) + " " + to_string(wiek);
    }
};

class Szpital{
private:
    int maxPacjentow;
    vector<Pacjent> listaPacjentow;
public:
    Szpital(int maxPacjentow, vector<Pacjent> lista){
        this->maxPacjentow =maxPacjentow;
        if(lista.size() <= maxPacjentow)
            listaPacjentow = lista;
    }
    Szpital(){}
    int getMax(){
        return maxPacjentow;
    }
    vector <Pacjent> getVector(){
        return listaPacjentow;
    }
    void wyswietlPacjentowZOddzialu(string nazwa){
        for(Pacjent p: listaPacjentow){
            if(p.getNazwaOddzialu() == nazwa){
                cout << p.getImie() << " " << p.getNazwisko() << endl;
            }
        }
    }
    float zwrocSredniaDniPobytu(){
        int sumDni = 0;
        for(Pacjent p: listaPacjentow){
            sumDni += p.getLiczbaDniPobytu();
        }
        return float(sumDni)/listaPacjentow.size();
    }
    void dodajPacjenta(Pacjent p){
        if(listaPacjentow.size() + 1 > maxPacjentow){
            cout << "Nie mamy miejsca" << endl;
        }else{
            listaPacjentow.push_back(p);
        }
    }
    int zwrocNajPobyt(){
        int maxDni = 0;
        for(Pacjent p: listaPacjentow){
            if(p.getLiczbaDniPobytu() > maxDni){
                maxDni = p.getLiczbaDniPobytu();
            }
        }
        return maxDni;
    }
    int zwrocIlePowyzejWieku(int check){
        int count_ = 0;
        for(Pacjent p: listaPacjentow){
            if(p.getWiek() > check){
                count_++;
            }
        }
        return count_;
    }
};



int main(){
    vector <Pacjent> pacjenci;
    for(int i = 0; i < 5; i++){
        Pacjent pac("Imie", "Nazwisko", i, "oddzial", i);
        pacjenci.push_back(pac);
    }
    vector <Pacjent>:: iterator it;
    for(it = pacjenci.begin(); it != pacjenci.end(); it++){
        cout << it->toString() << endl;
    }
    Szpital szpital1(20, pacjenci);
    cout << szpital1.zwrocSredniaDniPobytu() << endl;
    szpital1.wyswietlPacjentowZOddzialu("oddzial");
    Pacjent p2("nowy", "test", 233, "nowy", 20);
    szpital1.dodajPacjenta(p2);
    szpital1.wyswietlPacjentowZOddzialu("nowy");
//    srand(time(NULL));
//    vector <int> lista;
//
//    for(int i = 0; i<10; i++){
//        lista.push_back(rand() % 100 + 1);
//    }
//    wyswietl(lista);
//  //  lista.erase(lista.begin()+3);
//  //lista.erase(lista.begin());//usuwa pierwszy jak damy + 4 to usunie 5 element
//   // lista.erase(lista.end()); //ostatni
//   // lista.erase(lista.begin(), lista.begin()+2);//usuwa przedzial
//   // lista.insert(lista.begin()+3, 550);//wstawia wartosc
//   // wyswietl(lista);
//    cout << "Nowy sposob" << endl;
//    for(int x: lista){
//        cout << x << endl;
//    }
//    cout<<"ITERATORE" << endl;
//    vector <int>:: iterator it;
//    for(it = lista.begin(); it != lista.end(); it++){
//        if(*it % 2 == 0){
//                cout << *it << endl;
//        }
//    }
//    // #include<alponthnw>
//    // sortowanie sort(vec.begin(), vec.end());

    return 0;
}
