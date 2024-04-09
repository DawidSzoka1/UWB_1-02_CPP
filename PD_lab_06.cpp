#include<iostream>
#include<string>

using namespace std;

class KontoBankowe{
private:
    string numer;
    double saldo;
    int debet;
public:
    KontoBankowe();
    KontoBankowe(string nu, double sal, int deb){
        numer = nu;
        saldo = sal;
        debet = deb;
    }
    double SprawdzStan(){
        return saldo;
    }
    void wyplac(double ile){
        if(saldo + debet < ile){
            cout << "Za malo srodow plus za maly debet" << endl;
        }
        else if(saldo < ile && saldo+ debet > ile){
            saldo -= ile;
            cout << "Wyplata jest za sprawa debetu stan konta po wyplacie " << saldo <<  endl;
        }
        else{
            saldo -= ile;
            cout << "Stan konta po wyplacie " << saldo << endl;
        }
    }
    void wplac(double ile){
        saldo += ile;
        cout<< "Srodki wplacono pomyslnie stan konta po operacji " << saldo << endl;

    }
    void zmianaDebetu(int nowyDebet){
        debet = nowyDebet;
        cout << "Pomyslnie zmieniono debet nowy debet to " << debet << endl;
    }
    void Przelew(KontoBankowe &konto2, double ile){
        if(saldo < ile){
            cout << "Brak wystarczajacych srodkow" << endl;
        }
        else{
            saldo -= ile;
            konto2.wplac(ile);
            cout << "Przelew sie powidl" << endl;
        }
    }
    string numerKonta(){
        return numer;
    }

};


class Klient{
private:
    KontoBankowe& konto;
    string pesel;
    string imie_nazwisko;

public:
    Klient();
    Klient(KontoBankowe& konto, string pesel, string imie_nazwisko): konto(konto), pesel(pesel), imie_nazwisko(imie_nazwisko){}
    KontoBankowe& kontoKlienta(){
        return konto;
    }
    void wypisz(){
        cout << "Pesel: " << pesel << endl;
        cout << "Imie nazwisko: " << imie_nazwisko << endl;
        cout << "Konto: " << konto.numerKonta() << endl;
    }

};
double KlientBankAccount(Klient osoba){
    return osoba.kontoKlienta().SprawdzStan();
}


bool CheckAccoutBalance(KontoBankowe kontoCheck){
    if(kontoCheck.SprawdzStan() > 0){
        return true;
    }
    return false;
}
int main(){
    KontoBankowe konta[3] = {
        KontoBankowe("43245", 200, 10),
        KontoBankowe("4323245", 20066,310),
        KontoBankowe("43245fds", 20320, 1210),

    };

    Klient klienci[3] = {
        Klient(konta[0], "dfgdf", "pierwszy dgas"),
        Klient(konta[1], "dfgsdfsdfsdf", "drugi dgas"),
        Klient(konta[2], "fsd", "trzeci dgas")
    };
    for(int i = 0; i < 3; i++){
        klienci[i].wypisz();
    }
    klienci[0].kontoKlienta().Przelew(klienci[1].kontoKlienta(), 100);
    for(int i = 0; i < 3; i++){
        cout << "stan konta klienta " << i+1 << " wynosi " << klienci[i].kontoKlienta().SprawdzStan() << endl;
    }
    for(int i = 0; i < 3; i++){
        if(klienci[i].kontoKlienta().SprawdzStan() < 0){
            klienci[i].wypisz();
        }
    }

    return 0;
}



