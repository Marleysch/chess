#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "piece.hpp"
#include "helpers.hpp"
#include "bishop.hpp"
using namespace std;


Bishop::Bishop(string incolor, char rank, int row) : Piece(incolor,rank,row){};

string Bishop::toString() const{
    return "Bp";
};

pair<char,int>& Bishop::get_curr_square(){
    return curr_square;
}

vector<pair<char,int>>& Bishop::get_possible_squares(){
    return possible_squares;
}

void Bishop::calc_possible_squares(){
    possible_squares.clear();
    pair<int,int> num_square = {letter_to_number(curr_square.first), curr_square.second};
    pair<int,int> num_square_array = {letter_to_number(curr_square.first), the_maggie_function(curr_square.second)};
    
    pair<int,int> num_square_temp = {num_square.first + 1, num_square.second + 1};
    pair<int,int> num_square_temp_array = {num_square_array.first + 1, num_square_array.second - 1};
    while (num_square_temp.first < 9 && num_square_temp.second < 9){
        if (board[(num_square_temp_array.second) - 1][num_square_temp_array.first - 1] == nullptr){
            possible_squares.push_back({number_to_letter(num_square_temp.first),num_square_temp.second});
        }
        else if (board[(num_square_temp_array.second) - 1][num_square_temp_array.first - 1]->color != color){
            possible_squares.push_back({number_to_letter(num_square_temp.first),num_square_temp.second});
            break;
        }
        else{
            break;
        }
        num_square_temp.first += 1;
        num_square_temp.second += 1;
        num_square_temp_array.first += 1;
        num_square_temp_array.second -= 1;
    }

    num_square_temp = {num_square.first + 1, num_square.second - 1};
    num_square_temp_array = {num_square_array.first + 1, num_square_array.second + 1};
    while (num_square_temp.first < 9 && num_square_temp.second > 0){
        if (board[(num_square_temp_array.second) - 1][num_square_temp_array.first - 1] == nullptr){
            possible_squares.push_back({number_to_letter(num_square_temp.first),num_square_temp.second});
        }
        else if (board[(num_square_temp_array.second) - 1][num_square_temp_array.first - 1]->color != color){
            possible_squares.push_back({number_to_letter(num_square_temp.first),num_square_temp.second});
            break;
        }
        else{
            break;
        }
        num_square_temp.first += 1;
        num_square_temp.second -= 1;
        num_square_temp_array.first += 1;
        num_square_temp_array.second += 1;
    }

    num_square_temp = {num_square.first - 1, num_square.second + 1};
    num_square_temp_array = {num_square_array.first - 1, num_square_array.second - 1};
    while (num_square_temp.first > 0 && num_square_temp.second < 9){
        if (board[(num_square_temp_array.second) - 1][num_square_temp_array.first - 1] == nullptr){
            possible_squares.push_back({number_to_letter(num_square_temp.first),num_square_temp.second});
        }
        else if (board[(num_square_temp_array.second) - 1][num_square_temp_array.first - 1]->color != color){
            possible_squares.push_back({number_to_letter(num_square_temp.first),num_square_temp.second});
            break;
        }
        else{
            break;
        }
        num_square_temp.first -= 1;
        num_square_temp.second += 1;
        num_square_temp_array.first -= 1;
        num_square_temp_array.second -= 1;
    }

    num_square_temp = {num_square.first - 1, num_square.second - 1};
    num_square_temp_array = {num_square_array.first - 1, num_square_array.second + 1};
    while (num_square_temp.first > 0 && num_square_temp.second > 0){
        if (board[(num_square_temp_array.second) - 1][num_square_temp_array.first - 1] == nullptr){
            possible_squares.push_back({number_to_letter(num_square_temp.first),num_square_temp.second});
        }
        else if (board[(num_square_temp_array.second) - 1][num_square_temp_array.first - 1]->color != color){
            possible_squares.push_back({number_to_letter(num_square_temp.first),num_square_temp.second});
            break;
        }
        else{
            break;
        }
        num_square_temp.first -= 1;
        num_square_temp.second -= 1;
        num_square_temp_array.first -= 1;
        num_square_temp_array.second += 1;
    }
};



