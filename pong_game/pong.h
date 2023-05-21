#ifndef PONG_H
#define PONG_H

#include<stdbool.h>
#include<SDL2/SDL.h>


#define SCREEN_WIDTH 640
#define SCREEN_WIDTH_LEFT 640
#define SCREEN_HEIGHT 480
#define SCREEN_HEIGHT_DOWN 480
#define PRANCHA_WIDTH 20
#define PRANCHA_HEIGHT 100
#define BOLA_SIZE 10
#define BOLA_SPEED 3


typedef struct
{
  int x;
  int y;
  int dx;
  int dy;
} Bola;

typedef struct
{
  int x;
  int y;
  int dy;
} Prancha;


extern int initial(SDL_Window** window, SDL_Renderer** render);
extern int render_game(SDL_Renderer* render);
extern void update_game(void);
extern void handle_events(void);
extern void* game_thread(void* arg);


#endif