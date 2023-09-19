#include <iostream>
#include <cmath>

void oblicz(int ni){
    double down;
    double up;

    for(double n=1; n<=ni;n++){
        down += 1/n;
    }

    for(double n=ni; n<=0;n++){
        up += 1/n;
    }

    std::cout<<"down "<<down<<std::endl;
    std::cout<<"up "<<up<<std::endl;
    std::cout<<"wynik dla n="<<ni<<" "<<up-down<<std::endl;
    std::cout<<std::endl;
}

int main(){
    int n1 = 100;
    int n2 = 100000;
    int n3 = 100000000;

    oblicz(n1);
    oblicz(n2);
    oblicz(n3);

}