#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include "game_structure.h"

#define tam 10



void text_write(char text[])
{
    int i=0,timer=30;

    while(text[i]!='\0')
    {
        printf("%c",text[i]);
        Sleep(timer);//30 default
        i++;
    }
}

void loadingBar()
{
    // 0 - black background,
    // A - Green Foreground
    system("color 0A");

    // Initialize char for printing
    // loading bar
    char a = 183, b = 164;


    const int barWidth = 50;
    printf("Loading: ");

    for (int progress = 0; progress <= barWidth; ++progress) {
        float percentage = (float)progress / barWidth * 100.0;

        printf("[");
        for (int i = 0; i < barWidth; ++i) {
            if (i < progress)
                printf("%c",b);
            else
                printf("%c",a);
        }

        printf("] %.2f%%\r", percentage);
        //fflush(stdout);
        usleep(1000);
    }

    printf("\n");
    reset();
}

void set_player_name(player_info *character, player_data bloco)
{
    int i=0;
    char name_copy[20];
    bloco.STR = 0;
    bloco.DEX = 0;
    bloco.CON = 0;
    bloco.INT = 0;
    bloco.WIS = 0;
    bloco.CHA = 0;
    bloco.CA = 0;
    bloco.LV = 1;
    bloco.EXP_NEEDED = 300;
    bloco.EXP = 0;
    bloco.PA = 0;
    bloco.money = 0;

    while(i>16||i==0)
    {
        i=0;
        while(bloco.name[i] != '\0')
        {
            name_copy[i] = bloco.name[i];
            i++;
        }
        name_copy[i] = '\0';
        if(i>16)
        {
            system("cls");
            printf("\nNah, este nome é muito comprido, escolha um menor.\n");
            printf(">.");
            gets(bloco.name);
        }
        if(i==0)
        {
            system("cls");
            printf("\nNão se lembra do seu nome? Então basta escolher um novo.\n");
            printf(">.");
            gets(bloco.name);
        }
    }

    character->bloco=bloco;
}

void race_choice(player_info *character)
{
    int opc=0;

    printf("\n\n1.Humano");
    printf("\n2.Elfo");
    printf("\n3.Anao");
    printf("\n4.Draconato");
    printf("\n5.Tiefling");
    printf("\n6.Automato");
    printf("\n>.");
    scanf("%d",&opc);

    while(opc<1||opc>6)
    {
        system("cls");
        printf("\nAcho que voce esta se confundindo com as escolhas.");
        printf("\n\n1.Humano");
        printf("\n2.Elfo");
        printf("\n3.Anao");
        printf("\n4.Draconato");
        printf("\n5.Tiefling");
        printf("\n6.Automato");
        printf("\n>.");
        scanf("%d",&opc);
    }

    if(opc==1)
    {
        strcpy(character->bloco.race,"Humano");
        character->bloco.WIS += 2;
    }
    if(opc==2)
    {
        strcpy(character->bloco.race,"Elfo");
        character->bloco.DEX += 2;
    }
    if(opc==3)
    {
        strcpy(character->bloco.race,"Anao");
        character->bloco.CON += 2;
    }
    if(opc==4)
    {
        strcpy(character->bloco.race,"Draconato");
        character->bloco.STR += 2;
    }
    if(opc==5)
    {
        strcpy(character->bloco.race,"Tiefling");
        character->bloco.INT += 2;
    }
    if(opc==6)
    {
        strcpy(character->bloco.race,"Automato");
        character->bloco.CHA += 2;
    }
}

