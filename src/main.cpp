#include <iostream>
#include "BazaTestu.hh"
#define ATTEMPT_NUMBER 3

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

  
  while (PobierzNastpnePytanie(&BazaT,&quizQuestion)) {
    cout << ":? Podaj wynik operacji: ";
    Display(quizQuestion);
    cout << "Twoja Odpowiedz: ";
    Complex answer; 
    WriteComplex(answer);
    Complex correctAnswer =  CalculateExpression(quizQuestion);
    for(int j = 0; j < ATTEMPT_NUMBER; j ++){
      if(answer == correctAnswer){
        cout << ":) Odpowiedz poprawna" << endl;
        break;
      }
      else{
        cout << ":( Blad. Prawidlowym wynikiem jest: " << correctAnswer << endl;
        break;
      }
    }
  }

  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
