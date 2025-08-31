#include <iostream>
#include <vector>
#include <algorithm>
#include "helpers.hpp"
#include "knight.hpp"
#include "piece.hpp"
#include "rook.hpp"
#include "king.hpp"
#include "bishop.hpp"
#include "queen.hpp"
#include "pawn.hpp"
#include "crow.h"
#include "corshandler.hpp"
using namespace std;


int main(){
    cout << "running main" << endl << endl;
    string color = "white";
    string turn = "white";
    vector<crow::websocket::connection*> connections;

    crow::App<CORSHandler> app;

    initialize_game();

    CROW_ROUTE(app, "/start")([&color, &turn](){

        crow::json::wvalue start_values;

        string old_color = color;
        if (color == "white"){
            color = "black";
        }
        else{
            color = "white";
        }
        
        start_values["board"] = build_client_board();
        start_values["color"] = old_color;
        start_values["turn"] = turn;

        return start_values;
    });

    CROW_ROUTE(app, "/<int>/<int>/<int>/<int>")([&turn, &connections](int p1rank, int p1row, int p2rank, int p2row){

        char p2rankletter = number_to_letter(p2rank + 1);
        p2row = the_maggie_function(p2row + 1);

        bool result = board[p1row][p1rank]->move({p2rankletter, p2row});

        string old_turn = turn;
        if (result){
            if (turn == "white"){
                turn = "black";
            }
            else if(turn == "black"){
                turn = "white";
            }
        }

        crow::json::wvalue board_and_turn;
        board_and_turn["board"] = build_client_board();
        board_and_turn["turn"] = old_turn;

        string msg = board_and_turn.dump();

        cout << msg << endl;

        for (auto& conn_ptr: connections){
            conn_ptr->send_text(msg);
        }

        return board_and_turn;
    });

    CROW_WEBSOCKET_ROUTE(app, "/ws") 
    .onopen([&](crow::websocket::connection& conn){ 
        connections.push_back(&conn);
    }) 
    .onmessage([&](crow::websocket::connection& conn, const std::string& msg, bool is_binary){
        // handle incoming messages 
    }) 
    .onclose([&](crow::websocket::connection& conn, const std::string& reason, uint16_t with_status_code ){ 
        connections.erase(remove(connections.begin(), connections.end(), &conn), connections.end());
    });

    app.port(18080).multithreaded().run();

};
