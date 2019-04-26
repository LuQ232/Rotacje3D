#include "Prostopadloscian.hh"

using namespace std;
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Prostopadloscian, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
std::ostream& operator << ( std::ostream       &Strm,const Prostopadloscian    &Pr)
{
	Strm << Pr(0) << endl;
	Strm << Pr(1) << endl << endl;
	Strm << Pr(2) << endl;
	Strm << Pr(3) << endl << endl;
	Strm << Pr(4) << endl;
	Strm << Pr(5) << endl << endl;
	Strm << Pr(6) << endl;
	Strm << Pr(7) << endl << endl;
	return Strm;
}

Prostopadloscian::Prostopadloscian(Wektor3D W1,Wektor3D W2,Wektor3D W3,Wektor3D W4,Wektor3D W5,Wektor3D W6,Wektor3D W7,Wektor3D W8)
{
	
	TablicaWierzcholkow[0]=W1;
	TablicaWierzcholkow[1]=W2;
	TablicaWierzcholkow[2]=W3;
	TablicaWierzcholkow[3]=W4;
	TablicaWierzcholkow[4]=W5;
	TablicaWierzcholkow[5]=W6;
	TablicaWierzcholkow[6]=W7;
	TablicaWierzcholkow[7]=W8;

}