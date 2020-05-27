CWICZENIE 4 



#include <iostream>
#include <cstdlib>
using namespace std;

   /// klasa wraz z działaniem objętości
  class prostopadloscian
  {
    float a;
    float b;
    float c;
    public:
    void podanie_danych()
    {
      cout << "Podaj szerokość prostopadłościanu: " << endl;
      cin >> a; 
      cout << "Podaj długość prostopadłościanu: " << endl;
      cin >> b;
      cout << "Podaj wysokość prostopadłościanu: " << endl;
      cin >> c;
    }
    friend void objetosc(prostopadloscian x);
    friend class duos; 
  };

    void objetosc(prostopadloscian x)
  {
    float wynik = x.a * x.b * x.c;
    cout << "Objętość prostopadłościanu wynosi: " << wynik << " jednostek kwadratowych." << endl; 
  }
  class duos
  {
    float a1;
    float b1;
    float c1;
    public:
    void dane(prostopadloscian x1)
    {
    a1=x1.a;
    b1=x1.b;
    c1=x1.c;

    cout << "Dane do obliczeń: " << a1 << " " << b1 << " " << " " << c1 << endl;
    }
  };
  
  int main()
  {
    prostopadloscian x;
    x.podanie_danych();
    objetosc(x);
    duos alamakota;
    alamakota.dane(x);
    return 0;
  }

Ćwiczenie 5

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Uczen
{
  private:
  string imie, nazwisko, pesel;

  public:
  void imie1()
  {
    cout << "Podaj imie: " << endl;
    cin >> imie;
  }
  void nazwisko1()
  {
    cout << "Podaj nazwisko: " << endl;
    cin >> nazwisko;
  }
  void pesel1()
  {
    cout << "Podaj PESEL: " << endl;
    cin >> pesel;
  }
};
class UczenSzkoly:public Uczen
{
private:
  string nazwa_szkoly;
public:
    void ustaw_szkole()
  {
    cout << "Wprowadz nazwe szkoly: " << endl;
    cin >> nazwa_szkoly; 
  }
};
int main()
{
  //Uczen x;
  //x.imie1();
  //x.nazwisko1();
  //x.pesel1();
  UczenSzkoly y;
  y.imie1();
  y.nazwisko1();
  y.pesel1();
  y.ustaw_szkole();
  return 0;
}

ĆWICZENIE 6

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class uczestnik
{
  public:
  uczestnik *next;
  virtual void info()=0;
};

class student:public uczestnik
{
  string nr_indeksu;
  
  public:
  
  student()
  {
    next = NULL;
    cout << "Podaj nr indeksu: " << endl;
    cin >> nr_indeksu;
  }

  void info()
  {
    cout << "Nr indeksu: " << nr_indeksu << endl;
  }
};

class profesor:public uczestnik
{
  string tel;
  
  public:
  
  profesor()
  {
    next = NULL;
    cout << "Podaj numer telefonu profesora: " << endl;
    cin >> tel;
  }
  
  void info()
  {
    cout << "Numer telefonu profesora: " << tel << endl;
  }
};

class technik:public uczestnik
{
  string godz_pracy, nr_pokoju;
  
  public:
  
  technik()
  {
    next = NULL;
    cout << "Podaj godziny pracy technika: " << endl;
    cin >> godz_pracy;
    cout << "Podaj numer pokoju technika: " << endl;
    cin >> nr_pokoju;
  }
  
  void info ()
  {
    cout << "Godziny pracy technika: " << godz_pracy << endl;
    cout << "Numer pokoju technika: " << nr_pokoju << endl;
  }
};

class zebranie
{
  string miejsce,termin;
  
  uczestnik *head;
  
public:

  zebranie()
  {
    head = NULL;
    head->next = NULL;
  }
  
  void podanie_miejsca_i_terminu()  
  {
    cout << "Podaj miejsce zebrania: "<< endl;
    cin >> miejsce;
    cout << "Podaj termin zebrania: "<< endl;
    cin >> termin;
  }
  void dodaj_uczestnika(uczestnik *x)
  {
    if(!head)
    {
      head = x;
    }
    else
    {
      uczestnik *p = head;
      while(p)
      {
        p = p->next;
      }
      p = x;
    }
  }
  void pokaz_informacje_uczestnikow()
  {
    if(!head)
    {
      cout << "Nie ma nikogo na liscie" << endl;
    }
    else
    {
      uczestnik *p = head;
      while(p)
      {
        p->info();
        p = p->next;
      }
    }
  }
};

int main()
{
  zebranie x1;
  x1.podanie_miejsca_i_terminu();
  bool comeback = false;
  while(!comeback)
  {
    cout
    << "1: Dodaj studenta" << endl
    << "2: Dodaj profesora" << endl
    << "3: Dodaj technika" << endl
    << "4: Pokaz informacje uczestnikow" << endl
    << "5: Zakoncz" <<endl;
    char wybor;
    cin >> wybor;
    switch(wybor)
    {
      case '1':
      {
        student *a = new student;
        x1.dodaj_uczestnika(a);
      }
      break;
      case '2':
      {
        profesor *a = new profesor;
        x1.dodaj_uczestnika(a);
      }
      break;
      case '3':
      {
        technik *a = new technik;
        x1.dodaj_uczestnika(a);
      }
      break;
      case '4':
      {
        x1.pokaz_informacje_uczestnikow();
      }
      break;
      case '5':
      {
        comeback = true;
      }
      break;
      default:
      {
        cout << "zla komenda" << endl;
      }
      break;
    }
  }
  return 0;
}
