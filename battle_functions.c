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
    char text[150],spell[50];
    int flag,i,choice,fight_choice,fight_enemy,spell_choice;
    int player_dmg,player_heal,enemy_dmg,dice;
    int dmg_buff,def_buff;
    int mp_cost;

    choice=fight_choice=dice=0;
    dmg_buff=def_buff=0;

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

            while(enemies[fight_enemy-1].HP<=0 || fight_enemy<1 || fight_enemy>5)
            {
                player_id(character);
                show_enemies(enemies);

                printf("\n\n");
                printf("=================================");
                if(enemies[fight_enemy-1].HP<=0)
                {
                    printf("\nInimigo já está morto");
                }
                else if(fight_enemy<1 || fight_enemy>5)
                {
                    printf("\nEscolha inválida!");
                }
                printf("\nEscolha quem você quer atacar");
                printf("\n>.");
                scanf("%d",&fight_enemy);
            }

            action_choice:
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

                if(dmg_buff>0)
                {
                    if(strcmp(character->bloco.jclass,"Guerreiro")==0)
                    {
                        player_dmg += 1 + rand()%6;
                    }
                    else if(strcmp(character->bloco.jclass,"Patrulheiro")==0)
                    {
                        player_dmg += 1 + rand()%6;
                    }
                    else if(strcmp(character->bloco.jclass,"Paladino")==0)
                    {
                        player_dmg += 1 + rand()%4;
                    }
                    dmg_buff--;
                }

                dice = 1 + rand()%20;

                if(dice==20)
                {
                    player_dmg = player_dmg*2;
                    yellow();
                    printf("\nACERTO CRÍTICO\n");
                    reset();
                }

                text_write(strcpy(text,"\nVocê ataca "));
                red();
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
                if(strcmp(character->bloco.jclass,"Guerreiro")==0)
                {
                    player_id(character);
                    show_enemies(enemies);

                    printf("\n\n");
                    printf("=================================");
                    printf("\nMAGIAS");
                    printf("\n1.Retomar o fôlego = 1d10");
                    printf("\n2.Espírito guerreiro");
                    printf("\n0.Voltar");
                    printf("\n>.");
                    scanf("%d",&spell_choice);

                    if(spell_choice==1)
                    {
                        strcpy(spell,"Retomar o fôlego");
                        mp_cost = 20;

                        if(character->bloco.MP > mp_cost)
                        {
                            player_heal = 1 + rand()%10;
                            character->bloco.MP -= mp_cost;
                            character->bloco.HP += player_heal;
                            if(character->bloco.HP > character->bloco.MAX_HP)
                            {
                                character->bloco.HP = character->bloco.MAX_HP;
                            }
                            printf("\nVocê usa ");
                            blue();
                            printf("%s",spell);
                            reset();
                            printf(" e restaura ");
                            green();
                            printf("%d",player_heal);
                            reset();
                            printf(" pontos de vida");
                            printf("\n<>");
                            getch();
                        }
                        else
                        {
                            printf("\nVocê não possui MP suficiente");
                            printf("\n<>");
                            getch();
                            goto action_choice;
                        }


                    }
                    else if(spell_choice==2)
                    {
                        strcpy(spell,"Espírito guerreiro");
                        mp_cost = 15;

                        if(character->bloco.MP > mp_cost)
                        {
                            character->bloco.MP -= mp_cost;
                            dmg_buff = 3;
                            printf("\nVocê usa ");
                            blue();
                            printf("%s",spell);
                            reset();
                            printf(" e aumenta seu dano causado nas próximas 3 rodadas");
                            printf("\n<>");
                            getch();
                        }
                        else
                        {
                            printf("\nVocê não possui MP suficiente");
                            printf("\n<>");
                            getch();
                            goto action_choice;
                        }
                    }
                    else if(spell_choice==0)
                    {
                        goto action_choice;
                    }
                }
                else if(strcmp(character->bloco.jclass,"Patrulheiro")==0)
                {
                    player_id(character);
                    show_enemies(enemies);

                    printf("\n\n");
                    printf("=================================");
                    printf("\nMAGIAS");
                    printf("\n1.Marca do caçador");
                    printf("\n2.Conjurar rajada - 3d8");
                    printf("\n3.Flecha relampejante - 4d8");
                    printf("\n0.Voltar");
                    printf("\n>.");
                    scanf("%d",&spell_choice);

                    if(spell_choice==1)
                    {
                        strcpy(spell,"Marca do caçador");
                        mp_cost = 15;

                        if(character->bloco.MP > mp_cost)
                        {
                            character->bloco.MP -= mp_cost;
                            dmg_buff = 3;
                            printf("\nVocê usa ");
                            blue();
                            printf("%s",spell);
                            reset();
                            printf(" e aumenta seu dano causado nas próximas 3 rodadas");
                            printf("\n<>");
                            getch();
                        }
                        else
                        {
                            printf("\nVocê não possui MP suficiente");
                            printf("\n<>");
                            getch();
                            goto action_choice;
                        }
                    }
                    else if(spell_choice==2)
                    {
                        strcpy(spell,"Conjurar rajada");
                        mp_cost = 24;

                        if(character->bloco.MP > mp_cost)
                        {
                            character->bloco.MP -= mp_cost;
                            player_dmg = 1 +rand()% 8;
                            player_dmg += 1 +rand()%8;
                            player_dmg += 1 +rand()%8;
                            printf("\nVocê usa ");
                            blue();
                            printf("%s",spell);
                            reset();
                            printf(" para atacar ");
                            red();
                            printf("%s",enemies[fight_enemy-1].name);
                            reset();
                            printf(" e causa ");
                            red();
                            printf("%d",player_dmg);
                            reset();
                            printf(" pontos de dano");
                            enemies[fight_enemy-1].HP -= player_dmg;
                            printf("\n<>");
                            getch();
                        }
                        else
                        {
                            printf("\nVocê não possui MP suficiente");
                            printf("\n<>");
                            getch();
                            goto action_choice;
                        }
                    }
                    else if(spell_choice==3)
                    {
                        strcpy(spell,"Flecha relampejante");
                        mp_cost = 32;

                        if(character->bloco.MP > mp_cost)
                        {
                            character->bloco.MP -= mp_cost;
                            player_dmg = 1 +rand()% 8;
                            player_dmg += 1 +rand()%8;
                            player_dmg += 1 +rand()%8;
                            player_dmg += 1 +rand()%8;
                            printf("\nVocê usa ");
                            blue();
                            printf("%s",spell);
                            reset();
                            printf(" para atacar ");
                            red();
                            printf("%s",enemies[fight_enemy-1].name);
                            reset();
                            printf(" e causa ");
                            red();
                            printf("%d",player_dmg);
                            reset();
                            printf(" pontos de dano");
                            enemies[fight_enemy-1].HP -= player_dmg;
                            printf("\n<>");
                            getch();
                        }
                        else
                        {
                            printf("\nVocê não possui MP suficiente");
                            printf("\n<>");
                            getch();
                            goto action_choice;
                        }

                    }
                    else if(spell_choice==0)
                    {
                        goto action_choice;
                    }
                }
                else if(strcmp(character->bloco.jclass,"Paladino")==0)
                {
                    player_id(character);
                    show_enemies(enemies);

                    printf("\n\n");
                    printf("=================================");
                    printf("\nMAGIAS");
                    printf("\n1.Curar ferimentos - 1d8");
                    printf("\n2.Auxílio divino");
                    printf("\n3.Escudo da fé");
                    printf("\n0.Voltar");
                    printf("\n>.");
                    scanf("%d",&spell_choice);

                    if(spell_choice==1)
                    {
                        strcpy(spell,"Curar ferimentos");
                        mp_cost = 16;

                        if(character->bloco.MP > mp_cost)
                        {
                            player_heal = 1 +rand()% 8;
                            character->bloco.MP -= mp_cost;
                            character->bloco.HP += player_heal;
                            if(character->bloco.HP > character->bloco.MAX_HP)
                            {
                                character->bloco.HP = character->bloco.MAX_HP;
                            }
                            printf("\nVocê usa ");
                            blue();
                            printf("%s",spell);
                            reset();
                            printf(" e restaura ");
                            green();
                            printf("%d",player_heal);
                            reset();
                            printf(" pontos de vida");
                            printf("\n<>");
                            getch();
                        }
                        else
                        {
                            printf("\nVocê não possui MP suficiente");
                            printf("\n<>");
                            getch();
                            goto action_choice;
                        }

                    }
                    else if(spell_choice==2)
                    {
                        strcpy(spell,"Auxilio divino");
                        mp_cost = 10;

                        if(character->bloco.MP > mp_cost)
                        {
                            character->bloco.MP -= mp_cost;
                            dmg_buff=3;
                            printf("\nVocê usa ");
                            blue();
                            printf("%s",spell);
                            reset();
                            printf(" e aumenta seu dano causado nas próximas 3 rodadas");
                            printf("\n<>");
                            getch();
                        }
                        else
                        {
                            printf("\nVocê não possui MP suficiente");
                            printf("\n<>");
                            getch();
                            goto action_choice;
                        }
                    }
                    else if(spell_choice==3)
                    {
                        strcpy(spell,"Escudo da fé");
                        mp_cost = 20;

                        if(character->bloco.MP > mp_cost)
                        {
                            character->bloco.MP -= mp_cost;
                            def_buff=3;
                            printf("\nVocê usa ");
                            blue();
                            printf("%s",spell);
                            reset();
                            printf(" e diminui o dano tomado nas próximas 3 rodadas");
                            printf("\n<>");
                            getch();
                        }
                        else
                        {
                            printf("\nVocê não possui MP suficiente");
                            printf("\n<>");
                            getch();
                            goto action_choice;
                        }
                    }
                    else if(spell_choice==0)
                    {
                        goto action_choice;
                    }
                }
                else if(strcmp(character->bloco.jclass,"Mago")==0)
                {
                    player_id(character);
                    show_enemies(enemies);

                    printf("\n\n");
                    printf("=================================");
                    printf("\nMAGIAS");
                    printf("\n1.Bola de fogo - 8d6");
                    printf("\n2.Raio de gelo - 1d8");
                    printf("\n3.Espirro ácido - 1d6");
                    printf("\n0.Voltar");
                    printf("\n>.");
                    scanf("%d",&spell_choice);

                    if(spell_choice==1)
                    {
                        strcpy(spell,"Bola de fogo");
                        mp_cost = 64;

                        if(character->bloco.MP > mp_cost)
                        {
                            character->bloco.MP -= mp_cost;
                            player_dmg = 1 +rand()% 6;
                            player_dmg += 1 +rand()%6;
                            player_dmg += 1 +rand()%6;
                            player_dmg += 1 +rand()%6;
                            player_dmg += 1 +rand()%6;
                            player_dmg += 1 +rand()%6;
                            player_dmg += 1 +rand()%6;
                            player_dmg += 1 +rand()%6;

                            printf("\nVocê usa ");
                            blue();
                            printf("%s",spell);
                            reset();
                            printf(" para atacar ");
                            red();
                            printf("%s",enemies[fight_enemy-1].name);
                            reset();
                            printf(" e causa ");
                            red();
                            printf("%d",player_dmg);
                            reset();
                            printf(" pontos de dano");
                            enemies[fight_enemy-1].HP -= player_dmg;
                            printf("\n<>");
                            getch();
                        }
                        else
                        {
                            printf("\nVocê não possui MP suficiente");
                            printf("\n<>");
                            getch();
                            goto action_choice;
                        }

                    }
                    else if(spell_choice==2)
                    {
                        strcpy(spell,"Raio de gelo");
                        mp_cost = 12;

                        if(character->bloco.MP > mp_cost)
                        {
                            character->bloco.MP -= mp_cost;
                            player_dmg = 1 +rand()%8;

                            printf("\nVocê usa ");
                            blue();
                            printf("%s",spell);
                            reset();
                            printf(" para atacar ");
                            red();
                            printf("%s",enemies[fight_enemy-1].name);
                            reset();
                            printf(" e causa ");
                            red();
                            printf("%d",player_dmg);
                            reset();
                            printf(" pontos de dano");
                            enemies[fight_enemy-1].HP -= player_dmg;
                            printf("\n<>");
                            getch();
                        }
                        else
                        {
                            printf("\nVocê não possui MP suficiente");
                            printf("\n<>");
                            getch();
                            goto action_choice;
                        }
                    }
                    else if(spell_choice==3)
                    {
                        strcpy(spell,"Espirro ácido");
                        mp_cost = 8;

                        if(character->bloco.MP > mp_cost)
                        {
                            character->bloco.MP -= mp_cost;
                            player_dmg = 1 +rand()%6;

                            printf("\nVocê usa ");
                            blue();
                            printf("%s",spell);
                            reset();
                            printf(" para atacar ");
                            red();
                            printf("%s",enemies[fight_enemy-1].name);
                            reset();
                            printf(" e causa ");
                            red();
                            printf("%d",player_dmg);
                            reset();
                            printf(" pontos de dano");
                            enemies[fight_enemy-1].HP -= player_dmg;
                            printf("\n<>");
                            getch();
                        }
                        else
                        {
                            printf("\nVocê não possui MP suficiente");
                            printf("\n<>");
                            getch();
                            goto action_choice;
                        }
                    }
                    else if(spell_choice==0)
                    {
                        goto action_choice;
                    }
                }
                else if(strcmp(character->bloco.jclass,"Druida")==0)
                {
                    player_id(character);
                    show_enemies(enemies);

                    printf("\n\n");
                    printf("=================================");
                    printf("\nMAGIAS");
                    printf("\n1.Curar ferimentos - 1d8");
                    printf("\n2.Onda trovejante - 2d8");
                    printf("\n3.Chicote de espinhos - 1d6");
                    printf("\n0.Voltar");
                    printf("\n>.");
                    scanf("%d",&spell_choice);

                    if(spell_choice==1)
                    {
                        strcpy(spell,"Curar ferimentos");
                        mp_cost = 16;

                        if(character->bloco.MP > mp_cost)
                        {
                            player_heal = 1 +rand()% 8;
                            character->bloco.MP -= mp_cost;
                            character->bloco.HP += player_heal;
                            if(character->bloco.HP > character->bloco.MAX_HP)
                            {
                                character->bloco.HP = character->bloco.MAX_HP;
                            }
                            printf("\nVocê usa ");
                            blue();
                            printf("%s",spell);
                            reset();
                            printf(" e restaura ");
                            green();
                            printf("%d",player_heal);
                            reset();
                            printf(" pontos de vida");
                            printf("\n<>");
                            getch();
                        }
                        else
                        {
                            printf("\nVocê não possui MP suficiente");
                            printf("\n<>");
                            getch();
                            goto action_choice;
                        }
                    }
                    else if(spell_choice==2)
                    {
                        strcpy(spell,"Onda trovejante");
                        mp_cost = 16;

                        if(character->bloco.MP > mp_cost)
                        {
                            character->bloco.MP -= mp_cost;
                            player_dmg = 1 +rand()%8;
                            player_dmg += 1 +rand()%8;

                            printf("\nVocê usa ");
                            blue();
                            printf("%s",spell);
                            reset();
                            printf(" para atacar ");
                            red();
                            printf("%s",enemies[fight_enemy-1].name);
                            reset();
                            printf(" e causa ");
                            red();
                            printf("%d",player_dmg);
                            reset();
                            printf(" pontos de dano");
                            enemies[fight_enemy-1].HP -= player_dmg;
                            printf("\n<>");
                            getch();
                        }
                        else
                        {
                            printf("\nVocê não possui MP suficiente");
                            printf("\n<>");
                            getch();
                            goto action_choice;
                        }
                    }
                    else if(spell_choice==3)
                    {
                        strcpy(spell,"Chicote de espinhos");
                        mp_cost = 6;

                        if(character->bloco.MP > mp_cost)
                        {
                            character->bloco.MP -= mp_cost;
                            player_dmg = 1 +rand()%6;

                            printf("\nVocê usa ");
                            blue();
                            printf("%s",spell);
                            reset();
                            printf(" para atacar ");
                            red();
                            printf("%s",enemies[fight_enemy-1].name);
                            reset();
                            printf(" e causa ");
                            red();
                            printf("%d",player_dmg);
                            reset();
                            printf(" pontos de dano");
                            enemies[fight_enemy-1].HP -= player_dmg;
                            printf("\n<>");
                            getch();
                        }
                        else
                        {
                            printf("\nVocê não possui MP suficiente");
                            printf("\n<>");
                            getch();
                            goto action_choice;
                        }
                    }
                    else if(spell_choice==0)
                    {
                        goto action_choice;
                    }
                }
                else if(strcmp(character->bloco.jclass,"Bruxo")==0)
                {
                    player_id(character);
                    show_enemies(enemies);

                    printf("\n\n");
                    printf("=================================");
                    printf("\nMAGIAS");
                    printf("\n1.Rajada de veneno - 1d12");
                    printf("\n2.Toque vampírico - 3d6");
                    printf("\n3.Toque arrepiante - 1d8");
                    printf("\n0.Voltar");
                    printf("\n>.");
                    scanf("%d",&spell_choice);

                    if(spell_choice==1)
                    {
                        strcpy(spell,"Rajada de veneno");
                        mp_cost = 14;

                        if(character->bloco.MP > mp_cost)
                        {
                            character->bloco.MP -= mp_cost;
                            player_dmg = 1 +rand()% 12;

                            printf("\nVocê usa ");
                            blue();
                            printf("%s",spell);
                            reset();
                            printf(" para atacar ");
                            red();
                            printf("%s",enemies[fight_enemy-1].name);
                            reset();
                            printf(" e causa ");
                            red();
                            printf("%d",player_dmg);
                            reset();
                            printf(" pontos de dano");
                            enemies[fight_enemy-1].HP -= player_dmg;
                            printf("\n<>");
                            getch();
                        }
                        else
                        {
                            printf("\nVocê não possui MP suficiente");
                            printf("\n<>");
                            getch();
                            goto action_choice;
                        }
                    }
                    else if(spell_choice==2)
                    {
                        strcpy(spell,"Toque vampírico");
                        mp_cost = 28;

                        if(character->bloco.MP > mp_cost)
                        {
                            character->bloco.MP -= mp_cost;
                            player_dmg = 1 +rand()%6;
                            player_dmg += 1 +rand()%6;
                            player_dmg += 1 +rand()%6;
                            player_heal = player_dmg/2;
                            character->bloco.HP += player_heal;
                            if(character->bloco.HP > character->bloco.MAX_HP)
                            {
                                character->bloco.HP = character->bloco.MAX_HP;
                            }

                            printf("\nVocê usa ");
                            blue();
                            printf("%s",spell);
                            reset();
                            printf(" para atacar ");
                            red();
                            printf("%s",enemies[fight_enemy-1].name);
                            reset();
                            printf(" e causa ");
                            red();
                            printf("%d",player_dmg);
                            reset();
                            printf(" pontos de dano e restaura ");
                            green();
                            printf("%d",player_heal);
                            reset();
                            printf(" pontos de vida a você");
                            enemies[fight_enemy-1].HP -= player_dmg;
                            printf("\n<>");
                            getch();
                        }
                        else
                        {
                            printf("\nVocê não possui MP suficiente");
                            printf("\n<>");
                            getch();
                            goto action_choice;
                        }
                    }
                    else if(spell_choice==3)
                    {
                        strcpy(spell,"Toque arrepiante");
                        mp_cost = 10;

                        if(character->bloco.MP > mp_cost)
                        {
                            character->bloco.MP -= mp_cost;
                            player_dmg = 1 +rand()%8;

                            printf("\nVocê usa ");
                            blue();
                            printf("%s",spell);
                            reset();
                            printf(" para atacar ");
                            red();
                            printf("%s",enemies[fight_enemy-1].name);
                            reset();
                            printf(" e causa ");
                            red();
                            printf("%d",player_dmg);
                            reset();
                            printf(" pontos de dano");
                            enemies[fight_enemy-1].HP -= player_dmg;
                            printf("\n<>");
                            getch();
                        }
                        else
                        {
                            printf("\nVocê não possui MP suficiente");
                            printf("\n<>");
                            getch();
                            goto action_choice;
                        }
                    }
                    else if(spell_choice==0)
                    {
                        goto action_choice;
                    }
                }
            }

            if(enemies[fight_enemy-1].HP<=0)
            {
                system("cls");
                player_id(character);
                show_enemies(enemies);
                printf("\n\n");
                printf("=================================");
                printf("\n\n");
                red();
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
                printf("\n%d",enemy_dmg);
                if(def_buff>0 && enemy_dmg>0)
                {
                    enemy_dmg = enemy_dmg/2;
                    printf("\n%d",enemy_dmg);
                }
                if(enemy_dmg>0)
                {
                    printf("\n");
                    red();
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
                    red();
                    text_write(strcpy(text,enemies[i].name));
                    reset();
                    text_write(strcpy(text," errou o ataque"));
                }
                i++;
            }
            if(def_buff>0)
            {
                def_buff--;
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
