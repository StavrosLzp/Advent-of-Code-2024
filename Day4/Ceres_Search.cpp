#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

string pat = "XMAS";
string patX = "MAS";

int checkChar(vector<vector<char>> input, int x, int y) {
    int tempResult = 0;
    
    int i = 0;
    // Horizontal Checks
    for (i = 0 ; i < 4 ; i++) {
        if (x + i >= input[0].size()) break;
        if (input[y][x+i] != pat[i]) break;
    }
    if (i == 4) tempResult += 1;
    for (i = 0 ; i < 4 ; i++) {
        if (x - i < 0) break;
        if (input[y][x-i] != pat[i]) break;
    }
    if (i == 4) tempResult += 1;
    for (i = 0 ; i < 4 ; i++) {
        if (y + i >= input.size()) break;
        if (input[y+i][x] != pat[i]) break;
    }
    if (i == 4) tempResult += 1;
    for (i = 0 ; i < 4 ; i++) {
        if (y - i < 0) break;
        if (input[y-i][x] != pat[i]) break;
    }
    if (i == 4) tempResult += 1;


    //Diagonal checks
    for (i = 0 ; i < 4 ; i++) {
        if ((x + i >= input[0].size()) or (y + i >= input.size() )) break;
        if (input[y + i][x + i] != pat[i]) break;
    }
    if (i == 4) tempResult += 1;
    for (i = 0 ; i < 4 ; i++) {
        if (x + i >= input[0].size() or y - i < 0) break;
        if (input[y - i][x + i] != pat[i]) break;
    }
    if (i == 4) tempResult += 1;
    for (i = 0 ; i < 4 ; i++) {
        if (x - i < 0 or y + i >= input.size()) break;
        if (input[y + i][x - i] != pat[i]) break;
    }
    if (i == 4) tempResult += 1;
    for (i = 0 ; i < 4 ; i++) {
        if (x - i < 0 or y - i < 0) break;
        if (input[y - i][x - i] != pat[i]) break;
    }
    if (i == 4) tempResult += 1;

    //  cout << tempResult << " ";
    return tempResult;
}

int checkCharX(vector<vector<char>> input, int x, int y) {
    int tempResult = 0;
    //  M S
    //   A
    //  M S
    if (input[y][x] == patX[1]){
        if (input[y+1][x-1] == patX[0] and input[y+1][x+1] == patX[2] \ 
        and input[y-1][x-1] == patX[0] and input[y-1][x+1] == patX[2]){
            tempResult = 1;
        }
        if (input[y+1][x-1] == patX[2] and input[y+1][x+1] == patX[0] \ 
        and input[y-1][x-1] == patX[2] and input[y-1][x+1] == patX[0]){
            tempResult = 1;
        }
        if (input[y+1][x-1] == patX[0] and input[y+1][x+1] == patX[0] \ 
        and input[y-1][x-1] == patX[2] and input[y-1][x+1] == patX[2]){
            tempResult = 1;
        }
        if (input[y+1][x-1] == patX[2] and input[y+1][x+1] == patX[2] \ 
        and input[y-1][x-1] == patX[0] and input[y-1][x+1] == patX[0]){
            tempResult = 1;
        }
    }
    return tempResult;
}




int main() {
    /* ------------ ------------ Part 1 ------------ ------------  */
    int result = 0;
    string line;
    vector<vector<char>> input;

    // for (int i = 0 ; i < 3 ; i++) 


    string filename = "input.txt";
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    while (getline(inputFile, line)) {
        vector<char> row;
        
        for (char c : line) {
            row.push_back(c);
        }
        input.push_back(row);
    }

    for (int y = 0 ; y < input.size() ; y++) {
        for (int x = 0 ; x < input[0].size() ; x++) {
            result += checkChar(input, x, y);
        }
    }

    cout << "Part 1 : Xmas appears : " << result << " times" << endl;


    /* ------------ ------------ Part 2 ------------ ------------  */

    result = 0;

    for (int y = 1 ; y < input.size()-1 ; y++) {
        for (int x = 1 ; x < input[0].size()-1 ; x++) {
            result += checkCharX(input, x, y);
        }
    }

    cout << "Part 2 : Total multiplication result is " << result << endl;
}

