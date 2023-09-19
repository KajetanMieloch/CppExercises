#include <iostream>

int suma(const int tab[], unsigned size){
    int result = 0;
    for(int i = 0; i < size; i++){
        result += tab[i];
    }
    return result;
}
void suma(const int tab[], unsigned size, int* result){
    int suma = 0;
    for(int i = 0; i < size; i++){
        suma += tab[i];
    }
    *result = suma;
}
void pisz(const int* tab, size_t size, std::ostream * out){
    for(int i = 0; i < size; i++){
        *out<<tab[i]<<std::endl;
    }
}
void iota(int tab[], unsigned size){
    for(int i = 0; i < size; i++){
        tab[i] = i;
    }
}
void reverse(int* tab, size_t size){
    int* tab2 = new int[size];
    for(int i = 0; i < size; i++){
        tab2[i] = tab[size - i - 1];
    }
    for(int i = 0; i < size; i++){
        tab[i] = tab2[i];
    }
}
int dot_product(const int* tab1, const int* tab2, size_t size){
    int result = 0;
    for(int i = 0; i < size; i++){
        result += tab1[i] * tab2[i];
    }
    return result;
}

int main(){

    std::cout << "Zadanie A" << std::endl;

    int tab[] = {1,2,3,4,5};
    std::cout<<suma(tab, 5)<<std::endl;

    std::cout << "Zadanie B" << std::endl;

    int* result = new int;
    suma(tab, 5, result);
    std::cout<<*result<<std::endl;

    std::cout << "Zadanie C" << std::endl;

    pisz(tab, 5, &std::cout);



    std::cout << "Zadanie D" << std::endl;

    int tabD[5] = {};

    iota(tabD, 5);
    for(int i = 0; i < 5; i++){
        std::cout<<tabD[i]<<std::endl;
    }

    std::cout << "Zadanie E" << std::endl;

    int tabR[5] = {1,4,7,8,12};
    reverse(tabR, 5);
    for(int i = 0; i < 5; i++){
        std::cout<<tabR[i]<<std::endl;
    }

    std::cout << "Zadanie F" << std::endl;

    int tab1[3] = {1,2,3};
    int tab2[3] = {3,21,1};
    std::cout<<dot_product(tab1, tab2, 3)<<std::endl;

return 0;
}