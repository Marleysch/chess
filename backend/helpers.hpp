#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "piece.hpp"
#include "crow.h"
using namespace std;

extern Piece * board[8][8];


bool check_membership(pair<char, int> item, vector<pair<char,int>> vector, int array_size);

int letter_to_number(char letter);

char number_to_letter(int number);

int the_maggie_function(int number);

bool check_for_check(Piece * king);

void print_board();

void initialize_game();

crow::json::wvalue build_client_board();
