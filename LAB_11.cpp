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
        return m1.liczba < m2.liczba;
    }
    return m1.nazwa < m2.nazwa;
}

int main(){
    vector <Miasto> miasta;
    for(int i = 0; i< 10; i++){
        Miasto m1(10-i, "Nazwa" + to_string(10-i));
        miasta.push_back(m1);
    }
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
