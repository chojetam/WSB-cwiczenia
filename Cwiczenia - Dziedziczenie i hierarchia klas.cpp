#include <iostream>
using namespace std;

class Adres
{
    string miasto, ulica;
    short nr;

public:
    Adres(string m, string u, short n)
    {
        cout << "Wywolano konstruktor klasy Adres" << endl;
        miasto = m;
        ulica = u;
        nr = n;
    }
    ~Adres()
    {
        cout << "Wywolano destruktor klasy Adres" << endl;
    }
    void Wyswietl()
    {
        cout << "Adres: " << endl
             << "Miasto: " << miasto << endl
             << "Ulica: " << ulica << endl
             << "nr domu: " << nr << endl;
    }
};

class TOsoba
{
    string imie, nazwisko;
    short wiek;
    Adres adres;

public:
    TOsoba(string i, string na, short w, string m, string u, short n):
        adres(m, u, n)
    {
        cout << "Wywolano konstruktor klasy TOsoba" << endl;
        imie = i;
        nazwisko = na;
        wiek = w;
    }
    ~TOsoba()
    {
        cout << "Wywolano destruktor klasy TOsoba" << endl;
    }
    void Wyswietl()
    {
        adres.Wyswietl();
        cout << "Imie: " << imie << endl
             << "Nazwisko: " << nazwisko << endl
             << "Wiek: " << wiek << endl;
    }
    string PodajImie()
    {
        return imie;
    }
    string PodajNazwisko()
    {
        return nazwisko;
    }
};

class TStudent:
        public TOsoba
{
    string kierunek;
    short rok;

public:
    TStudent(string k, short r, string i, string na, short w, string m, string u, short n):
        TOsoba(i, na, w, m, u, n)
    {
        cout << "Wywolano konstruktor klasy TStudent" << endl;
        kierunek = k;
        rok = r;
    }
    ~TStudent()
    {
        cout << "Wywolano destruktor klasy TStudent" << endl;
    }
    void Wyswietl()
    {
        TOsoba::Wyswietl();
        cout << "Kierunek: " << kierunek << endl
             << "Rok: " << rok << endl;
    }
    string PodajKierunek()
    {
        return kierunek;
    }
};

int main()
{
    string miasto, ulica, imie, nazwisko, kierunek;
    short nr, wiek, rok;

    cout << "Podaj imie: >" << endl;
    cin >> imie;
    cout << "Podaj nazwisko: >" << endl;
    cin >> nazwisko;
    cout << "Podaj wiek: >" << endl;
    cin >> wiek;
    cout << "Podaj miasto: >" << endl;
    cin >> miasto;
    cout << "Podaj ulice: >" << endl;
    cin >> ulica;
    cout << "Podaj nr domu: >" << endl;
    cin >> nr;
    cout << "Podaj kierunek studiow: >" << endl;
    cin >> kierunek;
    cout << "Podaj rok studiow: >" << endl;
    cin >> rok;

    TStudent student(kierunek, rok, imie, nazwisko, wiek, miasto, ulica, nr);
    student.Wyswietl();
}
