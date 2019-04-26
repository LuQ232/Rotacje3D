#ifndef WEKTOR_HH
#define WEKTOR_HH
#define ROZMIARWEKTORA 3
#include <iostream>
#include <iomanip>
#include <fstream>


/*!
 * \file
 * \brief Ten plik powinien zawierać definicję szablonu Wektor<>
 *
 * Ten plik powinien zawierać definicję szablonu Wektor<>.
 * W tym celu należy przerobić definicję klasy Wektor2D.
 */


/*!
 * \brief Krótki opis czego to jest szablon
 * 
 *  Tutaj trzeba opisac szablon. Jakie pojecie on modeluje
 *  i jakie ma glowne cechy.
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
    typ operator [] (int Ind) const { return TablicaWektorow[Ind];}
    typ& operator [] (int Ind) {return TablicaWektorow[Ind];}
    Wektor<typ,WymiarWektora>  operator + (Wektor<typ,WymiarWektora> wektor1);
    Wektor<typ,WymiarWektora>  operator - (Wektor<typ,WymiarWektora> wektor1);
    Wektor<typ,WymiarWektora>  operator * (Wektor<typ,WymiarWektora> wektor1);
    Wektor<typ,WymiarWektora>  operator * (typ liczba);
    Wektor<typ,WymiarWektora>  operator / (typ liczba);
};


/*!
 * \brief Przeciążenie dla wyjścia musi także być szablonem
 *
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
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
 * \brief Przeciążenie dla wejścia musi także być szablonem
 * 
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
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

//ILORAZ   WEKTORA I LICZBY  -> ZWRACA WEKTOR 
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
