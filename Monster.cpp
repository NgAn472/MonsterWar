#include "Monster.h"

Monster ::Monster(string animation, int _hp, int _mp, int _pow, int _def, int _attack)
{
    def_max = _def;
    def = 0;
    hp_max = hp = _hp;
    mp_max = _mp;
    pow_max = _pow;
    mp = 0;
    pow = 0;
    attack = _attack;
    Animation.loadMedia(animation);
}
Monster ::Monster()
{
}

// void Monster::Monster_action_nor(int id)
// {
//     static int frame = 0;
//     if (frame >= FPS * Act_Normal_Animation_frame)
//             frame = 0;
        
// }

void Monster::Skill_1_attack(Monster &another, int count_skill_1)
{
    double dmg = attack * count_skill_1;
    if (pow > 70)
    {
        dmg = dmg * (100 + pow) / 100;
        pow = 0;
    }
    dmg -= another.def;
    another.hp -= (int)dmg;
    if (another.hp <= 0)
        another.hp = 0;
}
void Monster ::Skill_2_heal(int count_skill_2)
{
    hp += count_skill_2 * hp_max / 20;
    if (hp > hp_max)
        hp = hp_max;
}
void Monster ::Skill_3_magic(int count_skill)
{
    mp += count_skill * mp_max / 20;
    if (mp > mp_max)
        mp = mp_max;
}
void Monster ::Skill_4_pow(int count_skill)
{
    pow += count_skill * pow_max / 10;
    if (pow > pow_max)
        pow = pow_max;
}
void Monster ::Skill_5_defense(int count_skill)
{
    if (count_skill == 0)
        def_max = def;
    else
        def_max = count_skill * def;
}

bool Monster ::Skill_6_agility(int count_skill)
{
    if (count_skill >= 20)
        count_skill = 20;
    else if (count_skill)
    {
        // agl+=count_skill;
        agl = (count_skill - 0) * (50 - 15) / (20 - 0) + 15;
    }
    int un_miss = rand() % 100 + 1;
    if (un_miss <= agl)
        return true;
    else
        return false;
}

void Monster ::Skill_7_convert(int count_skill)
{
    
    hp += mp*count_skill/10;
    mp = 0;
}

void Monster ::Monster_action(int b[], Monster &another, int id)
{
    
    int x, y;
    if (id == 1)
    {
        x = 15;
        y = 255;
    }
    else
    {
        x = 785;
        y = 255;
    }
    for (int i = num_skill - 1; i >= 1; i--)
    {
        if (b[i] != 0)
        {
            for (int i = Act_Normal_Animation_frame; i < 6 * Act_Buff_Animation_frame; i++)
            {
                SDL_Rect *currentClip1 = &gSpriteClips[i / 6];
                Animation.render(x, y, currentClip1);

                // Update screen
                SDL_RenderPresent(gRenderer);

                // Go to next frame
            }
            switch (i)
            {
            case 6:
                Skill_7_convert(b[i]);
                break;
            case 5:
                Skill_6_agility(b[i]);
                break;
            case 4:
                Skill_5_defense(b[i]);
                break;
            case 3:
                Skill_4_pow(b[i]);
                break;
            case 2:
                Skill_3_magic(b[i]);
                break;
            case 1:
                Skill_2_heal(b[i]);
                break;
            default:
                break;
            }
        }
    }
    if (b[0] != 0)
    {
        for (int i = Act_Buff_Animation_frame; i < 6 * Act_Attack_Animation_frame; i++)
        {
            SDL_Rect *currentClip1 = &gSpriteClips[i / 6];
            Animation.render(x, y, currentClip1);

            // Update screen
            SDL_RenderPresent(gRenderer);

            // Go to next frame
        }
        Skill_1_attack(another, b[0]);
    }
    
}