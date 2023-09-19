#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;

 
int fib(int n){
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

void ciekawyCiag(int n){
    int[] y = new int[15];
    ofstream wynik("wynik.dat");
    for(n; n>0; n--):
        y = 1/n^2
  	    wynik << n << '\t'<< y[n] << endl;
  	
    wynik.close();
}
 
int main(){
    int n = 10;
    cout << fib(n) << endl;
    cout << ciekawyCiag(n);
    return 0;
}
