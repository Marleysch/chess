#include <string>
#include <vector>
#include <iostream>
#include "piece.hpp"
#include "helpers.hpp"
using namespace std;


bool check_membership(pair<char, int> item, vector<pair<char,int>> vector, int array_size){
    for (int i=0; i < array_size;i++){
        if (item == vector.at(i)){
            return true;
        }
    } 
    return false;
};

int letter_to_number(char letter){
    if (letter == 'a')
        return 1;
    else if (letter == 'b')
        return 2;
    else if (letter == 'c')
        return 3;
    else if (letter == 'd')
        return 4;
    else if (letter == 'e')
        return 5;
    else if (letter == 'f')
        return 6;
    else if (letter == 'g')
        return 7;
    else
        return 8;
}

char number_to_letter(int number){
    if (number == 1)
        return 'a';
    else if (number == 2)
        return 'b';
    else if (number == 3)
        return 'c';
    else if (number == 4)
        return 'd';
    else if (number == 5)
        return 'e';
    else if (number == 6)
        return 'f';
    else if (number == 7)
        return 'g';
    else
        return 'h';
}

void print_board(Piece* board[8][8]){
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            if (board[i][j] == nullptr)
                cout << "hi";
            else
                cout << *board[i][j];
        }
        cout << endl;
    }
}

