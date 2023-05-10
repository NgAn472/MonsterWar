#include <string>
#include <algorithm>
#include "Animation.h"
#include "Board.h"
class Monster
{
public:
    LTexture Animation;
    std::string name;
    int hp;
    int mp;
    int pow;
    int def;     // def cơ bản
    int hp_max, mp_max, pow_max, def_max, agl;
    int attack;

    Monster(string animation, int _hp, int _mp, int _pow,int _def,  int _attack);
    Monster();
   // void Monster_action_nor(int id);
    
    void Skill_1_attack(Monster& another, int count_skill_1);
   
    void Skill_2_heal(int count_skill_2);
   
    void Skill_3_magic(int count_skill);
   
    void Skill_4_pow(int count_skill);
    

    void Skill_5_defense(int count_skill);
    

    bool Skill_6_agility(int count_skill);
    

    void Skill_7_convert(int count_skill);

    void Monster_action(int b[], Monster &another, int id);
    
};

