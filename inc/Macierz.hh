#ifndef MACIERZ_HH
#define MACIERZ_HH
#define LICZBAMACIERZY 3

#include <iostream>
#include "Wektor3D.hh"
#include "Wektor.hh"


/*!
 * \file
 * \brief Ten plik powinien zawierać definicję szablonu Macierz<>
 *
 * Ten plik powinien zawierać definicję szablonu Macierz<>.
 * W tym celu należy przerobić definicję klasy Macierz2x2.
 */




/*!
 * \brief  Krótki opis czego to jest szablon
 *
 *  Tutaj trzeba opisac szablon. Jakie pojecie on modeluje
 *  i jakie ma glowne cechy.
 */
template <typename typ,int WymiarMacierzy>
class Macierz{
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  Wektor<typ,WymiarMacierzy> TablicaMacierzy[WymiarMacierzy];
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */
   Wektor<typ,WymiarMacierzy> operator () (unsigned int Indeks) const {return TablicaMacierzy[Indeks];}
   Wektor<typ,WymiarMacierzy>& operator () (unsigned int Indeks)  {return TablicaMacierzy[Indeks];}
   Wektor<typ,WymiarMacierzy> operator * (Wektor<typ,WymiarMacierzy> wektor);//Mnożenie macierzy
   Macierz<typ,WymiarMacierzy> operator * (Macierz<typ,WymiarMacierzy> MacierzMnozenia);
   Macierz<typ,WymiarMacierzy> Transponuj ();
};




/*!
 * \brief Przeciążenie dla wejścia musi także być szablonem
 * 
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
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


template <typename typ, int WymiarMacierzy>
inline
Wektor<typ,WymiarMacierzy> Macierz<typ,WymiarMacierzy>::operator * (Wektor<typ,WymiarMacierzy> wektor)
{

Wektor<typ,WymiarMacierzy> Wynik;
Wynik[0]=0;
Wynik[1]=0;
 

  for (int i=0; i<LICZBAMACIERZY;i++)
  {
      for (int j=0; j<ROZMIARWEKTORA;j++)
    {
        Wynik[i]+=TablicaMacierzy[i][j]*wektor[j];

    }       
  }

return Wynik;
}
/*
template <typename typ, int WymiarMacierzy>
inline
Macierz<typ,WymiarMacierzy> operator * (Macierz<typ,WymiarMacierzy> MacierzMnozenia1,Macierz<typ,WymiarMacierzy> MacierzMnozenia2)
{
  Macierz<typ,WymiarMacierzy> Wynik;

 

  for (int i=0; i<LICZBAMACIERZY;i++)
  {
      for (int j=0; j<ROZMIARWEKTORA;j++)
    {
      Wynik(i)=MacierzMnozenia1(i)*MacierzMnozenia2(j);

    }       
  }
  return Wynik;
}
*/


template <typename typ, int WymiarMacierzy>
inline
Macierz<typ,WymiarMacierzy> Macierz<typ,WymiarMacierzy>::operator * (Macierz<typ,WymiarMacierzy> MacierzMnozenia)
{
  Macierz<typ,WymiarMacierzy> wynik;
  MacierzMnozenia=MacierzMnozenia.Transponuj();
  typ suma;
    for (int i = 0; i < LICZBAMACIERZY; i++) {
      for (int j = 0; j < LICZBAMACIERZY; j++) {
        suma = 0;
        for (int k = 0; k < ROZMIARWEKTORA; k++) {
          suma += TablicaMacierzy[i][k] * MacierzMnozenia(k)[j];
        }
        wynik(i)[j]= suma;
      }
    }
    return wynik;
}
/*

 Macierz<Wymiar> operator*(Macierz<Wymiar> const &Arg2) {
    Macierz<Wymiar> temp;
    double suma;
    for (int i = 0; i < Wymiar; i++) {
      for (int j = 0; j < Wymiar; j++) {
        suma = 0;
        for (int k = 0; k < Wymiar; k++) {
          suma += (*this)(i, k) * Arg2(k, j);
        }
        temp(i, j) = suma;
      }
    }
    return temp;
  }
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


#endif
