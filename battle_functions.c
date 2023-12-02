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

#define tam 10


void enemy_generation(enemy_data enemies[], char enemy_list[])
{
    int i;

    /*
        Danger class - Enemy
            1           Slime - X
            2           Goblin - pronto
            3           Bandit - pronto
            4           Specter - pronto
            5           Orc - pronto
    */

    i=0;
    while(enemy_list[i]!='\0')
    {

        if(enemy_list[i]=='0')
        {
            strcpy(enemies[i].name,"");
            enemies[i].HP = 0;
            enemies[i].CA = 0;
            enemies[i].EXP_drop = 0;
            strcpy(enemies[i].weapon1,"");
            strcpy(enemies[i].weapon2,"");
        }
        if(enemy_list[i]=='1')
        {

//            strcpy(enemies[i].name,"Slime");
//            enemies[i].HP = 7 + rand()%9;
//            enemies[i].EXP_drop = 3 + rand()%5;
        }
        if(enemy_list[i]=='2')
        {
            strcpy(enemies[i].name,"Goblin");
            enemies[i].HP = roll_dice(2,6);
            enemies[i].CA = roll_dice(1,15);
            enemies[i].EXP_drop = roll_dice(1,50);
            strcpy(enemies[i].weapon1,"Cimitarra");
            strcpy(enemies[i].weapon2,"Arco Curto");
        }
        if(enemy_list[i]=='3')
        {
            strcpy(enemies[i].name,"Bandido");
            enemies[i].HP = roll_dice(2,8);
            enemies[i].CA = roll_dice(1,12);
            enemies[i].EXP_drop = roll_dice(1,25);
            strcpy(enemies[i].weapon1,"Cimitarra");
            strcpy(enemies[i].weapon2,"Besta Leve");
        }
        if(enemy_list[i]=='4')
        {
            strcpy(enemies[i].name,"Espectro");
            enemies[i].HP = roll_dice(5,8);
            enemies[i].CA = roll_dice(1,13);
            enemies[i].EXP_drop = roll_dice(1,100);
            strcpy(enemies[i].weapon1,"Drenar Vida");
            strcpy(enemies[i].weapon2,"Drenar Vida");
        }
        if(enemy_list[i]=='5')
        {
            strcpy(enemies[i].name,"Orc");
            enemies[i].HP = roll_dice(2,8);
            enemies[i].CA = roll_dice(1,13);
            enemies[i].EXP_drop = roll_dice(1,100);
            strcpy(enemies[i].weapon1,"Machado Grande");
            strcpy(enemies[i].weapon2,"Azagaia");
        }
        if(enemy_list[i]=='G')
        {
            strcpy(enemies[i].name,"Guardião da Sombra");
            enemies[i].HP = 50;
            enemies[i].CA = 12;
            enemies[i].EXP_drop = 500;
            strcpy(enemies[i].weapon1,"Malho");
            strcpy(enemies[i].weapon2,"Martelo Leve");
        }

        system("cls");
        if(enemy_list[i]!='0')
        {
            loadingBar();
        }
        i++;
    }
    //getch();
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
    int n=0;
    while(i<tam)
    {
        if(strcmp(enemies[i].name,"")!=0)
        {
            printf("\n%d. ",n+1);
            red();
            printf("%s",enemies[i].name);
            reset();
            n++;

            if(enemies[i].HP>0)
            {

            }
            else
            {
                printf(" - Derrotado");
            }
        }
        i++;
    }
}

