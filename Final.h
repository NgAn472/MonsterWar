#include "Monster.h"
#include <fstream>
class Final
{
public:
    int b[num_skill] = {0};
    SDL_Renderer *Renderer = NULL;
    SDL_Texture *Texture = NULL;
    SDL_Event e;
    Board_game Game;
    int level_game = 1;
    string monster_pick = "Infor\\1.txt";
    int result;
    Final(SDL_Renderer *r, SDL_Event event)
    {
        Renderer = r;
        e = event;
        Game = Board_game(Renderer, Texture);
    }
    int Game_menu();
    int Game_setting();
    void Game_init();
    int Game_play();
    int Game_result();
    void Game_Quit();
    void Game_selected();
    void reset_count();

};