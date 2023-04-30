#ifndef TESTGAME_INCLUDES_H
#define TESTGAME_INCLUDES_H

using namespace std;

constexpr int S_WIDTH = 1280;
constexpr int S_HEIGHT = 720;
constexpr int TILESIZE = 32;
constexpr int MAPSIZE = 20;


#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "Tile.h"
#include "GameState.h"
#include "Player.h"
#include "mapRenderer.h"
#include "MapNode.h"

#endif //TESTGAME_INCLUDES_H
