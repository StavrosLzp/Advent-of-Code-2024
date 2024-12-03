#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;


int checkline(vector<int> Line){
    int increasing = 0, decreasing = 0;

    for (size_t i = 0 ; i < Line.size() - 1; i++){
        if (Line[i] <= Line[i+1]) increasing = 1;
        if (Line[i] >= Line[i+1]) decreasing = 1; 

        if (abs(Line[i+1] - Line[i]) > 3){
            increasing = 1;
            decreasing = 1;
        }
    }

    if ( (increasing == 1 and decreasing == 0) or (increasing == 0 and decreasing == 1) )
        return 1;
    else {
        return 0;
    }
}


int main() {
    /* ------------ ------------ Part 1 ------------ ------------  */
    int result = 0;
    string line;
    int previous, current;
    int increasing, decreasing = 0;

    // Read file into internal stream buffer to later itarate through each line
    ifstream file("input.txt");
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Process each line
    while (getline(file, line)) { 
        istringstream iss(line);

        iss >> previous;
        while (iss.eof() ==0){
            iss >> current;
            if (current >= previous) increasing = 1;
            if (current <= previous) decreasing = 1; 

            if (abs(current - previous) > 3){
                increasing = 1;
                decreasing = 1;
            }
            previous = current;
        }
        
        if ( (increasing == 1 and decreasing == 0) \
            or (increasing == 0 and decreasing == 1) )
                result +=1;
        
        increasing = 0;
        decreasing = 0;

    }
    
    cout << "Part 1 : The Safety Score is " << result << endl; 


    /* ------------ ------------ Part 2 ------------ ------------  */
    result = 0;
    int tempResult = 0;
    vector<int> LineV, tempV;

    ifstream file2("input.txt");
    while (getline(file2, line)) { 
        istringstream iss(line);

        while (iss.eof() ==0){
            iss >> current;
            LineV.push_back(current);
        }


        if (checkline(LineV) == 1){
            tempResult = 1;

        }
        else {
            for (int i = 0 ; i < LineV.size() ; i++){
                copy(LineV.begin(), LineV.end(), back_inserter(tempV));
                tempV.erase(tempV.begin() + i);
                // for (auto j : tempV) cout << j << " ";
                // cout << endl;
                if (checkline(tempV) == 1) tempResult = 1;
                tempV.clear();
            }
        }
        result += tempResult;
        tempResult = 0;
        LineV.clear();
    }
    
    cout << "Part 2 : The Safety Score is " << result << endl; 


    
}

