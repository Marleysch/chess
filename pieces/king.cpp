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
    cout << curr_square.first << curr_square.second << endl;
    pair<char,int> curr_square_holder = curr_square;
    pair<int,int> num_square = {letter_to_number(curr_square.first), the_maggie_function(curr_square.second)};

    if (!has_moved && !in_check){
        num_square.first += 1;
        while (num_square.first != 8){
            if (board[num_square.second - 1][num_square.first - 1] != nullptr){
                break;
            }
            num_square.first += 1;
        }
        if (num_square.first == 8){
            if (Rook* r = dynamic_cast<Rook*>(board[num_square.second - 1][num_square.first - 1])){
                if (!board[num_square.second - 1][num_square.first - 1]->has_moved){
                    pair<char,int> rook_curr_square_holder = r->curr_square;
                    r->curr_square = {curr_square.first + 1, curr_square.second};
                    curr_square = {number_to_letter(letter_to_number(curr_square.first) + 2),curr_square.second};
                    if (!check_for_check(this)){
                        possible_squares.push_back(curr_square);
                    }
                    curr_square = curr_square_holder;
                    r->curr_square = rook_curr_square_holder;
                }
            }
        }   

        num_square = {letter_to_number(curr_square.first), the_maggie_function(curr_square.second)};
        num_square.first -= 1;
        while (num_square.first != 1){
            if (board[num_square.second - 1][num_square.first - 1] != nullptr){
                break;
            }
            num_square.first -= 1;
        }
        if (num_square.first == 1){
            if (Rook* r = dynamic_cast<Rook*>(board[num_square.second - 1][num_square.first - 1])){
                if (!board[num_square.second - 1][num_square.first - 1]->has_moved){
                    pair<char,int> rook_curr_square_holder = r->curr_square;
                    r->curr_square = {curr_square.first - 1, curr_square.second};
                    curr_square = {number_to_letter(letter_to_number(curr_square.first) - 2),curr_square.second};
                    if (!check_for_check(this)){
                        possible_squares.push_back(curr_square);
                    }
                    curr_square = curr_square_holder;
                    r->curr_square = rook_curr_square_holder;
                }
            }
        }
    }

    curr_square.first = number_to_letter(letter_to_number(curr_square.first + 1));
    num_square = {letter_to_number(curr_square.first), the_maggie_function(curr_square.second)};
    if ((board[num_square.second - 1][num_square.first - 1] == nullptr || board[num_square.second - 1][num_square.first - 1]->color != color) && !check_for_check(this) && num_square.first < 9){
        possible_squares.push_back(curr_square);
    }
    curr_square = curr_square_holder;

    curr_square.first = number_to_letter(letter_to_number(curr_square.first - 1));
    num_square = {letter_to_number(curr_square.first), the_maggie_function(curr_square.second)};
    if ((board[num_square.second - 1][num_square.first - 1] == nullptr || board[num_square.second - 1][num_square.first - 1]->color != color) && !check_for_check(this) && num_square.first > 0){
        possible_squares.push_back(curr_square);
    }
    curr_square = curr_square_holder;

    curr_square.second = curr_square.second + 1;
    num_square = {letter_to_number(curr_square.first), the_maggie_function(curr_square.second)};
    if ((board[num_square.second - 1][num_square.first - 1] == nullptr || board[num_square.second - 1][num_square.first - 1]->color != color) && !check_for_check(this) && num_square.second > 0){
        possible_squares.push_back(curr_square);
    }
    curr_square = curr_square_holder;

    curr_square.second = curr_square.second - 1;
    num_square = {letter_to_number(curr_square.first), the_maggie_function(curr_square.second)};
    if ((board[num_square.second - 1][num_square.first - 1] == nullptr || board[num_square.second - 1][num_square.first - 1]->color != color) && !check_for_check(this) && num_square.second < 9){
        possible_squares.push_back(curr_square);
    }
    curr_square = curr_square_holder;

    curr_square.first = number_to_letter(letter_to_number(curr_square.first + 1));
    curr_square.second = curr_square.second + 1;
    num_square = {letter_to_number(curr_square.first), the_maggie_function(curr_square.second)};
    if ((board[num_square.second - 1][num_square.first - 1] == nullptr || board[num_square.second - 1][num_square.first - 1]->color != color) && !check_for_check(this) && num_square.first < 9 && num_square.second > 0){
        possible_squares.push_back(curr_square);
    }
    curr_square = curr_square_holder;

    curr_square.first = number_to_letter(letter_to_number(curr_square.first + 1));
    curr_square.second = curr_square.second - 1;
    num_square = {letter_to_number(curr_square.first), the_maggie_function(curr_square.second)};
    if ((board[num_square.second - 1][num_square.first - 1] == nullptr || board[num_square.second - 1][num_square.first - 1]->color != color) && !check_for_check(this) && num_square.first < 9 && num_square.second < 9){
        possible_squares.push_back(curr_square);
    }
    curr_square = curr_square_holder;

    curr_square.first = number_to_letter(letter_to_number(curr_square.first - 1));
    curr_square.second = curr_square.second + 1;
    num_square = {letter_to_number(curr_square.first), the_maggie_function(curr_square.second)};
    if ((board[num_square.second - 1][num_square.first - 1] == nullptr || board[num_square.second - 1][num_square.first - 1]->color != color) && !check_for_check(this) && num_square.first > 0 && num_square.second > 0){
        possible_squares.push_back(curr_square);
    }
    curr_square = curr_square_holder;

    curr_square.first = number_to_letter(letter_to_number(curr_square.first - 1));
    curr_square.second = curr_square.second - 1;
    num_square = {letter_to_number(curr_square.first), the_maggie_function(curr_square.second)};
    if ((board[num_square.second - 1][num_square.first - 1] == nullptr || board[num_square.second - 1][num_square.first - 1]->color != color) && !check_for_check(this) && num_square.first > 0 && num_square.second < 9){
        possible_squares.push_back(curr_square);
    }
    curr_square = curr_square_holder;
}



