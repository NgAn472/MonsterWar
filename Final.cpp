#include "Final.h"
using namespace std;
// vào menu game
int Final ::Game_menu()
{
    load_Music(bkg_music);

    // SDL_RenderClear(gRenderer);
    int z = 10;
    Show_image(bkg, bkg_rect);
    Show_image(bkg_play, bkg_play_rect);
    Show_image(bkg_setting, bkg_setting_rect);
    Show_image(bkg_quit, bkg_quit_rect);

    // Đoạn mã lệnh để phát nhạc
    if (Mix_PlayingMusic() == 0)
    {
        // Play the music
        Mix_PlayMusic(gMusic, -1);
    }
    while (!quit)
    {
        int x, y;

        if (SDL_PollEvent(&e) == 0)
            continue;
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            Mix_PlayChannel(-1, gClick, 0);
            SDL_GetMouseState(&x, &y);
         
            if ((x >= bkg_quit_x && x <= (bkg_quit_x + 250)) && (y >= bkg_quit_y && y <= (bkg_quit_y + 100)))
            {
                z = -1;

                quit = true;
            }
            else if ((x >= bkg_setting_x && x <= (bkg_setting_x + 250)) && (y >= bkg_setting_y && y <= (bkg_setting_y + 100)))
            {
                z = 3;
                Mix_HaltMusic();
                break;
            }
            else if ((x >= bkg_play_x && x <= (bkg_play_x + 250)) && (y >= bkg_play_y && y <= (bkg_play_y + 100)))
            {
                z = 1;
                Mix_HaltMusic();
                break;
            }
          
        }
        if (e.type == SDL_QUIT)
            quit = true;
        z = -1;
    }
    return z;
}

int Final::Game_setting()
{
    SDL_RenderClear(gRenderer);
    load_Music(bkg_music);

    Show_image(level_setting, Level_setting);
    Show_image(level1, Level1);
    Show_image(level2, Level2);
    Show_image(level3, Level3);
    Show_image(monster_s, Monster_pick);
    Show_image(flame, Flame);
    Show_image(play_setting, Play_setting);
    Show_image(menu_setting, Menu_setting);
    Show_image(bkg_quit, bkg_quit_rect);


    int z;
    // Đoạn mã lệnh để phát nhạc
    if (Mix_PlayingMusic() == 0)
    {
        // Play the music
        Mix_PlayMusic(gMusic, -1);
    }
    while (!quit)
    {
        int x, y;

        if (SDL_PollEvent(&e) == 0)
            continue;
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            Mix_PlayChannel(-1, gClick, 0);
            SDL_GetMouseState(&x, &y);
          
            if ((x >= bkg_quit_x && x <= (bkg_quit_x + 250)) && (y >= bkg_quit_y && y <= (bkg_quit_y + 100)))
            {
                z = -1;

                quit = true;
            }
            else if ((x >= bkg_play_x && x <= (bkg_setting_x + 100)) && (y >= bkg_play_y && y <= (bkg_play_y + 100)))
            {
                level_game = 1;
                Show_image(level1, Level1);
                Show_image(level2, Level2);
                Show_image(level3, Level3);
                Show_image(selected, Level1);
            }
            else if ((x >= bkg_play_x+100 && x <= (bkg_setting_x + 200)) && (y >= bkg_play_y && y <= (bkg_play_y + 100)))
            {
                level_game = 2;
                Show_image(level1, Level1);
                Show_image(level2, Level2);
                Show_image(level3, Level3);
                Show_image(selected, Level2);
            }
            else if ((x >= bkg_play_x+200 && x <= (bkg_setting_x + 300)) && (y >= bkg_play_y && y <= (bkg_play_y + 100)))
            {
                level_game = 3;
                Show_image(level1, Level1);
                Show_image(level2, Level2);
                Show_image(level3, Level3);
                Show_image(selected, Level3);
            }
            else if ((x >= bkg_setting_x && x <= (bkg_setting_x + 125)) && (y >= bkg_setting_y && y <= (bkg_setting_y + 100)))
            {
                z = 1;
                Mix_HaltMusic();
                break;
            }
            else if ((x >= Menu_setting.x && x <= Menu_setting.x + Menu_setting.w) && (y >= Menu_setting.y && y <= (Menu_setting.y + 100)))
            {
                z = 0;
                Mix_HaltMusic();
                break;
            }
        }
        if (e.type == SDL_QUIT)
        {
            quit = true;
            z = -1;
        }
    }
    return z;
}

