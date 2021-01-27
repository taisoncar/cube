#include "cube.h"
#include "SDLT.h"

#define CWIDTH 70
#define CHEIGHT 70

void setcolor(char* string)
{
    if ( strcmp(string, "G") == 0 ) //green
    {
        SDL_SetRenderDrawColor( gRenderer, 0x00, 0xFF, 0x00, 0xFF );
    }

    else if ( strcmp(string, "B") == 0 ) //blue
    {
        SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0xFF, 0xFF );
    }

    else if ( strcmp(string, "R") == 0 ) //red
    {
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
    }

    else if ( strcmp(string, "O") == 0 ) //orange
    {
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x70, 0x00, 0xFF );
    }

    else if ( strcmp(string, "W") == 0 ) //white
    {
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    }

    else if ( strcmp(string, "Y") == 0 ) //yellow
    {
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0x00, 0xFF );
    }

    else
    {
        fprintf(fptr, "error finding specific color in a face");
    }
    
}

void colorface( char *matrix[3][3], int x, int y ) // (x, y) = bottom left coordinate of the cube
{
    int xtemp = x;
    int ytemp = y;
    for( int r=0; r<3; ++r )
    {
        x = xtemp;
        for( int c=0; c<3; ++c )
        {
            SDL_Rect cube = { x, y, CWIDTH, CHEIGHT };
            setcolor( matrix[c][r] );
            SDL_RenderFillRect( gRenderer, &cube);
            SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );      
            SDL_RenderDrawRect( gRenderer, &cube );
            x += CWIDTH;
        }
        y -= CHEIGHT;
    }
}

void colorcube()
{
    colorface( front.color,
            (( SCREEN_WIDTH - ( CWIDTH * 12 ))/2) + ( CWIDTH * 3 ),
            (( SCREEN_HEIGHT - ( CHEIGHT * 9 ))/2) + ( CHEIGHT * 6 )
            );
    colorface( back.color,
            (( SCREEN_WIDTH - ( CWIDTH * 12 ))/2) + ( CWIDTH * 9 ),
            (( SCREEN_HEIGHT - ( CHEIGHT * 9 ))/2) + ( CHEIGHT * 6 )
            );
    colorface( right.color,
            (( SCREEN_WIDTH - ( CWIDTH * 12 ))/2) + ( CWIDTH * 6 ),
            (( SCREEN_HEIGHT - ( CHEIGHT * 9 ))/2) + ( CHEIGHT * 6 )
            );
    colorface( left.color,
            (( SCREEN_WIDTH - ( CWIDTH * 12 ))/2) + ( CWIDTH * 0 ),
            (( SCREEN_HEIGHT - ( CHEIGHT * 9 ))/2) + ( CHEIGHT * 6 )
            );
    colorface( up.color,
            (( SCREEN_WIDTH - ( CWIDTH * 12 ))/2) + ( CWIDTH * 3 ),
            (( SCREEN_HEIGHT - ( CHEIGHT * 9 ))/2) + ( CHEIGHT * 3 )
            );
    colorface( down.color,
            (( SCREEN_WIDTH - ( CWIDTH * 12 ))/2) + ( CWIDTH * 3 ),
            (( SCREEN_HEIGHT - ( CHEIGHT * 9 ))/2) + ( CHEIGHT * 9 )
            );    
}

int main( int argc, char* args[] )
{
    printf( "Welcome to my cube simulator in c\n");
    initcube();
    bool quit = false;
    SDL_Event e;

	if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }

	else
	{
        SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );
        SDL_RenderClear( gRenderer );
        colorcube();
        printcube();
        SDL_RenderPresent( gRenderer );
        while( !quit )
		{
			while( SDL_PollEvent( &e ) != 0 )
			{
				if( e.type == SDL_QUIT )
				{
					quit = true;
				}
                else if( e.type == SDL_KEYDOWN )
                {
                    switch( e.key.keysym.sym )
                    {
                        case SDLK_f:
                        notation_f();
						break;

						case SDLK_b:
						notation_b();
						break;

						case SDLK_r:
						notation_r();
						break;

						case SDLK_l:
                        notation_l();
						break;

                        case SDLK_u:
                        notation_u();
						break;

                        case SDLK_d:
                        notation_d();
						break;
                    }
                    printcube();
                    SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );
                    SDL_RenderClear( gRenderer );
                    colorcube();
                    printcube();
                    SDL_RenderPresent( gRenderer );
                }
            }
		}
	}
    closeSDL();
    endcube();
    return 0;
}
