#include <iostream>
#include "mat.hpp"

using namespace std;

int main(){
    while (true){
        int cols = 0, rows = 0;
        char first = 'a', second = 'b', choice = 'A';
        cout<<"To make a mat please press 'A', to quit press 'B'"<<endl;
        if(choice == 'A'){
            cout<<"enter two numbers and two symbols for the mat (seperate them using space)"<<endl;
            cin>>cols>>rows>>first>>second;
            ariel::mat(cols, rows, first, second);
        } else {
            return 0;
        }
    }
    return 0;
}