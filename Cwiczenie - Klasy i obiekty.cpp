#include <iostream>
using namespace std;
class osoba //klasa osoba
{
 
 char nazwisko[25]; //sekcja prywatna
 char imie[20];
 int wiek;

public: //sekcja publiczna
  void wczytaj(char *n, char *i, int w); //deklaracja metody
  void wypisz() //definicja metody wewnątrz klasy
   {
   cout<<"\n"<<imie<<" "<<nazwisko<<endl;
   cout<<"wiek: "<<wiek<<endl;
   }
}; //koniec klasy

void osoba::wczytaj (char *n, char *i, int w) //funkcja
{
 strcpy(nazwisko,n);
 strcpy(imie,i);
 wiek=w;
}
main()
{
 osoba O1, O2;
char na[25], im[20];
int wi;
 cout<<"podaj dane osoby nr 1:"<<endl;
 cout<<"nazwisko: ";
 cin.getline(na,sizeof(na));
cout<<"imię: ";
 cin.getline(im,sizeof(im));
cout<<"wiek: "; 
cin>>wi;
 O1.wczytaj(na,im,wi);
 O2.wczytaj("Nowak","Maciej",24);
cout<<"\nwyświetlenie danych wszystkich osób:"<<endl;
 O1.wypisz();
 O2.wypisz();
return 0;
}
