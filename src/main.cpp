#include <iostream>
#include "BazaTestu.hh"

using namespace std;




int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  Expression   quizQuestion;
  cin   >>  quizQuestion;
  Display(quizQuestion);
  
  while (PobierzNastpnePytanie(&BazaT,&quizQuestion)) {
    cout << ":? Podaj wynik operacji: ";
    //cout << WyrZ_PytanieTestowe.Arg1.re << endl;
    Display(quizQuestion);
  }

  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