void class_choice(player_info *character)
{
    int opc=0;
    float modf;
    int verif_modf;

    printf("\n\n1.Bárbaro");
    printf("\n2.Patrulheiro");
    printf("\n3.Paladino");
    printf("\n4.Mago");
    printf("\n5.Druida");
    printf("\n6.Bruxo");
    printf("\n>.");
    scanf("%d",&opc);

    while(opc<1||opc>6)
    {
        system("cls");
        printf("\nAcho que voce esta se confundindo com as escolhas.");
        printf("\n\n1.Bárbaro");
        printf("\n2.Patrulheiro");
        printf("\n3.Paladino");
        printf("\n4.Mago");
        printf("\n5.Druida");
        printf("\n6.Bruxo");
        printf("\n>.");
        scanf("%d",&opc);
    }

    if(opc==1)
    {
        strcpy(character->bloco.jclass,"Bárbaro");
        character->bloco.STR = character->bloco.STR + 15;
        character->bloco.DEX = character->bloco.DEX + 13;
        character->bloco.CON = character->bloco.CON + 14;
        character->bloco.INT = character->bloco.INT + 8;
        character->bloco.WIS = character->bloco.WIS + 10;
        character->bloco.CHA = character->bloco.CHA + 12;

        modf = (character->bloco.CON - 10)/2;
        verif_modf=modf;
        if(verif_modf!=modf)
        {
            modf-=0,5;
        }
        character->bloco.MAX_HP = 120 + modf;

        modf = (character->bloco.INT - 10)/2;
        verif_modf=modf;
        if(verif_modf!=modf)
        {
            modf-=0,5;
        }
        character->bloco.MAX_MP = 60 + modf;

        strcpy(character->bloco.equiped_weapon1,"Machado Grande");
        strcpy(character->bloco.equiped_weapon2,"Azagaia");
        strcpy(character->bloco.equiped_armor,"");
    }
    if(opc==2)
    {
        strcpy(character->bloco.jclass,"Patrulheiro");
        character->bloco.STR = character->bloco.STR + 13;
        character->bloco.DEX = character->bloco.DEX + 15;
        character->bloco.CON = character->bloco.CON + 12;
        character->bloco.INT = character->bloco.INT + 8;
        character->bloco.WIS = character->bloco.WIS + 14;
        character->bloco.CHA = character->bloco.CHA + 10;

        modf = (character->bloco.CON - 10)/2;
        verif_modf=modf;
        if(verif_modf!=modf)
        {
            modf-=0,5;
        }
        character->bloco.MAX_HP = 100 + modf;

        modf = (character->bloco.INT - 10)/2;
        verif_modf=modf;
        if(verif_modf!=modf)
        {
            modf-=0,5;
        }
        character->bloco.MAX_MP = 80 + modf;

        strcpy(character->bloco.equiped_weapon1,"Espada Curta");
        strcpy(character->bloco.equiped_weapon2,"Arco Longo");
        strcpy(character->bloco.equiped_armor,"Armadura de Couro");
    }
    if(opc==3)
    {
        strcpy(character->bloco.jclass,"Paladino");
        character->bloco.STR = character->bloco.STR + 15;
        character->bloco.DEX = character->bloco.DEX + 12;
        character->bloco.CON = character->bloco.CON + 13;
        character->bloco.INT = character->bloco.INT + 8;
        character->bloco.WIS = character->bloco.WIS + 10;
        character->bloco.CHA = character->bloco.CHA + 14;

        modf = (character->bloco.CON - 10)/2;
        verif_modf=modf;
        if(verif_modf!=modf)
        {
            modf-=0,5;
        }
        character->bloco.MAX_HP = 100 + modf;

        modf = (character->bloco.INT - 10)/2;
        verif_modf=modf;
        if(verif_modf!=modf)
        {
            modf-=0,5;
        }
        character->bloco.MAX_MP = 80 + modf;

        strcpy(character->bloco.equiped_weapon1,"Espada Longa");
        strcpy(character->bloco.equiped_weapon2,"Maça");
        strcpy(character->bloco.equiped_armor,"Cota de Malha");
    }
    if(opc==4)
    {
        strcpy(character->bloco.jclass,"Mago");
        character->bloco.STR = character->bloco.STR + 8;
        character->bloco.DEX = character->bloco.DEX + 13;
        character->bloco.CON = character->bloco.CON + 14;
        character->bloco.INT = character->bloco.INT + 15;
        character->bloco.WIS = character->bloco.WIS + 10;
        character->bloco.CHA = character->bloco.CHA + 12;

        modf = (character->bloco.CON - 10)/2;
        verif_modf=modf;
        if(verif_modf!=modf)
        {
            modf-=0,5;
        }
        character->bloco.MAX_HP = 60 + modf;

        modf = (character->bloco.INT - 10)/2;
        verif_modf=modf;
        if(verif_modf!=modf)
        {
            modf-=0,5;
        }
        character->bloco.MAX_MP = 120 + modf;

        strcpy(character->bloco.equiped_weapon1,"Bordão");
        strcpy(character->bloco.equiped_weapon2,"");
        strcpy(character->bloco.equiped_armor,"");
    }
    if(opc==5)
    {
        strcpy(character->bloco.jclass,"Druida");
        character->bloco.STR = character->bloco.STR + 8;
        character->bloco.DEX = character->bloco.DEX + 10;
        character->bloco.CON = character->bloco.CON + 14;
        character->bloco.INT = character->bloco.INT + 13;
        character->bloco.WIS = character->bloco.WIS + 15;
        character->bloco.CHA = character->bloco.CHA + 12;

        modf = (character->bloco.CON - 10)/2;
        verif_modf=modf;
        if(verif_modf!=modf)
        {
            modf-=0,5;
        }
        character->bloco.MAX_HP = 80 + modf;

        modf = (character->bloco.INT - 10)/2;
        verif_modf=modf;
        if(verif_modf!=modf)
        {
            modf-=0,5;
        }
        character->bloco.MAX_MP = 100 + modf;

        strcpy(character->bloco.equiped_weapon1,"Foice Curta");
        strcpy(character->bloco.equiped_weapon2,"Besta Leve");
        strcpy(character->bloco.equiped_armor,"Armadura de Couro");
    }
    if(opc==6)
    {
        strcpy(character->bloco.jclass,"Bruxo");
        character->bloco.STR = character->bloco.STR + 12;
        character->bloco.DEX = character->bloco.DEX + 10;
        character->bloco.CON = character->bloco.CON + 8;
        character->bloco.INT = character->bloco.INT + 13;
        character->bloco.WIS = character->bloco.WIS + 14;
        character->bloco.CHA = character->bloco.CHA + 15;

        modf = (character->bloco.CON - 10)/2;
        verif_modf=modf;
        if(verif_modf!=modf)
        {
            modf-=0,5;
        }
        character->bloco.MAX_HP = 80 + modf;

        modf = (character->bloco.INT - 10)/2;
        verif_modf=modf;
        if(verif_modf!=modf)
        {
            modf-=0,5;
        }
        character->bloco.MAX_MP = 100 + modf;

        strcpy(character->bloco.equiped_weapon1,"Azagaia");
        strcpy(character->bloco.equiped_weapon2,"Besta Leve");
        strcpy(character->bloco.equiped_armor,"Armadura de Couro");
    }

    character->bloco.HP = character->bloco.MAX_HP;
    character->bloco.MP = character->bloco.MAX_MP;

    modf = (character->bloco.DEX - 10)/2;
    verif_modf=modf;
    if(verif_modf!=modf)
    {
        modf-=0,5;
    }

    if(strcmp(character->bloco.equiped_armor,"")==0)
    {
        character->bloco.CA = 10 + modf;
    }

    //Armadura Leve
    else if(strcmp(character->bloco.equiped_armor,"Armadura Acolchoada")==0)
    {
        character->bloco.CA = 11 + modf;
    }
    else if(strcmp(character->bloco.equiped_armor,"Armadura de Couro")==0)
    {
        character->bloco.CA = 11 + modf;
    }
    else if(strcmp(character->bloco.equiped_armor,"Armadura de Couro Batido")==0)
    {
        character->bloco.CA = 12 + modf;
    }

    //Armadura média
    else if(strcmp(character->bloco.equiped_armor,"Gibão de Peles")==0)
    {
        if(modf>2)
        {
            character->bloco.CA = 12 + 2;
        }
        else
        {
            character->bloco.CA = 12 + modf;
        }
    }
    else if(strcmp(character->bloco.equiped_armor,"Camisão de Malha")==0)
    {
        if(modf>2)
        {
            character->bloco.CA = 13 + 2;
        }
        else
        {
            character->bloco.CA = 13 + modf;
        }
    }
    else if(strcmp(character->bloco.equiped_armor,"Brunea")==0)
    {
        if(modf>2)
        {
            character->bloco.CA = 14 + 2;
        }
        else
        {
            character->bloco.CA = 14 + modf;
        }
    }
    else if(strcmp(character->bloco.equiped_armor,"Peitoral")==0)
    {
        if(modf>2)
        {
            character->bloco.CA = 14 + 2;
        }
        else
        {
            character->bloco.CA = 14 + modf;
        }
    }
    else if(strcmp(character->bloco.equiped_armor,"Meia-Armadura")==0)
    {
        if(modf>2)
        {
            character->bloco.CA = 15 + 2;
        }
        else
        {
            character->bloco.CA = 15 + modf;
        }
    }

    //Armadura Pesada
    else if(strcmp(character->bloco.equiped_armor,"Cota de Anéis")==0)
    {
        character->bloco.CA = 14;
    }
    else if(strcmp(character->bloco.equiped_armor,"Cota de Malha")==0)
    {
        character->bloco.CA = 16;
    }
    else if(strcmp(character->bloco.equiped_armor,"Cota de Talas")==0)
    {
        character->bloco.CA = 17;
    }
    else if(strcmp(character->bloco.equiped_armor,"Placas")==0)
    {
        character->bloco.CA = 18;
    }
}

