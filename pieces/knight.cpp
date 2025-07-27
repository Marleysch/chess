
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "piece.hpp"
#include "helpers.hpp"
#include "knight.hpp"
using namespace std;
    
    Knight::Knight(string incolor, char rank, int row) : Piece(incolor,rank,row){
        calc_possible_squares();
        board[the_maggie_function(row)- 1][letter_to_number(rank) - 1] = this;
    };

    string Knight::toString() const{
        return "Kn";
    }

    pair<char,int>& Knight::get_curr_square(){
        return curr_square;
    }

    vector<pair<char,int>>& Knight::get_possible_squares(){
        return possible_squares;
    }

    void Knight::calc_possible_squares(){
        possible_squares.clear();
        pair<int,int> array_square = {letter_to_number(curr_square.first), the_maggie_function(curr_square.second)};
        pair<int,int> square = {letter_to_number(curr_square.first), (curr_square.second)};


        for (int i=0; i<2; i++){
            int first;
            int second;
            for (int j=0; j<4; j++){
                if (i == 0){first=2;second=1;}else{first=1;second=2;}
                if (j == 0)
                    if (0 < square.first+first && square.first+first < 9 && 0 < square.second+second && square.second < 9 && board[array_square.second-1][array_square.first-1] == nullptr)
                        possible_squares.push_back({number_to_letter(square.first+first), square.second+second});
                if (j == 1)
                    if (0 < square.first+first && square.first+first < 9 && 0 < square.second-second && square.second-second < 9 && board[array_square.second-1][square.first-1] == nullptr)
                        possible_squares.push_back({number_to_letter(square.first+first), square.second-second});
                if (j == 2)
                    if (0 < square.first-first && square.first-first < 9 && 0 < square.second+second && square.second+second < 9 && board[array_square.second-1][square.first-1] == nullptr)
                        possible_squares.push_back({number_to_letter(square.first-first), square.second+second});
                if (j == 3)
                    if (0 < square.first-first && square.first-first < 9 && 0 < square.second-second && square.second-second < 9 && board[array_square.second-1][square.first-1] == nullptr)
                        possible_squares.push_back({number_to_letter(square.first-first), square.second-second});
            }
        }
    };

 