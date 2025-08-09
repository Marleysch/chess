#pragma once
#include "crow.h"

struct CORSHandler{
    struct context{};

    void before_handle(crow::request& req, crow::response& res, context&){
        if (req.method == "OPTIONS"_method){
            res.add_header("ACCESS-CONTROL-ALLOW-ORIGIN", "*");
            res.add_header("ACCESS-CONTROL-ALLOW-METHODS", "GET, POST, OPTIONS");
            res.add_header("ACCESS-CONTROL-ALLOW-HEADERS", "*");
            res.end();
        }
    }

    void after_handle(crow::request& req, crow::response& res, context&){
        res.add_header("ACCESS-CONTROL-ALLOW-ORIGIN", "*");
    }
};

