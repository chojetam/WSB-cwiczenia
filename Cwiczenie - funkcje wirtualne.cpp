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
    //head = new uczestnik;
    head->next = NULL;
    head = NULL;
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
      while(p->next)
      {
        p = p->next;
      }
      p->next = x;
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
