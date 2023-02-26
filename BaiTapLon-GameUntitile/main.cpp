﻿#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
#include <string.h>
#include <ctime> 
#include <cstdlib> 
#include <random>
using namespace std;
#include "Engine.h"
#include "Object.h"
#include "Knight.h"


const int S = 25;
const int SCREEN_WIDTH = 32 * S;
const int SCREEN_HEIGHT = 16 * S;
const string WINDOW_TITLE = "UntiledGame";
SDL_Event e;
time_t t;

int main(int argc, char* argv[])
{
	SDL_Renderer* renderer;
	SDL_Window* window;
	initSDL(window, renderer);
    // SOURCE PICTURE
    SDL_Texture* background = loadTexture("Art//WhiteBackground.png", renderer);
    SDL_Texture* KnightIdie = loadTexture("Art//Knight//idle.png", renderer);
    SDL_Texture* KnightRun = loadTexture("Art//_Run.png", renderer);

    // KHỞI TẠO
    All* all = new All(KnightRun, 500 , 400 , textureWidth(KnightRun)/10 , textureHeight(KnightRun) );
    Knight* player = new Knight(all);

    
    // GAME LOOP
	bool quit = 0;
	while (quit == 0)
	{	

	    // EVENT
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = 1;
				break;
			}
			if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym)
				{
				case SDLK_ESCAPE: quit = 1;
					break;
                case SDLK_a: cout << "Push a " << endl;

                    
                    player->body->setForceX(-5);
                    
                    
                    break;
                case SDLK_s:cout << "Push s " << endl;


                    break;
                case SDLK_w: cout << "Push w" << endl;
                    break; 
                case SDLK_d: cout << "Push d " << endl;

                    player->body->setForceX(5);

                    break;
                case SDLK_j: cout << "Push j " << endl;
				default:
					break;
				}
			}


		}
        // UPDATE
        player->updateObject();
       // player->O_tranform->vector.print(" player : ");
        // RENDER
        SDL_RenderCopy(renderer, background, NULL, NULL);
        player->drawObject(renderer, KnightRun);

        SDL_RenderPresent(renderer);


        	}

    
    //cout <<"x : " << player->O_tranform->vector.x << "   y: " << player->O_tranform->vector.y << " " << player->O_width << " " << player->O_height << " " << player->animationRun->frame << " " << player->animationRun->frameCount << " " << player->animationRun->row << endl;



	quitSDL(window, renderer);
	return 0;
}