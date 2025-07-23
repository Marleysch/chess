#pragma once
#include <iostream>
#include <string>
#include "piece.hpp"
#include "helpers.hpp"
using namespace std;

class Bishop: public Piece{
    public:
    
    Bishop(string incolor, char rank, int row);

    virtual string toString() const override;

    void move(pair<char, int> square) override;

    protected:
    void calc_possible_squares();

};