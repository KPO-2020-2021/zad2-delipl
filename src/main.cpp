#include <iostream>
#include "BazaTestu.hh"
#define ATTEMPT_NUMBER 3

using namespace std;

int main(int argc, char **argv){
    if (argc < 2){
        cout << endl;
        cout << " Brak opcji okreslajacej rodzaj testu." << endl;
        cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
        cout << endl;
        return 1;
    }

    BazaTestu BazaT = {nullptr, 0, 0};

    if (InicjalizujTest(&BazaT, argv[1]) == false){
        cerr << " Inicjalizacja testu nie powiodla sie." << endl;
        return 1;
    }
    cout << endl;
    cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
    cout << endl;

    /*===TEST====*/
    while(true){
        Expression temp;
        cin >> temp;
        Display(temp);
        cout << CalculateExpression(temp) << endl;
        // string lol;
        // cin >> lol;
        // int i = 0;
        // Complex x = StringToComplex(lol, &i);
        // cout << x;
    }
    return 0;
    /*===========*/
    Expression quizQuestion;

    while (PobierzNastpnePytanie(&BazaT, &quizQuestion)){
        cout << ":? Podaj wynik operacji: ";
        Display(quizQuestion);

        Complex answer;
        Complex correctAnswer = CalculateExpression(quizQuestion);
        for (int j = 0; j < ATTEMPT_NUMBER; j++){
            cout << "   Twoja Odpowiedz: ";
            try{
                WriteComplex(answer);
                if (answer == correctAnswer){
                    cout << ":) Odpowiedz poprawna" << endl
                         << endl;
                    break;
                }
                else{
                    cout << ":( Blad. Prawidlowym wynikiem jest: " << correctAnswer << endl
                         << endl;
                    break;
                }
            }
            catch (...){
                if (j == ATTEMPT_NUMBER - 1)
                    cerr << endl
                         << "\nBlad zapisu liczby zespolonej. Przechodzisz do nastepnego pytania." << endl
                         << endl;
                else
                    cerr << endl
                         << "\nBlad zapisu liczby zespolonej. Sprobuj jeszcze raz." << endl
                         << endl;
            }
        }
    }

    cout << endl;
    cout << " Koniec testu." << endl;
    cout << endl;
}
