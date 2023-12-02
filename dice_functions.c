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


int roll_dice(int rolls, int dice)
{
    srand(time(NULL));
    int i;
    i=0;

    //system("cls");
    //getch();

    int result=0;

    while(i<rolls)
    {
        result += 1 + rand()% dice;
        i++;
    }

    return result;
}

int weapons_dmg(char weapon[])
{
    int dmg=0;


    //ARMAS SIMPLES CORPO A CORPO
    if(strcmp(weapon,"Adaga")==0)
    {
        dmg = roll_dice(1,4);
    }
    else if(strcmp(weapon,"Bordão")==0)
    {
        dmg = roll_dice(1,6);
    }
    else if(strcmp(weapon,"Clava Grande")==0)
    {
        dmg = roll_dice(1,8);
    }
    else if(strcmp(weapon,"Foice Curta")==0)
    {
        dmg = roll_dice(1,4);
    }
    else if(strcmp(weapon,"Lança")==0)
    {
        dmg = roll_dice(1,6);
    }
    else if(strcmp(weapon,"Maça")==0)
    {
        dmg = roll_dice(1,6);
    }
    else if(strcmp(weapon,"Machadinha")==0)
    {
        dmg = roll_dice(1,6);
    }
    else if(strcmp(weapon,"Martelo Leve")==0)
    {
        dmg = roll_dice(1,4);
    }
    else if(strcmp(weapon,"Porrete")==0)
    {
        dmg = roll_dice(1,4);
    }

    //ARMAS SIMPLES A DISTÂNCIA
    else if(strcmp(weapon,"Arco Curto")==0)
    {
        dmg = roll_dice(1,6);
    }
    else if(strcmp(weapon,"Besta Leve")==0)
    {
        dmg = roll_dice(1,8);
    }
    else if(strcmp(weapon,"Dardo")==0)
    {
        dmg = roll_dice(1,4);
    }
    else if(strcmp(weapon,"Funda")==0)
    {
        dmg = roll_dice(1,4);
    }

    //ARMAS MARCIAIS CORPO A CORPO
    else if(strcmp(weapon,"Alabarda")==0)
    {
        dmg = roll_dice(1,10);
    }
    else if(strcmp(weapon,"Cimitarra")==0)
    {
        dmg = roll_dice(1,6);
    }
    else if(strcmp(weapon,"Chicote")==0)
    {
        dmg = roll_dice(1,4);
    }
    else if(strcmp(weapon,"Espada Curta")==0)
    {
        dmg = roll_dice(1,6);
    }
    else if(strcmp(weapon,"Espada Grande")==0)
    {
        dmg = roll_dice(2,6);
    }
    else if(strcmp(weapon,"Espada Longa")==0)
    {
        dmg = roll_dice(1,8);
    }
    else if(strcmp(weapon,"Glaive")==0)
    {
        dmg = roll_dice(1,10);
    }
    else if(strcmp(weapon,"Lança de Montaria")==0)
    {
        dmg = roll_dice(1,12);
    }
    else if(strcmp(weapon,"Lança Longa")==0)
    {
        dmg = roll_dice(1,10);
    }
    else if(strcmp(weapon,"Maça Estrela")==0)
    {
        dmg = roll_dice(1,8);
    }
    else if(strcmp(weapon,"Machado Grande")==0)
    {
        dmg = roll_dice(1,12);
    }
    else if(strcmp(weapon,"Machado de Batalha")==0)
    {
        dmg = roll_dice(1,8);
    }
    else if(strcmp(weapon,"Malho")==0)
    {
        dmg = roll_dice(2,6);
    }
    else if(strcmp(weapon,"Mangual")==0)
    {
        dmg = roll_dice(1,8);
    }
    else if(strcmp(weapon,"Martelo de Guerra")==0)
    {
        dmg = roll_dice(1,8);
    }
    else if(strcmp(weapon,"Picareta de Guerra")==0)
    {
        dmg = roll_dice(1,8);
    }
    else if(strcmp(weapon,"Rapieira")==0)
    {
        dmg = roll_dice(1,8);
    }
    else if(strcmp(weapon,"Tridente")==0)
    {
        dmg = roll_dice(1,6);
    }

    //ARMAS MARCIAIS A DISTÂNCIA
    else if(strcmp(weapon,"Arco Longo")==0)
    {
        dmg = roll_dice(1,8);
    }
    else if(strcmp(weapon,"Besta de Mão")==0)
    {
        dmg = roll_dice(1,6);
    }
    else if(strcmp(weapon,"Besta Pesada")==0)
    {
        dmg = roll_dice(1,10);
    }
    else if(strcmp(weapon,"Zarabatana")==0)
    {
        dmg = 1;
    }

    //ARMAS ESPECIAIS E ATAQUES DE MONSTROS
    else if(strcmp(weapon,"Drenar Vida")==0)
    {
        dmg = roll_dice(3,6);
    }

    return dmg;
}
