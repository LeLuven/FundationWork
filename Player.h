#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
enum Direction {
    Left,
    Right,
};

class Player {
public:
    SDL_Texture* texture;
    SDL_Rect lRect = {0,4*32,32,32};
    SDL_Rect rRect = {0,5*32,32,32};
    SDL_Rect srcRect;
    SDL_Rect dstRect;
    int currentFrame;
    int frameDuration;
    Direction dir = Right;
    int speed = 32;

    Player(SDL_Texture* texture, const SDL_Rect& srcRect, const SDL_Rect& dstRect, int frameDuration = 0)
            : texture(texture), srcRect(srcRect), dstRect(dstRect), currentFrame(0), frameDuration(frameDuration) {}

    void updateAnimationFrame(int elapsedTime) {
        if (frameDuration > 0) {
            currentFrame = (elapsedTime / frameDuration) % 8;
        }
    }

    // Render the player using the provided SDL_Renderer
    void render(SDL_Renderer* renderer) {
        SDL_Rect currentSrcRect;
        if(dir == Right){
            currentSrcRect = rRect;
        } else if (dir == Left){
            currentSrcRect = lRect;
        }
        currentSrcRect.x += currentFrame * dstRect.w;
        SDL_RenderCopy(renderer, texture, &currentSrcRect, &dstRect);
    }

    void handleMovement(SDL_Event e, const std::vector<std::vector<int>>& map, const std::vector<Tile>& tiles) {
        int newX = dstRect.x;
        int newY = dstRect.y;
        if(e.type == SDL_KEYDOWN){
            switch (e.key.keysym.sym) {
                case SDLK_UP:
                case SDLK_w:
                    newY -= speed;
                    break;
                case SDLK_DOWN:
                case SDLK_s:
                    newY += speed;
                    break;
                case SDLK_LEFT:
                case SDLK_a:
                    newX -= speed;
                    dir = Direction::Left;
                    break;
                case SDLK_RIGHT:
                case SDLK_d:
                    newX += speed;
                    dir = Direction::Right;
                    break;
            }
        }

        int mapWidth = map[0].size();
        int mapHeight = map.size();
        int playerTileX = newX / 32;
        int playerTileY = newY / 32;
        if (playerTileX >= 0 && playerTileX < mapWidth && playerTileY >= 0 && playerTileY < mapHeight) {
            int tileType = map[playerTileY][playerTileX];
            const Tile& tile = tiles[tileType];
            if (!tile.isSolid) {
                dstRect.x = newX;
                dstRect.y = newY;
            }
        }
    }


};
#endif //TESTGAME_PLAYER_H
