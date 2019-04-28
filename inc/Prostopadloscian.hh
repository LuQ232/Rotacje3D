#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH
#define ILOSCWIERZCHOLKOW 8
#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "Macierz3x3.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
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

};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << ( std::ostream       &Strm,const Prostopadloscian    &Pr);




#endif
