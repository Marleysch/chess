#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "piece.hpp"
#include "helpers.hpp"
using namespace std;

Piece * board[8][8];

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

int the_maggie_function(int number){
    if (number == 1)
        return 8;
    else if (number == 2)
        return 7;
    else if (number == 3)
        return 6;
    else if (number == 4)
        return 5;
    else if (number == 5)
        return 4;
    else if (number == 6)
        return 3;
    else if (number == 7)
        return 2;
    else
        return 1;
}

bool check_for_check(Piece * king){
    for (auto& row : board){
        for(auto& space : row){
            if (space != nullptr && space->color != king->color){
                for (auto& possible_square : space->possible_squares){
                    if (possible_square == king->curr_square){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

void print_board(){
    int y = 8;
    for (int i=0;i<8;i++){
        cout << y << "  |";
        for (int j=0;j<8;j++){
            if (board[i][j] == nullptr)
                cout << left << setw(4) << "XXX";
            else{
                ostringstream oss;
                oss << *board[i][j];
                string squarestring = oss.str();
                cout << left << setw(4) << squarestring;
            }
        }
        cout << endl;
        y -= 1;
    }
    cout << "   -------------------------------" << endl;
    cout << "    ";
    for (int i = 1;i < 9; i++){
        cout << left << setw(4) << number_to_letter(i);
    }
    cout << endl;
}

