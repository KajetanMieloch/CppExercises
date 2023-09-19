#include <iostream>
#include <vector>

double operator*(const std::vector<double>& v1, const std::vector<double>& v2) {
    double result = 0;
    for (int i = 0; i < v1.size(); i++) {
        result += v1[i] * v2[i];
    }
    return result;
}

int main() {
    std::vector<double> v1 = {1.4, 2, 3};
    std::vector<double> v2 = {4, 5, 6};
    std::cout << v1 * v2 << std::endl;
    return 0;
}