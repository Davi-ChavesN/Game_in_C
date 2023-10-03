#include <stdio.h>
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


void enemy_generation(enemy_data enemies[], int danger_class_min, int danger_class_max)
{
    srand(time(NULL));
    int i,dice,max,min;
    min = danger_class_min;
    max = danger_class_max;
    dice=i=0;

    /*
        Danger class - Enemy
            1           Slime
            2           Goblin
            3           Bandit
            4           Specter
            5           Orc
    */

    while(i<tam)
    {
        dice = min + rand()% max;
        printf("%d",dice);
        if(dice==1)
        {

            strcpy(enemies[i].name,"Slime");
            enemies[i].HP = 7 + rand()%9;
            enemies[i].EXP_drop = 3 + rand()%5;
        }
        if(dice==2)
        {
            strcpy(enemies[i].name,"Goblin");
            enemies[i].HP = 10 + rand()%11;
            enemies[i].EXP_drop = 7 + rand()%10;
        }
        if(dice==3)
        {
            strcpy(enemies[i].name,"Bandido");
            enemies[i].HP = 12 + rand()%13;
            enemies[i].EXP_drop = 7 + rand()%10;
        }
        if(dice==4)
        {
            strcpy(enemies[i].name,"Espectro");
            enemies[i].HP = 7 + rand()%15;
            enemies[i].EXP_drop = 9 + rand()%12;
        }
        if(dice==5)
        {
            strcpy(enemies[i].name,"Orc");
            enemies[i].HP = 20 + rand()%11;
            enemies[i].EXP_drop = 12 + rand()%14;
        }
        i++;
    }
    getch();
}

int alive_enemies(enemy_data enemies[])
{
    int flag,i;
    flag=0;
    i=0;

    while(i<tam)
    {
        if(enemies[i].HP>0)
        {
            flag++;
        }
        i++;
    }

    return flag;
}

void show_enemies(enemy_data enemies[])
{
    int i=0;
    while(i<tam)
    {
        printf("\n%d. %s\t HP: ",i+1,enemies[i].name);
        if(enemies[i].HP>0)
        {
            printf("%d",enemies[i].HP);
        }
        else
        {
            printf("0 - Derrotado");
        }
        i++;
    }
}

int enemy_attack(enemy_data enemies[],int i)
{
    srand(time(NULL));
    int dmg=-1;

    if(enemies[i].HP>0)
    {
        if(strcmp(enemies[i].name,"Slime")==0)
        {
            dmg = rand()% 5;
        }
        if(strcmp(enemies[i].name,"Goblin")==0)
        {
            dmg = rand()% 7;
        }
        if(strcmp(enemies[i].name,"Bandido")==0)
        {
            dmg = rand()% 7;
        }
        if(strcmp(enemies[i].name,"Espectro")==0)
        {
            dmg = rand()% 9;
        }
        if(strcmp(enemies[i].name,"Orc")==0)
        {
            dmg = rand()% 13;
        }
    }

    return dmg;
}

void battle(player_info *character, enemy_data enemies[])
{
    srand(time(NULL));
    char text[150];
    int flag,i,choice,fight_choice,fight_enemy;
    int player_dmg, enemy_dmg;

    choice=fight_choice=0;

    flag=alive_enemies(enemies);
    while(character->bloco.HP>0&&flag!=0)
    {
        system("cls");
        player_id(character);
        show_enemies(enemies);

        printf("\n\n");
        printf("=================================");
        printf("\nEscolha sua ação");
        printf("\n1.Lutar");
        printf("\n2.Fugir");
        printf("\n>.");
        scanf("%d",&choice);

        if(choice==1)
        {
            player_id(character);
            show_enemies(enemies);

            printf("\n\n");
            printf("=================================");
            printf("\nEscolha quem você quer atacar");
            printf("\n>.");
            scanf("%d",&fight_enemy);

            system("cls");
            player_id(character);
            show_enemies(enemies);

            printf("\n\n");
            printf("=================================");
            printf("\nEscolha sua ação");
            printf("\n1.Atacar");
            printf("\n2.Magia");
            printf("\n3.Itens");
            printf("\n>.");
            scanf("%d",&fight_choice);

            if(fight_choice==1)
            {
                player_dmg = 5 + rand()% 6;
                if(strcmp(character->bloco.jclass,"Guerreiro")==0)
                {
                    player_dmg = player_dmg*(character->bloco.STR/10);
                }
                else if(strcmp(character->bloco.jclass,"Patrulheiro")==0)
                {
                    player_dmg = player_dmg*(character->bloco.DEX/10);
                }
                else if(strcmp(character->bloco.jclass,"Paladino")==0)
                {
                    player_dmg = player_dmg*(character->bloco.STR/10);
                }
                else if(strcmp(character->bloco.jclass,"Mago")==0)
                {
                    player_dmg = player_dmg*(character->bloco.STR/10);
                }
                else if(strcmp(character->bloco.jclass,"Druida")==0)
                {
                    player_dmg = player_dmg*(character->bloco.DEX/10);
                }
                else if(strcmp(character->bloco.jclass,"Bruxo")==0)
                {
                    player_dmg = player_dmg*(character->bloco.DEX/10);
                }

                text_write(strcpy(text,"\nVocê ataca "));
                green();
                text_write(strcpy(text,enemies[fight_enemy-1].name));
                reset();
                text_write(strcpy(text," e causa "));
                red();
                printf("%d",player_dmg);
                reset();
                text_write(strcpy(text," de dano"));
                enemies[fight_enemy-1].HP -= player_dmg;
                printf("\n<>");
                getch();
            }
            else if(fight_choice==2)
            {

            }

            if(enemies[fight_enemy-1].HP<=0)
            {
                system("cls");
                player_id(character);
                show_enemies(enemies);
                printf("\n\n");
                printf("=================================");
                printf("\n\n");
                green();
                text_write(strcpy(text,enemies[fight_enemy-1].name));
                reset();
                text_write(strcpy(text," foi derrotado e você ganhou "));
                yellow();
                printf("%d",enemies[fight_enemy-1].EXP_drop);
                reset();
                text_write(strcpy(text," pontos de experiência"));
                character->bloco.EXP += enemies[fight_enemy-1].EXP_drop;
                printf("\n<>");
                getch();
            }

            system("cls");
            player_id(character);
            show_enemies(enemies);
            printf("\n\n");
            printf("=================================");
            printf("\n\n");

            i=0;
            while(i<tam)
            {
                enemy_dmg = enemy_attack(enemies,i);
                if(enemy_dmg>0)
                {
                    printf("\n");
                    green();
                    text_write(strcpy(text,enemies[i].name));
                    reset();
                    text_write(strcpy(text," atacou você e causou "));
                    red();
                    printf("%d ",enemy_dmg);
                    reset();
                    text_write(strcpy(text,"de dano"));
                    character->bloco.HP -= enemy_dmg;
                }
                else if(enemy_dmg==0)
                {
                    printf("\n");
                    green();
                    text_write(strcpy(text,enemies[i].name));
                    reset();
                    text_write(strcpy(text," errou o ataque"));
                }
                i++;
            }
            flag=alive_enemies(enemies);
            printf("\n<%d>",flag);
            getch();
        }
        if(choice==2)
        {
            printf("\nVocê fugiu!");
            printf("\n<>");
            getch();
            break;
        }
    }
    if(character->bloco.HP<=0)
    {
        red();
        text_write(strcpy(text,"Você morreu!"));
        reset();
    }
}