void player_id(player_info *character)
{
    float percent_hp,hp,hp_max;
    hp = character->bloco.HP;
    hp_max = character->bloco.MAX_HP;
    percent_hp = (hp/hp_max)*100;

    system("cls");
    printf("\n=========================================");
    green();
    printf("\n%s",character->bloco.name);
    reset();
    printf("\tLV: %d", character->bloco.LV);
    printf("\nHP: ");

    if(percent_hp>=75)
    {
        green();
        printf("%d",character->bloco.HP);
        reset();
        printf("/");
        green();
        printf("%d",character->bloco.MAX_HP);
        reset();
    }
    else if(percent_hp>=50 && percent_hp<75)
    {
        blue();
        printf("%d",character->bloco.HP);
        reset();
        printf("/");
        blue();
        printf("%d",character->bloco.MAX_HP);
        reset();
    }
    else if(percent_hp>=25 && percent_hp<50)
    {
        yellow();
        printf("%d",character->bloco.HP);
        reset();
        printf("/");
        yellow();
        printf("%d",character->bloco.MAX_HP);
        reset();
    }
    else if(percent_hp<25)
    {
        red();
        printf("%d",character->bloco.HP);
        reset();
        printf("/");
        red();
        printf("%d",character->bloco.MAX_HP);
        reset();
    }
    printf("\tMP: ");
    cyan();
    printf("%d",character->bloco.MP);
    reset();
    printf("/");
    cyan();
    printf("%d",character->bloco.MAX_MP);
    reset();
    printf("\nClasse: %s",character->bloco.jclass);
    printf("\tEXP: ");
    yellow();
    printf("%d",character->bloco.EXP);
    reset();
    printf("/");
    yellow();
    printf("%d",character->bloco.EXP_NEEDED);
    reset();
    printf("\n=========================================");
    printf("\n");
}

