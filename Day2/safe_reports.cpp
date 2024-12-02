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

    // Process each line
    string line;
    int previous, current;
    int increasing, decreasing = 0;
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
    
    cout << result << endl;    


    
}

