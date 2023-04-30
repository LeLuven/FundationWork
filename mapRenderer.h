#ifndef TESTGAME_MAPRENDERER_H
#define TESTGAME_MAPRENDERER_H
#include "includes.h"
#include "MapNode.h"

void renderTile(SDL_Renderer* renderer, SDL_Texture* tileset, const SDL_Rect& srcRect, const SDL_Rect& dstRect) {
    SDL_RenderCopy(renderer, tileset, &srcRect, &dstRect);
}

void renderMap(SDL_Renderer* renderer, SDL_Texture* tileset, MapNode& map, const std::vector<Tile>& tiles) {
    const int TILE_SIZE = 32; // the size of each tile in pixels
    const int MAP_WIDTH = map.layout[0].size(); // the width of the map in tiles
    const int MAP_HEIGHT = map.layout.size(); // the height of the map in tiles

    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            int tileType = map.layout[y][x];
            const Tile& tile = tiles[tileType];

            SDL_Rect dstRect = {
                    x * TILE_SIZE,
                    y * TILE_SIZE,
                    TILE_SIZE,
                    TILE_SIZE
            };

            renderTile(renderer, tileset, tile.srcRect, dstRect);
        }
    }
}

void updateAnimationFrame(Tile& tile, int elapsedTime) {
    if (tile.numFrames > 1) {
        int currentFrame = (elapsedTime / tile.frameDuration) % tile.numFrames;
        tile.srcRect.x = tile.srcRect.w * currentFrame;
    }
}

void renderLevelNum(SDL_Renderer* renderer, SDL_Texture* tileset, GameState& game, const Tile& tile){
    SDL_Rect dR{0, 0, 32, 32};
    SDL_Rect sR = tile.srcRect;
    sR.y = game.currentMap->id * 32;
    SDL_RenderCopy(renderer, tileset,&sR, &dR);
}



#endif //TESTGAME_MAPRENDERER_H