void level_up(player_info *character)
{
    int opc,add_hp,add_mp;
    add_hp=add_mp=0;

    while(character->bloco.EXP >= character->bloco.EXP_NEEDED)
    {
        if(character->bloco.LV == 4||character->bloco.LV == 4||character->bloco.LV == 4||character->bloco.LV == 4||character->bloco.LV == 4)
        {
            character->bloco.PA += 2;
        }

        while(character->bloco.PA > 0)
        {
            system("cls");
            player_id(character);
            printf("\nPA: %d",character->bloco.PA);
            printf("\n");
            printf("\n1.STR: %.0f",character->bloco.STR);
            printf("\n2.DEX: %.0f",character->bloco.DEX);
            printf("\n3.CON: %.0f",character->bloco.CON);
            printf("\n4.INT: %.0f",character->bloco.INT);
            printf("\n5.WIS: %.0f",character->bloco.WIS);
            printf("\n6.CHA: %.0f",character->bloco.CHA);
            printf("\n>.");
            scanf("%d",&opc);
            while(opc<1||opc>6)
            {
                system("cls");
                player_id(character);
                printf("\nAcho que voce esta se confundindo com as escolhas.");
                printf("\nPA: %d",character->bloco.PA);
                printf("\n");
                printf("\n1.STR: %.0f",character->bloco.STR);
                printf("\n2.DEX: %.0f",character->bloco.DEX);
                printf("\n3.CON: %.0f",character->bloco.CON);
                printf("\n4.INT: %.0f",character->bloco.INT);
                printf("\n5.WIS: %.0f",character->bloco.WIS);
                printf("\n6.CHA: %.0f",character->bloco.CHA);
                printf("\n>.");
                scanf("%d",&opc);
            }
            if(opc==1)
            {
                if(character->bloco.STR +1 >20)
                {
                    printf("\nValor máximo atingido.");
                }
                else
                {
                    character->bloco.STR++;
                    character->bloco.PA--;
                }
            }
            if(opc==2)
            {
                if(character->bloco.DEX +1 >20)
                {
                    printf("\nValor máximo atingido.");
                }
                else
                {
                    character->bloco.DEX++;
                    character->bloco.PA--;
                }
            }
            if(opc==3)
            {
                if(character->bloco.CON +1 >20)
                {
                    printf("\nValor máximo atingido.");
                }
                else
                {
                    character->bloco.CON++;
                    character->bloco.PA--;
                }
            }
            if(opc==4)
            {
                if(character->bloco.INT +1 >20)
                {
                    printf("\nValor máximo atingido.");
                }
                else
                {
                    character->bloco.INT++;
                    character->bloco.PA--;
                }
            }
            if(opc==5)
            {
                if(character->bloco.WIS +1 >20)
                {
                    printf("\nValor máximo atingido.");
                }
                else
                {
                    character->bloco.WIS++;
                    character->bloco.PA--;
                }
            }
            if(opc==6)
            {
                if(character->bloco.CHA +1 >20)
                {
                    printf("\nValor máximo atingido.");
                }
                else
                {
                    character->bloco.CHA++;
                    character->bloco.PA--;
                }
            }
        }

        character->bloco.LV++;
        if(character->bloco.LV==2)
        {
            character->bloco.EXP_NEEDED = character->bloco.EXP_NEEDED * 1.8;
        }
        else if(character->bloco.LV==3)
        {
            character->bloco.EXP_NEEDED = character->bloco.EXP_NEEDED * 1.5;
        }
        else if(character->bloco.LV==4)
        {
            character->bloco.EXP_NEEDED = character->bloco.EXP_NEEDED * 1.4;
        }
        else if(character->bloco.LV>=5&&character->bloco.LV<=7)
        {
            character->bloco.EXP_NEEDED = character->bloco.EXP_NEEDED * 1.3;
        }
        else if(character->bloco.LV>=8&&character->bloco.LV<=20)
        {
            character->bloco.EXP_NEEDED = character->bloco.EXP_NEEDED * 1.25;
        }
        else if(character->bloco.LV>20)
        {
            character->bloco.EXP_NEEDED = character->bloco.EXP_NEEDED * 1.3;
        }

        if(strcmp(character->bloco.jclass,"Bárbaro")==0)
        {
            add_hp = roll_dice(1,12);
            add_mp = roll_dice(1,6);
            character->bloco.MAX_HP += add_hp;
            character->bloco.MAX_MP += add_mp;
        }
        if(strcmp(character->bloco.jclass,"Patrulheiro")==0)
        {
            add_hp = roll_dice(1,10);
            add_mp = roll_dice(1,8);
            character->bloco.MAX_HP += add_hp;
            character->bloco.MAX_MP += add_mp;
        }
        if(strcmp(character->bloco.jclass,"Paladino")==0)
        {
            add_hp = roll_dice(1,10);
            add_mp = roll_dice(1,8);
            character->bloco.MAX_HP += add_hp;
            character->bloco.MAX_MP += add_mp;
        }
        if(strcmp(character->bloco.jclass,"Mago")==0)
        {
            add_hp = roll_dice(1,6);
            add_mp = roll_dice(1,12);
            character->bloco.MAX_HP += add_hp;
            character->bloco.MAX_MP += add_mp;
        }
        if(strcmp(character->bloco.jclass,"Druida")==0)
        {
            add_hp = roll_dice(1,8);
            add_mp = roll_dice(1,10);
            character->bloco.MAX_HP += add_hp;
            character->bloco.MAX_MP += add_mp;
        }
        if(strcmp(character->bloco.jclass,"Bruxo")==0)
        {
            add_hp = roll_dice(1,8);
            add_mp = roll_dice(1,10);
            character->bloco.MAX_HP += add_hp;
            character->bloco.MAX_MP += add_mp;
        }
    }
}

void rest(player_info *character)
{
    character->bloco.HP = character->bloco.MAX_HP;
    character->bloco.MP = character->bloco.MAX_MP;
}
//printf("\n");
//text_write(strcpy(text,"\n"));
