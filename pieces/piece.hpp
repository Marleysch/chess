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


    virtual vector<pair<char,int>>& get_possible_squares() =0;
    virtual pair<char,int>& get_curr_square() =0;


    virtual string toString() const = 0;

    virtual void calc_possible_squares();

    void move(pair<char,int> square);


    friend ostream& operator<<(ostream& os, const Piece& piece);
};