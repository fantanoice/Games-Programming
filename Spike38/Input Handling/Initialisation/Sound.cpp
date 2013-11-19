#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <iostream>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 600;

int main( int argc, char* args[] ) {
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
        std::cout << "SDL could not initialize!\n";
    else if( SDL_Init( SDL_INIT_AUDIO ) < 0 )
        std::cout << "SDL Audio could not initialize!\n";
    else {
        bool loop = true;
        SDL_Event e;

        SDL_Surface* screenSurface = NULL;
        SDL_Window *window = SDL_CreateWindow("Sound", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_SWSURFACE);

        screenSurface = SDL_GetWindowSurface(window);

        Mix_Chunk* sound1 = NULL;
        Mix_Chunk* sound2 = NULL;
        Mix_Chunk* sound3 = NULL;
        Mix_Music* music = NULL;

        Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,4,4096);

        music = Mix_LoadMUS( "audio/dancezone.wav" );
        sound1 = Mix_LoadWAV( "audio/Hammer-knocking-multiple-nail-into-a-plank-of-pine-wood.wav" );
        sound2 = Mix_LoadWAV( "audio/Man-Walking-through-the-grass.wav" );
        sound3 = Mix_LoadWAV( "audio/Matches-Successful-Ignition-and-Long-Burning.wav" );
        
        if(music == NULL) {
            std::cout << "music not set\n";
        }
        if(sound1 == NULL) {
            std::cout << "sound1 not set\n";
        }
        if(sound2 == NULL) {
            std::cout << "sound2 not set\n";
        }
        if(sound3 == NULL) {
            std::cout << "sound3 not set\n";
        }

        Mix_VolumeMusic(100);

        while(loop) {
            while(SDL_PollEvent(&e)) {
                if((e.type == SDL_QUIT) || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_a))
                    loop = false;
                else if(e.type == SDL_KEYDOWN) {
                    if(e.key.keysym.sym == SDLK_0) {
                        std::cout << "0 pressed\n";
                        if( Mix_PlayingMusic() == 0 ) {
                            Mix_PlayMusic(music, -1);
                        }
                        else {
                            if( Mix_PausedMusic() == 1 ) {
                                Mix_ResumeMusic();
                            }
                            else {
                                Mix_PauseMusic();
                            }
                        }
                    }
                    if(e.key.keysym.sym == SDLK_1) {
                        std::cout << "1 pressed\n";
                        Mix_PlayChannel(-1, sound1, 0);
                    }
                    if(e.key.keysym.sym == SDLK_2) {
                        std::cout << "2 pressed\n";
                        Mix_PlayChannel(-1, sound2, 0);
                    }
                    if(e.key.keysym.sym == SDLK_3) {
                       std::cout << "3 pressed\n";
                       Mix_PlayChannel(-1, sound3, 0);
                    }
                }
            }
        }

        Mix_FreeChunk(sound1);
        Mix_FreeChunk(sound2);
        Mix_FreeChunk(sound3);
        Mix_FreeMusic(music);
        Mix_CloseAudio();

        SDL_FreeSurface(screenSurface);
        SDL_DestroyWindow( window );

        SDL_Quit();
        }
    return 0;
}