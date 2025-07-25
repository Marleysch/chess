#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include "piece.hpp"
#include "helpers.hpp"
using namespace std;


Piece::Piece(string incolor, char rank, int row) : color(incolor),curr_square({rank,row}){};

void Piece::move(pair<char, int> square){
    auto& curr_square_child = get_curr_square();
    auto& possible_squares_child = get_possible_squares();
 
    int possible_squares_size = possible_squares_child.size(); 
    if (check_membership(square, possible_squares_child, possible_squares_size)){
        board[the_maggie_function(curr_square_child.second)-1][letter_to_number(curr_square_child.first)-1] = nullptr;
        curr_square_child = square;
        board[the_maggie_function(square.second)-1][letter_to_number(square.first)-1] = this;
        calc_possible_squares();
    }
    else
        cout << "you cant go there" << endl;
};

void Piece::calc_possible_squares(){};

std::ostream& operator<<(std::ostream& os, const Piece& piece){
    os << piece.color;
    os << piece.toString();
    return os;
};
