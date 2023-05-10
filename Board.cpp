#include "Board.h"

// khởi tạo_sàn đấu
void Board_game ::Board_Init()
{
    for (int i = 0; i < Size_of_Row; i++)
    {
        for (int j = 0; j < Size_of_Col; j++)
        {
            Piece_Board[i][j].random_skill = rand() % 7 + 1;
            Piece_Board[i][j].selected = 0;
            Piece_Board[i][j].Piece_rect = {Board_Position_x + j * Piece_Width, Board_Position_y + i * Piece_Width, Piece_Width, Piece_Width};
        }
    }
    IMG_Init(IMG_INIT_PNG);
    SDL_Surface *Surface = NULL;
    string t;
    for (int i = 0; i <= num_skill; i++)
    {

        t = "Image/";
        char skill = i + '0';
        t += skill;
        t += "Skill.png";

        Surface = IMG_Load(t.c_str());
        if (Surface == NULL)
        {
            cerr << "Unable to load Surface!" << t << endl
                 << "SDL Error: " << SDL_GetError();
        }
        else
        {
            text_image[i] = SDL_CreateTextureFromSurface(Renderer, Surface);
        }
    }
    t = "Image/selected.png";
    Surface = IMG_Load(t.c_str());
    text_selected = SDL_CreateTextureFromSurface(Renderer, Surface);
    SDL_FreeSurface(Surface);
    Surface = NULL;
    IMG_Quit();
}

// in sàn đấu
void Board_game ::Board_Render()
{
    SDL_Surface *Surface = NULL;
    for (int i = 0; i < Size_of_Row; i++)
    {
        for (int j = 0; j < Size_of_Col; j++)
        {
            SDL_RenderCopy(Renderer, text_image[Piece_Board[i][j].random_skill], NULL, &Piece_Board[i][j].Piece_rect);
            if (Piece_Board[i][j].selected == 1)
            {
                SDL_RenderCopy(Renderer, text_selected, NULL, &Piece_Board[i][j].Piece_rect);
            }
        }

        SDL_RenderPresent(Renderer);
    }
}

void Board_game::Normalize_Board(int b[])
{
    while (Check_Start())
    {

        // cout << endl;

        // for (int i = 0; i < Size_of_Row; i++)
        // {
        //     for (int j = 0; j < Size_of_Col; j++)
        //     {
        //         cout << Piece_Board[i][j].random_skill << ";" << Piece_Board[i][j].selected << " ";
        //     }

        //     cout << endl;
        // }
        Full_fillBoard();

        for (int i = 0; i < num_skill; i++)
        {
            b[i] += a[i];
            a[i] = 0;
        }
    }
}

bool Board_game ::Check_Start()
{
    Count_NumOfSkill();
    Board_Render();
    for (int i = 0; i < num_skill; i++)
    {
        if (a[i] != 0)
            return true;
    }
    return false;
}

void Board_game ::Full_fillBoard()
{
    for (int j = 0; j < Size_of_Col; j++)
    {
        for (int i = Size_of_Row - 1; i >= 0; i--)
        {
            if (Piece_Board[i][j].random_skill == 0)
            {
                int k = i;
                while (k >= 0 && Piece_Board[k][j].random_skill == 0)
                    k--;
                if (k >= 0)
                {
                    Piece_Board[i][j].random_skill = Piece_Board[k][j].random_skill;
                    Piece_Board[k][j].random_skill = 0;
                }
                else
                {
                    Piece_Board[i][j].random_skill = rand() % 7 + 1;
                }
                Mix_PlayChannel(-1, gBlock_break, 0);
            }
        }
    }
    Board_Render();
}

// kiểm tra khả năng di chuyển
bool Board_game ::Check_Move_Piece(int y_first_choose, int x_first_choose, int y_second_choose, int x_second_choose)
{
    bool check_position;
    if ((y_first_choose == y_second_choose && x_first_choose == x_second_choose - 1) || (y_first_choose == y_second_choose && x_first_choose == x_second_choose + 1) ||
        (y_first_choose == y_second_choose - 1 && x_first_choose == x_second_choose) || (y_first_choose == y_second_choose + 1 && x_first_choose == x_second_choose))
        check_position = true;
    else
        check_position = false;
    swap(Piece_Board[y_first_choose][x_first_choose].random_skill, Piece_Board[y_second_choose][x_second_choose].random_skill);
    Count_NumOfSkill();
    for (int i = 0; i < num_skill; i++)
    {
        if (a[i] != 0)
            return check_position;
    }

    return false;
}

// tính điểm mỗi loại skill
void Board_game ::Count_NumOfSkill()
{

    for (int i = 0; i < Size_of_Row; i++)
    {
        int k = 1;
        for (int j = 0; j < Size_of_Col - 2;)
        {
            if (k < Size_of_Col && Piece_Board[i][j].random_skill == Piece_Board[i][k].random_skill)
            {
                k++;
                continue;
            }

            if (k - j >= 3)
            {
                a[Piece_Board[i][j].random_skill - 1] += k - j;
                for (int temp = j; temp < k; temp++)
                {

                    Piece_Board[i][temp].random_skill = 0;
                }
            }
            j = k;
        }
    }

    for (int i = 0; i < Size_of_Col; i++)
    {
        int k = 1;
        for (int j = 0; j < Size_of_Row - 2;)
        {
            if (k < Size_of_Row && Piece_Board[j][i].random_skill == Piece_Board[k][i].random_skill)
            {
                k++;
                continue;
            }
            if (k - j >= 3)
            {
                a[Piece_Board[j][i].random_skill - 1] += k - j;
                for (int temp = j; temp < k; temp++)
                {

                    Piece_Board[temp][i].random_skill = 0;
                }
            }
            j = k;
        }
    }
}

