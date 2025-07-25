#pragma once
#include <iostream>
#include <string>
#include "piece.hpp"
#include "helpers.hpp"
using namespace std;

class King: public Piece{
    public:
    
    King(string incolor, char rank, int row);

    virtual string toString() const override;

    void calc_possible_squares();

};