// reset mang b
void Final ::reset_count()
{
    for (int i = 0; i < num_skill; i++)
    {
        b[i] = 0;
    }
}

void Final ::Game_init()
{
}

int Final ::Game_play()
{
    int z;
    int q = 0;
    int turn = 1;
    bool check = false;
    // int q = 1;
    Mix_FreeMusic(gMusic);
    gMusic = NULL;
    load_Music(ing_music);

    if (Mix_PlayingMusic() == 0)
    {
        // Play the music
        Mix_PlayMusic(gMusic, -1);
    }

    Show_image(water_image, bkg_rect);
    Show_image(game_play_board, Game_play_board);
    Show_image(game_check_possible_move, check_possible_move_rect);
    SDL_Surface *task = IMG_Load(heal_task);
    SDL_Texture *task_heal_texture = SDL_CreateTextureFromSurface(gRenderer, task);
    task = IMG_Load(mana_task);
    SDL_Texture *task_mana_texture = SDL_CreateTextureFromSurface(gRenderer, task);
    task = IMG_Load(pow_task);
    SDL_Texture *task_pow_texture = SDL_CreateTextureFromSurface(gRenderer, task);
    task = IMG_Load(black_task);

    SDL_Texture *task_black_texture = SDL_CreateTextureFromSurface(gRenderer, task);
    Show_task(task_heal_texture, Black_task_rect_heal_1);
    Show_task(task_black_texture, Black_task_rect_mana_1);
    Show_task(task_black_texture, Black_task_rect_pow_1);

    Show_task(task_heal_texture, Black_task_rect_heal_2);
    Show_task(task_black_texture, Black_task_rect_mana_2);
    Show_task(task_black_texture, Black_task_rect_pow_2);
    
    string animation;
    int hp, mp, pow, def, attack;
    ifstream fin(monster_pick.c_str());
    fin >> animation >> hp >> mp >> pow >> def >> attack;

    Monster player1(animation, hp, mp, pow, def, attack);

    fin.close();
    fin.open("Infor\\Flame_flip.txt");
    fin >> animation >> hp >> mp >> pow >> def >> attack;

    Monster player2(animation, hp, mp, pow, def, attack);
    player2.hp_max = player2.hp_max * level_game;
    player2.attack = player2.attack * level_game;
    int player1hp(player1.hp_max), player1mp(player1.mp), player1pow(player1.pow), player2hp(player2.hp), player2mp(player2.mp), player2pow(player2.pow);

    Game.Board_Init();
    Game.Normalize_Board(b);
 
    int x, y;
    reset_count();

    gFont = TTF_OpenFont("lazy.ttf", 25);

    Show_task(gTexture, Black_task_rect_heal_1);
    double s;

    SDL_Rect *currentClip1;
    SDL_Rect *currentClip2;
    uint32_t t = SDL_GetTicks();
    int frame1 = 0, frame2 = 0;
    while (!quit && player1.hp * player2.hp)
    {
        if (frame1 >= FPS * Act_Normal_Animation_frame)
            frame1 = 0;
        if (frame2 >= FPS * Act_Normal_Animation_frame)
            frame2 = 0;

        currentClip1 = &gSpriteClips[frame1++ / FPS];
        currentClip2 = &gSpriteClips[frame2++ / FPS];

        player1.Animation.render(15, 255, currentClip1);
        player2.Animation.render(785, 255, currentClip2);
        // Update screen
        SDL_RenderPresent(gRenderer);

        if (SDL_PollEvent(&e) == 0 && SDL_GetTicks() - t <= 20000)
            continue;
        if (e.type == SDL_QUIT)
        {
            quit = true;
            z = -1;
            break;
        }
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {

            Mix_PlayChannel(-1, gClick, 0);
            while (((SDL_GetTicks() - t) <= 20000) && turn)
            {
                SDL_GetMouseState(&x, &y);
                
                if (check)
                    Show_image(game_check_possible_move, check_possible_move_rect);
                if ((x >= Board_Position_x && y >= Board_Position_y && x <= (Board_Position_x + Size_of_Col * Piece_Width) && y <= (Board_Position_y + Size_of_Row * Piece_Width)))
                {

                    if (Game.Search_selected_Piece(x, y))
                    {
                        
                       
                        Game.Board_Render();
                        Game.Normalize_Board(b);
                        Show_image(water_image, Board);
                        player2.Animation.render(785, 255, currentClip2);
                        // Update screen
                        SDL_RenderPresent(gRenderer);
                        for (int i = 1; i <= num_skill; i++)
                        {
                            Show_task(Game.text_image[i], Position_Skill_pick, 0, 0, i);
                            string point = to_string(b[i - 1]);
                            loadText(point);
                            Show_task(gTexture, Position_Skill_pick, 1, 0, i);
                        }
                        player1.agl = 10;
                        player1.Monster_action(b, player2, 1);
                        if (player2.hp != player2hp)
                        {
                            s = (player2.hp_max - player2.hp) * Heal_task_rect.w / player2.hp_max;
                            Show_task(task_black_texture, Black_task_rect_heal_2);
                            Show_task(task_heal_texture, Black_task_rect_heal_2, s, 1);
                            player2hp = player2.hp;
                        }

                        //////////////////////////////////////////////////////////////////
                        if (player1.hp != player1hp)
                        {
                            s = (player1.hp == player1.hp_max) ? Black_task_rect_heal_1.w : (player1.hp * Heal_task_rect.w / player1.hp_max);
                            Show_task(task_black_texture, Black_task_rect_heal_1);
                            Show_task(task_heal_texture, Black_task_rect_heal_1, s);
                            player1hp = player1.hp;
                        }
                        //////////////////////////////////////////////////////////////////
                        if (player1.mp != player1mp)
                        {
                            s = (player1.mp == player1.mp_max) ? Black_task_rect_heal_1.w : (player1.mp * Heal_task_rect.w / player1.mp_max);
                            Show_task(task_black_texture, Black_task_rect_mana_1);
                            Show_task(task_mana_texture, Black_task_rect_mana_1, s);
                            player1mp = player1.mp;
                        }
                        //////////////////////////////////////////////////////////////////
                        if (player1pow = player1.pow)
                        {
                            s = (player1.pow == player1.pow_max) ? Black_task_rect_heal_1.w : (player1.pow * Heal_task_rect.w / player1.pow_max);
                            Show_task(task_black_texture, Black_task_rect_pow_1);
                            Show_task(task_pow_texture, Black_task_rect_pow_1, s);
                            player1pow = player1.pow;
                        }
                        //////////////////////////////////////////////////////////////////
                        Game.Board_Render();

                        turn = 0;
                        break;
                    }

                    else
                    {
                        Game.Board_Render();
                        break;
                    }

                    reset_count();
                }
                else if (x >= (Board_Position_x + Size_of_Col * Piece_Width) && x <= (Board_Position_x + Size_of_Col * Piece_Width + check_possible_move_rect.w) && y >= (Board_Position_y + Size_of_Row * Piece_Width) && y <= (Board_Position_y + Size_of_Row * Piece_Width + check_possible_move_rect.h))
                {
                    if (Game.Find_Position_Move())
                    {
                        check = 1;
                        Show_image(check_right, check_possible_move_rect);
                    }
                    else
                    {
                        Game.Board_Init();
                        Game.Normalize_Board(b);
                        reset_count();
                    }
                    Game.reset_find_possible_move();
                    break;
                }
                else
                    continue;
            }
        }
        if ((SDL_GetTicks() - t) >= 20000 || !turn)
        {
           

            //////////////////////////////////////////////////////////// Player 2
            if (!player1.hp * player2.hp)
              {  break;}
            while (!Game.Find_Position_Move())
            {
                Game.Board_Init();
                Game.Normalize_Board(b);
                reset_count();
            }
            int total = Game.u.size();
            
            int random = rand() % total;

          
            
           
            Game.Search_selected_Piece(Game.u[random].second, Game.u[random].first, 1);
            Game.Board_Render();

            /////////////////////////////////////
            if (Game.Search_selected_Piece(Game.v[random].second, Game.v[random].first, 1))
            {

                Game.Board_Render();

                Game.Normalize_Board(b);
               
                player2.agl = 10;
                Show_image(water_image, Board);
                for (int i = 1; i <= num_skill; i++)
                {
                    Show_task(Game.text_image[i], Position_Skill_pick, 0, 0, i);
                    string point = to_string(b[i - 1]);
                    loadText(point);
                    Show_task(gTexture, Position_Skill_pick, 1, 0, i);
                }
                player2.Monster_action(b, player1, 2);
                if (player1.hp != player1hp)
                {
                    s = (player1.hp == player1.hp_max) ? Black_task_rect_heal_1.w : (player1.hp * Heal_task_rect.w / player1.hp_max);
                    Show_task(task_black_texture, Black_task_rect_heal_1);
                    Show_task(task_heal_texture, Black_task_rect_heal_1, s);
                    player1hp = player1.hp;
                }
                if (player2.hp != player2hp)
                {
                    s = (player2.hp_max - player2.hp) * Heal_task_rect.w / player2.hp_max;
                    Show_task(task_black_texture, Black_task_rect_heal_2);
                    Show_task(task_heal_texture, Black_task_rect_heal_2, s, 1);
                    player2hp = player2.hp;
                }
                //////////////////////////////////////////////////////////////////
                if (player2.mp != player2mp)
                {
                    s = (player2.mp_max - player2.mp) * Heal_task_rect.w / player2.mp_max;
                    Show_task(task_black_texture, Black_task_rect_mana_2);
                    Show_task(task_mana_texture, Black_task_rect_mana_2, s, 1);
                    player2mp = player2.mp;
                }
                //////////////////////////////////////////////////////////////////
                if (player2.pow != player2pow)
                {
                    s = (player2.pow_max - player2.pow) * Heal_task_rect.w / player2.pow_max;
                    Show_task(task_black_texture, Black_task_rect_pow_2);
                    Show_task(task_pow_texture, Black_task_rect_pow_2, s, 1);
                    player2pow = player2.pow;
                }
                //////////////////////////////////////////////////////////////////
                Game.Board_Render();
                Show_image(game_check_possible_move, check_possible_move_rect);
            }

            reset_count();
            Game.reset_find_possible_move();
            turn = 1;
        }
        if (!quit)
        {
          
            t = SDL_GetTicks();
        }
    }
    if (player1.hp == 0)
        result = 0;
    else
        result = 1;
    /////////////////////////////////////////////////// free
    z = 2;

    player1.Animation.free();
    player2.Animation.free();
    Game.free();
    SDL_DestroyTexture(task_heal_texture);
    SDL_DestroyTexture(task_mana_texture);
    SDL_DestroyTexture(task_pow_texture);
    SDL_DestroyTexture(task_black_texture);
    SDL_FreeSurface(task);
    task_heal_texture = NULL;
    IMG_Quit();
   
    return z;
}

int Final::Game_result()
{
    int z;
     load_Music(bkg_music);
      if (Mix_PlayingMusic() == 0)
    {
        // Play the music
        Mix_PlayMusic(gMusic, -1);
    }
    if (result)
    {
        Show_image(win, bkg_rect);
    }
    else
    {
        Show_image(lose, bkg_rect);
    }
    while (!quit)
    {
        int x, y;

        if (SDL_PollEvent(&e) == 0)
            continue;
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            Mix_PlayChannel(-1, gClick, 0);
            SDL_GetMouseState(&x, &y);
       
            if ((x >= bkg_quit_x && x <= (bkg_quit_x + 250)) && (y >= bkg_quit_y && y <= (bkg_quit_y + 100)))
            {
                z = -1;

                quit = true;
            }
        }
        if (e.type == SDL_QUIT)
        {
            quit = true;
            z = -1;
        }
    }
    return z;
}
