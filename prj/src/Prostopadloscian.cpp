#include "Prostopadloscian.hh"
#include "Macierz3x3.hh"
#include "lacze_do_gnuplota.hh"
#include <unistd.h>
#include <cmath>
using namespace std;
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Prostopadloscian, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */




/*!
 * \brief Przeciążenie dla wyjścia (szablon)
 * 
 * \param Strm - Strumien
 * \param Pr - Prostopadłościan, ktorego koordynaty chcemy wyswietlic
 * \retval Strm - Strumien 
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


/*!
 * \brief Konstruktor Prostopadłościanu
 * 
 * \param W1 - Wektor3D, pierwszy wektor wspołrzednych wierzchołka
 * \param W2 - Wektor3D, drugi wektor wspołrzednych wierzchołka
 * \param W3 - Wektor3D, trzeci wektor wspołrzednych wierzchołka
 *  itd..
 * 
 * \retval Powstały Prostopadłościan 
 */
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


/*!
 * \brief Funkcja Przesunięcią Prostopadłościanu o Wektor
 * 
 * \param koordy - Wektor3D, jest to wektor o który będziemy przesuwać prostopadłościan.
 *
 * \retval Prostopadłościan - prostopadłościan po przesunieciu 
 */
Prostopadloscian Prostopadloscian::Przesuniecie (Wektor3D koordy)
{
 
	Wektor3D W1,W2,W3,W4,W5,W6,W7,W8;
	Prostopadloscian Wynik(W1,W2,W3,W4,W5,W6,W7,W8);
	//AnimacjaPrzesuniecia(Lacze,1000,Wynik,koordy);	
	for(int i=0; i<ILOSCWIERZCHOLKOW; i++)
	{
	Wynik(i)=TablicaWierzcholkow[i]+koordy;
	}

return Wynik;
}


/*!
 * \brief Funkcja Wypełniająca Macierz funkcjami trygonometrycznymi do rotacji względem Osi OZ
 * 
 * \param kat - double, jest to kat o który bedziemy rotować Prostopadłościan
 *
 * \retval Macierz3x3 - Macierz wypełniona wartościami funkcji trygonometrycznymi 
 */
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



/*!
 * \brief Funkcja Wypełniająca Macierz funkcjami trygonometrycznymi do rotacji względem Osi OY
 * 
 * \param kat - double, jest to kat o który bedziemy rotować Prostopadłościan
 *
 * \retval Macierz3x3 - Macierz wypełniona wartościami funkcji trygonometrycznymi 
 */
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



/*!
 * \brief Funkcja Wypełniająca Macierz funkcjami trygonometrycznymi do rotacji względem Osi OX
 * 
 * \param kat - double, jest to kat o który bedziemy rotować Prostopadłościan
 *
 * \retval Macierz3x3 - Macierz wypełniona wartościami funkcji trygonometrycznymi 
 */
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


/*!
 * \brief Funkcja Obliczająca Macierz rotacji po zadanej sekwencji rotacji
 * 
 * \param 
 *
 * \retval Macierz3x3 - Macierz wypełniona wartościami funkcji trygonometrycznymi dla zadanej sekwencji rotacji
 */
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

/*!
 * \brief Funkcja Rotująca Prostopadłościan o daną sekwencję 
 * 
 * \param IleRazy - int, jest to liczba ile razy ma zostać wykonana rotacja
 * \param MacierzRotacji - Macierz3x3, jest to macierz wypełniona liczbami obliczonymi dla danej sekwencji rotacji
 * \retval 
 */
void Prostopadloscian::Rotacja(int IleRazy, Macierz3x3 MacierzRotacji)
{

	for(int i=0; i<IleRazy; i++){
		for(int j=0; j<ILOSCWIERZCHOLKOW; j++){
			TablicaWierzcholkow[j] =  MacierzRotacji * TablicaWierzcholkow[j];
		}
	}

}


/*!
 * \brief Funkcja Obliczająca odleglosc punktu w ukladzie 3D
 * 
 * \param x - wspolrzedne na osi OX 
 * \param y - wspolrzedne na osi OY
 * \param z - wspolrzedne na osi OZ
 *
 * \retval Double - Odleglosc punktu w ukladzie 3D
 */
double Prostopadloscian::odleglosc(double x, double y, double z)
{
	return(sqrt( pow(x,2) + pow(y,2) + pow(z,2)));
}

/*!
 * \brief Funkcja Wyswietlajaca
 * 
 * \param pierwszy - dlugosc pierwszego boku
 * \param drugi - Dlugosc drugiego boku 
 * \param trzeci - Dlugosc trzeciego boku
 * \param czwarty - Dlugosc czwartego boku 
 * \retval 
 */
void Prostopadloscian::WyswietlOdleglosc(double pierwszy, double drugi, double trzeci, double czwarty)
{
	cout << "  Dlugosc pierwszego boku wynosi: " << setw(16) << fixed << setprecision(16) << pierwszy << endl;
	cout << "  Dlugosc drugiego boku wynosi: " << setw(16) << fixed << setprecision(16) << drugi << endl;
	cout << "  Dlugosc trzeciego boku wynosi: " << setw(16) << fixed << setprecision(16) << trzeci << endl;
	cout << "  Dlugosc czwartego boku wynosi: " << setw(16) << fixed << setprecision(16) << czwarty << endl;
}


/*!
 * \brief Funkcja Porównująca dlugosci boków prostopadłoscianu
 * 
 * \param A - Wektor3D, wspolrzedne pierwszego wierzcholka
 * \param B - Wektor3D, wspolrzedne drugiego wierzcholka
 * \param C - Wektor3D, wspolrzedne trzeciego wierzcholka
 * \param D - Wektor3D, wspolrzedne czwartego wierzcholka
 * \retval 
 */
