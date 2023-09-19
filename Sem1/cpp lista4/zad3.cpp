#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::vector<std::string> args(argv, argv + argc);
    if (std::find(args.begin(), args.end(), "--help") != args.end() or std::find(args.begin(), args.end(), "-h") != args.end() or argc == 1) {
        std::cout << "sumuj.exe wyświetla sumę argumentów wiersza poleceń" << std::endl;
        std::cout << "Usage:" << std::endl;
        std::cout << "sumuj.exe arg1, arg2,... , argn" << std::endl;
    } else {
        double sum = 0;
        for (int i = 1; i < argc; i++) {
            std::stringstream ss;
            ss << argv[i];
            double arg;
            ss >> arg;
            sum += arg;
        }
        std::cout << sum << std::endl;
    }
    return 0;
}