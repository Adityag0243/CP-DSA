#include <iostream>
#include <fstream>

int main() {
    char c = '2';
    int l = 1000;

    // std::cout << "Enter character: ";
    // std::cin >> c;

    // std::cout << "Enter length: ";
    // std::cin >> l;

    std::ofstream outFile("inp.txt");
    if (!outFile) {
        std::cerr << "Failed to create file." << std::endl;
        return 1;
    }
    outFile << 1;
    outFile << '\n';

    for (int i = 0; i < l; ++i) {
        outFile << c;
    }

    outFile.close();
    std::cout << "File 'inp.txt' created with " << l << " characters of '" << c << "'." << std::endl;
    return 0;
}
