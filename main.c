/*
	NOME-_-_-_: Breno
                Davi
                Gabriel
                Luiz
	RA-_-_-_-_: ?
	CURSO_-_-_: Análise e Desenvolvimento de Sistemas (ADS)
	PERÍDODO-_: 1º
	DISCIPLINA: Extensão 2
	DATA-_-_-_:

	Descrição do algoritmo;


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
    printf("\nPara jogar, basta escolher o numero da opção desejada quando for solicitado!");
    printf("\nPressione qualquer botão para prosseguir");
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
            text_write(strcpy(text,"\nUma luz forte cega seus olhos, você fica atordoado por algum tempo."));
            Sleep(800);
            text_write(strcpy(text,"\nVocê escuta uma voz lhe chamando."));
            printf("\n<>");
            getch();

            system("cls");
            printf("\nVoz misteriosa: ");
            text_write(strcpy(text,"Olá! "));
            Sleep(800);
            text_write(strcpy(text,"Oiee!"));
            Sleep(800);
            printf("\nVoz misteriosa: ");
            text_write(strcpy(text,"Hmm, será que este foi outro erro?"));
            printf("\n<>");
            getch();

            system("cls");
            text_write(strcpy(text,"\nApós abrir seus olhos você se encontra em um ambiente completamente branco, uma névoa suave preenche este ambiente."));
            text_write(strcpy(text,"\nA voz que te chamava pertence a uma estranha figura em sua frente, impossível de determinar suas expressões faciais, gênero ou qualquer outra coisa além de sua aparência humanoide."));
            text_write(strcpy(text,"\nEste estranho ser começa a conversar com você."));
            printf("\n<>");
            getch();

            system("cls");
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Ah, ótimo! Você acordou."));
            Sleep(800);
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Muito prazer, eu sou ####. Qual é o seu nome?"));
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
            text_write(strcpy(text,"Impressionante, né?"));
            printf("\n");
            printf("\t1.Uau! Com certeza impressionante.\n");
            printf("\t2.Não muito!");
            printf("\n>.");
            scanf("%d",&choice);

            system("cls");
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Enfim, você provavelmente sabe do que se trata isso."));
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Ir para outro mundo, lutar contra monstros, salvar pessoas, etc."));
            Sleep(800);
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Mas antes de você continuar para a parte divertida vamos terminar com a papelada."));
            Sleep(800);
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Você pode escolher ir para sua aventura como uma das seguintes raças."));
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Humano, elfo, anão, draconato, tiefling ou autômato."));
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
            text_write(strcpy(text,"\nO ser misterioso pega uma folha de papel do nada e começa a murmurar como se estivesse procurando algo escrito na folha."));
            printf("\n\n");
            Sleep(800);
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Ah, sim!"));
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Você precisa escolher uma classe também."));
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"As classes são as seguintes."));
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Guerreiro, patrulheiro, paladino, mago, druida e bruxo."));

            class_choice(character);
            player_id(character);
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Ótimo, ótimo."));
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Agora você está pronto para sua aventura."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Agora vou te dizer o que você precisa fazer neste mundo."));
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"De maneira simples, você só tem que derrotar o Soberano Sombrio que tomou conta deste mundo."));
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Nada muito complicado. Eu mesmo faria isso, mas, infelizmente não posso interferir no mundo físico diretamente."));
            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Agora que você sabe o que precisa ser feito você tem alguma dúvida?"));

            printf("\n");
            printf("\t1.Sem dúvidas.\n");
            printf("\t2.Por que eu?\n");
            printf("\t3.Posso ir pra casa?");
            printf("\n>.");
            scanf("%d",&choice);

            if(choice==2)
            {
                printf("\nSer misterioso: ");
                text_write(strcpy(text,"Err, porque você é especial. Você possui uma energia diferente. Um potencial latente."));
            }
            else if(choice==3)
            {
                printf("\nSer misterioso: ");
                text_write(strcpy(text,"Assim que você completar essa minha missão eu te envio de volta."));
            }

            printf("\nSer misterioso: ");
            text_write(strcpy(text,"Ótimo, agora que terminamos vou te enviar para uma vila que está sendo atacada por alguns monstros, comece ajudando a defender esta vila."));
            printf("\n<>");
            getch();

            system("cls");
            text_write(strcpy(text,"\nO ser misterioso estala os dedos e de repente você se encontra em um lugar completamente diferente de onde estava."));
            text_write(strcpy(text,"\nA fraca névoa dá lugar a uma fumaça espessa e o ambiente agora possui uma cor avermelhada, você vê chamas por todos os lados, e escuta gritos vindos da vila a sua frente."));
            text_write(strcpy(text,"\nEstranhas criaturas atacam a vila, pequenos seres verdes com narizes grandes."));
            text_write(strcpy(text,"\nAlguns deles percebem sua presença e correm em sua direção, prontos para atacar."));
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
