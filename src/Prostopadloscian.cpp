#include "Prostopadloscian.hh"
#include "Macierz3x3.hh"
#include <cmath>
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
Prostopadloscian Prostopadloscian::Przesuniecie (Wektor3D koordy)
{
	Wektor3D W1,W2,W3,W4,W5,W6,W7,W8;
	Prostopadloscian Wynik(W1,W2,W3,W4,W5,W6,W7,W8);

	for(int i=0; i<ILOSCWIERZCHOLKOW; i++)
	{
		Wynik(i)=TablicaWierzcholkow[i]+koordy;
	}

return Wynik;
}


Macierz3x3 Prostopadloscian::MacierzRotacjiOZ(double kat)
{

  	Macierz3x3 macierzrotacji;
	
	macierzrotacji(0)[0] = cos(kat*M_PI/180);
	macierzrotacji(0)[1] = -sin(kat*M_PI/180);
	macierzrotacji(0)[2] = 0;
	macierzrotacji(1)[0] = sin(kat*M_PI/180);
	macierzrotacji(1)[1] = cos(kat*M_PI/180);
	macierzrotacji(1)[2] = 0;
	macierzrotacji(2)[0] = 0;
	macierzrotacji(2)[1] = 0;
	macierzrotacji(2)[2] = 1;

	return macierzrotacji;
}



Macierz3x3 Prostopadloscian::MacierzRotacjiOY(double kat)
{
	Macierz3x3 macierzrotacji;

	macierzrotacji(0)[0] = cos(kat*M_PI/180);
	macierzrotacji(0)[1] = 0;
	macierzrotacji(0)[2] = sin(kat*M_PI/180);
	macierzrotacji(1)[0] = 0;
	macierzrotacji(1)[1] = 1;
	macierzrotacji(1)[2] = 0;
	macierzrotacji(2)[0] = -sin(kat*M_PI/180);
	macierzrotacji(2)[1] = 0;
	macierzrotacji(2)[2] = cos(kat*M_PI/180);

	return macierzrotacji;
}



Macierz3x3 Prostopadloscian::MacierzRotacjiOX(double kat)
{
	Macierz3x3 macierzrotacji;

	macierzrotacji(0)[0] = 1;
	macierzrotacji(0)[1] = 0;
	macierzrotacji(0)[2] = 0;
	macierzrotacji(1)[0] = 0;
	macierzrotacji(1)[1] = cos(kat*M_PI/180);
	macierzrotacji(1)[2] = -sin(kat*M_PI/180);
	macierzrotacji(2)[0] = 0;
	macierzrotacji(2)[1] = sin(kat*M_PI/180);
	macierzrotacji(2)[2] = cos(kat*M_PI/180);

	return macierzrotacji;
}

Macierz3x3 Prostopadloscian::StworzMacierzRotacji()
{
	cout << "  Podaj sekwencje oznaczen osi oraz katy obrotu w stopniach " << endl << "  ";
	Macierz3x3 Macierz;
	Macierz = Macierz.StworzMacierzJednostkowa();
	int koniec=0;
	char znak;
	double kat;
	while(koniec!=1)
	{
		cin >> znak;
		if(znak == '.')
		{
			koniec=1;
		}
		else
		{
			cin >> kat;
			cout << "  ";
		

			if(znak == 'x')
			{
				Macierz = Macierz*MacierzRotacjiOX(kat);
			}

			if(znak == 'y')
			{
				Macierz = Macierz*MacierzRotacjiOY(kat);
			}

			if(znak == 'z')
			{
				Macierz = Macierz*MacierzRotacjiOZ(kat);
			}
		}

		if(znak != 'x' && znak != 'y' && znak != 'z' && znak != '.')
		{
			cout << "  Podano nieprawidlowa os obrotu!" << endl;
		}
	}

return Macierz;

}


void Prostopadloscian::Rotacja(int IleRazy, Macierz3x3 MacierzRotacji)
{

	for(int i=0; i<IleRazy; i++){
		for(int j=0; j<ILOSCWIERZCHOLKOW; j++){
			TablicaWierzcholkow[j] =  MacierzRotacji * TablicaWierzcholkow[j];
		}
	}

}