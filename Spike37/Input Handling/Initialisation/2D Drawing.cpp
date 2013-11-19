#include <SDL.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

void Draw(bool &backgroundOn, SDL_Surface *screenSurface, SDL_Surface *backgroundSurface, SDL_Rect *backgroundLocRect, SDL_Surface *foregroundSurface, SDL_Rect *bigForegroundRect, SDL_Rect *bigForegroundLocRect, SDL_Rect *medForegroundRect, SDL_Rect *medForegroundLocRect, SDL_Rect *smallForegroundRect, SDL_Rect *smallForegroundLocRect, SDL_Window *window);
int RandLocX();
int RandLocY();

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 600;

int main( int argc, char* args[] )
{
    srand(time(0));
    
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
        std::cout << "SDL could not initialize!\n";
    else {
        bool loop = true;
        SDL_Event e;

        SDL_Surface* screenSurface = NULL;
        SDL_Surface* backgroundSurface = NULL;
        SDL_Surface* foregroundSurface = NULL;
        SDL_Window *window = SDL_CreateWindow("2D Drawing", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);

	    backgroundSurface = SDL_LoadBMP("img/happy_ray.bmp");
        foregroundSurface = SDL_LoadBMP("img/penguin_power.bmp");

        SDL_Rect backgroundLocRect = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
        SDL_Rect bigForegroundRect = {200,200,300,300};
        SDL_Rect bigForegroundLocRect = {RandLocX(),RandLocY(),100,100};
        SDL_Rect medForegroundRect = {200,100,100,100};
        SDL_Rect medForegroundLocRect = {RandLocX(),RandLocY(),100,100};
        SDL_Rect smallForegroundRect = {600,200,50,50};
        SDL_Rect smallForegroundLocRect = {RandLocX(),RandLocY(),100,100};
        
        if(backgroundSurface != NULL && foregroundSurface != NULL) {
            bool backgroundOn = true;
            screenSurface = SDL_GetWindowSurface(window);

            while(loop) {
                while(SDL_PollEvent(&e)) {

                    if((e.type == SDL_QUIT) || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_a))
                        loop = false;
                    else if(e.type == SDL_KEYDOWN) {
                        if(e.key.keysym.sym == SDLK_0) {
                            if(backgroundOn)
                                backgroundOn = false;
                            else
                                backgroundOn = true;
                        }
                        else if(e.key.keysym.sym == SDLK_1) {
                            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( foregroundSurface->format, 0x00, 0x00, 0x00 ) );
                            bigForegroundLocRect.x = RandLocX();
                            bigForegroundLocRect.y = RandLocY();
                        }
                        else if(e.key.keysym.sym == SDLK_2) {
                            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( foregroundSurface->format, 0x00, 0x00, 0x00 ) );
                            medForegroundLocRect.x = RandLocX();
                            medForegroundLocRect.y = RandLocY();
                        }
                        else if(e.key.keysym.sym == SDLK_3) {
                            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( foregroundSurface->format, 0x00, 0x00, 0x00 ) );
                            smallForegroundLocRect.x = RandLocX();
                            smallForegroundLocRect.y = RandLocY();
                        }
                    }

                    Draw(backgroundOn, screenSurface, backgroundSurface, &backgroundLocRect, foregroundSurface, &bigForegroundRect, &bigForegroundLocRect, &medForegroundRect, &medForegroundLocRect, &smallForegroundRect, &smallForegroundLocRect, window); 
                }
            }

            SDL_FreeSurface(backgroundSurface);
            SDL_FreeSurface(screenSurface);
            SDL_DestroyWindow( window );

            SDL_Quit();
        }
        else
            std::cout << "Unable to load images\n";
    }
    
    return 0;
}

void Draw(bool &backgroundOn, SDL_Surface *screenSurface, SDL_Surface *backgroundSurface, SDL_Rect *backgroundLocRect, SDL_Surface *foregroundSurface, SDL_Rect *bigForegroundRect, SDL_Rect *bigForegroundLocRect, SDL_Rect *medForegroundRect, SDL_Rect *medForegroundLocRect, SDL_Rect *smallForegroundRect, SDL_Rect *smallForegroundLocRect, SDL_Window *window) { 
    if(backgroundOn)
        SDL_BlitSurface(backgroundSurface, NULL, screenSurface, backgroundLocRect);
    else
        SDL_FillRect( screenSurface, NULL, SDL_MapRGB( backgroundSurface->format, 0x00, 0x00, 0x00 ) );
    SDL_BlitSurface(foregroundSurface, bigForegroundRect, screenSurface, bigForegroundLocRect);
    SDL_BlitSurface(foregroundSurface, medForegroundRect, screenSurface, medForegroundLocRect);
    SDL_BlitSurface(foregroundSurface, smallForegroundRect, screenSurface, smallForegroundLocRect);
    SDL_UpdateWindowSurface( window );
}

int RandLocX() {
    return rand()%SCREEN_WIDTH;
}

int RandLocY() {
    return rand()%SCREEN_HEIGHT;
}