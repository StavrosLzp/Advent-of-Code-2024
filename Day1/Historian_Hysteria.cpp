
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    vector<int> L,R;

    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) { 
        std::cout << line << std::endl; 
    }



    
}

