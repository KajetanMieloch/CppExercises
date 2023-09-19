#include <iostream>
#include <vector>
#include <algorithm>

struct Sortuj {
    bool operator()(int& a, int& b) const {
        return a % 10 < b % 10;
    }
};

int main() {

    //Podpunkt 1

    std::vector<int> v = {1, 5, 16, 12, 35, 6, 13, 45, 6, 8};

    std::sort(v.begin(), v.end(), Sortuj());

    for (auto x : v) {
        std::cout << x << " ";
    }

    std::cout << std::endl;

    //Podpunkt 2

    std::sort(v.begin(), v.end(), [](int a, int b) {
        return (a % 10) < (b % 10);
    });
    
    // wyświetlenie posortowanych elementów
    for (auto x : v) {
        std::cout << x << " ";
    }

    return 0;
}