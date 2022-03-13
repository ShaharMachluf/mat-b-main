#include <iostream>
#include <string>
#include <vector>
#include "mat.hpp"

using namespace std;

bool check_exceptions(int cols, int rows, char first, char second){
    if(cols <= 0 || rows <=0){
        throw invalid_argument("The number of rows and the number of columns must be positive");
        return false;
    } else if(cols%2 == 0 || rows%2 == 0){
        throw invalid_argument("The number of rows and the number of columns must be odd");
        return false;
    } else if(first == ' ' || first == '\n' || first == '\t' || second == ' ' || second == '\n' || second == '\t'){
        throw invalid_argument("The symbols must not be empty symbols");
        return false;
    } else if(cols < 33 || cols > 126 || rows < 33 || rows > 126){
        throw invalid_argument("The symbols must be printable");
        return false;
    }
    return true;
}

namespace ariel{
    string mat(int cols, int rows, char first, char second){
        int i = 0, j=0;
        char sym = first;
        bool valid = check_exceptions(cols, rows, first, second); //make sure the input is valid
        if(!valid){
            return "";
        }
        vector<vector<char>> vec( rows , vector<char> (cols));
        while(i*2 <= rows && i*2 <= cols){ //go through the 2D vector by "frames" going from the outside in
            if(i%2 == 0){ //choose the current symbol
                sym = first;
            } else{
                sym = second;
            }
            for(j = i; j < cols-i; j++){ //go through the i-th and the rows-i-th row
                vec[i][j] = sym;
                vec[rows-i-1][j] = sym;
            }
            for(j = i; j < rows-i; j++){ //go through the i-th and the cols-i-th column
                vec[j][i] = sym;
                vec[j][cols-i-1] = sym;
            }
            i++;
        }
        if(i%2 == 0){ //choose the current symbol
            sym = first;
        } else{
            sym = second;
        }
        if(i*2+1 == rows){ //there is more columns then rows
            for(j = i; j < cols-i; j++){
                vec[i][j] = sym;
            }
        } else{
            for(j = i; j < rows-i; j++){ //there is more rows then columns 
                vec[j][i] = sym;
            }
        }
        return ("ok");
    }
};