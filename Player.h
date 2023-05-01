#ifndef PLAYER_H
#define PLAYER_H

#include "includes.h"
#include "Tile.h"
#include "Gun.h"
#include <SDL.h>
#include <memory>


enum Direction {
    Left,
    Right,
};

class Player {
public:
    SDL_Texture* texture;
    SDL_Rect lRect = {0, 4 * 32, 32, 32};
    SDL_Rect rRect = {0, 5 * 32, 32, 32};
    SDL_Rect srcRect;
    SDL_FRect dstRect;
    unique_ptr<Gun> gun;
    int currentFrame;
    int frameDuration;
    Direction dir = Right;
    int speed = 256;


    Player(SDL_Texture* texture, const SDL_Rect& srcRect, const SDL_FRect& dstRect, unique_ptr<Gun> gun, int frameDuration = 0)
            : texture(texture), srcRect(srcRect), dstRect(dstRect), gun(std::move(gun)), currentFrame(0), frameDuration(frameDuration) {}


    void updateAnimationFrame(Uint32 elapsedTime) {
        if (frameDuration > 0) {
            currentFrame = (elapsedTime / (frameDuration * 8)) % 8;
        }
    }

    // Render the player using the provided SDL_Renderer
    void render(SDL_Renderer* renderer) {
        SDL_Rect currentSrcRect;
        if (dir == Right) {
            currentSrcRect = rRect;
        } else if (dir == Left) {
            currentSrcRect = lRect;
        }
        currentSrcRect.x += currentFrame * static_cast<int>(dstRect.w);
        gun->render(renderer, dstRect);
        SDL_RenderCopyF(renderer, texture, &currentSrcRect, &dstRect);
    }

    void handleMovement(const Uint8* keyboardState, const std::vector<std::vector<int>>& map, const std::vector<Tile>& tiles, int deltaTime) {
        float newX = dstRect.x;
        float newY = dstRect.y;

        float moveSpeed = static_cast<float>(speed) * (deltaTime / 1000.0f);
        float dirX = 0.0f;
        float dirY = 0.0f;

        if (keyboardState[SDL_SCANCODE_UP] || keyboardState[SDL_SCANCODE_W]) {
            dirY -= 1.0f;
        }
        if (keyboardState[SDL_SCANCODE_DOWN] || keyboardState[SDL_SCANCODE_S]) {
            dirY += 1.0f;
        }
        if (keyboardState[SDL_SCANCODE_LEFT] || keyboardState[SDL_SCANCODE_A]) {
            dirX -= 1.0f;
        }
        if (keyboardState[SDL_SCANCODE_RIGHT] || keyboardState[SDL_SCANCODE_D]) {
            dirX += 1.0f;
        }

        if (dirX < 0) {
            dir = Direction::Left;
        } else if (dirX > 0) {
            dir = Direction::Right;
        }

        float length = std::sqrt(dirX * dirX + dirY * dirY);
        if (length > 0.0f) {
            dirX /= length;
            dirY /= length;
            newX += dirX * moveSpeed;
            newY += dirY * moveSpeed;
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

    void handleShooting(SDL_Event e, SDL_Window* window) {
        if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_RIGHT) {
            // Shoot the gun
            SDL_FPoint bulletStartPosition = gun->getBulletExitPosition();
            // Create and manage bullet objects using bulletStartPosition
        }

        if (e.type == SDL_MOUSEMOTION) {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            int windowWidth, windowHeight;
            SDL_GetWindowSize(window, &windowWidth, &windowHeight);

            float centerX = dstRect.x + dstRect.w / 2;
            float centerY = dstRect.y + dstRect.h / 2;

            gun->angle = atan2f(mouseY - centerY, mouseX - centerX) * (180.0f / M_PI);
        }
    }



};
#endif //TESTGAME_PLAYER_H
