#ifndef TESTGAME_GAMESTATE_H
#define TESTGAME_GAMESTATE_H
#include "includes.h"
#include "Player.h"

class GameState {
public:
    MapNode* currentMap;
    Player* player;

    GameState() : currentMap(nullptr),player(player) {}
};

#endif //TESTGAME_GAMESTATE_H
