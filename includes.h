#ifndef TESTGAME_INCLUDES_H
#define TESTGAME_INCLUDES_H

using namespace std;

constexpr int S_WIDTH = 1000;
constexpr int S_HEIGHT = 600;
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
#include "MapNode.h"
#include "GameState.h"
#include "Player.h"
#include "mapRenderer.h"

#endif //TESTGAME_INCLUDES_H
