#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
  ofstream wynik("wynik.dat");
  
  for(float x=0; x<2*M_PI; x=x+0.01)
	{
		wynik << x << '\t'<< pow(cos(x),2) << endl;
	}

  wynik.close();
} 

