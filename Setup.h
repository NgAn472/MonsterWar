#ifndef _SETUP_H_
#define _SETUP_H_
using namespace std;
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

extern bool quit;

const int Screen_Width = 1000;
const int Screen_Height = 650;
const int FPS = 6;
const int num_skill = 7;

const int Size_of_Col = 9;
const int Size_of_Row = 7;

const int Board_Position_x = 275;
const int Board_Position_y = 150;
const int bkg_play_x = 375;
const int bkg_play_y = 325;
const int bkg_setting_x = 375;
const int bkg_setting_y = 435;
const int bkg_quit_x = 375;
const int bkg_quit_y = 545;

const int Piece_Width = 50;

const std::string WINDOW_TITLE = "MonsterWar";

extern const char* bkg ;
extern const char* bkg_play;
extern const char* bkg_setting;
extern const char* bkg_quit;

extern const char* play_setting;
extern const char* menu_setting;
extern const char* level_setting;
extern const char* level1;
extern const char* level2;
extern const char* level3;
extern const char* selected;
extern const char* flame;
extern const char* monster_s;

extern const char* win;
extern const char* lose;


extern const char* water_image;
extern const char* game_play_board;
extern const char *game_check_possible_move;
extern const char* heal_task;
extern const char* mana_task;
extern const char* pow_task;
extern const char* black_task;
extern const char *check_right;

extern const char* bkg_music;
extern const char* ing_music;

extern const char* Action1_image;
extern SDL_Rect bkg_rect;
extern SDL_Rect Action1;
extern SDL_Rect Action2;
extern SDL_Rect bkg_play_rect;
extern SDL_Rect bkg_setting_rect;
extern SDL_Rect bkg_quit_rect;
extern SDL_Rect Game_play_board;
extern SDL_Rect check_possible_move_rect;
extern SDL_Rect Heal_task_rect;
extern SDL_Rect Mana_task_rect;
extern SDL_Rect Pow_task_rect;
extern SDL_Rect Black_task_rect_heal_1;
extern SDL_Rect Black_task_rect_mana_1;
extern SDL_Rect Black_task_rect_pow_1;
extern SDL_Rect Black_task_rect_heal_2;
extern SDL_Rect Black_task_rect_mana_2;
extern SDL_Rect Black_task_rect_pow_2;
extern SDL_Rect Position_Skill_pick;
extern SDL_Rect Board;
extern SDL_Rect Play_setting;
extern SDL_Rect Menu_setting;
extern SDL_Rect Level_setting;
extern SDL_Rect Level1;
extern SDL_Rect Level2;
extern SDL_Rect Level3;
extern SDL_Rect Flame;
extern SDL_Rect Monster_pick;

extern SDL_Window* gWindow;
extern SDL_Surface* gSurface;
extern SDL_Renderer* gRenderer;
extern SDL_Texture* gTexture;
extern TTF_Font* gFont;
extern SDL_Surface* textSurface;
extern Mix_Music* gMusic;
extern Mix_Chunk* gClick;
extern Mix_Chunk* gBlock_break;
extern SDL_Color textColor;

void initSDL(SDL_Window *&window, SDL_Renderer *&renderer);

void logSDLError(std::ostream &os, const std::string &msg, bool fatal = false);

void close();

void Show_image(const char *str_gSurface, SDL_Rect rect);

// void Show_Broad(char** b, SDL_Rect** a);

void load_Music(const char* path);

void Show_task(SDL_Texture *texture, SDL_Rect rect, int x = Black_task_rect_heal_1.w, int t = 0, int y = 0);

void loadText(string textureText);

#endif
