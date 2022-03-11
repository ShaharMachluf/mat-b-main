#include <iostream>
#include <string>
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
    }
    return true;
}

namespace ariel{
    string mat(int cols, int rows, char first, char second){
        bool valid = check_exceptions(cols, rows, first, second);
        return ("ok");
    }
};