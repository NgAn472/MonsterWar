#pragma once
#include "Setup.h"
using namespace std;

// enum class Piece_skills{
//     Empty,
//     Sword,
//     Shield,
//     Heart,
//     Fire,
//     Mana,
// };

class Piece{
    public:
        int x_pos; // position
        int y_pos; //
        int height = 50;
        int width = 50;
        int selected = 0;// trạng thái bị chọn(1), k chọn(0)
        int random_skill = 0; // số random ban đầu -> skill
        SDL_Rect Piece_rect = { x_pos, y_pos, width, height};
        SDL_Renderer* pieceRenderer = gRenderer;
        SDL_Texture* pieceTexture = gTexture;
        Piece() {};
        ~Piece() {}; 
        // void render();
        // void render_empty();
        void swapPiece(Piece anotherPiece, int speed);

        
};
