#include <string>
#include <iostream>
#include <utility>
#include <vector>
#pragma once
using namespace std;

class Piece{
    public:
    string color;
    pair<char, int> curr_square;
    vector<pair<char,int>> possible_squares;

    Piece(string incolor, char rank, int row);

    virtual string toString() const = 0;

    virtual void move(pair<char,int> square);
    
    protected:
    void calc_possible_squares();

    friend ostream& operator<<(ostream& os, const Piece& piece);
};