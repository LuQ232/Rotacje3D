#ifndef WEKTOR_HH
#define WEKTOR_HH
#define ROZMIARWEKTORA 3
#include <iostream>
#include <iomanip>
#include <fstream>


/*!
 * \file
 * \brief Plik zawiera definicję szablonu Wektor<>
 *
 * Ten plik  zawiera definicję szablonu Wektor<>.
 * W tym celu  przerobiono definicję klasy Wektor2D.
 */


/*!
 * \brief Jest to Szablon Wektora
 * 
 *  Szablon modeluje pojęcie wektora o zadanej wielkości
 *  oraz podnym typie. Jego atrybutem jest tablica podanego typu.
 */
template <typename typ, int WymiarWektora>
class Wektor {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  typ TablicaWektorow[WymiarWektora];
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */ 
    /*!
 * \brief Indeksowanie Wektora do "odczytu"
 * \param Indeks(numer miejsca w tablicy) 
 * 
 * \retval typ - wartosc z tablicy typów w miejscu indeks 
 */
    typ operator [] (int Ind) const { return TablicaWektorow[Ind];}
  /*!
 * \brief Indeksowanie Macierzy do zapisu
 * \param Indeks
 * 
 * \retval Wektor 
 */
    typ& operator [] (int Ind) {return TablicaWektorow[Ind];}
    Wektor<typ,WymiarWektora>  operator + (Wektor<typ,WymiarWektora> wektor1);
    Wektor<typ,WymiarWektora>  operator - (Wektor<typ,WymiarWektora> wektor1);
    Wektor<typ,WymiarWektora>  operator * (Wektor<typ,WymiarWektora> wektor1);
    Wektor<typ,WymiarWektora>  operator * (typ liczba);
    Wektor<typ,WymiarWektora>  operator / (typ liczba);
};



/*!
 * \brief Przeciążenie dla wejścia (szablon)
 * 
 * \param Strm - Strumien
 * \param Wek - Wektor, do ktorego "chcemy się dostać"
 * \retval Strm - Strumien 
 */
template <typename typ, int WymiarWektora>
inline
std::istream& operator >> (std::istream &Strm, Wektor<typ,WymiarWektora> &Wek)
{
  for(int i=0; i<ROZMIARWEKTORA; i++)
  {
    Strm >> Wek[i]; 
  }

  return Strm;
}

/*!
 * \brief Przeciążenie dla wyjścia (szablon)
 * 
 * \param Strm - Strumien
 * \param Wek - Wektor, ktory chcemy wyswietlic
 * \retval Strm - Strumien 
 */
template <typename typ, int WymiarWektora>
inline
std::ostream& operator << (std::ostream &Strm, const Wektor<typ,WymiarWektora> &Wek)
{
  for(int i=0; i<ROZMIARWEKTORA; i++)
  {
    Strm <<std::setw(16)<<std::fixed <<std::setprecision(10)<<Wek[i] << " "; 
  }

  return Strm;  
}


/*!
 * \brief Przeciążenie dodawania (szablon)
 * 
 * \param wektor1 - Wektor, który będzie składnikiem dodawania
 * 
 * \retval Wektor - Suma dwóch wektorów 
 */
template<typename typ, int WymiarWektora>
inline
Wektor<typ,WymiarWektora>  Wektor<typ,WymiarWektora>::operator + (Wektor<typ,WymiarWektora>  wektor1)
{
  

  for(int i=0;i<ROZMIARWEKTORA;i++)
  {
    wektor1[i] = wektor1[i] + TablicaWektorow[i];
  }


  return wektor1;
}



/*!
 * \brief Przeciążenie odejmowania (szablon)
 * 
 * \param wektor1 - Wektor, który będzie składnikiem odejmowania
 * 
 * \retval Wektor - Roznica dwóch wektorów 
 */
template<typename typ, int WymiarWektora>
inline
Wektor<typ,WymiarWektora>  Wektor<typ,WymiarWektora>::operator - (Wektor<typ,WymiarWektora>  wektor1)
{
  

  for(int i=0;i<ROZMIARWEKTORA;i++)
  {
    wektor1[i] = wektor1[i] - TablicaWektorow[i];
  }


  return wektor1;
}


/*!
 * \brief Przeciążenie mnożenia(iloczyn skalarny dwoch wektorów) [szablon]
 * 
 * \param wektor1 - Wektor, który będzie składnikiem mnozenia
 * 
 * \retval Wektor - Iloczyn skalarny dwóch wektorów
 */

//ILOCZYN SKALARNY DWOCH WEKTORÓW -> ZWRACA WEKTOR 
template<typename typ, int WymiarWektora>
inline
Wektor<typ,WymiarWektora>  Wektor<typ,WymiarWektora>::operator * (Wektor<typ,WymiarWektora>  wektor1)
{
  Wektor  Wynik;
  double tmp;
  for(int i=0;i<ROZMIARWEKTORA;i++)
  {
    tmp=TablicaWektorow[i]*wektor1[i];
    Wynik[i]=tmp;  
  }


  return Wynik;
}


/*!
 * \brief Przeciążenie mnożenia(iloczyn wektora i liczby) [szablon]
 * 
 * \param liczba - Typ,który będzie składnikiem mnozenia
 * 
 * \retval Wektor - Iloczyn Wektora i liczby
 */

//ILOCZYN   WEKTORA I LICZBY  -> ZWRACA WEKTOR 
template<typename typ, int WymiarWektora>
inline
Wektor<typ,WymiarWektora>  Wektor<typ,WymiarWektora>::operator * (typ liczba)
{
  Wektor  Wynik;
  double tmp;
  for(int i=0;i<ROZMIARWEKTORA;i++)
  {
    tmp=TablicaWektorow[i]*liczba;
    Wynik[i]=tmp;  
  }


  return Wynik;
}


/*!
 * \brief Przeciążenie dzielenia(iloraz wektora i liczby) [szablon]
 * 
 * \param liczba - Typ,który będzie składnikiem dzielenia
 * 
 * \retval Wektor - Iloraz Wektora i liczby
 */
template<typename typ, int WymiarWektora>
inline
Wektor<typ,WymiarWektora>  Wektor<typ,WymiarWektora>::operator / (typ liczba)
{
  Wektor  Wynik;
  double tmp;
  for(int i=0;i<ROZMIARWEKTORA;i++)
  {
    tmp=TablicaWektorow[i]/liczba;
    Wynik[i]=tmp;  
  }


  return Wynik;
}


#endif
