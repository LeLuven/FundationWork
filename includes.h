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

#include <memory>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "GameState.h"
#include "Gun.h"
#include "MapNode.h"
#include "mapRenderer.h"
#include "Player.h"
#include "Tile.h"

#endif //TESTGAME_INCLUDES_H
