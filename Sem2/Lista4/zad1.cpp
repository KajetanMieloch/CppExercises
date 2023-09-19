#include <iostream>
using namespace std;

void wypiszDoCon(){
	cout<<"Hello World"<<endl;
}

void wypiszDoConFloat(float x){
	cout<<x<<endl;
}

void suma(int x, int y){
	cout<<x+y<<endl;
}

int iloczyn3(int x, float y, float z){
	int iloczyn = x*y*z;
	return iloczyn;
}

int tablicaIloczyn(int tab[], int rozmiar)
{
	int iloczyn = tab[0];
	
        for(int i=1; i<rozmiar; i++){
			iloczyn *= tab[i];
		}
	return iloczyn;
}



int main(){
	wypiszDoCon();
	wypiszDoConFloat(12.54);
	suma(10,23);
	cout<<iloczyn3(2,2.3,3.14)<<endl;
	
	int rozmiar = 4;	
	int tablica[rozmiar] = {2,3,2,2};
	
	cout<<tablicaIloczyn(tablica, rozmiar)<<endl;
	
    return 0;
}
