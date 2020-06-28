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
