#include<iostream>
#include<cstdlib>
#include<complex>
#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b) {

    std::complex<double> af = *(std::complex<double>*)a;
    std::complex<double> bf= *(std::complex<double>*)b;

    double am = sqrt(pow(af.real(),2) + pow(af.imag(),2));
    double bm = sqrt(pow(bf.real(),2) + pow(bf.imag(),2));

    if (am > bm) return 1;
    else if (am < bm) return -1;
    else return 0;
}

int main(){

    std::complex<double> nComplex[10];
    nComplex[0] = std::complex<double>(6,8);
    nComplex[1] = std::complex<double>(2,4);
    nComplex[2] = std::complex<double>(15,26);
    nComplex[3] = std::complex<double>(6,9);
    nComplex[4] = std::complex<double>(18,3);
    nComplex[5] = std::complex<double>(12,12);
    nComplex[6] = std::complex<double>(4,2);
    nComplex[7] = std::complex<double>(5,0);
    nComplex[8] = std::complex<double>(18,11);
    nComplex[9] = std::complex<double>(2,5);

    double nModule[10];

    for (int i=0; i<10; i++)
        nModule[i] = sqrt(pow(nComplex[i].real(),2) + pow(nComplex[i].imag(),2));


    for (int i=0; i<10; i++)
        std::cout<<nComplex[i]<<" "<<nModule[i]<<std::endl;

    std::cout<<"++++"<<std::endl;

    qsort (nComplex,10, sizeof(std::complex<double>), compare);

    for (int i=0; i<10; i++)
        nModule[i] = sqrt(pow(nComplex[i].real(),2) + pow(nComplex[i].imag(),2));


    for (int i=0; i<10; i++)
        std::cout<<nComplex[i]<<" "<<nModule[i]<<std::endl;
    
    return 0;
}