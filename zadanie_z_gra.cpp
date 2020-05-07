\\\\Zadanie 2 

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

string losowanie(string slowo)
{
  string mieszanie;
  int pozycja(0);
  while (slowo.size() != 0)
  {
    pozycja = rand() % slowo.size();
    mieszanie += slowo[pozycja];
    slowo.erase(pozycja, 1);
  }
  return mieszanie;
}

int liczbaProb;
int liczbagier;
int a; // zadeklarowana liczba prób
int b; //  zadeklarowana ilość gier
int wynik1 = 0;
int wynik2 = 0;

int main()
{
  cout << "Podaj liczbę prób: ";
  cin >> a;
  cout << "Podaj ilość gier: ";
  cin >> b;

  for (int i = 1; i<=b; i++)
  {
    string wpisaneslowo, pomieszaneslowo, wprowadzoneslowo;

    srand(time(0));

    cout << "Wpisz słowo do pomieszania ( Gracz drugi ma  " << a << " prób/y)" << endl;
    cin >> wpisaneslowo;

    pomieszaneslowo = losowanie(wpisaneslowo);
    while(wprowadzoneslowo != wpisaneslowo)
    {
      cout << endl << "Zgadnij słowo " << pomieszaneslowo << endl;
      cin >> wprowadzoneslowo;

      if (wprowadzoneslowo == wpisaneslowo)
      {
        cout << "Poprawnie, punkt otrzymuje Gracz drugi" << endl;
        wynik2 = wynik2 + 1;
        liczbaProb = 0;
        break;
      }
      else
      {
        cout << "Błąd, to już twoja " << liczbaProb << " próba." << endl;
        liczbaProb = liczbaProb + 1;
      }
      if (liczbaProb == a)
      {
        cout << "Sprobuj ponownie, wykorzystałeś wszystkie próby " << endl;
        cout << "Punkt otrzymuje gracz pierwszy!";
        wynik1 = wynik1 + 1;
        liczbagier = b + 1;
        liczbaProb = 0;

        if (i == b)
        {
          cout << "Wynik gracza pierwszego  " << wynik1 << endl;
          cout << "Wynik gracza drugiego  " << wynik2 << endl;
          if (wynik1 > wynik2)
          {
            cout << "Wygrywa gracz pierwszy!";
          }
          else
          {
            cout << "Wygrywa gracz drugi!";
          }

          
        }
        else
        {
          cout << " Kolejna gra rozpoczyna się!";
          liczbagier = b + 1;
        }
        break;
      }
      else
      {

      }
    }

    
  }
  return 0;
}
