#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "piece.hpp"
#include "helpers.hpp"
#include "pawn.hpp"
using namespace std;

Pawn::Pawn(string incolor, char rank, int row) : Piece(incolor,rank,row){};

string Pawn::toString() const{
    return "pawn";
}

pair<char,int>& Pawn::get_curr_square(){
    return curr_square;
}

vector<pair<char,int>>& Pawn::get_possible_squares(){
    return possible_squares;
}

void Pawn::calc_possible_squares(){
    possible_squares.clear();
    if (color == "W"){
        if (board[the_maggie_function(curr_square.second + 1) - 1][letter_to_number(curr_square.first) - 1] == nullptr){
            possible_squares.push_back({curr_square.first, curr_square.second  + 1});
            if (!has_moved && board[the_maggie_function(curr_square.second + 2) - 1][letter_to_number(curr_square.first) - 1] == nullptr){
                possible_squares.push_back({curr_square.first, curr_square.second + 2});
            }
        }
        if (board[the_maggie_function(curr_square.second + 1) - 1][letter_to_number(curr_square.first + 1) - 1] != nullptr){
            if (board[the_maggie_function(curr_square.second + 1) - 1][letter_to_number(curr_square.first + 1) - 1]->color == "B"){
                possible_squares.push_back({number_to_letter(letter_to_number(curr_square.first) + 1), curr_square.second + 1});
            }
        }
        if (board[the_maggie_function(curr_square.second + 1) - 1][letter_to_number(curr_square.first - 1) - 1] != nullptr){
            if (board[the_maggie_function(curr_square.second + 1) - 1][letter_to_number(curr_square.first - 1) - 1]->color == "B"){
                possible_squares.push_back({number_to_letter(letter_to_number(curr_square.first) - 1), curr_square.second + 1});
            }
        }
    }

    if (color == "B"){
        if (board[the_maggie_function(curr_square.second - 1) - 1][letter_to_number(curr_square.first) - 1] == nullptr){
            possible_squares.push_back({curr_square.first, curr_square.second - 1});
            if (!has_moved && board[the_maggie_function(curr_square.second - 2) - 1][letter_to_number(curr_square.first) - 1] == nullptr){
                possible_squares.push_back({curr_square.first, curr_square.second - 2});
            }
        }
        if (board[the_maggie_function(curr_square.second - 1) - 1][letter_to_number(curr_square.first + 1) - 1] != nullptr){
            if (board[the_maggie_function(curr_square.second - 1) - 1][letter_to_number(curr_square.first + 1) - 1]->color == "W"){
                possible_squares.push_back({number_to_letter(letter_to_number(curr_square.first) + 1), curr_square.second - 1});
            }
        }
        if (board[the_maggie_function(curr_square.second - 1) - 1][letter_to_number(curr_square.first - 1) - 1] != nullptr){
            if (board[the_maggie_function(curr_square.second - 1) - 1][letter_to_number(curr_square.first - 1) - 1]->color == "W"){
                possible_squares.push_back({number_to_letter(letter_to_number(curr_square.first) - 1), curr_square.second - 1});
            }
        }
    }
};