// đổi giá trị 2 Piece trong Board
void Board_game ::swap_Piece_in_Board(int x_first, int y_first, int j, int i)
{
    swap(Piece_Board[x_first][y_first].random_skill, Piece_Board[j][i].random_skill);
}

// tìm kiếm vị trí đổi và đổi vị trí
bool Board_game::Search_selected_Piece(const int x_of_mouse, const int y_of_mouse, int id)
{
    static int count_selected = 0;
    static int _x_first, _y_first;
    int _i;
    int _j;
    if (id)
    {
        _i = y_of_mouse;
        _j = x_of_mouse;
    }
    else
    {
        _i = (y_of_mouse - Board_Position_y) / Piece_Width;
        _j = (x_of_mouse - Board_Position_x) / Piece_Width;
    }
    // cout << _j << "  " << _i << endl;
    count_selected++;
    cout << endl
         << count_selected << endl;
    if (count_selected == 1)
    {
        _x_first = _j;
        _y_first = _i;
        Piece_Board[_i][_j].selected = 1;
        // Piece_Board[_i][_j].pieceRenderer = gRenderer;
        // Piece_Board[_i][_j].pieceTexture = gTexture;
        // Piece_Board[_i][_j].render();
        return false;
    }
    if (count_selected == 2)
    {

        if (!Check_Move_Piece(_y_first, _x_first, _i, _j))
        {
            // cout << endl;

            swap_Piece_in_Board(_y_first, _x_first, _i, _j); // render lại khi chỉnh skill
        }
       
        count_selected = 0;
        Piece_Board[_y_first][_x_first].selected = 0;
        return true;
    }
    return false;
}

bool Board_game ::Find_Position_Move()
{
    for (int i = 0; i < 7; i++)
    {
        int k = 1;
        for (int j = 0; j < 9 - 2;)
        {
            if (k < 9 && Piece_Board[i][j].random_skill == Piece_Board[i][k].random_skill)
            {
                k++;
                continue;
            }

            if (k - j == 2)
            {

                // top left
                if (i - 1 >= 0 && j - 1 >= 0 && Piece_Board[i - 1][j - 1].random_skill == Piece_Board[i][j].random_skill)
                {
                    u.push_back({i - 1, j - 1});
                    v.push_back({i, j - 1});
                }
                // mid left
                if (j - 2 >= 0 && Piece_Board[i][j - 2].random_skill == Piece_Board[i][j].random_skill)
                {
                    u.push_back({i, j - 2});
                    v.push_back({i, j - 1});
                }
                // bottom left
                if (i + 1 < 7 && j - 1 >= 0 && Piece_Board[i + 1][j - 1].random_skill == Piece_Board[i][j].random_skill)
                {
                    u.push_back({i + 1, j - 1});
                    v.push_back({i, j - 1});
                }

                // top right
                if (i - 1 >= 0 && k < 9 && Piece_Board[i - 1][k].random_skill == Piece_Board[i][j].random_skill)
                {
                    u.push_back({i - 1, k});
                    v.push_back({i, k});
                }
                // mid right
                if (k + 1 < 9 && Piece_Board[i][k + 1].random_skill == Piece_Board[i][j].random_skill)
                {
                    u.push_back({i, k + 1});
                    v.push_back({i, k});
                }
                // bottom left
                if (i + 1 < 7 && k < 9 && Piece_Board[i + 1][k].random_skill == Piece_Board[i][j].random_skill)
                {
                    u.push_back({i + 1, k});
                    v.push_back({i, k});
                }
            }
            j = k;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        int k = 1;
        for (int j = 0; j < 7 - 2;)
        {
            if (k < 7 && Piece_Board[j][i].random_skill == Piece_Board[k][i].random_skill)
            {
                k++;
                continue;
            }
            if (k - j == 2)
            {

                // top left
                if (i - 1 >= 0 && j - 1 >= 0 && Piece_Board[j - 1][i - 1].random_skill == Piece_Board[j][i].random_skill)
                {
                    u.push_back({j - 1, i - 1});
                    v.push_back({j - 1, i});
                }
                // top between
                if (j - 2 >= 0 && Piece_Board[j - 2][i].random_skill == Piece_Board[j][i].random_skill)
                {
                    u.push_back({j - 2, i});
                    v.push_back({j - 1, i});
                }
                // top right
                if (i + 1 < 9 && j - 1 >= 0 && Piece_Board[j - 1][i + 1].random_skill == Piece_Board[j][i].random_skill)
                {
                    u.push_back({j - 1, i + 1});
                    v.push_back({j - 1, i});
                }

                // bottom left
                if (i - 1 >= 0 && k < 9 && Piece_Board[k][i - 1].random_skill == Piece_Board[j][i].random_skill)
                {
                    u.push_back({k, i - 1});
                    v.push_back({k, i});
                }
                // bottom between
                if (k + 1 < 7 && Piece_Board[k + 1][i].random_skill == Piece_Board[j][i].random_skill)
                {
                    u.push_back({k + 1, i});
                    v.push_back({k, i});
                }
                // bottom left
                if (i + 1 < 9 && k < 7 && Piece_Board[k][i + 1].random_skill == Piece_Board[j][i].random_skill)
                {
                    u.push_back({k, i + 1});
                    v.push_back({k, i});
                }
            }
            j = k;
        }
    }

    return u.size();
}

void Board_game ::reset_find_possible_move()
{
    u.erase(u.begin(), u.end());
    v.erase(v.begin(), v.end());
}

void Board_game::free()
{
    for (int i = 0; i <= num_skill; i++)
    {
        SDL_DestroyTexture(text_image[i]);
        text_image[i] = NULL;
    }
    SDL_DestroyTexture(text_selected);
    text_selected = NULL;
}
