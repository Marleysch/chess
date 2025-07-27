#include <iostream>
#include "helpers.hpp"
#include "knight.hpp"
#include "piece.hpp"
#include "rook.hpp"
#include "king.hpp"
#include "bishop.hpp"
using namespace std;

//DONT FORGET TO CHECK FOR CHECK
int main(){
    cout << "running" << endl << endl;

    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            board[i][j] = nullptr;
        };
    }   
    
    print_board();

    Piece * whiterook1 = new Rook("W", 'a', 1);
    Piece * whiteknight1 = new Knight("W", 'b', 1);
    Piece * whitebishop1 = new Bishop("W", 'c', 1);
    Piece * whiteking = new King("W", 'e', 1);
    cout << "king possible squares:  {";
    for (const auto& square : whiteking->possible_squares){
        cout << square.first << square.second << ", ";
    }
    cout << "}" << endl;
    cout << "king space: " << whiteking->curr_square.first << whiteking->curr_square.second << endl;
    cout << "before:" << whiteknight1->has_moved << endl;
    print_board();
    whiteknight1->move({'d',2});
    // whitebishop1->move({'b',2});
    print_board();
    cout << "king space: " << whiteking->curr_square.first << whiteking->curr_square.second << endl;
    cout << "after:" << whiteknight1->has_moved << endl;

    cout << "knigth possible squares:  {";
    for (const auto& square : whiteknight1->possible_squares){
        cout << square.first << square.second << ", ";
    }
    cout << "}" << endl;

    cout << "bishop possible squares:  {";
    for (const auto& square : whitebishop1->possible_squares){
        cout << square.first << square.second << ", ";
    }
    cout << "}" << endl;

    cout << "rook possible squares:  {";
    for (const auto& square : whiterook1->possible_squares){
        cout << square.first << square.second << ", ";
    }
    cout << "}" << endl;

    cout << "king possible squares:  {";
    for (const auto& square : whiteking->possible_squares){
        cout << square.first << square.second << ", ";
    }
    cout << "}" << endl;

};
