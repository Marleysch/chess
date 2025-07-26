
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "piece.hpp"
#include "helpers.hpp"
#include "rook.hpp"
using namespace std;
    
    Rook::Rook(string incolor, char rank, int row) : Piece(incolor,rank,row){
        calc_possible_squares();
        board[the_maggie_function(row)- 1][letter_to_number(rank) - 1] = this;
    };

    string Rook::toString() const{
        return "Rk";
    }

    pair<char,int>& Rook::get_curr_square(){
        return curr_square;
    }

    vector<pair<char,int>>& Rook::get_possible_squares(){
        return possible_squares;
    }

    void Rook::calc_possible_squares(){
    possible_squares.clear();
    pair<int,int> num_square = {letter_to_number(curr_square.first), curr_square.second};
    
    pair<int,int> num_square_temp = {num_square.first + 1, num_square.second};
    while (num_square_temp.first < 9 && num_square_temp.second < 9){
        if (board[num_square_temp.second - 1][num_square_temp.first - 1] == nullptr){
            possible_squares.push_back({number_to_letter(num_square_temp.first),num_square_temp.second});
        }
        else{
            break;
        }
        num_square_temp.first += 1;
    }

    num_square_temp = {num_square.first, num_square.second + 1};
    while (num_square_temp.first < 9 && num_square_temp.second > 0){
        if (board[num_square_temp.second - 1][num_square_temp.first - 1] == nullptr){
            possible_squares.push_back({number_to_letter(num_square_temp.first),num_square_temp.second});
        }
        else{
            break;
        }
        num_square_temp.second += 1;
    }

    num_square_temp = {num_square.first - 1, num_square.second};
    while (num_square_temp.first < 9 && num_square_temp.second > 0){
        if (board[num_square_temp.second - 1][num_square_temp.first - 1] == nullptr){
            possible_squares.push_back({number_to_letter(num_square_temp.first),num_square_temp.second});
        }
        else{
            break;
        }
        num_square_temp.first -= 1;
    }

    num_square_temp = {num_square.first, num_square.second - 1};
    while (num_square_temp.first < 9 && num_square_temp.second > 0){
        if (board[num_square_temp.second - 1][num_square_temp.first - 1] == nullptr){
            possible_squares.push_back({number_to_letter(num_square_temp.first),num_square_temp.second});
        }
        else{
            break;
        }
        num_square_temp.second -= 1;
    }
    };

 