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
    SDL_Rect srcRect;
    SDL_Rect dstRect;
    int currentFrame;
    int frameDuration;
    Direction dir = Right;

    Player(SDL_Texture* texture, const SDL_Rect& srcRect, const SDL_Rect& dstRect, int frameDuration = 0)
            : texture(texture), srcRect(srcRect), dstRect(dstRect), currentFrame(0), frameDuration(frameDuration) {}

    void updateAnimationFrame(int elapsedTime) {
        if (frameDuration > 0) {
            currentFrame = (elapsedTime / frameDuration) % 8;
        }
    }

    // Render the player using the provided SDL_Renderer
    void render(SDL_Renderer* renderer) {
        SDL_Rect currentSrcRect = srcRect;
        currentSrcRect.x += currentFrame * dstRect.w;
        SDL_RenderCopy(renderer, texture, &currentSrcRect, &dstRect);
    }

    void handleMovement(SDL_Event e){

    }

    // Other player-related methods, such as input handling and physics updates
    // ...
};
#endif //TESTGAME_PLAYER_H
