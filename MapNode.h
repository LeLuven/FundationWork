#ifndef TESTGAME_MAPNODE_H
#define TESTGAME_MAPNODE_H
#include "includes.h"
#include "Player.h"


struct MapNode {
    int id;
    std::vector<std::vector<int>> layout;
    MapNode* north;
    MapNode* east;
    MapNode* south;
    MapNode* west;

    MapNode(int id,vector<vector<int>> map)
        :id(id),layout(map), north(nullptr), east(nullptr), south(nullptr), west(nullptr) {};


    static MapNode* findMap(Player& player, MapNode& currentMap) {
        int playerTileX = player.dstRect.x / 32;
        int playerTileY = player.dstRect.y / 32;
        int tileType = currentMap.layout[playerTileY][playerTileX];
        if (tileType == TELEPORT) {
            if (playerTileY == 0 && currentMap.north != nullptr) {
                player.dstRect.y = currentMap.layout.size() * 32 - 32;
                return currentMap.north;
            } else if (playerTileX == currentMap.layout[0].size() - 1 && currentMap.east != nullptr) {
                player.dstRect.x = 0;
                return currentMap.east;
            } else if (playerTileY == currentMap.layout.size() - 1 && currentMap.south != nullptr) {
                player.dstRect.y = 0;
                return currentMap.south;
            } else if (playerTileX == 0 && currentMap.west != nullptr) {
                player.dstRect.x = currentMap.layout[0].size() * 32 - 32;
                return currentMap.west;
            }
        }
        return &currentMap;
    }

};



#endif //TESTGAME_MAPNODE_H
