
#include "Final.h"
#include <SDL2/SDL_ttf.h>
using namespace std;

int main(int argc, char *argv[])
{
    srand(time(0));
    initSDL(gWindow, gRenderer);
    int status = 0;
    SDL_Event e;
    Final Game(gRenderer, e);

    while (!quit)
    {
        switch (status)
        {

        case 0:
            status = Game.Game_menu();
            break;
        case 1:

            status = Game.Game_play();
            break;
        case 2:
            status = Game.Game_result();
            break;
        case 3:
            status = Game.Game_setting();
            break;
        default:
            quit = true;
            break;
        }
        cout << "Quit main";
        if (e.type == SDL_QUIT)
        {
            quit = true;
            cout << "quit main";
        }
    }
    close();
    return 0;
}