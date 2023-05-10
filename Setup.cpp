

#include "Setup.h"

bool quit = false;

const char *bkg = "Image/Bkg.png";
const char *bkg_play = "Image/bkg_play.png";
const char *bkg_setting = "Image/bkg_setting.png";
const char *bkg_quit = "Image/bkg_quit.png";

const char* play_setting = "Image\\play_mini.png";
const char* menu_setting = "Image\\menu.png";
const char* level_setting = "Image\\Level.png";
 const char* level1 = "Image\\level1.png";
 const char* level2= "Image\\level2.png";;
 const char* level3 = "Image\\level3.png";
const char* selected = "Image\\selected.png";
const char* flame = "Image\\Flame.png";
const char* monster_s = "Image\\monster_pick.png";

const char* win = "Image\\Win.png";
const char* lose = "Image\\Lose.png";

const char *water_image = "Image\\bkg_play2.png";
const char *game_play_board = "Image\\Board.png";
const char *game_check_possible_move = "Image\\check-mark.png";
const char *heal_task = "Image/Heal.png";
const char *mana_task = "Image\\Mana.png";
const char *pow_task = "Image\\Power.png";
const char *black_task = "Image\\Black.png";
const char *check_right = "Image\\check_right.png";

const char *bkg_music = "Audio\\game_menu.mp3";
const char *ing_music = "Audio\\Ingame_normal.mp3";

const char *Action1_image = "Image/Wolf.png";


SDL_Rect bkg_rect = {0, 0, Screen_Width, Screen_Height};
SDL_Rect Action1 = {15, 225, 200, 200};
SDL_Rect Action2 = {785, 225, 200, 200};
SDL_Rect bkg_play_rect = {bkg_play_x, bkg_play_y, 250, 100};
SDL_Rect bkg_setting_rect = {bkg_setting_x, bkg_setting_y, 250, 100};
SDL_Rect bkg_quit_rect = {bkg_quit_x, bkg_quit_y, 250, 100};
SDL_Rect check_possible_move_rect = {750, 500, 100, 100};
SDL_Rect Heal_task_rect = {3, 3, 496, 35};
SDL_Rect Mana_task_rect = {3, 42, 496, 39};
SDL_Rect Pow_task_rect = {3, 85, 496, 36};
SDL_Rect Black_task_rect_heal_1 = {3, 3, 496, 35};
SDL_Rect Black_task_rect_mana_1 = {3, 41, 496, 39};
SDL_Rect Black_task_rect_pow_1 = {3, 85, 496, 36};
SDL_Rect Black_task_rect_heal_2 = {501, 3, 496, 35};
SDL_Rect Black_task_rect_mana_2 = {501, 41, 496, 39};
SDL_Rect Black_task_rect_pow_2 = {501, 85, 496, 36};
SDL_Rect Position_Skill_pick = {Board_Position_x + Piece_Width * 4, Board_Position_y- Piece_Width , Piece_Width, Piece_Width};
SDL_Rect Game_play_board = {0, 0, 1000, 126};
SDL_Rect Board = {Board_Position_x, Board_Position_y, Board_Position_x + Size_of_Col *Piece_Width, Board_Position_y + Size_of_Row *Piece_Width};
SDL_Rect Play_setting ={bkg_setting_x, bkg_setting_y,125, 100} ;
SDL_Rect Menu_setting = {bkg_setting_x+125, bkg_setting_y, 125, 100};
SDL_Rect Level_setting = {bkg_play_x-250, bkg_play_y, 250, 100};
SDL_Rect Level1 = {bkg_play_x, bkg_play_y, 100, 100};
SDL_Rect Level2 = {bkg_play_x+100, bkg_play_y, 100, 100};
SDL_Rect Level3 = {bkg_play_x+200, bkg_play_y, 100, 100};
SDL_Rect Flame = {350, 80, 100, 100};
SDL_Rect Monster_pick = {100, 80, 250, 100};
// Create window
SDL_Window *gWindow = NULL;

// Surface
SDL_Surface *gSurface = NULL;

// Renderer
SDL_Renderer *gRenderer = NULL;

