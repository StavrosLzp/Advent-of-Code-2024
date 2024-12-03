#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;




int main() {
    /* ------------ ------------ Part 1 ------------ ------------  */
    int result = 0;
    int x = 0 ,y = 0;
    
    string filename = "input.txt";
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    string input((istreambuf_iterator<char>(inputFile)),istreambuf_iterator<char>());

    inputFile.close();

    // Regular expression to match "mul(X,Y)" where X and Y are integers
    regex mulRegex(R"(mul\((-?\d+),\s*(-?\d+)\))");

    // Use regex_iterator to find all matches
    auto matchesBegin = sregex_iterator(input.begin(), input.end(), mulRegex);
    auto matchesEnd = sregex_iterator();

    

    // Iterate through all matches
    for (sregex_iterator it = matchesBegin; it != matchesEnd; ++it) {
        smatch match = *it;

        // Extract the integers X and Y
        x = stoi(match[1].str());
        y = stoi(match[2].str());

        result += x*y;

    }

    // Print the total number of matches
    cout << "Part 1 : Total multiplication result is " << result << endl;


    /* ------------ ------------ Part 2 ------------ ------------  */
    result = 0;
    int doMultiply = 1;

    // Regular expression to match "mul(X,Y)", "do()", and "don't()"
    regex pattern(R"((mul\((-?\d+),\s*(-?\d+)\))|(do\(\))|(don't\(\)))");

    auto matchesBeginPart2 = sregex_iterator(input.begin(), input.end(), pattern);
    auto matchesEndPart2 = sregex_iterator();
     
    // Iterate through all matches
    for (sregex_iterator it = matchesBeginPart2; it != matchesEndPart2; ++it) {
        smatch match = *it;

        
        if(match[4].matched) doMultiply = 1;
        else if (match[5].matched) doMultiply = 0;
        else if (match[1].matched) {
            x = stoi(match[2].str());
            y = stoi(match[3].str());
            if (doMultiply == 1) result += x*y;
        }

    }

    cout << "Part 2 : Total multiplication result is " << result << endl;
}

