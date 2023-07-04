#include <SDL2/SDL_assert.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdio.h>
#include "pong.h"
#include<SDL2/SDL_error.h>


Bola bola;
Prancha prancha1, prancha2;

bool quit = false;
pthread_mutex_t mutex;


// Incialização do Game
extern int initial(SDL_Window** window, SDL_Renderer** render)
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "SDL não pode iniciar o video: %s\n", SDL_GetError());
    exit(1);
  }
  *window = SDL_CreateWindow("PONG",SDL_WINDOWPOS_UNDEFINED ,SDL_WINDOWPOS_UNDEFINED,
    SCREEN_WIDTH ,SCREEN_HEIGHT ,SDL_WINDOW_SHOWN);

  if(*window == NULL){
    fprintf(stderr, "SDL não pode iniciar o video: %s\n", SDL_GetError());
    exit(1);
  }
  
  *render = SDL_CreateRenderer(*window,-1 ,SDL_RENDERER_ACCELERATED);

  if(*render == NULL){
    fprintf(stderr, "SDL não pode iniciar o video: %s\n", SDL_GetError());
    exit(1);
  }

  SDL_SetRenderDrawColor(*render,0 ,0 ,0 ,255);
  SDL_RenderClear(*render);
  SDL_RenderPresent(*render);
  
  return 0;
}

// Função que ler todos os eventos do jogo
extern void handle_events(void)
{
  SDL_Event event;

  while (SDL_PollEvent(&event)){
    if (event.type == SDL_QUIT) {
      quit = true;
    }
  }

  // Leitura do Teclado e movimentação da Prancha 
  const Uint8* state = SDL_GetKeyboardState(NULL);
  if(state[SDL_SCANCODE_UP]) {
    pthread_mutex_lock(&mutex);
    prancha2.y -= prancha2.dy;
    pthread_mutex_unlock(&mutex);
  }
  if(state[SDL_SCANCODE_DOWN]) {
     pthread_mutex_lock(&mutex);
     prancha2.y += prancha2.dy;
     pthread_mutex_unlock(&mutex);
  }
  if(state[SDL_SCANCODE_W]) {
     pthread_mutex_lock(&mutex);
     prancha1.y -= prancha1.dy;
     pthread_mutex_unlock(&mutex);
  }
  if(state[SDL_SCANCODE_S]) {
    pthread_mutex_lock(&mutex);
    prancha1.y += prancha1.dy;
    pthread_mutex_unlock(&mutex);
  }
  
}


// Atulização das ações do game (Como Movimentação da bola etc)
extern void update_game(void)
{
  pthread_mutex_lock(&mutex);

  bola.x += bola.dx;
  bola.y += bola.dy;

  if(bola.x <= 0 || bola.y >= SCREEN_HEIGHT - BOLA_SIZE){
    bola.dy = -bola.dy;
  }

  if (bola.y <= PRANCHA_WIDTH && bola.x >= prancha1.x && bola.x <= prancha1.x + PRANCHA_HEIGHT){
    bola.dx = -bola.dx;
  }

  if (bola.x >= SCREEN_WIDTH - PRANCHA_WIDTH - BOLA_SIZE && bola.y >= prancha2.y && bola.y <= prancha2.y + PRANCHA_HEIGHT) {
    bola.dx = -bola.dx;
  }

  if (bola.x <= 0 || bola.y >= SCREEN_WIDTH - BOLA_SIZE) {
    quit = true;
  }
  
  // TODO: Fazer comando para Prancha
  // NOTE: (if prancha1 == screen_width_down) ->  stop(SDL_stop)
  if (prancha1.x == -SCREEN_HEIGHT && prancha2.x == -SCREEN_HEIGHT){}
  pthread_mutex_unlock(&mutex);
}


// Renderiação do Jogo
extern int render_game(SDL_Renderer* render)
{
  pthread_mutex_lock(&mutex);

  SDL_SetRenderDrawColor(render,0 ,0 ,0 ,255);
  SDL_RenderClear(render);

  SDL_SetRenderDrawColor(render,255 ,255 ,255 ,255);

  SDL_Rect bolaRect = { bola.x, bola.y, BOLA_SIZE, BOLA_SIZE };
  SDL_RenderFillRect(render, &bolaRect);

  SDL_Rect prancha1Rect = { prancha1.x, prancha1.y, PRANCHA_WIDTH, PRANCHA_HEIGHT };
  SDL_RenderFillRect(render, &prancha1Rect);
  
  SDL_Rect prancha2Rect = { prancha2.x, prancha2.y, PRANCHA_WIDTH, PRANCHA_HEIGHT };
  SDL_RenderFillRect(render, &prancha2Rect);

  SDL_RenderPresent(render);

  pthread_mutex_unlock(&mutex);
  
  return 0;
}

// Uso de Threads do CPU 
extern void* game_thread(void* arg)
{
  SDL_Window* window;
  SDL_Renderer* render;


  initial(&window, &render);

  while(!quit){
    handle_events();
    update_game();
    render_game(render);

    SDL_Delay(25);
  }

  SDL_DestroyRenderer(render);
  SDL_DestroyWindow(window);

  SDL_Quit();

  pthread_exit(NULL);
  return 0;
}

//static void menu(void){}



int main(void)
{
  pthread_t thread;
  pthread_mutex_init(&mutex, NULL);

  // Renderiazação das bola e dos movimentos da Bola
  bola.x = SCREEN_WIDTH / 2 - BOLA_SIZE / 2;
  bola.y = SCREEN_HEIGHT / 2 - BOLA_SIZE / 2;
  bola.dx = BOLA_SPEED;
  bola.dy = BOLA_SPEED;

  // Renderização da Prancha 1 e seu movimento
  prancha1.x = PRANCHA_WIDTH;
  prancha1.y = SCREEN_HEIGHT / 2 - PRANCHA_WIDTH - PRANCHA_WIDTH;
  prancha1.dy = 5;

  // Renderização da Prancha 2 e seu movimento
  prancha2.x = PRANCHA_WIDTH;
  prancha2.y = SCREEN_HEIGHT / 2 - PRANCHA_WIDTH - PRANCHA_WIDTH;
  prancha2.dy = 5;

  // Condição para tratamento de error da inicialização do Game
  if (pthread_create(&thread, NULL, game_thread, NULL) != 0){
    fprintf(stderr,"Falied to create thread\n" );
    return 1;
  }

  pthread_join(thread, NULL);
  pthread_mutex_destroy(&mutex);
  return 0;
}