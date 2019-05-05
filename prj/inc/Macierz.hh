#ifndef MACIERZ_HH
#define MACIERZ_HH
#define LICZBAMACIERZY 3

#include <iostream>
#include "Wektor3D.hh"
#include "Wektor.hh"


/*!
 * \file
 * \brief Plik zawierający definicję szablonu Macierz<>
 *
 * Plik zawiera definicję szablonu Macierz<>.
 * W tym celu przerobiono definicję klasy Macierz2x2 z poprzedniego programu.
 */




/*!
 * \brief  Jest to szablon Macierzy
 *
 *  Szablon modeluje pojęcie macierzy o zadanej wielkości
 *  oraz podnym typie. Jego atrybutem jest tablica wektorow.
 */
template <typename typ,int WymiarMacierzy>
class Macierz{
  
  Wektor<typ,WymiarMacierzy> TablicaMacierzy[WymiarMacierzy];
  public:
  
 

/*!
 * \brief Indeksowanie Macierzy do "odczytu"
 * \param Indeks(numer miejsca w tablicy) 
 * 
 * \retval Wektor - wartosc z tablicy wektorów w miejscu indeks 
 */
   Wektor<typ,WymiarMacierzy> operator () (unsigned int Indeks) const {return TablicaMacierzy[Indeks];}
 /*!
 * \brief  
 */
   /*!
 * \brief Indeksowanie Macierzy do zapisu
 * \param Indeks
 * 
 * \retval Wektor 
 */
   Wektor<typ,WymiarMacierzy>& operator () (unsigned int Indeks)  {return TablicaMacierzy[Indeks];}
   Wektor<typ,WymiarMacierzy> operator * (Wektor<typ,WymiarMacierzy> wektor);//Mnożenie macierzy razy wektor
   Macierz<typ,WymiarMacierzy> operator * (Macierz<typ,WymiarMacierzy> MacierzMnozenia);//macierz razy macierz
   Macierz<typ,WymiarMacierzy> Transponuj ();
   Macierz<typ,WymiarMacierzy> StworzMacierzJednostkowa ();
};



/*!
 * \brief Przeciążenie dla wejścia (szablon)
 * 
 * \param Strm - Strumien
 * \param Mac - Macierz, ktora chcemy wyswietlic
 * \retval Strumien 
 */
template <typename typ,int WymiarMacierzy>
inline
std::ostream& operator << (std::ostream &Strm, const Macierz<typ,WymiarMacierzy> &Mac)
{
  
  for(int i=0;i<LICZBAMACIERZY;i++)
  {
    Strm<<Mac(i)<<" "<<std::endl;
  }

  return Strm;  
}


/*!
 * \brief Przeciążenie dla mnozenia macierzy i wektora 
 * 
 * \param wektor- Wektor przez który bedziemy mnożyć macierz
 * 
 * \retval Wektor 
 */
template <typename typ, int WymiarMacierzy>
inline
Wektor<typ,WymiarMacierzy> Macierz<typ,WymiarMacierzy>::operator * (Wektor<typ,WymiarMacierzy> wektor)
{

Wektor<typ,WymiarMacierzy> Wynik;


  for (int i=0; i<LICZBAMACIERZY;i++)
  {
    Wynik[i]=0;
      for (int j=0; j<ROZMIARWEKTORA;j++)
    {
        Wynik[i]+=TablicaMacierzy[i][j]*wektor[j];

    }       
  }

return Wynik;
}





/*!
 * \brief Przeciążenie dla mnozenia macierz razy macierz 
 * 
 * \param MacierzMnozenia - Macierz która będzie czynnikiem mnożenia
 * 
 * \retval Macierz 
 */

template <typename typ, int WymiarMacierzy>
inline
Macierz<typ,WymiarMacierzy> Macierz<typ,WymiarMacierzy>::operator * (Macierz<typ,WymiarMacierzy> MacierzMnozenia)
{
  Macierz<typ,WymiarMacierzy> wynik;
  //std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl<<"MACIERZ PRZED TRANSPONOWANIEM"<<std::endl<<MacierzMnozenia<<std::endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
  MacierzMnozenia=MacierzMnozenia.Transponuj();
  //std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl<<"MACIERZ MNOZENIA PO TRANSPONOWANIU"<<std::endl<<MacierzMnozenia<<std::endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
  typ suma;
    for (int i = 0; i < LICZBAMACIERZY; i++) {
      for (int j = 0; j < LICZBAMACIERZY; j++) {
        suma = 0;
        for (int k = 0; k < ROZMIARWEKTORA; k++) {
          //std::cout<<TablicaMacierzy[i][k]<<"*"<<MacierzMnozenia(j)[k]<<std::endl;
          suma += TablicaMacierzy[i][k] * MacierzMnozenia(j)[k];
        }
        //std::cout<<"tab["<<i<<"]["<<j<<"] WYNOSI: "<<suma<<std::endl;
        wynik(i)[j]= suma;
      }
    }
    return wynik;
}




/*!
 * \brief Funkcja która transponuje macierz
 * Funkcja potrzebna do poprawnego mnozenia macierzy.
 * \param 
 * 
 * \retval Macierz 
 */

template <typename typ, int WymiarMacierzy>
inline
Macierz<typ,WymiarMacierzy> Macierz<typ,WymiarMacierzy>::Transponuj()
{
Macierz<typ,WymiarMacierzy> Wynik;
for(int i=0; i<LICZBAMACIERZY;i++)
  {
     for(int j=0;j<LICZBAMACIERZY;j++)
      {
        Wynik(j)[i]=TablicaMacierzy[i][j];
      }
  }
return Wynik;
}


/*!
 * \brief Funkcja tworząca macierz jednostkowa
 * 
 * \param 
 * 
 * \retval Macierz 
 */
template <typename typ, int WymiarMacierzy>
inline
Macierz<typ,WymiarMacierzy> Macierz<typ,WymiarMacierzy>::StworzMacierzJednostkowa()
{

  Macierz<typ,WymiarMacierzy> Wynik;
  for(int i=0;i<LICZBAMACIERZY;i++)
  {
    for(int j=0;j<LICZBAMACIERZY;j++)
    {
      if(i==j)
        Wynik(i)[j]=1;
      else 
        Wynik(i)[j]=0;
    }

  }

return Wynik;
}


#endif
