#include <iostream>
#include <string>
#include <vector>
#include "mat.hpp"

constexpr int FIRST_CHAR=33;
constexpr int LAST_CHAR=126;

using namespace std;

bool check_exceptions(int cols, int rows, char first, char second){
    if(cols <= 0 || rows <=0){
        throw invalid_argument("The number of rows and the number of columns must be positive");
        return false;
    } 
    if(cols%2 == 0 || rows%2 == 0){
        throw invalid_argument("The number of rows and the number of columns must be odd");
        return false;
    }
    if(first == ' ' || first == '\n' || first == '\t' || second == ' ' || second == '\n' || second == '\t'){
        throw invalid_argument("The symbols must not be empty symbols");
        return false;
    }
    if((int)first < FIRST_CHAR || (int)first > LAST_CHAR || (int)second < FIRST_CHAR || (int)second > LAST_CHAR){
        throw invalid_argument("The symbols must be printable");
        return false;
    }
    return true;
}

namespace ariel{
    string mat(int cols, int rows, char first, char second){
        int i = 0;
        int j=0;
        char sym = first;
        string res;
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
        for(i = 0; i < rows; i++){ //turn the 2D vector into string
            for(j = 0; j < cols; j++){
                res += vec[i][j];
            }
            res += "\n";
        }
        return (res);
    }
};