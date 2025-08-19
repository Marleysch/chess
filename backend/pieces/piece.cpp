#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include "piece.hpp"
#include "helpers.hpp"
#include "king.hpp"
#include "pawn.hpp"
using namespace std;


Piece::Piece(string incolor, char rank, int row) : color(incolor),curr_square({rank,row}){
    has_moved = 0;
};

bool Piece::move(pair<char, int> square){
    auto& curr_square_child = get_curr_square();
    auto& possible_squares_child = get_possible_squares();
 
    int possible_squares_size = possible_squares_child.size(); 
    if (check_membership(square, possible_squares_child, possible_squares_size)){
        board[the_maggie_function(curr_square_child.second)-1][letter_to_number(curr_square_child.first)-1] = nullptr;

        //Castling
        if (dynamic_cast<King*>(this)){
            if (abs(letter_to_number(curr_square_child.first) - letter_to_number(square.first)) > 1){
                if (letter_to_number(square.first) > 5){
                    Piece * temp_rook = board[the_maggie_function(square.second) - 1][7];
                    board[the_maggie_function(square.second) - 1][7] = nullptr;
                    board[the_maggie_function(square.second) - 1][letter_to_number(square.first) - 2] = temp_rook;
                    temp_rook->curr_square = {number_to_letter(letter_to_number(square.first) - 1), square.second};
                }
                else{
                    Piece * temp_rook = board[the_maggie_function(square.second) - 1][0];
                    board[the_maggie_function(square.second) - 1][0] = nullptr;
                    board[the_maggie_function(square.second) - 1][letter_to_number(square.first)] = temp_rook;
                    temp_rook->curr_square = {number_to_letter(letter_to_number(square.first) + 1), square.second};
                }
            }
        }

        //En Passant
        if (dynamic_cast<Pawn*>(this)){
            //actual en passant
            if (abs(letter_to_number(curr_square_child.first) - letter_to_number(square.first)) != 0){
                if (color == "W"){
                    delete board[the_maggie_function(square.second - 1) - 1][letter_to_number(square.first) - 1];
                    board[the_maggie_function(square.second - 1) - 1][letter_to_number(square.first) - 1] = nullptr;
                }
                else{
                    delete board[the_maggie_function(square.second + 1) - 1][letter_to_number(square.first) - 1];
                    board[the_maggie_function(square.second + 1) - 1][letter_to_number(square.first) - 1] = nullptr;
                }
            }
            
            //add en passant to adjacent pawns possible squares
            else if (abs(curr_square_child.second - square.second) > 1){
                if (Pawn * p = dynamic_cast<Pawn*>(board[the_maggie_function(square.second) - 1][letter_to_number(square.first) - 1 - 1])){
                    if (p->color != color){
                        if (color == "W"){
                            p->possible_squares.push_back({square.first, square.second - 1});
                        }
                        else{
                            p->possible_squares.push_back({square.first, square.second + 1});
                        } 
                    }
                }
            }
        }

        //moving
        curr_square_child = square;
        has_moved = 1;
        if (board[the_maggie_function(square.second)-1][letter_to_number(square.first)-1] != nullptr){
            delete board[the_maggie_function(square.second)-1][letter_to_number(square.first)-1];
        }
        board[the_maggie_function(square.second)-1][letter_to_number(square.first)-1] = this;

        for (auto& row : board){
            for(auto& space : row){
                if (space != nullptr){
                    space->calc_possible_squares();
                }
                if (King * k = dynamic_cast<King*>(space)){
                    k->in_check = check_for_check(space);
                }
            }
        }
        return 1;
    }      
    else{
        return 0;
    }
};

void Piece::calc_possible_squares(){};

std::ostream& operator<<(std::ostream& os, const Piece& piece){
    os << piece.color;
    os << piece.toString();
    return os;
};
