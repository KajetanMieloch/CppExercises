#include <iostream>
#include <math.h> 

double find_root(double (*f)(double), double a, double b, double tolerance = 1e-10){
    double x = (a + b) / 2;
    while (abs(f(x)) > tolerance) {
        if (f(a) * f(x) < 0) {
            b = x;
        } else {
            a = x;
        }
        x = (a + b) / 2;
    }
    return x;
}

double f1(double x) {
    return cos(x) - x;
}

double f2(double x) {
    return cos(x) - 0.5;
}

int main() {
    std::cout << "cos(x) przedział [0,2] " << find_root(f1, 0,2) << std::endl;
    std::cout << "cos(x) przedział [0,1.5] " << find_root(f2, 0,1.5) << std::endl;
    return 0;
}

