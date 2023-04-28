#include "includes.h"

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window *window = SDL_CreateWindow("GameTest", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, S_WIDTH,
                                          S_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Texture *spritesheet = IMG_LoadTexture(renderer, "../../bd.png");

    /**
     * Generating Maps and connections
     */

    MapNode map0 = {0,
                    {
                            {1, 1, 1, 1, 2, 1, 1, 1, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {2, 0, 0, 0, 0, 0, 0, 0, 2},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 1, 1, 1, 2, 1, 1, 1, 1}
                    }
    };
    MapNode map1 = {1,
                    {
                            {1, 1, 1, 1, 2, 1, 1, 1, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {2, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 1, 1, 1, 1, 1, 1, 1, 1}
                    }
    };
    MapNode map2 = {2,
                    {
                            {1, 1, 1, 1, 1, 1, 1, 1, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {2, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 1, 1, 1, 2, 1, 1, 1, 1}
                    }
    };
    MapNode map3 = {3,
                    {
                            {1, 1, 1, 1, 1, 1, 1, 1, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 2},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 1, 1, 1, 2, 1, 1, 1, 1}
                    }
    };
    MapNode map4 = {4,
                    {
                            {1, 1, 1, 1, 2, 1, 1, 1, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 1, 1, 1, 2, 1, 1, 1, 1}
                    }
    };
    MapNode map5 = {5,
                    {
                            {1, 1, 1, 1, 1, 1, 1, 1, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 2},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 1, 1, 1, 1, 1, 1, 1, 1}
                    }
    };
    MapNode map6 = {6,
                    {

                            {1, 1, 1, 1, 2, 1, 1, 1, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 1, 1, 1, 1, 1, 1, 1, 1}

                    }
    };
    map0.north = &map3;
    map0.east = &map1;
    map0.south = &map4;
    map0.west = &map5;

    map1.north = &map2;
    map1.west = &map0;

    map2.south = &map1;
    map2.west = &map3;

    map3.east = &map2;
    map3.south = &map0;

    map4.north = &map0;
    map4.south = &map6;

    map5.east = &map0;

    map6.north = &map4;

    /**
     * Generating Tile Vector
     */
    std::vector<Tile> tiles = {
            // Ground
            {spritesheet, {32, 7 * 32, TILESIZE, TILESIZE}, GROUND,   false},
            // Wall
            {spritesheet, {32, 6 * 32, TILESIZE, TILESIZE},  WALL,     true},
            // Teleport
            {spritesheet, {0,  9 * 32, TILESIZE, TILESIZE},  TELEPORT, false, 4, 1}
    };

    vector<MapNode> mapTest = {map0,map1,map2,map3,map4,map5,map6};

    GameState gameState;
    gameState.currentMap = &mapTest[0];
    int inc = 0;
    SDL_Event e;
    bool quit = false;
    while (!false) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN){
                cout << "change" << endl;
                gameState.currentMap = &mapTest[++inc];
            }
        }
        SDL_RenderClear(renderer);
        renderMap(renderer,spritesheet,*gameState.currentMap,tiles);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(spritesheet);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();


}
