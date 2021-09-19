#pragma once

#include "json.hpp"

typedef struct {
    int cmd;
    float x;
    float y;
    float r;
} hPlayerMove;

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(hPlayerMove, cmd, x, y, r);

typedef struct {
    int cmd;
    int player_id;
    int hp;
    float x;
    float y;
    float r;
} sPlayerMove;

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(sPlayerMove, cmd, player_id, x, y, r);
