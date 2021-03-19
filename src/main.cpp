#include <iostream>
#include <limits>
#include "QuizDataBase.hpp"
#include "Statistics.hpp"

using namespace std;

int main(int argc, char **argv){
    if (argc < 2) {
        cout << endl;
        cout << " Brak opcji okreslajacej rodzaj testu." << endl;
        cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
        cout << endl;
        return 1;
    }
    try{
        Quiz   quiz(argv[1]);
        Statistics stats;
        Complex answer, correctAnswer;
        int attempt = 0;

        for (unsigned int i = 0; i < quiz.size(); i++){
            try{
                correctAnswer = quiz[i].Calculate();

                if(!attempt)
                    cout << "Podaj wynik operacji: " << quiz[i] << " = " << endl;
                cout << "Twoja odpowiedz(proba " << attempt + 1 << " z 3): ";

                cin >> answer;
                attempt = 0;

                if (answer == correctAnswer){
                    cout << "Odpowiedz poprawna" << endl << endl;
                    stats++;
                }
                else{
                    cout << "Blad. Prawidlowym wynikiem jest: " << correctAnswer << endl << endl;
                    stats--;
                }

            }
            catch (std::logic_error& e){
                if (attempt < 2){
                    i--; attempt++;
                    cerr << endl << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." << endl << endl;
                }
                else{
                    stats--; attempt = 0;
                    cerr << endl << "Blad zapisu liczby zespolonej. Prawidlowym wynikiem jest: " << correctAnswer << endl << endl;
                }
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
            }
            catch (...){
                throw;
            }
        }
        cout << "Koniec testu!" << endl << stats;
    }
    catch (std::logic_error& e){
        cerr << e.what() << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return 2;
    }
    catch (...){
        cerr << "Unknown error" << endl;
    }

    return 0;
}
