#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

typedef enum boolean{false, true} bool;

bool init();
bool loadMedia();
void closeSDL();
SDL_Texture* loadTexture( char* path );

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
FILE* fptr;

bool init()
{
    bool success = true;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }

    else
    {
        gWindow = SDL_CreateWindow( "SDLT", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }

        else
        {
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
        }
    }

    return success;
}

SDL_Texture* loadTexture( char* path )
{
    SDL_Texture* newTexture = NULL;

    SDL_Surface* loadedSurface = IMG_Load( path );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError() );
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError() );
        }

        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}

void closeSDL()
{
    SDL_DestroyWindow( gWindow );
    SDL_DestroyRenderer( gRenderer );
    gWindow = NULL;
    gRenderer = NULL;

    IMG_Quit();
    SDL_Quit();
}