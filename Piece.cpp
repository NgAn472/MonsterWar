#include "Piece.h"

// void Piece ::render()
// {
//     char t = (char)random_skill + '0';
//     string file_name = "Image/";
//     file_name += t;
//     file_name += "Skill.png";
//     SDL_Surface *image = NULL;
//     image = IMG_Load(file_name.c_str());
//     pieceTexture = SDL_CreateTextureFromSurface(pieceRenderer, image);
//     SDL_RenderCopy(pieceRenderer, pieceTexture, NULL, &Piece_rect);
//     SDL_DestroyTexture(pieceTexture);
//     if (selected == 1)
//     {
//         file_name = "Image/selected.png";
//         image = IMG_Load(file_name.c_str());
//         pieceTexture = SDL_CreateTextureFromSurface(pieceRenderer, image);
//         SDL_RenderCopy(pieceRenderer, pieceTexture, NULL, &Piece_rect);
//         SDL_DestroyTexture(pieceTexture);
        
//     }
//     SDL_FreeSurface(image);
    
//     pieceTexture = NULL;
//     IMG_Quit();
//     SDL_RenderPresent(pieceRenderer);
// }
void Piece ::swapPiece(Piece anotherPiece, int speed)
{
    SDL_Rect thisRect = this->Piece_rect;
    SDL_Rect anotherRect = anotherPiece.Piece_rect;

    int x_anotherPiece = anotherRect.x; // tọa độ x miếng another
    int y_anotherPiece = anotherRect.y; // tọa độ x miếng another
    while (thisRect.y != y_anotherPiece)
    {
        if (thisRect.y > y_anotherPiece)
        {
            thisRect.y -= speed;
            anotherRect.y += speed;
        }
        else
        {
            thisRect.y += speed;
            anotherRect.y -= speed;
        }
        // this->render_empty();
        // anotherPiece.render_empty();
        // anotherPiece.render();
        // this->render();
    }

    while (thisRect.x != x_anotherPiece)
    {
        if (thisRect.x > x_anotherPiece)
        {
            thisRect.x -= speed;
            anotherRect.x += speed;
        }
        else
        {
            thisRect.x += speed;
            anotherRect.x -= speed;
        }
        // this->render_empty();
        // anotherPiece.render_empty();
        // anotherPiece.render();
        // this->render();
    }
}