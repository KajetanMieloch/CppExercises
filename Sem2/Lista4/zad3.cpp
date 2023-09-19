#include <time.h>
#include <iostream>

using namespace std;

int wygenereujZakres(int zakres){
	srand(time( NULL ) );
	
	int rng = (int) rand() % zakres + 1;
	
	return rng;
} 

int main(){
    int zakres, liczba, proby = 1;
    cout << "wybierz zakres: ";
    cin >> zakres;
    int wynik = wygenereujZakres(zakres);
    
    for(;;){
        cout << "zgadnij liczbę: ";
        cin >> liczba;
        if (liczba > zakres){
            cout << "podpowiedź: zgaduj liczby z podanego zakresu, czyli 0-" << zakres << endl;
        }
        if(liczba == wynik){
            break;
        }
        proby += 1;
        cout << "niestety niepoprawnie! Spróbuj ponownie." << endl;
    }
    
    cout << "Brawo zgadłeś liczbe w " << proby << " próbach.";

    return 0;
}