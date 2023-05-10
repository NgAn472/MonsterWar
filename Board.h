#pragma once

#include "Piece.h"

class Board_game
{
public:
    Piece Piece_Board[Size_of_Row][Size_of_Col];
    int a[num_skill] = {0}; // Num of Skill = 7;
    SDL_Renderer *Renderer = NULL;
    vector<pair<int, int>> u /*vector luư vị trí đổi đầu*/, v /*lưu vị trí đổi khi xét ngữ cảnh*/;
    SDL_Texture *text_image[num_skill + 1] = {NULL};
    SDL_Texture *text_selected = NULL;
    Board_game(SDL_Renderer *r, SDL_Texture *t)
    {
        Renderer = r;
    }
    Board_game(){

    };
    void Board_Init();
    void Board_Render();
    bool Search_selected_Piece(int x_of_mouse, int y_of_mouse, int id = 0);
    bool Check_Move_Piece(int y_first_choose, int x_first_choose, int y_second_choose, int x_second_choose);
    bool Check_Start();
    void Count_NumOfSkill();
    void swap_Piece_in_Board(int y_first, int x_first, int i, int j);
    void Normalize_Board(int a[]);
    void Full_fillBoard();
    bool Find_Position_Move();
    void reset_find_possible_move();
    void free();
};
