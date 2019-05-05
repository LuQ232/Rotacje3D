#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH
#define ILOSCWIERZCHOLKOW 8
#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "Macierz3x3.hh"

/*!
 * \file
 * \brief Plik zawiera definicję klasy Prostopadłościan
 *
 * Ten plik  zawiera definicję klasy Prostopadłościan
 * W tym celu  przerobiono definicję klasy Prostokat.
 */


/*!
 * \brief Jest to Klasa Prostopadloscianu
 * 
 *  Klasa modeluje pojęcie Prostopadłościanu. Jego atrybutem jest tablica Wektorów3D, czyli jego wierzchołków.
 */
class Prostopadloscian {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
	Wektor3D TablicaWierzcholkow[ILOSCWIERZCHOLKOW];
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */  
   Wektor3D operator () (int Ind) const { return TablicaWierzcholkow[Ind];}
   Wektor3D& operator () (int Ind) {return TablicaWierzcholkow[Ind];}  
   Prostopadloscian(Wektor3D W1,Wektor3D W2,Wektor3D W3,Wektor3D W4,Wektor3D W5,Wektor3D W6,Wektor3D W7,Wektor3D W8);
   Prostopadloscian Przesuniecie(Wektor3D koordy);
   Macierz3x3 StworzMacierzRotacji();
   void Rotacja(int IleRazy, Macierz3x3 MacierzRotacji);
   Macierz3x3 MacierzRotacjiOX(double kat);
   Macierz3x3 MacierzRotacjiOY(double kat);
   Macierz3x3 MacierzRotacjiOZ(double kat);

    double odleglosc(double x, double y, double z);
    void WyswietlOdleglosc(double pierwszy, double drugi, double trzeci, double czwarty);
    void PorownajOdleglosci(Wektor3D A, Wektor3D B, Wektor3D C, Wektor3D D, Wektor3D E, Wektor3D F, Wektor3D G, Wektor3D H);
};


/*!
 * \brief Przeciążenie dla wyjścia (szablon)
 * 
 * \param Strm - Strumien
 * \param Pr - Prostopadloscian, ktorego koordynaty chcemy wyswietlic
 * \retval Strm - Strumien 
 */
std::ostream& operator << ( std::ostream       &Strm,const Prostopadloscian    &Pr);
bool PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku,Prostopadloscian Pr);


#endif
