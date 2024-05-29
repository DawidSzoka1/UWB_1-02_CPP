#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<time.h>
#include<fstream>

using namespace std;
class Punkt{
private:
    float x;
    float y;
public:
    Punkt(){}
    Punkt(float x, float y): x(x), y(y){}
    int cwiartka(){
        if(x > 0 && y > 0){
            return 1;
        }else if(x > 0 && y < 0){
            return 4;
        }else if(x < 0 && y > 0){
            return 2;
        }else if (x < 0 && y < 0){
            return 3;
        }else{
            return 0;
        }
    }
    float odleglosc(){
        return sqrt(x*x + y*y);
    }
    float getX(){
        return x;
    }
    float getY(){
        return y;
    }
};
ostream& operator<<(ostream& o, Punkt& p){
    o << "(" << p.getX() << ", " << p.getY() << ")";
    return o;
}
bool por_punkty(Punkt p1, Punkt p2){
    if(p1.odleglosc() == p2.odleglosc()){
        return p1.cwiartka() < p2.cwiartka();
    }
    return p1.odleglosc() < p2.odleglosc();
}

int main(){
//    srand(time(NULL));
//    vector <Punkt> punkty;
//    for(int i = 0; i < 20; i++){
//        Punkt p(rand() % 11 - 5, rand() % 11 - 5);
//        punkty.push_back(p);
//    }
//    sort(punkty.begin(), punkty.end(), por_punkty);
//    for(int i = 0; i < punkty.size(); i++){
//        if(punkty[i].cwiartka() == 3){
//            punkty.erase(punkty.begin() + i);
//            i--;
//        }
//        cout << punkty[i] << endl;
//    }
//    fstream plik;
//    plik.open("punkty.txt", ios::out);
//    if(!plik.good()){
//        cout << "Nie uzyskano dostepu do pliku" << endl;
//        return 1;
//    }
//    for(Punkt x: punkty){
//        plik << x << "-> suma " << x.getX() + x.getY() << endl;
//    }
//    plik.close();
//    plik.open("punkty.txt", ios::in);
//    if(!plik.good()){
//        cout << "blad w odczyciue pliku" << endl;
//        return 1;
//    }
//    string napis;
//    string num1;
//    string num2;
//    while(!plik.eof()){
//        getline(plik, num1, ',');
//        getline(plik, num2, ')');
//        getline(plik, napis);
//
//        cout << "x = " <<  num1 << endl;
//        cout << "y = " <<  num2 << endl;
//    }
//    plik.close();
    fstream plik;
    plik.open("uzytkownik.txt", ios::out);
    if(!plik.good()){
        cout << "Blad" << endl;
        return 1;
    }
    string wartosc;
    cout << "Podaj tekst ktory zapiszemy do pliku uzytkownik.txt do momentu wpisania '.'" << endl;
    while(true){
        getline(cin, wartosc);
        if(wartosc == "."){
            break;
        }
        plik << wartosc << endl;
    }
    plik.close();

    return 0;
}
