#ifndef TESTGAME_MAPNODE_H
#define TESTGAME_MAPNODE_H
#include "includes.h"

struct MapNode {
    int id;
    std::vector<std::vector<int>> layout;
    MapNode* north;
    MapNode* east;
    MapNode* south;
    MapNode* west;

    MapNode(int id,vector<vector<int>> map)
        :id(id),layout(map), north(nullptr), east(nullptr), south(nullptr), west(nullptr) {};

    /*
    MapNode* findConnectedMap(Player& player, MapNode& currentMap) {
        if () {
            return currentMap.north;
        } else if () {
            return currentMap.east;
        } else if () {
            return currentMap.south;
        } else if () {
            return currentMap.west;
        }
        return &currentMap;
    }
    */

};



#endif //TESTGAME_MAPNODE_H
