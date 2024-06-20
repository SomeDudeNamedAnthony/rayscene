#include "./MyStage1.hh"
#include "./MyStage2.hh"
#include "Stager/Stage.hh"
#include "Stager/Theatre.hh"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <cstdlib>
#include <exception>
#include <iostream>

int main( )
{
    try
    {
        if ( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER )
             != 0 )
        {
            std::cout << "SDL failed to initialize because: " << SDL_GetError( )
                      << '\n';
            return EXIT_FAILURE;
        }

        SDL_Rect displayBounds{ };
        SDL_GetDisplayBounds( 0, &displayBounds );

        auto *window
            = SDL_CreateWindow( "", SDL_WINDOWPOS_CENTERED_DISPLAY( 0 ),
                                SDL_WINDOWPOS_CENTERED_DISPLAY( 0 ),
                                displayBounds.w / 2, displayBounds.h / 2, 0 );

        if ( window == nullptr )
        {
            std::cout << "SDL failed to create window because: "
                      << SDL_GetError( ) << '\n';
            return EXIT_FAILURE;
        }

        auto *surface = SDL_GetWindowSurface( window );

        MyStage1 myStage1;
        MyStage2 myStage2;
        Stager::Theatre theatre{ "MyTheatre" };
        theatre.addStage( myStage1 );
        theatre.addStage( myStage2 );

        theatre.changeStage( "", true );

        auto should_close = false;
        while ( !should_close )
        {
            SDL_Event event;
#ifndef __llvm__
#pragma unroll
#endif
            while ( SDL_PollEvent( &event ) != 0 )
            {
                if ( event.type == SDL_QUIT )
                {
                    should_close = true;
                }
            }

            SDL_UpdateWindowSurface( window );
        }
        SDL_DestroyWindow( window );
        SDL_Quit( );
        return EXIT_SUCCESS;
    }
    catch ( std::exception &e )
    {
        std::cout << e.what( ) << '\n';
        return EXIT_FAILURE;
    }
}