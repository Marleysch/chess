#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include "piece.hpp"
using namespace std;


Piece::Piece(string incolor, char rank, int row) : color(incolor),curr_square({rank,row}){};

void Piece::move(pair<char,int> square){};

void Piece::calc_possible_squares(){};

std::ostream& operator<<(std::ostream& os, const Piece& piece){
    os << piece.color << " ";
    os << piece.toString();
    return os;
};
