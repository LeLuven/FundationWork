#ifndef TESTGAME_MAPRENDERER_H
#define TESTGAME_MAPRENDERER_H
#include "includes.h"

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

            // Calculate the destination rectangle of the tile based on its position in the map
            SDL_Rect dstRect = {
                    x * TILE_SIZE, // x position of the tile in pixels
                    y * TILE_SIZE, // y position of the tile in pixels
                    TILE_SIZE,     // width of the tile in pixels
                    TILE_SIZE      // height of the tile in pixels
            };

            // Render the tile using the calculated destination rectangle
            renderTile(renderer, tileset, tile.srcRect, dstRect);
        }
    }
}


#endif //TESTGAME_MAPRENDERER_H
