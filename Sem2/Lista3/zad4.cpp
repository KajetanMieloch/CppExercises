#include <iostream>
#include <climits>
using namespace std;

void krok4(int k1, int k2, int k3){
	
	cout << "Twój wynik to:";
	
	if(k1 == 0){
		cout << k2 + k3 << endl;
	}
	if(k1 == 1){
		cout << k2 * k3 << endl;
	}
}

void krok3(int k1, int k2){
	cout << "Podaj drugą liczbe: ";
	int k3;
	int x;
	while(! (cin>>x) ){
		cin.clear();
		cin.ignore(INT_MAX,'\n');
	};
	krok4(k1, k2, x);
}

void krok2(int k1){
	cout << "Podaj pierwsza liczbe: ";
	int k2;
	int x;
	while(! (cin>>x) ){
		cin.clear();
		cin.ignore(INT_MAX,'\n');
	};
	krok3(k1,x);
}

void krok1(){
	cout << "Podaj działanie(0 - dodawanie, 1 - mnozenie): ";
	int x;
	while(! (cin>>x) ){
		cin.clear();
		cin.ignore(INT_MAX,'\n');
	};
	switch(x) {
	  case 0:
		krok2(x);
		break;
	  case 1:
		krok2(x);
		break;
	  default:
		cout << "Wystapil blad. Podaj liczbe ponownie. Upewnij sie, ze zachowales odpowiedni zakres"<< endl;
		krok1();
}
}

	
int main(void){
	cout << "Witaj w kalkulatorze wersja 1.0" << endl;

	krok1();
for(;;){
	cout << "Chcesz spróbować jeszcze raz? (0/1)";
	int x;
	while(! (cin>>x) ){
		cin.clear();
		cin.ignore(INT_MAX,'\n');
	};
	switch(x) {
	  case 0:
	  return 0;
		break;
	  case 1:
		krok1();
		break;
	  default:
		cout << "Wystapil blad. Podaj liczbe ponownie. Upewnij sie, ze zachowales odpowiedni zakres"<< endl;}
	
}
}
