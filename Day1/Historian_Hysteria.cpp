
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    vector<int> L,R;
    int result = 0;

    // Read file into internal stream buffer to later itarate through each line
    ifstream file("input.txt");
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Process each line to create the L and R list
    string line;
    int first, last, len=0;
    while (getline(file, line)) { 
        istringstream iss(line);
        iss >> first >> last;
        L.push_back(first);
        R.push_back(last);
        len++;
    }

    // Sort Lists and calculate result of the first part
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    for (int i = len; i > 0 ; i--){
        result += abs(L[i] - R[i]);
    }

    cout << "Part 1 : Total Distance is " << result << endl; 

    /* ------------ ------------ Part 2 ------------ ------------  */
    result = 0;

    // iterate through L, count the pperacnces of L[i] in R
    // add the amount * the elemnt L[i] to the result
    for (int i = 0; i < len ; i++){
        result +=  count(R.begin(), R.end(), L[i]) * L[i];
    }

    cout << "Part 2 : The Similarity Score is " << result << endl; 
}

