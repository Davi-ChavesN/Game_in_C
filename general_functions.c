#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include "game_structure.h"

#define tam 5


void text_write(char text[])
{
    int i=0,timer=0;

    while(text[i]!='\0')
    {
        printf("%c",text[i]);
        Sleep(timer);//30 default
        i++;
    }
}

void set_player_name(player_info *character, player_data bloco)
{
    int i=0;
    char name_copy[20];

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
        character->bloco.STR = 0;
        character->bloco.DEX = 0;
        character->bloco.CON = 0;
        character->bloco.INT = 0;
        character->bloco.WIS = 2;
        character->bloco.CHA = 0;
    }
    if(opc==2)
    {
        strcpy(character->bloco.race,"Elfo");
        character->bloco.STR = 0;
        character->bloco.DEX = 2;
        character->bloco.CON = 0;
        character->bloco.INT = 0;
        character->bloco.WIS = 0;
        character->bloco.CHA = 0;
    }
    if(opc==3)
    {
        strcpy(character->bloco.race,"Anao");
        character->bloco.STR = 0;
        character->bloco.DEX = 0;
        character->bloco.CON = 2;
        character->bloco.INT = 0;
        character->bloco.WIS = 0;
        character->bloco.CHA = 0;
    }
    if(opc==4)
    {
        strcpy(character->bloco.race,"Draconato");
        character->bloco.STR = 2;
        character->bloco.DEX = 0;
        character->bloco.CON = 0;
        character->bloco.INT = 0;
        character->bloco.WIS = 0;
        character->bloco.CHA = 0;
    }
    if(opc==5)
    {
        strcpy(character->bloco.race,"Tiefling");
        character->bloco.STR = 0;
        character->bloco.DEX = 0;
        character->bloco.CON = 0;
        character->bloco.INT = 2;
        character->bloco.WIS = 0;
        character->bloco.CHA = 0;
    }
    if(opc==6)
    {
        strcpy(character->bloco.race,"Automato");
        character->bloco.STR = 0;
        character->bloco.DEX = 0;
        character->bloco.CON = 0;
        character->bloco.INT = 0;
        character->bloco.WIS = 0;
        character->bloco.CHA = 2;
    }
}

void class_choice(player_info *character)
{
    int opc=0;

    printf("\n\n1.Guerreiro");
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
        printf("\n\n1.Guerreiro");
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
        strcpy(character->bloco.jclass,"Guerreiro");
        character->bloco.STR = character->bloco.STR + 15;
        character->bloco.DEX = character->bloco.DEX + 13;
        character->bloco.CON = character->bloco.CON + 14;
        character->bloco.INT = character->bloco.INT + 8;
        character->bloco.WIS = character->bloco.WIS + 10;
        character->bloco.CHA = character->bloco.CHA + 12;
    }
    if(opc==2)
    {
        strcpy(character->bloco.jclass,"Patrulheiro");
        character->bloco.STR = character->bloco.STR + 14;
        character->bloco.DEX = character->bloco.DEX + 15;
        character->bloco.CON = character->bloco.CON + 12;
        character->bloco.INT = character->bloco.INT + 10;
        character->bloco.WIS = character->bloco.WIS + 13;
        character->bloco.CHA = character->bloco.CHA + 8;
    }
    if(opc==3)
    {
        strcpy(character->bloco.jclass,"Paladino");
        character->bloco.STR = character->bloco.STR + 14;
        character->bloco.DEX = character->bloco.DEX + 12;
        character->bloco.CON = character->bloco.CON + 15;
        character->bloco.INT = character->bloco.INT + 8;
        character->bloco.WIS = character->bloco.WIS + 13;
        character->bloco.CHA = character->bloco.CHA + 10;
    }
    if(opc==4)
    {
        strcpy(character->bloco.jclass,"Mago");
        character->bloco.STR = character->bloco.STR + 12;
        character->bloco.DEX = character->bloco.DEX + 8;
        character->bloco.CON = character->bloco.CON + 10;
        character->bloco.INT = character->bloco.INT + 15;
        character->bloco.WIS = character->bloco.WIS + 13;
        character->bloco.CHA = character->bloco.CHA + 14;
    }
    if(opc==5)
    {
        strcpy(character->bloco.jclass,"Druida");
        character->bloco.STR = character->bloco.STR + 8;
        character->bloco.DEX = character->bloco.DEX + 10;
        character->bloco.CON = character->bloco.CON + 13;
        character->bloco.INT = character->bloco.INT + 14;
        character->bloco.WIS = character->bloco.WIS + 15;
        character->bloco.CHA = character->bloco.CHA + 12;
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
    }
    character->bloco.EXP = 0;
    character->bloco.EXP_NEEDED = 20;
    character->bloco.HP = character->bloco.CON * 10;
    character->bloco.MP = character->bloco.INT * 10;
}

void player_id(player_info *character)
{
    character->bloco.MAX_HP = character->bloco.CON * 10;
    character->bloco.MAX_MP = character->bloco.INT * 10;

    system("cls");
    printf("\n=========================================");
    printf("\n%s\tLV: %d",character->bloco.name, character->bloco.LV);
    printf("\nHP: %d/%d\tMP: %d/%d",character->bloco.HP,character->bloco.MAX_HP,character->bloco.MP,character->bloco.MAX_MP);
    printf("\nClasse: %s",character->bloco.jclass);
    printf("\tEXP: %d/%d",character->bloco.EXP,character->bloco.EXP_NEEDED);
    printf("\n=========================================");
    printf("\n");
}

void level_up(player_info *character)
{
    int opc;
    while(character->bloco.EXP >= character->bloco.EXP_NEEDED)
    {
        character->bloco.PA += 3;

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

                character->bloco.STR++;
                character->bloco.PA--;
            }
            if(opc==2)
            {
                character->bloco.DEX++;
                character->bloco.PA--;
            }
            if(opc==3)
            {
                character->bloco.CON++;
                character->bloco.PA--;
            }
            if(opc==4)
            {
                character->bloco.INT++;
                character->bloco.PA--;
            }
            if(opc==5)
            {
                character->bloco.WIS++;
                character->bloco.PA--;
            }
            if(opc==6)
            {
                character->bloco.CHA++;
                character->bloco.PA--;
            }
        }
        character->bloco.LV++;
        character->bloco.EXP_NEEDED = character->bloco.EXP_NEEDED * 1.4;
    }
    character->bloco.MAX_HP = character->bloco.CON * 10;
    character->bloco.MAX_MP = character->bloco.INT * 10;
    character->bloco.HP = character->bloco.MAX_HP;
    character->bloco.MP = character->bloco.MAX_MP;
}
