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
    int CA;
    int LV;
    int HP;
    int MAX_HP;
    int MP;
    int MAX_MP;
    int EXP;
    int EXP_NEEDED;
    int PA;
    float money;
    char equiped_weapon1[25];
    char equiped_weapon2[25];
    char equiped_armor[25];
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
    int CA;
    char weapon1[25];
    char weapon2[25];
}enemy_data;

typedef struct inventory_itens
{
    char name[50];
    int quantity;
    float buy_price;
    float sell_price;
}inventory_itens;

typedef struct item_info
{
    inventory_itens item_chunk;
}item_info;





//functions

void text_write(char text[]);
void set_player_name(player_info *character, player_data bloco);
void race_choice(player_info *character);
void class_choice(player_info *character);
void player_id(player_info *character);
void level_up(player_info *character);
void enemy_generation(enemy_data enemies[], char enemy_list[]);
int alive_enemies(enemy_data enemies[]);
void show_enemies(enemy_data enemies[]);
int enemy_attack(enemy_data enemies[],int i);
void battle(player_info *character, enemy_data enemies[]);




void reset();
void black();
void red();
void green();
void yellow();
void blue();
void magenta();
void cyan();
void white();
void bkg_black();
void bkg_red();
void bkg_green();
void bkg_yellow();
void bkg_blue();
void bkg_magenta();
void bkg_cyan();
void bkg_white();



#endif // game_structure_h_included
