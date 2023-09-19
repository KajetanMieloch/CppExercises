#include <time.h>
#include <iostream>
#include <fstream>
using namespace std;

void srednia(int ile){
	ofstream wynik;
	srand(time( NULL ) );
	float suma = 0;
	for(int i = 0; i < ile; i++){
		float rng = (float) rand()/RAND_MAX;
		suma += rng;
	}
	float srednia = suma/ile;
	wynik.open ("wynik.dat", std::ios_base::app);
	wynik<<ile<<"\t"<<srednia<<endl;
	wynik.close();
	cout<<srednia<<endl;


	
} 


int main(){
	remove("wynik.dat");
	
	srednia(10);
	srednia(20);
	srednia(50);
	srednia(100);
	srednia(250);
	srednia(500);
	srednia(1000);
	srednia(2500);
	srednia(5000);
    return 0;
}
