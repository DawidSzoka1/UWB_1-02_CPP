#include <iostream>

using namespace std;
class Prostokat {
private:
    int a;
    int b;
public:
    Prostokat(){
    }
    Prostokat(int a, int b): a(a), b(b){

    }
    void setA(int newA){
        a = newA;
    }
    void setB(int newB){
        b = newB;
    }
    int getA(){
        return a;
    }
    int getB(){
        return b;
    }
};


int main(){
    Prostokat *kwadrat = new Prostokat;
    int newa = 43;
    kwadrat->setA(newa);
    cout << "Bok a: " << kwadrat->getA();
    return 0;
}
