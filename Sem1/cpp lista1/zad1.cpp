#include <iostream>
#include <cmath>

double a(){
    int n = 1000000;
    double wynik = 0;
    for(int j=1;j<=n;j++){
        wynik += (pow(-1, j+1))/(2*j-1);
    }
    return 4*wynik;
}

double b(){
    int n = 1000000;
    double wynik = 1;
    for(int j=1;j<=n;j++){
        wynik *= (4*pow(j, 2))/(4*pow(j,2)-1);
    }
    return 2*wynik;
}

double c(){
    int n = 1000000;
    double wynik = 0;
    for(int j=1;j<=n;j++){
        wynik += (1)/(pow(2*j-1,2));
    }
    return sqrt(8*wynik);
}

int main(){
    std::cout<<a()<<std::endl;
    std::cout<<b()<<std::endl;
    std::cout<<c()<<std::endl;
}