void Prostopadloscian::PorownajOdleglosci(Wektor3D A, Wektor3D B, Wektor3D C, Wektor3D D, Wektor3D E, Wektor3D F, Wektor3D G, Wektor3D H)
{
double RoznicaOX, RoznicaOY, RoznicaOZ;


// krotsze przeciwlegle w1w2 w3w4 w5w6 w7w8
	double OdlegloscW1W2;
	RoznicaOX = B[0] - A[0];
	RoznicaOY = B[1] - A[1];
	RoznicaOZ = B[2] - A[2];
	OdlegloscW1W2 = odleglosc(RoznicaOX, RoznicaOY, RoznicaOZ);

	double OdlegloscW3W4;
	RoznicaOX = D[0] - C[0];
	RoznicaOY = D[1] - C[1];
	RoznicaOZ = D[2] - C[2];
	OdlegloscW3W4 = odleglosc(RoznicaOX, RoznicaOY, RoznicaOZ);

	double OdlegloscW5W6;
	RoznicaOX = F[0] - E[0];
	RoznicaOY = F[1] - E[1];
	RoznicaOZ = F[2] - E[2];
	OdlegloscW5W6 = odleglosc(RoznicaOX, RoznicaOY, RoznicaOZ);

	double OdlegloscW7W8;
	RoznicaOX = H[0] - G[0];
	RoznicaOY = H[1] - G[1];
	RoznicaOZ = H[2] - G[2];
	OdlegloscW7W8 = odleglosc(RoznicaOX, RoznicaOY, RoznicaOZ);



	if(OdlegloscW1W2 == OdlegloscW3W4 && OdlegloscW5W6 == OdlegloscW7W8 && OdlegloscW1W2 == OdlegloscW5W6)
	{
		cout << endl <<" :) Krotsze przeciwlegle boki sa sobie rowne!" << endl;
	}
	else
	{
		cout << endl <<" :( Krotsze przeciwlegle boki nie sa sobie rowne!" << endl;
	}

	WyswietlOdleglosc(OdlegloscW1W2, OdlegloscW3W4, OdlegloscW5W6, OdlegloscW7W8);


	//dluzsze przeciwlegle
	double OdlegloscW1W3;
	RoznicaOX = C[0] - A[0];
	RoznicaOY = C[1] - A[1];
	RoznicaOZ = C[2] - A[2];
	OdlegloscW1W3 = odleglosc(RoznicaOX, RoznicaOY, RoznicaOZ);

	double OdlegloscW2W4;
	RoznicaOX = D[0] - B[0];
	RoznicaOY = D[1] - B[1];
	RoznicaOZ = D[2] - B[2];
	OdlegloscW2W4 = odleglosc(RoznicaOX, RoznicaOY, RoznicaOZ);

	double OdlegloscW5W7;
	RoznicaOX = G[0] - E[0];
	RoznicaOY = G[1] - E[1];
	RoznicaOZ = G[2] - E[2];
	OdlegloscW5W7 = odleglosc(RoznicaOX, RoznicaOY, RoznicaOZ);

	double OdlegloscW6W8;
	RoznicaOX = H[0] - F[0];
	RoznicaOY = H[1] - F[1];
	RoznicaOZ = H[2] - F[2];
	OdlegloscW6W8 = odleglosc(RoznicaOX, RoznicaOY, RoznicaOZ);



	if(OdlegloscW1W3 == OdlegloscW2W4 && OdlegloscW5W7 == OdlegloscW6W8 && OdlegloscW1W3 == OdlegloscW5W7)
	{
		cout << endl <<" :) Dluzsze przeciwlegle boki sa sobie rowne!" << endl;
	}
	else
	{
		cout << endl <<" :( Dluzsze przeciwlegle boki nie sa sobie rowne!" << endl;
	}

	WyswietlOdleglosc(OdlegloscW1W3, OdlegloscW2W4, OdlegloscW5W7, OdlegloscW6W8);



	//poprzeczne przeciwlegle
	double OdlegloscW1W7;
	RoznicaOX = G[0] - A[0];
	RoznicaOY = G[1] - A[1];
	RoznicaOZ = G[2] - A[2];
	OdlegloscW1W7 = odleglosc(RoznicaOX, RoznicaOY, RoznicaOZ);

	double OdlegloscW2W8;
	RoznicaOX = H[0] - B[0];
	RoznicaOY = H[1] - B[1];
	RoznicaOZ = H[2] - B[2];
	OdlegloscW2W8 = odleglosc(RoznicaOX, RoznicaOY, RoznicaOZ);

	double OdlegloscW3W5;
	RoznicaOX = E[0] - C[0];
	RoznicaOY = E[1] - C[1];
	RoznicaOZ = E[2] - C[2];
	OdlegloscW3W5 = odleglosc(RoznicaOX, RoznicaOY, RoznicaOZ);

	double OdlegloscW4W6;
	RoznicaOX = F[0] - D[0];
	RoznicaOY = F[1] - D[1];
	RoznicaOZ = F[2] - D[2];
	OdlegloscW4W6 = odleglosc(RoznicaOX, RoznicaOY, RoznicaOZ);


	if(OdlegloscW1W7 == OdlegloscW2W8 && OdlegloscW3W5 == OdlegloscW4W6 && OdlegloscW1W7 == OdlegloscW3W5)
	{
		cout << endl <<" :) Poprzeczne przeciwlegle boki sa sobie rowne!" << endl;
	}
	else
	{
		cout << endl <<" :( Poprzeczne przeciwlegle boki nie sa sobie rowne!" << endl;
	}


	WyswietlOdleglosc(OdlegloscW1W7, OdlegloscW2W8, OdlegloscW3W5, OdlegloscW4W6);
}