// Texture
SDL_Texture *gTexture = NULL;

// Globally used font
TTF_Font *gFont = NULL;

SDL_Surface *textSurface = NULL;

// The music that will be played
Mix_Music *gMusic = NULL;

Mix_Chunk *gClick = NULL;

Mix_Chunk *gBlock_break;

SDL_Color textColor = {255, 255, 255};

// SDL_Rect Action1 = {15, 225, 200, 200};

void initSDL(SDL_Window *&window, SDL_Renderer *&renderer)
{
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
                logSDLError(std::cout, "SDL_Init", true);
        window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Screen_Width, Screen_Height, SDL_WINDOW_SHOWN);

        if (window == nullptr)
                logSDLError(std::cout, "CreateWindow", true);

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        if (renderer == nullptr)
                logSDLError(std::cout, "CreateRenderer", true);
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        SDL_RenderSetLogicalSize(renderer, Screen_Width, Screen_Height);
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
        {
                printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        }
        // Initialize SDL_ttf
        if (TTF_Init() == -1)
        {
                printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        }

        gClick = Mix_LoadWAV("Audio\\Click.mp3");
        gBlock_break = Mix_LoadWAV("Audio\\Block_break.mp3");
}

void logSDLError(std::ostream &os, const std::string &msg, bool fatal)
{
        os << msg << "log Error: " << SDL_GetError() << std::endl;
        if (fatal)
        {
                SDL_Quit();
                exit(1);
        }
}

void Show_task(SDL_Texture *texture, SDL_Rect rect, int x, int t, int y)
{
        SDL_Rect Re_rect;

        IMG_Init(IMG_INIT_PNG);
        if (!y)
        {
                if (t == 0)
                        Re_rect = {rect.x, rect.y, x, rect.h};
                else
                {

                        Re_rect = {rect.x + x, rect.y, rect.w - x, rect.h};
                }
        }
        else{
                Re_rect = {rect.x + x*Piece_Width, rect.y + y* Piece_Width, rect.w, rect.h};
        }
        SDL_RenderCopy(gRenderer, texture, NULL, &Re_rect);
        SDL_RenderPresent(gRenderer);
        IMG_Quit();
}

void loadText(string textureText)
{
        textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
        gTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
}

void close()
{
        // Free loaded images

        // Free the music
        Mix_FreeMusic(gMusic);
        gMusic = NULL;

        Mix_FreeChunk(gClick);
        gClick = NULL;

        TTF_CloseFont(gFont);
        gFont = NULL;
        // Destroy window
        SDL_DestroyRenderer(gRenderer);
        SDL_DestroyWindow(gWindow);
        SDL_DestroyTexture(gTexture);
        gTexture = NULL;
        gWindow = NULL;
        gRenderer = NULL;

        // Quit SDL subsystems
        IMG_Quit();
        SDL_Quit();
}

void Show_image(const char *str_gSurface, SDL_Rect rect)
{
        IMG_Init(IMG_INIT_PNG);
        gSurface = IMG_Load(str_gSurface);
        if (gSurface == NULL)
        {
                cerr << "Unable to load gSurface!" << str_gSurface << endl
                     << "SDL Error: " << SDL_GetError();
        }
        else
        {
                gTexture = SDL_CreateTextureFromSurface(gRenderer, gSurface);
                SDL_RenderCopy(gRenderer, gTexture, NULL, &rect);
                SDL_RenderPresent(gRenderer);
                SDL_FreeSurface(gSurface);
        }
        SDL_DestroyTexture(gTexture);
        gTexture = NULL;
        IMG_Quit();
}

void load_Music(const char *path)
{
        gMusic = Mix_LoadMUS(path);
        // Kiểm tra con trỏ tới tệp nhạc
        if (gMusic == NULL)
        {
                printf("Lỗi: không thể trỏ đến tệp nhạc! %s\n");
                return;
        }

        // Đoạn mã lệnh để phát nhạc
        if (Mix_PlayMusic(gMusic, -1) == -1)
        {
                printf("Lỗi khi phát nhạc: %s", Mix_GetError());
        }
}