void battle(player_info *character, enemy_data enemies[])
{
    char text[150],spell[50],weapon[25];
    int flag,i,choice,fight_choice,fight_enemy,spell_choice,weapon_choice,bp_choice;
    int player_dmg,player_heal,enemy_dmg,dice;
    int dmg_buff,def_buff;
    int mp_cost,rng;

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
        printf("\n2.Mochila");
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

            while(enemies[fight_enemy-1].HP<=0 || fight_enemy<1 || fight_enemy>10)
            {
                player_id(character);
                show_enemies(enemies);

                printf("\n\n");
                printf("=================================");
                if(enemies[fight_enemy-1].HP<=0)
                {
                    printf("\nInimigo já está morto");
                }
                else if(fight_enemy<1 || fight_enemy>10)
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
                system("cls");
                player_id(character);
                show_enemies(enemies);

                printf("\n\n");
                printf("=================================");
                printf("\nEscolha sua ação");
                printf("\n1.%s",character->bloco.equiped_weapon1);
                if(strcmp(character->bloco.equiped_weapon2,"")!=0)
                {
                    printf("\n2.%s",character->bloco.equiped_weapon2);
                }
                printf("\n>.");
                scanf("%d",&weapon_choice);

                if(weapon_choice==1)
                {
                    strcpy(weapon,character->bloco.equiped_weapon1);
                    printf("%s",weapon);
                    getch();
                }
                else if(weapon_choice==2)
                {
                    strcpy(weapon,character->bloco.equiped_weapon2);
                }

                player_dmg = weapons_dmg(weapon);

                if(dmg_buff>0)
                {
                    if(strcmp(character->bloco.jclass,"Bárbaro")==0)
                    {
                        player_dmg += roll_dice(1,6);
                    }
                    else if(strcmp(character->bloco.jclass,"Patrulheiro")==0)
                    {
                        player_dmg += roll_dice(1,6);
                    }
                    else if(strcmp(character->bloco.jclass,"Paladino")==0)
                    {
                        player_dmg += roll_dice(1,4);
                    }
                    dmg_buff--;
                }

                dice = roll_dice(1,20);

                if(dice==20)
                {
                    player_dmg = player_dmg*2;
                    yellow();
                    printf("\nACERTO CRÍTICO\n");
                    reset();
                }

                //arrumar d20 e CA dos inimigos
                if(dice>=enemies[fight_enemy-1].CA)
                {
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
                }
                else
                {
                    text_write(strcpy(text,"\nVocê errou seu ataque "));
                }
                printf("\n<>");
                getch();
            }
            else if(fight_choice==2)
            {
                if(strcmp(character->bloco.jclass,"Bárbaro")==0)
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
                if(enemies[i].HP>0)
                {
                    rng = 1 + rand()%2;

                    if(rng==1)
                    {
                        strcpy(weapon,enemies[i].weapon1);
                    }
                    else
                    {
                        strcpy(weapon,enemies[i].weapon2);
                    }
                    enemy_dmg = weapons_dmg(weapon);

                    dice = roll_dice(1,20);

                    if(dice>=character->bloco.CA)
                    {
                        if(def_buff>0 && enemy_dmg>0)
                        {
                            enemy_dmg = enemy_dmg/2;
                        }
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
                    else if(dice<character->bloco.CA)
                    {
                        printf("\n");
                        red();
                        text_write(strcpy(text,enemies[i].name));
                        reset();
                        text_write(strcpy(text," errou o ataque"));
                    }
                    Sleep(1000);
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
            system("cls");
            player_id(character);
            show_enemies(enemies);

            printf("\n\n");
            printf("=================================");
            printf("\nEscolha sua ação");
            printf("\n1.Poção de vida");
            printf("\n2.Poção de mana");
            printf("\n>.");
            scanf("%d",&bp_choice);

            if(bp_choice==1)
            {
                if(character->bloco.HP + 50 > character->bloco.MAX_HP)
                {
                    character->bloco.HP = character->bloco.MAX_HP;
                }
                else
                {
                    character->bloco.HP += 50;
                }
                printf("\nVocê usa uma poção de vida");
            }
            else if(bp_choice==2)
            {
                if(character->bloco.MP + 50 > character->bloco.MAX_MP)
                {
                    character->bloco.MP = character->bloco.MAX_MP;
                }
                else
                {
                    character->bloco.MP += 50;
                }
                printf("\nVocê usa uma poção de mana");
            }
        }
    }
    if(character->bloco.HP<=0)
    {
        red();
        text_write(strcpy(text,"Você morreu!"));
        reset();
        getch();
    }
}
