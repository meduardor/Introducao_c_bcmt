#ifndef MAP_H
#define MAP_H

#include "pong.h"
#include <sys/types.h>
#include<SDL2/SDL_render.h>

#define MAP_SIZE 96

#define TILE_HEIGHT 30
#define TILE_WIDTH 60
#define MAP_RENDER_SIZE 24

#define MAP_RENDER_OFFSET_X ((SCREEN_WIDTH - (TILE_WIDTH * MAP_RENDER_SIZE)) / 2)
#define MAP_RENDER_OFFSET_Y 425


typedef struct 
{
  int x;
  int y;
  int sx;
  int sy;
  // AltasImage *texture;
} ISOOBjectect;

typedef struct{ int tile; } Maptile;
typedef struct 
{
  int color_1;
  int color_2;
  int color_3;
  int color_4;
  float Alpha;
} ColorNAme;

extern uint RenderMap(double lado_x, double lado_y, ISOOBjectect Map);
extern int ColorType(Maptile map_div, char* Name, ColorNAme tipo);
extern double RenderImage(SDL_Texture image_out, SDL_Texture image_in);

#endif