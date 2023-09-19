#include <iostream>
using namespace std;

int licz = 0;
int temp;
unsigned long int suma = 1;

int main(){
    cout << "wpisz liczbe: ";
    cin >> temp;

    for(licz = temp; licz>0; licz--){
        suma *= licz;
    }
    cout << "wynik silni wynosi: " << suma << endl; 
    return 0;
}
