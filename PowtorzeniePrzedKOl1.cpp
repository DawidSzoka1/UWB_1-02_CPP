#include<iostream>
#include<string>
#include<cmath>
#include<time.h>
using namespace std;

class Telewizor{
protected:

private:
  int glosnosc;
    int jasnosc;
    int kontrast;
    bool wieksze0mniejsze100(int x){
        return x > 0 && x < 100;
    }
public:
    Telewizor(){
        glosnosc = 50;
        jasnosc = 50;
        kontrast = 50;
    }
    Telewizor(int glos, int jas, int kon){
        if(wieksze0mniejsze100(glos)){
            glosnosc = glos;
        }
        if(wieksze0mniejsze100(jas)){
            jasnosc = jas;
        }
        if(wieksze0mniejsze100(kon)){
            kontrast = kon;
        }
    }
    virtual void wypisz(){
        cout << "\nglosnosc: " << glosnosc << "\nJasnosc: " << jasnosc  << "\nkontrast: " << kontrast << endl;

    }
};

class TelwizorKolorowy: public Telewizor{
private:
        int kolor;
public:
    TelwizorKolorowy(): Telewizor(){
        kolor = 50;
    }
    TelwizorKolorowy(int glos, int jas, int kon, int kol): Telewizor(glos, jas, kon){
        if( kol > 0 && kol <= 100){
            kolor = kol;
        }
    }
    void wypisz(){
        Telewizor::wypisz();
        cout << "kolor:" << kolor << endl;

    }

};

class Lek{
protected:
    string nazwa;
    unsigned int cena;
    unsigned int naStanie;
public:
    Lek(string nazwa, float cena, int naStanie):nazwa(nazwa), cena(cena), naStanie(naStanie){}
    Lek(){}
    ~Lek(){
    cout << "dekonstruktor" << endl;
    }
    void UstawCene(int nowaCena){
        cena = nowaCena;
    }
    unsigned int IleNaStanie(){
        return naStanie;
    }
    unsigned int ZwrocCene(){
        return cena;
    }
    void Sprzedaj(unsigned int ile){
        if( ile > naStanie){
            cout << "NIe mamy tyle na stanie" << endl;
        }
        else{
            naStanie -= ile;
            cout<< "To bedzie " << cena * ile << " zl " << endl;
        }

    }
    void Dokup(unsigned int ile){
        naStanie += ile;
        cout << "Dokupilismy produkt ilosc na stanie " << naStanie << endl;
    }
    virtual void Wyswietl(){
        cout << "Nazwa: " << nazwa << endl;
        cout << "Na stanie: " << naStanie << endl;
        cout << "Cena za sztuke: " << cena << endl;
    }

};

class  LekRefundowany: public Lek{
protected:
    unsigned int cenaRef;
public:
    LekRefundowany(): Lek(){}
    LekRefundowany(string nazwa, unsigned int cena, unsigned int naStanie, unsigned int cenaRe): Lek(nazwa, cena, naStanie){
        cenaRef = cenaRe;
    }
    ~LekRefundowany(){}
    void Wyswietl(){
        Lek:: Wyswietl();
        cout << "Cena refundowana: " << cenaRef << endl;
    }
    unsigned int ZwrocCeneRef(){
        return cenaRef;
    }
    void ZmienCeneRef(unsigned int nowa){
        cenaRef = nowa;
    }

};
class Wektor3D{
public:
    float x;
    float y;
    float z;

    Wektor3D(): x(1), y(1), z(1){}
    Wektor3D(float x, float y, float z): x(x), y(y), z(z){}
    Wektor3D(float x): x(x), y(x), z(x){}
    bool Wersor(){
        return sqrt(pow(x,2) + pow(y,2) + pow(z, 2)) == 1;
    }
    Wektor3D operator+(Wektor3D& w2){
        return Wektor3D(x+w2.x, y+w2.y,z+w2.z);
    }
    void wypisz(){
        cout << "[" << x << "," << y << "," << z << "]" << endl;
    }
    void setX(float newx){x = newx;}
};
class Wektory3d{
public:
    Wektor3D w1;
    Wektor3D w2;

    Wektory3d(){}
    Wektory3d(Wektor3D w1, Wektor3D w2):w1(w1), w2(w2){}
    void wypisz(){
        w1.wypisz();
        w2.wypisz();
    }
    Wektor3D* getW1(){
        return &w1;
    }


};


int main(){
    srand(time(NULL));
    Wektor3D wektorty[10];
    Wektor3D *test2 = new Wektor3D(45);
    test2->wypisz();
    for(int i = 0; i < 10 ; i++){
        wektorty[i] = Wektor3D(rand() % 10, rand() % 10, rand() % 10);
        wektorty[i].wypisz();
    }
    Wektory3d test(wektorty[0], wektorty[1]);
    test.wypisz();
    cout<< "NOwy test" << endl;
    test.w1.x = 6969;
    test.wypisz();
    wektorty[0].wypisz();
    test.getW1()->setX(69);
    test.getW1()->wypisz();
    wektorty[0].wypisz();

    LekRefundowany lekRef[5];
    Lek *lek1 = new LekRefundowany();

    lek1->Wyswietl();
    Wektor3D suma;
    suma = wektorty[0] + wektorty[1];
    suma.wypisz();

    for(int i =0; i< 5; i++){
        lekRef[i] = LekRefundowany("234", 324, 342, 32);

    }




    return 0;
}
