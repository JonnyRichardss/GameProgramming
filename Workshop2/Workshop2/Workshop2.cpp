// Workshop2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SDL.h"
bool GLOBAL_QUIT_FLAG = false;
void ProcessEvents() {
    
}
void ExitGame() {
    SDL_Quit();
    GLOBAL_QUIT_FLAG = true;
}
int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return 1;
    SDL_DisplayMode mode;

    if (SDL_GetDesktopDisplayMode(0, &mode)<0)
        return 1;
    std::cout << "Hello World!\n";
    SDL_Window* window = SDL_CreateWindow("Jonathan Richards -- 26541501", mode.w / 4, mode.h / 4, 800, 600, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    
    std::cout << SDL_GetWindowFlags(window) << "\n";
    SDL_Delay(500);
    SDL_MaximizeWindow(window);
    std::cout << SDL_GetWindowFlags(window) << "\n";

    std::cout << "Loop started\n";
    int framecounter = 0;
    while (!GLOBAL_QUIT_FLAG) {
        
        SDL_Event event;
        SDL_GetDesktopDisplayMode(0, &mode);
        while (SDL_PollEvent(&event)!=0) {
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_F11:
                    if (SDL_GetWindowFlags(window)&SDL_WINDOW_MAXIMIZED) {
                        SDL_RestoreWindow(window);
                    }
                    else {
                        SDL_MaximizeWindow(window);
                    }
                    break;
                case SDLK_ESCAPE:
                    ExitGame();
                    break;
                }
            }          
            if (event.type == SDL_QUIT) {
                ExitGame();
                GLOBAL_QUIT_FLAG = true;
            } 
        }
        //SDL_RenderFlush(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255,0,0, 255);
        SDL_Rect rectangle;
        rectangle.x = 50;
        rectangle.y = 50;
        rectangle.w = 100;
        rectangle.h = 100;
        SDL_RenderDrawRect(renderer, &rectangle);
        SDL_RenderFillRect(renderer, &rectangle);
        SDL_RenderDrawLine(renderer,200, 100, 200, 500);
        SDL_RenderPresent(renderer);

        std::cout << "Frame " << framecounter++<<"\n";
    }
    return 0;
}

