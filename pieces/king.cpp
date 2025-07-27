#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <typeinfo>
#include "piece.hpp"
#include "helpers.hpp"
#include "king.hpp"
#include "rook.hpp"
using namespace std;


King::King(string incolor, char rank, int row) : Piece(incolor,rank,row){
    in_check = 0;
    calc_possible_squares();
    board[the_maggie_function(row)- 1][letter_to_number(rank) - 1] = this;
};

string King::toString() const{
    return "Kg";
};

pair<char,int>& King::get_curr_square(){
    return curr_square;
}

vector<pair<char,int>>& King::get_possible_squares(){
    return possible_squares;
}

void King::calc_possible_squares(){
    possible_squares.clear();
    pair<char,int> curr_square_holder = curr_square;
    pair<int,int> square = {letter_to_number(curr_square.first), curr_square.second};

    if (!has_moved && !in_check){
        square.first += 1;
        while (square.first != 8){
            if (board[the_maggie_function(square.second) - 1][square.first - 1] != nullptr){
                break;
            }
            square.first += 1;
        }
        if (square.first == 8){
            if (Rook* r = dynamic_cast<Rook*>(board[the_maggie_function(square.second) - 1][square.first - 1])){
                if (!board[the_maggie_function(square.second) - 1][square.first - 1]->has_moved){
                    curr_square = {number_to_letter(letter_to_number(curr_square.first) + 2),curr_square.second};
                    if (!check_for_check(this)){
                        possible_squares.push_back(curr_square);
                        curr_square = curr_square_holder;
                    }
            
                }
            }
        }   

        square = {letter_to_number(curr_square.first), curr_square.second};
        square.first -= 1;
        while (square.first != 1){
            if (board[the_maggie_function(square.second) - 1][square.first - 1] != nullptr){
                break;
            }
            square.first -= 1;
        }
        if (square.first == 1){
            if (Rook* r = dynamic_cast<Rook*>(board[the_maggie_function(square.second) - 1][square.first - 1])){
                if (!board[the_maggie_function(square.second) - 1][square.first - 1]->has_moved){
                    curr_square = {number_to_letter(letter_to_number(curr_square.first) - 2),curr_square.second};
                    if (!check_for_check(this)){
                        possible_squares.push_back(curr_square);
                        curr_square = curr_square_holder;
                    }
                }
            }
        }
    }

    square = {letter_to_number(curr_square.first), curr_square.second};
    curr_square.first = number_to_letter(letter_to_number(curr_square.first + 1));
    if (board[the_maggie_function(square.second)][square.first] == nullptr && !check_for_check(this)){
        possible_squares.push_back(curr_square);
        curr_square = curr_square_holder;
    }
    curr_square.first = number_to_letter(letter_to_number(curr_square.first - 1));
    if (board[the_maggie_function(square.second)][square.first - 2] == nullptr && !check_for_check(this)){
        possible_squares.push_back(curr_square);
        curr_square = curr_square_holder;
    }
    curr_square.second = number_to_letter(letter_to_number(curr_square.second + 1));
    if (board[the_maggie_function(square.second)][square.first] == nullptr && !check_for_check(this)){
        possible_squares.push_back(curr_square);
        curr_square = curr_square_holder;
    }
    curr_square.second = number_to_letter(letter_to_number(curr_square.second - 1));
    if (board[the_maggie_function(square.second) - 2][square.first] == nullptr && !check_for_check(this)){
        possible_squares.push_back(curr_square);
        curr_square = curr_square_holder;
    }
    curr_square.first = number_to_letter(letter_to_number(curr_square.first + 1));
    curr_square.second = number_to_letter(letter_to_number(curr_square.second + 1));
    if (board[the_maggie_function(square.second)][square.first] == nullptr && !check_for_check(this)){
        possible_squares.push_back(curr_square);
        curr_square = curr_square_holder;
    }
    curr_square.first = number_to_letter(letter_to_number(curr_square.first + 1));
    curr_square.second = number_to_letter(letter_to_number(curr_square.second - 1));
    if (board[the_maggie_function(square.second) - 2][square.first] == nullptr && !check_for_check(this)){
        possible_squares.push_back(curr_square);
        curr_square = curr_square_holder;
    }
    curr_square.first = number_to_letter(letter_to_number(curr_square.first - 1));
    curr_square.second = number_to_letter(letter_to_number(curr_square.second + 1));
    if (board[the_maggie_function(square.second)][square.first - 2] == nullptr && !check_for_check(this)){
        possible_squares.push_back(curr_square);
        curr_square = curr_square_holder;
    }
    curr_square.first = number_to_letter(letter_to_number(curr_square.first - 1));
    curr_square.second = number_to_letter(letter_to_number(curr_square.second - 1));
    if (board[the_maggie_function(square.second) - 2][square.first - 2] == nullptr && !check_for_check(this)){
        possible_squares.push_back(curr_square);
        curr_square = curr_square_holder;
    }
}



