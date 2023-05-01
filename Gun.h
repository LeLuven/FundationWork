#ifndef TESTGAME_GUN_H
#define TESTGAME_GUN_H
#include "includes.h"
#include "Player.h"
#include <memory>
#include <cmath>
#include "includes.h"

class Gun {
public:
    SDL_Texture* texture;
    SDL_Rect srcRect;
    SDL_FRect dstRect;
    SDL_FPoint gunMountOffset = {0.5f, 0.5f}; // Relative position to the player (range 0 to 1)
    SDL_FPoint bulletExitOffset = {1.0f, 0.5f}; // Relative position on the gun (range 0 to 1)

    float angle = 0.0f;

    Gun(SDL_Texture* texture, const SDL_Rect& srcRect, const SDL_FRect& dstRect)
            : texture(texture), srcRect(srcRect), dstRect(dstRect) {}

    SDL_FPoint getBulletExitPosition() const {
        float exitX = dstRect.x + dstRect.w * bulletExitOffset.x;
        float exitY = dstRect.y + dstRect.h * bulletExitOffset.y;
        return {exitX, exitY};
    }

    void render(SDL_Renderer* renderer, const SDL_FRect& playerRect) {
        float centerX = playerRect.x + playerRect.w * gunMountOffset.x;
        float centerY = playerRect.y + playerRect.h * gunMountOffset.y;

        dstRect.x = centerX - dstRect.w * bulletExitOffset.x;
        dstRect.y = centerY - dstRect.h * bulletExitOffset.y;

        SDL_Rect dstRectInt = {static_cast<int>(dstRect.x), static_cast<int>(dstRect.y), static_cast<int>(dstRect.w), static_cast<int>(dstRect.h)};
        SDL_Point center = {static_cast<int>(dstRect.w * gunMountOffset.x), static_cast<int>(dstRect.h * gunMountOffset.y)};
        SDL_RenderCopyEx(renderer, texture, &srcRect, &dstRectInt, angle, &center, SDL_FLIP_NONE);
    }

    void updateAngle(int mouseX, int mouseY, const SDL_FRect& playerRect) {
        float centerX = playerRect.x + playerRect.w * gunMountOffset.x;
        float centerY = playerRect.y + playerRect.h * gunMountOffset.y;

        float deltaX = mouseX - centerX;
        float deltaY = mouseY - centerY;

        angle = atan2(deltaY, deltaX) * 180 / M_PI;
    }


};

#endif //TESTGAME_GUN_H
