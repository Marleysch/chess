#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "piece.hpp"
#include "helpers.hpp"
#include "king.hpp"
using namespace std;


King::King(string incolor, char rank, int row) : Piece(incolor,rank,row){
    calc_possible_squares();
};

string King::toString() const{
    return "King";
};

void King::move(pair<char, int> square){
    int possible_squares_size = possible_squares.size(); 
    if (check_membership(square, possible_squares, possible_squares_size)){
        curr_square = square;
        calc_possible_squares();
    }
    else
        cout << "you cant go there" << endl;
};


void King::calc_possible_squares(){
    possible_squares.clear();
    pair<int,int> square = {letter_to_number(curr_square.first), curr_square.second};

    for (int i=0; i<2; i++){
        int first;
        int second;
        for (int j=0; j<4; j++){
            if (i == 0){first=2;second=1;}else{first=1;second=2;}
            if (j == 0)
                if (0 < square.first+first && square.first+first < 9 && 0 < square.second+second && square.second < 9)
                    possible_squares.push_back({number_to_letter(square.first+first), square.second+second});
            if (j == 1)
                if (0 < square.first+first && square.first+first < 9 && 0 < square.second-second && square.second-second < 9)
                    possible_squares.push_back({number_to_letter(square.first+first), square.second-second});
            if (j == 2)
                if (0 < square.first-first && square.first-first < 9 && 0 < square.second+second && square.second+second < 9)
                    possible_squares.push_back({number_to_letter(square.first-first), square.second+second});
            if (j == 3)
                if (0 < square.first-first && square.first-first < 9 && 0 < square.second-second && square.second-second < 9)
                    possible_squares.push_back({number_to_letter(square.first-first), square.second-second});
        }
    }
};



