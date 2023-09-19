#include <time.h>
#include <iostream>

using namespace std;

int wygenereujZakres(int zakres){
	srand(time( NULL ) );
	
	int rng = (int) rand() % zakres + 1;
	
	return rng;
}

int gra(bool nowyZakres, int zakres){
    int liczba, proby = 1;
    if(nowyZakres){
        cout << "wybierz zakres: ";
        cin >> zakres;
    }

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
    
    cout << "Brawo zgadłeś liczbe w " << proby << " próbach." << endl;
    
    return zakres;
}

int main(){
    bool nowyZakres;
    int wyb;
    int zakres;
    
    cout << "Zgadywanka, zapraszam do gry!!!" << endl;
    zakres = gra(1, 0);
    for(;;){
        cout << "To była dobra zabawa! Próbujemy jeszcze raz? 0-Nie 1-Tak: ";
        cin >> wyb;
        if(wyb == 0){
            cout << "Miłego dnia, do widzenia!";
            return 0;
        }
        cout << "Wybór zakresu. 0-Zostawiamy zakres 1-Nowy zakres: ";
        cin >> nowyZakres;
        zakres = gra(nowyZakres, zakres);
    }

    
    return 0;
}