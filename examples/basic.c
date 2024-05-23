#include <raylib.h>
#include <rayscene.h>
#include <stdlib.h>
void CenterWindow( int monitor );

#define WINDOW_SCALE 2

int main( )
{
    InitWindow( 1, 1, "Test" );
    Vector2 monitorSize = { ( float )GetMonitorWidth( GetCurrentMonitor( ) ),
                            ( float )GetMonitorHeight( GetCurrentMonitor( ) ) };
    SetWindowSize( ( int )monitorSize.x / WINDOW_SCALE,
                   ( int )monitorSize.y / WINDOW_SCALE );
    CenterWindow( GetCurrentMonitor( ) );

    while ( !WindowShouldClose( ) )
    {
        BeginDrawing( );
        ClearBackground( GREEN );
        EndDrawing( );
    }

    CloseWindow( );
    return EXIT_SUCCESS;
}

void CenterWindow( int monitor )
{
    Vector2 monitorPosition = GetMonitorPosition( monitor );
    Vector2 monitorSize = { ( float )GetMonitorWidth( monitor ),
                            ( float )GetMonitorHeight( monitor ) };
    Vector2 windowSize = { ( float )GetScreenWidth( ),
                           ( float )GetScreenHeight( ) };
    Vector2 windowPosition = {
        monitorPosition.x + ( ( monitorSize.x / 2 ) - ( windowSize.x / 2 ) ),
        monitorPosition.y + ( ( monitorSize.y / 2 ) - ( windowSize.y / 2 ) ) };
    SetWindowPosition( ( int )windowPosition.x, ( int )windowPosition.y );
}
