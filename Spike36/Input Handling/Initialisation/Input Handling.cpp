//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <iostream>

int main( int argc, char* args[] )
{
    bool loop = true;
    SDL_Event e;
    int keyStates [10][2] = {{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0}};
    
    // Initialising video and screen because they are needed to poll events. They are not used for anything else.
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *screen = SDL_CreateWindow("My Game Window", 0, 0, 0, 0, SDL_WINDOW_OPENGL);

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
    }
    return 0;
}