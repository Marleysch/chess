#include <string>
#include <utility>
#include <vector>
#pragma once
using namespace std;

class Piece{
    public:
    string color;
    pair<char, int> curr_square;
    vector<pair<char,int>> possible_squares;

    virtual string toString() const = 0;

    void calc_possible_squares(){}

    void move(pair<char,char> square){}

    friend ostream& operator<<(ostream& os, const Piece& piece){
        os << piece.color << piece.toString();
        return os;
    }
};