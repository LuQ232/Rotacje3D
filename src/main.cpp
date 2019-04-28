#include <iostream>
#include <iomanip>
#include <fstream>
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include "Prostopadloscian.hh"
#include "lacze_do_gnuplota.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


#define DL_BOKU   50





/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void PrzykladZapisuWspolrzednychDoStrumienia( ostream&     StrmWy, 
                                              Prostopadloscian Pr
                                            )
{
   //---------------------------------------------------------------
   // To tylko przyklad !!!
   // W programie nalezy uzywać pojęcia wektora, a nie oddzielnych 
   // zmiennych do reprezentowania wspolrzednych!
   //
StrmWy<<Pr;
StrmWy<<Pr(0)<<endl;
StrmWy<<Pr(1)<<endl;
                             // Jeszcze raz zapisujemy pierwsze dwa wierzcholki,
                             // aby gnuplot narysowal) zamkniętą powierzchnie.
}



/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku,
                                         Prostopadloscian Pr
                                       )
{
  ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
	 << ":(  nie powiodla sie." << endl;
    return false;
  }

  PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy,Pr);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}



int main()
{

Wektor3D Wektor1;Wektor1[0]=50;Wektor1[1]=50;Wektor1[2]=50;
Wektor3D Wektor2;Wektor2[0]=100;Wektor2[1]=50;Wektor2[2]=50;
Wektor3D Wektor3;Wektor3[0]=50;Wektor3[1]=100;Wektor3[2]=50;
Wektor3D Wektor4;Wektor4[0]=100;Wektor4[1]=100;Wektor4[2]=50;
Wektor3D Wektor5;Wektor5[0]=50;Wektor5[1]=100;Wektor5[2]=100;
Wektor3D Wektor6;Wektor6[0]=100;Wektor6[1]=100;Wektor6[2]=100;
Wektor3D Wektor7;Wektor7[0]=50;Wektor7[1]=50;Wektor7[2]=100;
Wektor3D Wektor8;Wektor8[0]=100;Wektor8[1]=50;Wektor8[2]=100;


 Prostopadloscian             Pr(Wektor1,Wektor2,Wektor3,Wektor4,Wektor5,Wektor6,Wektor7,Wektor8);   // To tylko przykladowe definicje zmiennej

  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("prostopadloscian.dat",PzG::RR_Ciagly,2);
   //
   //  Ustawienie trybu rysowania 3D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy x,y,z.
   //
  Lacze.ZmienTrybRys(PzG::TR_3D);
   // Ustawienie zakresow poszczegolnych osi
  Lacze.UstawZakresY(-200,200);
  Lacze.UstawZakresX(-200,200);
  Lacze.UstawZakresZ(-200,200);


  PrzykladZapisuWspolrzednychDoStrumienia(cout,Pr);
  if (!PrzykladZapisuWspolrzednychDoPliku("prostopadloscian.dat",Pr)) return 1;
      Lacze.Rysuj();
  

/*
    cout<<"ROTUJE"<<endl;
    int IleRazy;
    Macierz3x3 MacierzRotacji;
      MacierzRotacji = Pr.StworzMacierzRotacji();
      cout << "  Ile razy operacja obrotu ma byc powtorzona?  ";
      cin >> IleRazy;
      Pr.Rotacja(IleRazy, MacierzRotacji);
*/
char wybor;
int IleRazy;
Macierz3x3 MacierzDoPowtorzeniaRotacji;
int IleRazyDoPowtorzeniaRotacji;
int flaga=0;
for(;;)
{
  cout<<"Twoj wybor? (m - menu) > ";
  cin>>wybor;
  switch(wybor)
  {
    case 'o':
      Macierz3x3 MacierzRotacji;
      MacierzRotacji = Pr.StworzMacierzRotacji();
      cout << "  Ile razy operacja obrotu ma byc powtorzona?  ";
      cin >> IleRazy;
      MacierzDoPowtorzeniaRotacji=MacierzRotacji;
      IleRazyDoPowtorzeniaRotacji=IleRazy;
      Pr.Rotacja(IleRazy, MacierzRotacji);
      if (!PrzykladZapisuWspolrzednychDoPliku("prostopadloscian.dat",Pr)) return 1;
      Lacze.Rysuj();
      flaga=1;
    break;
      

    case 't':
      if(flaga==1)
      {
        Pr.Rotacja(IleRazyDoPowtorzeniaRotacji,MacierzDoPowtorzeniaRotacji);
        if (!PrzykladZapisuWspolrzednychDoPliku("prostopadloscian.dat",Pr)) return 1;
        Lacze.Rysuj();
      }else 
      {
       cout<<"Nie wykonano wczesniej rotacji!!!!!!!"<<endl; 
      }
    break;

    case 'r':
      cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<"Macierz Rotacji:"<<endl<<MacierzRotacji<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    break;

    case 'p':
      Wektor3D przesuniecie;
      cout<<"Podaj wektor przesuniecia Prostopadloscianu( x y z ) :";
      cin>>przesuniecie;
      Pr=Pr.Przesuniecie(przesuniecie);

    if (!PrzykladZapisuWspolrzednychDoPliku("prostopadloscian.dat",Pr)) return 1;
      Lacze.Rysuj();
    break;

    case 'w':
      PrzykladZapisuWspolrzednychDoStrumienia(cout,Pr);
      
    break;

    case 's':
      //kod
    break;

    case 'm':
      cout<<"o - obrot bryly o zadana sekwencje katow"<<endl;
      cout<<"t - powtorzenie poprzedniego obrotu"<<endl;
      cout<<"r - wyswietlenie macierzy rotacji"<<endl;
      cout<<"p - przesuniecie prostokata o zadany wektor"<<endl;
      cout<<"w - wyswietlenie wspolrzednych wierzcholkow i zapis do pliku"<<endl;
      cout<<"s - sprawdzenie dlugosci przeciwleglych bokow"<<endl;
      cout<<"m - wyswietl menu"<<endl;
      cout<<"k - koniec dzialania programu"<<endl;
    break;

    case 'k':
      cout<<"Zakonczono Program"<<endl;
      return 1;
    break;  
    
    default:
      cout << endl;
      cout << "  Wybierz poprawna opcje" << endl << endl;
      break;

  }



}













}
