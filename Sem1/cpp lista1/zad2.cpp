#include <iostream>
#include <cmath>
#include <vector>

void a(){
    std::vector< float > arr;
    arr.push_back(1/sqrt(3));
    double pi = 0;
    for(int i=1;i<=30;i++){
        arr.push_back((sqrt(pow(arr.at(i-1),2)+1)-1)/(arr.at(i-1)));
        pi = 6*pow(2,i-1)*arr.at(i-1);
        std::cout<<pi<<'\n';
    }
}

void b(){
    std::vector< float > arr;
    arr.push_back(1/sqrt(3));
    double pi = 0;
    for(int i=1;i<=30;i++){
        arr.push_back((arr.at(i-1))/(sqrt(pow(arr.at(i-1),2)+1)+1));
        pi = 6*pow(2,i-1)*arr.at(i-1);
        std::cout<<pi<<'\n';
    }
}

int main(){
    a();
    b();
}