#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<time.h>

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
    srand(time(NULL));
    vector <Punkt> punkty;
    for(int i = 0; i < 20; i++){
        Punkt p(rand() % 11 - 5, rand() % 11 - 5);
        punkty.push_back(p);
    }
    sort(punkty.begin(), punkty.end(), por_punkty);
    for(int i = 0; i < punkty.size(); i++){
        if(punkty[i].cwiartka() == 3){
            punkty.erase(punkty.begin() + i);
            i--;
        }
        cout << punkty[i] << endl;
    }

    return 0;
}
