#pragma once
#include <iostream>
#include <string>
#include "piece.hpp"
#include "helpers.hpp"
using namespace std;

class Queen: public Piece{
    public:
    
    Queen(string incolor, char rank, int row);

    virtual string toString() const override;
    virtual pair<char,int>& get_curr_square()override;
    virtual vector<pair<char,int>>& get_possible_squares()override;

    void calc_possible_squares();

};
 