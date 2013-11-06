//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <iostream>

bool loadMedia(SDL_Surface * surface);
bool init(SDL_Window* window, SDL_Surface* screenSurface);
void close(SDL_Surface* surface, SDL_Window* window, SDL_Surface* screenSurface);

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 600;

int main( int argc, char* args[] )
{
    bool loop = true;
    SDL_Event e;
    int keyStates [10][2] = {{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0}};

 //   SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;
    SDL_Surface* helloSurface = NULL;
    SDL_Window *window = SDL_CreateWindow("2D Drawing", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if(SDL_Init( SDL_INIT_VIDEO ) >= 0) {
        helloSurface = SDL_LoadBMP( "02_getting_an_image_on_the_screen/hello_world.bmp" );
        
        if(helloSurface != NULL) {
            screenSurface = SDL_GetWindowSurface(window);

            SDL_BlitSurface( helloSurface, NULL, screenSurface, NULL );
        
            SDL_UpdateWindowSurface( window );
            SDL_Delay( 10000 );


             while(loop) {
                    while(SDL_PollEvent(&e)) {
                        if(e.type == SDL_QUIT)
                            loop = false;
                        else if(e.type == SDL_KEYDOWN) {
                            // If A is pressed
                            if(e.key.keysym.sym == SDLK_a)
                                std::cout << "A was pressed\n";

                            // If a number is pressed
                            if(e.key.keysym.sym == SDLK_0)
                                keyStates[0][1] = 1;
                            else
                                keyStates[0][1] = 0;
                            if(e.key.keysym.sym == SDLK_1)
                                keyStates[1][1] = 1;
                            else
                                keyStates[1][1] = 0;
                            if(e.key.keysym.sym == SDLK_2)
                                keyStates[2][1] = 1;
                            else
                                keyStates[2][1] = 0;
                            if(e.key.keysym.sym == SDLK_3)
                                keyStates[3][1] = 1;
                            else
                                keyStates[3][1] = 0;
                            if(e.key.keysym.sym == SDLK_4)
                                keyStates[4][1] = 1;
                            else
                                keyStates[4][1] = 0;
                            if(e.key.keysym.sym == SDLK_5)
                                keyStates[5][1] = 1;
                            else
                                keyStates[5][1] = 0;
                            if(e.key.keysym.sym == SDLK_6)
                                keyStates[6][1] = 1;
                            else
                                keyStates[6][1] = 0;
                            if(e.key.keysym.sym == SDLK_7)
                                keyStates[7][1] = 1;
				            else
					            keyStates[7][1] = 0;
                            if(e.key.keysym.sym == SDLK_8)
					            keyStates[8][1] = 1;
				            else
					            keyStates[8][1] = 0;
                            if(e.key.keysym.sym == SDLK_9)
                                keyStates[9][1] = 1;
                            else
                                keyStates[9][1] = 0;

                            // Display keyboard states
                            for(int i = 0; i < 10; i++) {
                                if(keyStates[i][1] == 1)
                                    std::cout << keyStates[i][0] << " was pressed\n";
                            }
                        }
                    }
            }*/


/*
            //Apply the image
            SDL_BlitSurface( helloSurface, NULL, screenSurface, NULL );

            //Update the surface
            SDL_UpdateWindowSurface( window );

            //Wait two seconds
            SDL_Delay( 2000 );

         //   close(helloSurface, window, screenSurface);

*/


            std::cout << "Done!";

            	SDL_FreeSurface(helloSurface);
	delete helloSurface;

	SDL_DestroyWindow( window );
	delete window;

    SDL_FreeSurface(screenSurface);
	delete screenSurface;

        }
        else {
        printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
        }
    }
    else {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}

    SDL_Delay( 10000 );
    SDL_Quit();
    return 0;
}


/*
bool loadMedia(SDL_Surface* surface) {
	surface = SDL_LoadBMP( "02_getting_an_image_on_the_screen/hello_world.bmp" );

	if( surface == NULL ) {
		printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
		return false;
	}

	return true;
}

bool init(SDL_Window* window, SDL_Surface* screenSurface) {
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return false;
	}
	
    window = SDL_CreateWindow( "SDL Tutorial", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

	if( window == NULL ) {
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		return false;
	}

    screenSurface = SDL_GetWindowSurface(window);
	return true;
}

void close(SDL_Surface* surface, SDL_Window* window, SDL_Surface* screenSurface) {
	SDL_FreeSurface(surface);
	delete surface;

	SDL_DestroyWindow( window );
	delete window;

    SDL_FreeSurface(screenSurface);
	delete screenSurface;

	SDL_Quit();
}*/