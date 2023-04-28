#ifndef TESTGAME_GAMESTATE_H
#define TESTGAME_GAMESTATE_H
#include "includes.h"

class GameState {
public:
    MapNode* currentMap;
    //Player player;

    GameState() : currentMap(nullptr) {}
};

#endif //TESTGAME_GAMESTATE_H
