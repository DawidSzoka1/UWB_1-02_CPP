#include<iostream>
#include<string>

using namespace std;

string YearOfDate(string date){
    return date.substr(0, 4);

}
string MonthOfDate(string date){
    return date.substr(5, 2);

}
string DayOfDate(string date){
    return date.substr(8, 2);

}

int intYearOfDate(string date){
    return stoi(YearOfDate(date));
}
int intMonthOfDate(string date){
    return stoi(MonthOfDate(date));
}
int intDayOfDate(string date){
    return stoi(DayOfDate(date));
}



class Osoba{
private:
    string imie = "<brak danych>";
    string nazwisko = "<brak danych>";
    string dataUr = "????-??-??";
    bool isValidYear(int Y){
        if( Y >= 1900 && Y <= rok_teraz){
            return true;
        }
        return false;
    }
    bool isValidMonth(int M){
        if(M >= 1 && M<= 12){
            return true;
        }
        return false;
    }
    bool isValidDay(int D){
        if(D>= 1&& D<= 30){
            return true;

        }
        return false;
    }
    bool isValidData(string date){
        if(date.size() != 10){
            return false;
        }
        if(date[4] != '-' || date[7] != '-'){
            return false;
        }
        if(isValidYear(intYearOfDate(date)) && isValidMonth(intMonthOfDate(date)) && isValidDay(intDayOfDate(date))){
            return true;
        }


        return false;
    }
      string to_YYYY(int Y){
        if(Y < 0 || Y >= 10000){
            return "????";
        }
        else if(Y < 10){
            return "000" + to_string(Y);
        }
        else if( Y < 100){
            return "00" + to_string(Y);
        }
        else if(Y < 1000){
            return "0" + to_string(Y);
        }
        else{
            return to_string(Y);
        }
    }
    string to_MM(int M){
        if ( M <= 0 || M > 12){
            return "??";
        }
        else if ( M < 10){
            return "0" + to_string(M);
        }
        else{
            return to_string(M);
        }

    }
    string to_DD(int D){
        if( D<= 0|| D> 31){
            return "??";
        }
        else if(D < 10){
            return "0" + to_string(D);
        }
        else{
            return to_string(D);
        }
    }
public:
    friend bool same_dataUr(Osoba o1, Osoba o2);
    static int rok_teraz;
    Osoba(string imie_nazwisko, string du){
        int indeks_space = imie_nazwisko.find(" ");
        int indeks_last_space = imie_nazwisko.find_last_of(" ");
        if (indeks_space == indeks_last_space){
                imie = imie_nazwisko.substr(0, indeks_space);
                nazwisko = imie_nazwisko.substr(indeks_space+1);
        }
        else{
            imie = imie_nazwisko.substr(0, indeks_space-1);
            nazwisko = imie_nazwisko.substr(indeks_last_space+1);

        }

        if (isValidYear(intYearOfDate(du))){
                dataUr.replace(0,4, YearOfDate(du));
        }
        if(isValidMonth(intMonthOfDate(du))){
            dataUr.replace(5,2, MonthOfDate(du));
        }
        if(isValidDay(intDayOfDate(du))){
            dataUr.replace(8,2 , DayOfDate(du));
        }
    }
    Osoba(){
    }
    Osoba(string im, string nazw, string du){
        imie = im;
        nazwisko = nazw;
        if (isValidYear(intYearOfDate(du))){
                dataUr.replace(0,4, YearOfDate(du));
        }
        if(isValidMonth(intMonthOfDate(du))){
            dataUr.replace(5,2, MonthOfDate(du));
        }
        if(isValidDay(intDayOfDate(du))){
            dataUr.replace(8,2 , DayOfDate(du));
        }

    }
    Osoba(string im, string nazw, int Y, int M, int D){
        imie = im;
        nazwisko = nazw;
        if (isValidYear(Y)){
                dataUr.replace(0,4 , to_YYYY(Y));
        }
        if(isValidDay(D)){

            dataUr.replace(8,2 , to_DD(D));
        }
        if(isValidMonth(M)){
            dataUr.replace(5,2 , to_MM(M));
        }


    }
    void set_imie(string potential_imie){
        imie = potential_imie;
    }
    void set_nazwisko(string potential_nazw){
        nazwisko = potential_nazw;
    }
    void set_dataUr(string potential_dataUr){
        if(isValidData(potential_dataUr)){
            dataUr = potential_dataUr;
        }
    }
    void set_dataUr_Year(string potential_year){
        if(isValidYear(intYearOfDate(potential_year))){
            dataUr.replace(0, 4, YearOfDate(potential_year));
        }
    }
    void set_dataUr_Year(int potential_year){
        if(isValidYear(potential_year)){
            dataUr.replace(0,4, to_YYYY(potential_year));
        }
    }
    void set_dataUr_Month(string potential_month){
        if(isValidMonth(intMonthOfDate(potential_month))){
            dataUr.replace(5, 2, MonthOfDate(potential_month));
        }
    }
    void set_dataUr_Month(int potential_month){
        if(isValidMonth(potential_month)){
            dataUr.replace(5,2 , to_MM(potential_month));
        }
    }
    void set_dataUr_day(string potential_day){
        if(isValidDay(intDayOfDate(potential_day))){
            dataUr.replace(8, 2, DayOfDate(potential_day));
        }
    }
    void set_dataUr_day(int potential_day){
        if(isValidDay(potential_day)){
            dataUr.replace(8,2, to_DD(potential_day));
        }
    }

    void wypisz(){

        cout<< "Imie: " << imie << "\nNazwisko: "<< nazwisko << "dataUrodzenia[YYYY-MM-DD]: " << dataUr << endl;
    }
    int wiek(){
        return rok_teraz - intYearOfDate(dataUr);
    }


};
int Osoba::rok_teraz = 2024;

bool same_dataUr(Osoba o1, Osoba o2){
    return YearOfDate(o1.dataUr) == YearOfDate(o2.dataUr);
}


int main(){

    //s.insert(gdzie, co);
    //s.append("hej") na koniec napisu
    // s.size() s.lenght() dlugosc napisu

    //s.assign(" zmienia wartosc stringa");
    //s.substr(poczatek indeks, ile);
    // s.find("cos") s.find_last_of("Cos")
    //s.replace(indeks poczatku, ile litre skasowac, co wstawic)

    //string s = "123" + 50
    //stoi(s) zmienia string na inta bierze pierwsze wystapienie liczb w stringu cout << stoi(s) * 50;

    Osoba o1("daiwd", "szoka" , "2003-7-13");
    Osoba o2("daiwd", "szoka" , "2005-7-13");

    cout << "wiek:" << o1.wiek() << endl;
    cout<< "ten same rok " << same_dataUr(o1, o2);



    return 0;
}
