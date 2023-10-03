#ifndef game_structure_h_included
#define game_structure_h_included


//structs

typedef struct player_data
{
    char name[16];
    char race[20];
    char jclass[20];
    float STR;
    float DEX;
    float CON;
    float INT;
    float WIS;
    float CHA;
    int LV;
    int HP;
    int MAX_HP;
    int MP;
    int MAX_MP;
    int EXP;
    int EXP_NEEDED;
    int PA;
}player_data;

typedef struct player_info
{
    player_data bloco;
}player_info;

typedef struct enemy_data
{
    char name[20];
    int HP;
    int EXP_drop;
}enemy_data;





//functions





#endif // game_structure_h_included
