//
// Created by Jonas Luven on 27.04.23.
//

#ifndef TESTGAME_TILE_H
#define TESTGAME_TILE_H

#include <SDL.h>

enum TileType{
    GROUND = 0,
    WALL = 1,
    TELEPORT = 2
};

struct Tile {
    SDL_Texture * texture;
    SDL_Rect srcRect;
    SDL_Rect dstRect;
    TileType tileType;
    bool isSolid;
    int numFrames;
    int frameDuration;


    Tile(SDL_Texture* texture, const SDL_Rect& srcRect, const SDL_Rect& dstRect, TileType tileType, bool isSolid, int numFrames = 1, int frameDuration = 0)
            : texture(texture), srcRect(srcRect), dstRect(dstRect), tileType(tileType), isSolid(isSolid),numFrames(numFrames), frameDuration(frameDuration) {}
};


#endif //TESTGAME_TILE_H
