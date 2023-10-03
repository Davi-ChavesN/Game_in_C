/*
	NOME-_-_-_: Breno
                Davi
                Gabriel
                Luiz
	RA-_-_-_-_: ?
	CURSO_-_-_: An�lise e Desenvolvimento de Sistemas (ADS)
	PER�DODO-_: 1�
	DISCIPLINA: Extens�o 2
	DATA-_-_-_:

	Descri��o do algoritmo;


*/


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



int main()
{
    setlocale(LC_ALL, "portuguese-brazilian");

    player_info *character = calloc(1,sizeof(player_info));
    enemy_data enemies[tam];
    player_data bloco;
    int opc=-1;
    int choice=0;
    char text[150];


    system("cls");
    printf("\nPara jogar, basta escolher o numero da op��o desejada quando for solicitado!");
    printf("\nPressione qualquer bot�o para prosseguir");
    printf("\n<>");
    getch();


    while(opc!=0)
    {
        system("cls");
        printf("\n==========NOME DO JOGO==========\n");
        printf("\n1.Jogar");
        printf("\n2.?");
        printf("\n3.Creditos");
        printf("\n0.Sair");
        printf("\n>.");
        fflush(stdin);
        scanf("%d",&opc);

        if(opc==1)
        {
            system("cls");
            text_write(strcpy(text,"\nUma luz forte cega seus olhos, voc� fica atordoado por algum tempo."));
            Sleep(800);
            text_write(strcpy(text,"\nVoc� escuta uma voz lhe chamando."));
            printf("\n<>");
            getch();

            system("cls");
            printf("\nVoz misteriosa: ");
            text_write(strcpy(text,"Ol�! "));
            Sleep(800);
            text_write(strcpy(text,"Oiee!"));
            Sleep(800);
            printf("\nVoz misteriosa: ");
            text_write(strcpy(text,"Hmm, ser� que este foi outro erro?"));
            printf("\n<>");
            getch();

            system("cls");
            text_write(strcpy(text,"\nAp�s abrir seus olhos voc� se encontra em um ambiente completamente branco, uma n�voa suave preenche este ambiente."));
            text_write(strcpy(text,"\nA voz que te chamava pertence a uma estranha figura em sua frente, imposs�vel de determinar suas express�es faciais, g�nero ou qualquer outra coisa al�m de sua apar�ncia humanoide."));
            text_write(strcpy(text,"\nEste estranho ser come�a a conversar com voc�."));
            printf("\n<>");
            getch();

            system("cls");
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Ah, �timo! Voc� acordou."));
            Sleep(800);
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Muito prazer, eu sou ####. Qual � o seu nome?"));
            printf("\n[16]>.");
            fflush(stdin);
            gets(bloco.name);
            bloco.LV=0;

            set_player_name(character, bloco);
            system("cls");
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Muito prazer "));
            text_write(strcpy(text, character->bloco.name));
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Bom, vou direto ao assunto, eu lhe transportei para outro mundo."));
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Impressionante, n�?"));
            printf("\n");
            printf("\t1.Uau! Com certeza impressionante.\n");
            printf("\t2.N�o muito!");
            printf("\n>.");
            scanf("%d",&choice);

            system("cls");
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Enfim, voc� provavelmente sabe do que se trata isso."));
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Ir para outro mundo, lutar contra monstros, salvar pessoas, etc."));
            Sleep(800);
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Mas antes de voc� continuar para a parte divertida vamos terminar com a papelada."));
            Sleep(800);
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Voc� pode escolher ir para sua aventura como uma das seguintes ra�as."));
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Humano, elfo, an�o, draconato, tiefling ou aut�mato."));
            printf("\n<>");
            getch();

            race_choice(character);
            printf("\nSer misterioso: ");
            text_write(strcpy(text,character->bloco.race));
            text_write(strcpy(text," em. Uma escolha interessante."));
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"O que era depois disso mesmo?"));
            printf("\n<>");
            getch();

            system("cls");
            text_write(strcpy(text,"\nO ser misterioso pega uma folha de papel do nada e come�a a murmurar como se estivesse procurando algo escrito na folha."));
            printf("\n\n");
            Sleep(800);
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Ah, sim!"));
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Voc� precisa escolher uma classe tamb�m."));
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"As classes s�o as seguintes."));
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Guerreiro, patrulheiro, paladino, mago, druida e bruxo."));

            class_choice(character);
            player_id(character);
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"�timo, �timo."));
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Agora voc� est� pronto para sua aventura."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Agora vou te dizer o que voc� precisa fazer neste mundo."));
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"De maneira simples, voc� s� tem que derrotar o Soberano Sombrio que tomou conta deste mundo."));
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Nada muito complicado. Eu mesmo faria isso, mas, infelizmente n�o posso interferir no mundo f�sico diretamente."));
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Agora que voc� sabe o que precisa ser feito voc� tem alguma d�vida?"));

            printf("\n");
            printf("\t1.Sem d�vidas.\n");
            printf("\t2.Por que eu?\n");
            printf("\t3.Posso ir pra casa?");
            printf("\n>.");
            scanf("%d",&choice);

            if(choice==2)
            {
                printf("\nSer misterioso: ");
                text_write(strcpy(text,"Err, porque voc� � especial. Voc� possui uma energia diferente. Um potencial latente."));
            }
            else if(choice==3)
            {
                printf("\nSer misterioso: ");
                text_write(strcpy(text,"Assim que voc� completar essa minha miss�o eu te envio de volta."));
            }

            printf("\nSer misterioso: ");
            text_write(strcpy(text,"�timo, agora que terminamos vou te enviar para uma vila que est� sendo atacada por alguns monstros, comece ajudando a defender esta vila."));
            printf("\n<>");
            getch();

            system("cls");
            text_write(strcpy(text,"\nO ser misterioso estala os dedos e de repente voc� se encontra em um lugar completamente diferente de onde estava."));
            text_write(strcpy(text,"\nA fraca n�voa d� lugar a uma fuma�a espessa e o ambiente agora possui uma cor avermelhada, voc� v� chamas por todos os lados, e escuta gritos vindos da vila a sua frente."));
            text_write(strcpy(text,"\nEstranhas criaturas atacam a vila, pequenos seres verdes com narizes grandes."));
            text_write(strcpy(text,"\nAlguns deles percebem sua presen�a e correm em sua dire��o, prontos para atacar."));
            printf("\n<>");
            getch();

            system("cls");
            enemy_generation(enemies,2,1);
            battle(character, enemies);
            level_up(character);

            system("cls");
            player_id(character);
            printf("\n<>");
            getch();
        }
    }



    //text_write(strcpy(text,"\n"));
    printf("\n\nAcabou. Tchau!\n\n");
    return 0;
}
