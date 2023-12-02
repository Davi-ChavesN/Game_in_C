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

#define tam 10

player_info *character;
enemy_data enemies[tam];
int flagMap=1;
int flagShop=1;
int flagInhabitant=1;

void linkStart()
{
    character = calloc(1,sizeof(player_info));
}


int main()
{
    setlocale(LC_ALL, "portuguese-brazilian");

    //loadingBar();
    linkStart();

    player_data bloco;
    int move_opc, opc=-1;
    int choice=0;
    char text[150];
    int i=0;
    int tavern_flag;
    tavern_flag=1;

    //song();

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
            magenta();
            printf("\nVoz misteriosa: ");
            reset();
            text_write(strcpy(text,"Ol�! "));
            Sleep(800);
            text_write(strcpy(text,"Oiee!"));
            Sleep(800);
            magenta();
            printf("\nVoz misteriosa: ");
            reset();
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
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Ah, �timo! Voc� acordou."));
            Sleep(800);
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Muito prazer, eu sou ####. Qual � o seu nome?"));
            printf("\n[16]>.");
            fflush(stdin);
            gets(bloco.name);

            set_player_name(character, bloco);
            system("cls");
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Muito prazer "));
            green();
            text_write(strcpy(text, character->bloco.name));
            Sleep(500);
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Bom, vou direto ao assunto, eu lhe transportei para outro mundo."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Impressionante, n�?"));
            printf("\n");
            printf("\t1.Uau! Com certeza impressionante.\n");
            printf("\t2.N�o muito.");
            printf("\n>.");
            scanf("%d",&choice);

            if(choice==1)
            {
                system("cls");
                printf("\n");
                green();
                text_write(strcpy(text, character->bloco.name));
                reset();
                text_write(strcpy(text,": Uau! Com certeza impressionante."));
            }
            else if(choice==2)
            {
                system("cls");
                printf("\n");
                green();
                text_write(strcpy(text, character->bloco.name));
                reset();
                text_write(strcpy(text,": N�o muito."));
            }
            else
            {
                system("cls");
            }
            choice=0;

            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Enfim, voc� provavelmente sabe do que se trata isso."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Ir para outro mundo, lutar contra monstros, salvar pessoas, etc."));
            Sleep(800);
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Mas antes de voc� continuar para a parte divertida vamos terminar com a papelada."));
            Sleep(800);
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Voc� pode escolher ir para sua aventura como uma das seguintes ra�as."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Humano, elfo, an�o, draconato, tiefling ou aut�mato."));
            printf("\n<>");
            getch();

            race_choice(character);
            system("cls");

            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,character->bloco.race));
            text_write(strcpy(text," em. Uma escolha interessante."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"O que era depois disso mesmo?"));
            printf("\n<>");
            getch();

            system("cls");
            text_write(strcpy(text,"\nO ser misterioso pega uma folha de papel do nada e come�a a murmurar como se estivesse procurando algo escrito na folha."));
            printf("\n\n");
            Sleep(800);
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Ah, sim!"));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Voc� precisa escolher uma classe tamb�m."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"As classes s�o as seguintes."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"B�rbaro, patrulheiro, paladino, mago, druida e bruxo."));

            class_choice(character);
            system("cls");

            player_id(character);
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"�timo, �timo."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Agora voc� est� pronto para sua aventura."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Agora vou te dizer o que voc� precisa fazer neste mundo."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"De maneira simples, voc� s� tem que derrotar o Soberano Sombrio que tomou conta deste mundo."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Nada muito complicado. Eu mesmo faria isso, mas, infelizmente n�o posso interferir no mundo f�sico diretamente."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Agora que voc� sabe o que precisa ser feito voc� tem alguma d�vida?"));

            printf("\n");
            printf("\t1.Sem d�vidas.\n");
            printf("\t2.Por que eu?\n");
            printf("\t3.Posso ir pra casa?");
            printf("\n>.");
            scanf("%d",&choice);

            if(choice==1)
            {
                system("cls");
                player_id(character);
                printf("\n");
                green();
                text_write(strcpy(text, character->bloco.name));
                reset();
                text_write(strcpy(text,": Sem d�vidas."));
            }
            else if(choice==2)
            {
                system("cls");
                player_id(character);
                printf("\n");
                green();
                text_write(strcpy(text, character->bloco.name));
                reset();
                text_write(strcpy(text,": Por que eu?"));
                magenta();
                printf("\nSer misterioso: ");
                reset();
                text_write(strcpy(text,"Err, porque voc� � especial. Voc� possui uma energia diferente. Um potencial latente."));
            }
            else if(choice==3)
            {
                system("cls");
                player_id(character);
                printf("\n");
                green();
                text_write(strcpy(text, character->bloco.name));
                reset();
                text_write(strcpy(text,": Posso ir pra casa?"));
                magenta();
                printf("\nSer misterioso: ");
                reset();
                text_write(strcpy(text,"Assim que voc� completar essa minha miss�o eu te envio de volta."));
            }
            else
            {
                system("cls");
            }

            Sleep(500);
            magenta();
            printf("\nSer misterioso: ");
            reset();
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
            char enemy_list[tam];
            strcpy(enemy_list,"2220000000");
            enemy_generation(enemies, enemy_list);
            battle(character, enemies);
            level_up(character);

            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nAp�s derrotar os goblins que lhe atacaram, os demais come�am a correr em dire��o a floresta que fica pr�xima � vila."));
            text_write(strcpy(text,"\nAgora o �nico barulho que ainda toma conta do lugar que voc� se encontra � o crepitar das chamas que continuam a incendiar partes da vila."));
            text_write(strcpy(text,"\nAp�s algum tempo um habitante da vila se aproxima de voc�."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            blue();
            printf("\nAlde�o: ");
            reset();
            text_write(strcpy(text,"Obrigado por nos salvar viajante."));
            blue();
            printf("\nAlde�o: ");
            reset();
            text_write(strcpy(text,"Se n�o fosse por voc� n�s estar�amos perdidos."));
            blue();
            printf("\nGide�o, o Chefe da Vila: ");
            reset();
            text_write(strcpy(text,"Meu nome � Gide�o, sou o chefe desta vila."));
            blue();
            printf("\nGide�o, o Chefe da Vila: ");
            reset();
            text_write(strcpy(text,"Essas criaturas j� vem nos causando problemas h� algum tempo."));
            blue();
            printf("\nGide�o, o Chefe da Vila: ");
            reset();
            text_write(strcpy(text,"Por�m, � a primeira vez que eles atacam t�o ferozmente."));
            blue();
            printf("\nGide�o, o Chefe da Vila: ");
            reset();
            text_write(strcpy(text,"Geralmente eles apenas roubam coisas na vila, mas desta vez�"));
            blue();
            printf("\nGide�o, o Chefe da Vila: ");
            reset();
            text_write(strcpy(text,"De qualquer forma, obrigado novamente por nos salvar."));
            blue();
            printf("\nGide�o, o Chefe da Vila: ");
            reset();
            text_write(strcpy(text,"N�o temos muito a oferecer no momento, mas caso precise de um lugar para ficar a taverna n�o sofreu muitos danos, basta falar com o taverneiro e ele lhe dar� um quarto."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            printf("\nEscolha para onde quer ir");
            printf("\n1. Taverna");
            printf("\n>.");
            fflush(stdin);
            scanf("%d",&move_opc);
            while(move_opc!=1)
            {
               system("cls");
                player_id(character);
                printf("\nEscolha para onde quer ir");
                printf("\n1. Taverna");
                printf("\n>.");
                fflush(stdin);
                scanf("%d",&move_opc);
            }

            if(move_opc==1)
            {
                system("cls");
                text_write(strcpy(text,"\nVoc� chega ao lado de fora da taverna, algumas pessoas est�o paradas do lado de fora, algumas com express�es tristes em seus rostos, outras tentando confortar algumas dessas pessoas."));
                text_write(strcpy(text,"\nVoc� entra na taverna, l� dentro n�o est� t�o diferente do lado de fora, mais pessoas com semblantes abatidos preenchem o ambiente, voc� se dirige ao balc�o onde um homem alto e magro com um grande bigode se encontra."));
                text_write(strcpy(text,"\nAo se aproximar mais o homem come�a a falar com voc�."));
                printf("\n<>");
                getch();

                tavern:
                system("cls");
                player_id(character);
                blue();
                printf("\nTaverneiro: ");
                reset();
                text_write(strcpy(text,"Ora ora, n�o � todo dia que vemos novos rostos por aqui."));
                blue();
                printf("\nTaverneiro: ");
                reset();
                text_write(strcpy(text,"Em que posso ajudar?"));

                printf("\n1. Me disseram que posso conseguir um quarto aqui.");
                printf("\n2. O que tem pra beber?");
                printf("\n>.");
                fflush(stdin);
                scanf("%d",&choice);

                if(choice==1)
                {
                    system("cls");
                    player_id(character);
                    green();
                    printf("\n%s: ",character->bloco.name);
                    reset();
                    text_write(strcpy(text,"Me disseram que posso conseguir um quarto aqui."));
                    blue();
                    printf("\nTaverneiro: ");
                    reset();
                    text_write(strcpy(text,"Bom, os quartos n�o est�o nas melhores condi��es, mas temos alguns quartos vagos no segundo andar."));
                    blue();
                    printf("\nTaverneiro: ");
                    reset();
                    text_write(strcpy(text,"Vou pegar uma chave para voc�, s� um momento. "));
                    text_write(strcpy(text,"O taverneiro vai at� algum lugar atr�s do balc�o e retorna com uma chave."));
                    blue();
                    printf("\nTaverneiro: ");
                    reset();
                    text_write(strcpy(text,"Aqui est�, segundo quarto � direita no segundo andar."));

                }
                else if(choice==2)
                {
                    system("cls");
                    player_id(character);
                    green();
                    printf("\n%s: ",character->bloco.name);
                    reset();
                    text_write(strcpy(text,"O que tem pra beber?"));
                    blue();
                    printf("\nTaverneiro: ");
                    reset();
                    text_write(strcpy(text,"Infelizmente n�o muita coisa, o ataque desses malditos goblins acabou destruindo boa parte do meu estoque, vai levar um tempo at� conseguirmos organizar tudo."));
                    printf("\n<>");
                    getch();
                    goto tavern;
                }
                printf("\n<>");
                getch();
            }
            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nVoc� pega a chave e sobe as escadas em dire��o ao segundo andar."));
            text_write(strcpy(text,"\nAo entrar no quarto voc� anda em dire��o a cama, ao sentar nela uma estranha sensa��o de sonol�ncia toma conta de voc�."));
            text_write(strcpy(text,"\nSeus olhos come�am a pesar at� voc� perder a consci�ncia."));
            text_write(strcpy(text,"\nAo abrir os olhos voc� se encontra novamente em um lugar conhecido, um ambiente branco preenchido por uma fraca n�voa � onde voc� se encontra mais uma vez."));
            text_write(strcpy(text,"\nAquela estranha figura aparece novamente em sua frente e come�a a conversar com voc�."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Ol� novamente "));
            green();
            printf("%s ",character->bloco.name);
            reset();
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Voc� fez muito bem em defender a vila, gostei de ver."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Agora que voc� est� aqui, vou te contar mais sobre a situa��o deste mundo."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Este mundo est� sendo corro�do pela sombra, e o Soberano Sombrio � a fonte dessa corrup��o."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Para derrot�-lo, voc� precisa reunir fragmentos de uma antiga rel�quia, a L�mina da Aurora."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Cada fragmento est� escondido em locais perigosos, protegidos por guardi�es poderosos."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Sua primeira pista est� na Floresta do Crep�sculo. L� voc� encontrar� o Guardi�o da Sombra."));

            printf("\n1. Estou pronto para enfrentar o Guardi�o.");
            printf("\n2. Isso parece perigoso, posso me preparar antes?");
            printf("\n>.");
            fflush(stdin);
            scanf("%d",&choice);

            if(choice==1)
            {
                system("cls");
                player_id(character);
                green();
                printf("\n%s: ",character->bloco.name);
                reset();
                text_write(strcpy(text,"Estou pronto para enfrentar o Guardi�o."));

                magenta();
                printf("\nSer misterioso: ");
                reset();
                text_write(strcpy(text,"Claro, mas antes, voc� precisa explorar a vila, comprar equipamentos na loja ou conversar com os habitantes para obter informa��es."));
            }
            else if(choice==2)
            {
                system("cls");
                player_id(character);
                green();
                printf("\n%s: ",character->bloco.name);
                reset();
                text_write(strcpy(text,"Isso parece perigoso, posso me preparar antes?"));

                magenta();
                printf("\nSer misterioso: ");
                reset();
                text_write(strcpy(text,"Claro, voc� pode explorar a vila, comprar equipamentos na loja ou conversar com os habitantes para obter informa��es."));
            }
            else
            {
                system("cls");
                player_id(character);
                green();
                printf("\n%s: ",character->bloco.name);
                reset();
                text_write(strcpy(text,"..."));

                magenta();
                printf("\nSer misterioso: ");
                reset();
                text_write(strcpy(text,"O sil�ncio tamb�m � uma op��o. "));
                Sleep(500);
                text_write(strcpy(text,"Bom, mesmo que n�o queira falar comigo voc� deveria andar pela vila um pouco antes de ir para a floresta."));
            }
            printf("\n<>");
            getch();

            rest(character);

            system("cls");
            text_write(strcpy(text,"\nVoc� decide explorar a vila em busca de informa��es e recursos antes de enfrentar o Guardi�o da Sombra."));
            printf("\n<>");
            getch();

            while(move_opc!=0)
            {
                system("cls");
                player_id(character);
                printf("\nEscolha para onde quer ir");
                printf("\n1. Loja");
                printf("\n2. Habitante da Vila");
                printf("\n0. Sair");
                printf("\n>.");
                fflush(stdin);
                scanf("%d",&move_opc);
                choice=-1;

                if(move_opc==0 && flagMap==1)
                {
                    move_opc=-1;
                }

                if(move_opc==1)
                {
                    text_write(strcpy(text,"\nAo entrar na loja, um velho comerciante lhe cumprimenta."));
                    printf("\n<>");
                    getch();

                    system("cls");
                    player_id(character);
                    blue();
                    printf("\nComerciante: ");
                    reset();
                    text_write(strcpy(text,"Bem-vindo! Se precisar de armas, po��es ou qualquer coisa, estou aqui para ajudar."));
                    printf("\n<>");
                    getch();

                    while(choice!=0)
                    {
                        if(flagShop==1)
                        {
                            system("cls");
                            player_id(character);
                            printf("\n1. Por favor, me mostre os itens � venda.");
                            printf("\n2. Voc� tem informa��es sobre a Floresta do Crep�sculo?");
                            printf("\n0. Sair");
                            printf("\n>.");
                            fflush(stdin);
                            scanf("%d",&choice);

                            if(choice==1)
                            {
                                system("cls");
                                player_id(character);
                                blue();
                                printf("\nComerciante: ");
                                reset();
                                text_write(strcpy(text,"Claro, temos espadas, arcos, po��es de cura e at� mesmo algumas rel�quias antigas. D� uma olhada."));
                                printf("\n<>");
                                getch();
                            }
                            else if(choice==2)
                            {
                                system("cls");
                                player_id(character);
                                blue();
                                printf("\nComerciante: ");
                                reset();
                                text_write(strcpy(text,"Ah, a Floresta do Crep�sculo, um lugar sombrio e cheio de mist�rios. Dizem que o Guardi�o da Sombra protege um dos fragmentos da L�mina l�."));
                                printf("\n<>");
                                getch();
                                flagShop=2;
                            }
                            else if(choice!=0)
                            {
                                blue();
                                printf("\nComerciante: ");
                                reset();
                                text_write(strcpy(text,"E ent�o... Vai querer algo ou vai ficar apenas parado a�?"));
                                Sleep(500);
                            }
                            if(flagInhabitant==2 && flagShop==2)
                            {
                                flagMap=2;
                            }
                        }
                        if(flagShop==2)
                        {
                            printf("\n1. Por favor, me mostre os itens � venda.");
                            printf("\n0. Sair");
                            printf("\n>.");
                            fflush(stdin);
                            scanf("%d",&choice);

                            if(choice==1)
                            {
                                system("cls");
                                player_id(character);
                                blue();
                                printf("\nComerciante: ");
                                reset();
                                text_write(strcpy(text,"Claro, temos espadas, arcos, po��es de cura e at� mesmo algumas rel�quias antigas. D� uma olhada."));
                                printf("\n<>");
                                getch();
                            }
                            else if(choice!=0 && choice!=1)
                            {
                                system("cls");
                                player_id(character);
                                blue();
                                printf("\nComerciante: ");
                                reset();
                                text_write(strcpy(text,"E ent�o... Vai querer algo ou vai ficar apenas parado a�?"));
                                Sleep(500);
                            }
                        }
                    }
                }
                else if(move_opc==2)
                {
                    system("cls");
                    player_id(character);
                    text_write(strcpy(text,"\nVoc� encontra um morador local, um jovem curioso."));
                    printf("\n<>");
                    getch();

                    choice=-1;
                    system("cls");
                    player_id(character);
                    blue();
                    printf("\nMorador: ");
                    reset();
                    text_write(strcpy(text,"Ei, voc� � a pessoa que salvou a vila? Fascinante! Se precisar de alguma informa��o, estou aqui."));
                    printf("\n<>");
                    getch();

                    while(choice!=0)
                    {
                        if(flagInhabitant==1)
                        {
                            system("cls");
                            player_id(character);
                            printf("\n1. Conte-me mais sobre a Floresta do Crep�sculo.");
                            printf("\n2. Voc� conhece o Guardi�o da Sombra?");
                            printf("\n0. Sair");
                            printf("\n>.");
                            fflush(stdin);
                            scanf("%d",&choice);
                        }
                        else if(flagInhabitant==2)
                        {
                            system("cls");
                            player_id(character);
                            printf("\n1. Conversar com o jovem");
                            printf("\n0. Sair");
                            printf("\n>.");
                            fflush(stdin);
                            scanf("%d",&choice);

                            if(choice==1)
                            {
                                blue();
                                printf("\nMorador: ");
                                reset();
                                text_write(strcpy(text,"YOD�O, MATA O KHAZIX PELO MENOS MENOR, MEU DEUS DO C�U YODA, ME AJUDA, ME AJUDAAAA!!"));
                                printf("\n<>");
                                getch();
                            }
                        }
                        if(choice==1 && flagInhabitant==1)
                        {
                            blue();
                            printf("\nMorador: ");
                            reset();
                            text_write(strcpy(text,"A Floresta do Crep�sculo � assustadora, mas dizem que quem sobrevive encontra tesouros incr�veis."));
                            printf("\n<>");
                            getch();
                        }
                        else if(choice==2 && flagInhabitant==1)
                        {
                            blue();
                            printf("\nMorador: ");
                            reset();
                            text_write(strcpy(text,"O Guardi�o da Sombra � um lacaio do Soberano Sombrio, ele se esconde na Floresta do Crep�sculo, vigiando e protegendo os seres sombrios que causam mal a nossa vila"));
                            printf("\n<>");
                            getch();
                            flagInhabitant=2;
                        }
                        else if(choice!=0 && choice!=1 && choice!=2 && flagInhabitant==1)
                        {
                            blue();
                            printf("\nMorador: ");
                            reset();
                            text_write(strcpy(text,"Hmm... N�o t� afim de conversar?"));
                            Sleep(500);
                        }
                        if(flagInhabitant==2 && flagShop==2)
                        {
                            flagMap=2;
                        }
                    }
                }
                else
                {

                }
            }


            system("cls");
            player_id(character);
            printf("\n1. Ir para a Floresta do Crep�sculo");
            printf("\n>.");
            fflush(stdin);
            scanf("%d",&move_opc);

            while(move_opc!=1)
            {
                system("cls");
                player_id(character);
                printf("\nEscolha inv�lida!\n");
                printf("\n1. Ir para a Floresta do Crep�sculo");
                printf("\n>.");
                fflush(stdin);
                scanf("%d",&move_opc);
            }

            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nVoc� parte em dire��o a Floresta do Crep�sculo."));
            text_write(strcpy(text,"\nAo se aproximar da Floresta uma pequena criatura com asas voa at� voc�."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            cyan();
            printf("\nPixie: ");
            reset();
            text_write(strcpy(text,"Ei, voc�! N�o entre nessa floresta, coisas estranhas acontecem l� dentro e apenas a morte lhe aguarda."));

            printf("\n1. Recuar n�o � uma op��o fadinha.");
            printf("\n2. Bem que eu gostaria, mas est�o contando comigo.");
            printf("\n>.");
            fflush(stdin);
            scanf("%d",&choice);

            if(choice==1)
            {
                system("cls");
                player_id(character);
                green();
                printf("\n%s: ",character->bloco.name);
                reset();
                text_write(strcpy(text,"Recuar n�o � uma op��o fadinha."));
                cyan();
                printf("\nPixie: ");
                reset();
                text_write(strcpy(text,"Primeiramente n�o sou uma fada, sou uma pixie. N�o consegue perceber a diferen�a?"));
                cyan();
                printf("\nThelxie: ");
                reset();
                text_write(strcpy(text,"Ali�s, meu nome � Thelxie, e j� que voc� n�o quer ir embora mesmo, ao menos deixe-me te acompanhar, posso ao menos te guiar dentro da floresta para que voc� n�o se perca."));
            }
            else if(choice==2)
            {
                system("cls");
                player_id(character);
                green();
                printf("\n%s: ",character->bloco.name);
                reset();
                text_write(strcpy(text,"Bem que eu gostaria, mas est�o contando comigo."));
                cyan();
                printf("\nPixie: ");
                reset();
                text_write(strcpy(text,"Hunf, voc�s aventureiros s�o todos iguais. Sempre prontos a ir em dire��o � morte certa."));
                cyan();
                printf("\nPixie: ");
                reset();
                text_write(strcpy(text,"Enfim, como voc� vai de qualquer forma, agrade�a pois eu irei contigo, posso ao menos lhe guiar dentro da floresta."));
                cyan();
                printf("\nThelxie: ");
                reset();
                text_write(strcpy(text,"Ali�s, meu nome � Thelxie, prazer em te conhecer."));
            }
            else if(choice<1||choice>2)
            {
                system("cls");
                player_id(character);
                green();
                printf("\n%s: ",character->bloco.name);
                reset();
                text_write(strcpy(text,"..."));
                cyan();
                printf("\nPixie: ");
                reset();
                text_write(strcpy(text,"Voc� realmente vai me ignorar? Est� t�o desesperado assim para encontrar o seu fim?"));
                cyan();
                printf("\nPixie: ");
                reset();
                text_write(strcpy(text,"Pois bem, eu irei presenciar os seus momentos finais. Assim pelo menos sua alma poder� descansar depois de sua morte."));
                cyan();
                printf("\nThelxie: ");
                reset();
                text_write(strcpy(text,"Mesmo que voc� n�o queira saber, meu nome � Thelxie, agrade�a por ter cruzado meu caminho aventureiro."));
            }
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nAo entrar na floresta, as sombras parecem se contorcer, e um sil�ncio perturbador preenche o ar."));
            text_write(strcpy(text,"\nVoc� encontra um orc, uma criatura imponente que exala for�a."));
            strcpy(enemy_list,"5000000000");
            enemy_generation(enemies, enemy_list);
            battle(character, enemies);
            level_up(character);

            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nAp�s uma batalha intensa, o orc � derrotado. No local onde ele estava, um brilho revela o primeiro fragmento da L�mina da Aurora."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            cyan();
            printf("\nThelxie: ");
            reset();
            text_write(strcpy(text,"Uau. Eu n�o esperava que voc� fosse forte o suficiente para derrotar um Orc."));
            cyan();
            printf("\nThelxie: ");
            reset();
            text_write(strcpy(text,"Parab�ns, eu acho! N�o que eu estivesse torcendo por voc�."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nVoc� se sente mais confiante, mas a jornada est� apenas come�ando. O mundo misterioso aguarda novos desafios e descobertas. Voc� decide continuar na Floresta do Crep�sculo."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nAo avan�ar mais na Floresta do Crep�sculo, voc� chega a uma clareira onde a escurid�o parece mais densa. No centro, uma fonte misteriosa emite uma luz fraca."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            cyan();
            printf("\nThelxie: ");
            reset();
            text_write(strcpy(text,"Bom, chegamos na Fonte do Crep�sculo, n�o sei o que voc� queria fazer aqui mas � bom tomar cuidado."));
            cyan();
            printf("\nThelxie: ");
            reset();
            text_write(strcpy(text,"Dizem que ela � alimentada pela sombra que permeia esta floresta. Fique atento, podemos ser atacados a qualquer momento."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nUm grupo de sombras se manifesta, formando criaturas sombrias que avan�am na sua dire��o."));
            printf("\n<>");
            getch();

            strcpy(enemy_list,"4440000000");
            enemy_generation(enemies, enemy_list);
            battle(character, enemies);
            level_up(character);

            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nAp�s uma �rdua batalha, as sombras s�o dispersas. A Fonte do Crep�sculo emite uma luz mais brilhante, parece mais purificada."));
            text_write(strcpy(text,"\nAs sombras hesitam por um momento, como se considerassem sua for�a, mas de repente, voltam a te atacar. A batalha continua."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            cyan();
            printf("\nThelxie: ");
            reset();
            text_write(strcpy(text,"Bom, parece que ainda n�o acabou, boa sorte com isso."));
            printf("\n<>");
            getch();

            strcpy(enemy_list,"4400000000");
            enemy_generation(enemies, enemy_list);
            battle(character, enemies);
            level_up(character);

            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nAp�s a batalha, a Fonte do Crep�sculo emite um brilho ainda mais intenso. Um enigma misterioso aparece na sua frente."));
            printf("\n<>");
            getch();

            Enigma:
            system("cls");
            player_id(character);
            red();
            printf("\nEnigma: ");
            reset();
            text_write(strcpy(text,"A luz que purifica, a sombra que corrompe. Resolva este enigma para avan�ar."));

            printf("\n1. A resposta � a aurora.");
            printf("\n2. A resposta � a meia-noite.");
            printf("\n2. A resposta � o entardecer.");
            printf("\n>.");
            fflush(stdin);
            scanf("%d",&choice);

            if(choice==1)
            {
                system("cls");
                player_id(character);
                text_write(strcpy(text,"\nO enigma ressoa com a sua escolha, e a Fonte do Crep�sculo emite uma luz vibrante. Um caminho se revela."));
            }
            else if(choice==2||choice==3)
            {
                system("cls");
                player_id(character);
                text_write(strcpy(text,"\nO enigma parece n�o se encaixar, e as sombras ao redor come�am a se agitar."));
                printf("\n<>");
                getch();
                goto Enigma;
            }

            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nAo seguir o caminho iluminado, voc� chega a uma clareira mais profunda da floresta. L�, o Guardi�o da Sombra se revela, uma figura sinistra coberta por sombras."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            red();
            printf("\nGuardi�o da Sombra: ");
            reset();
            text_write(strcpy(text,"Voc� ousa interromper nosso dom�nio? Pagar�s por sua ousadia com sua pr�pria sombr- quero dizer� VIDA!"));
            printf("\n<>");
            getch();

            strcpy(enemy_list,"G000000000");
            enemy_generation(enemies, enemy_list);
            battle(character, enemies);
            level_up(character);

            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nAp�s uma batalha �rdua, o Guardi�o da Sombra � derrotado, dissipando-se em sombras escuras. No local onde ele estava, um fragmento brilhante da L�mina da Aurora aparece."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            cyan();
            printf("\nThelxie: ");
            reset();
            text_write(strcpy(text,"Ent�o era isto que voc� estava procurando. Impressionante, voc� n�o � t�o ruim quanto eu imaginei."));
            printf("\n<>");
            getch();

            fragmento1:
            printf("\n1. Pegar o fragmento da L�mina da Aurora.");
            printf("\n>.");
            fflush(stdin);
            scanf("%d",&choice);

            if(choice==1)
            {
                system("cls");
                player_id(character);
                text_write(strcpy(text,"\nAo pegar o fragmento, voc� sente uma energia poderosa fluindo atrav�s dele. Uma voz feminina suave ecoa na sua mente."));
                printf("\n<>");
                getch();

                cyan();
                printf("\nVoz M�stica: ");
                reset();
                text_write(strcpy(text,"Voc� � o escolhido, "));
                green();
                printf("%s. ",character->bloco.name);
                reset();
                text_write(strcpy(text,"Continue sua busca para restaurar a luz e derrotar o Soberano Sombrio."));
                printf("\n<>");
                getch();
            }
            else if(choice!=1)
            {
                goto fragmento1;
            }

            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nEnquanto reflete, a n�voa ao redor se dissipa, revelando uma vis�o clara da Floresta do Crep�sculo. Voc� percebe que a jornada est� apenas come�ando."));
            printf("\n<>");
            getch();
        }
        else if(opc==2)
        {
            system("cls");
            text_write(strcpy(text,"\nMAYBE THERE'LL BE SOMETHING HERE IN THE FUTURE"));
            text_write(strcpy(text,"\nBUT FOR NOW, YOU NEEDN'T WORRY ABOUT IT"));
            Sleep(800);
            printf("\n\n:)");
            text_write(strcpy(text,"\n\nREADING THIS FILLS YOU WITH DETERMINATION"));
            Sleep(500);
            song();
        }
        else if(opc==3)
        {
            system("cls");
            printf("\nJogo Criado para a Mat�ria de Extens�o 2");
            printf("\ndo Curso de An�lise e Desenvolvimento de Sistemas");
            printf("\ndo Instituto Federal de Educa��o, Ci�ncia e Tecnologia do Tri�ngulo Mineiro");
            printf("\n\nProfessor: ");
            green();
            text_write(strcpy(text,"\nJefferson Beethoven Martins"));
            reset();

            printf("\n\nAlunos respons�veis pela cria��o do jogo: ");
            cyan();
            text_write(strcpy(text,"\nBreno Domingos Silva\nDavi de Oliveira Chaves\nGabriel Lucas Silva Seabra\nLuiz Alberto Cury Andal�cio"));
            reset();

            printf("\n\nStakeholders: ");
            red();
            text_write(strcpy(text,"\nDavid Gabriel Beilfuss Jorge\nMurillo Sampaio Oliveira Antonio"));
            reset();

            printf("\n\nSobre o Jogo:");
            text_write(strcpy(text,"\nO jogo criado � um jogo do g�nero Text Adventure."));
            text_write(strcpy(text,"\n\nNa narrativa deste jogo, voc� ser� transportado para outro mundo, o qual possui diversos elementos inspirados e baseados em Jogos RPG de Mesa."));
            text_write(strcpy(text,"\n\nVoc� ser� posto a prova conforme avan�a em sua aventura lutando contra criaturas persversas que desejam destruir este mundo, e cabe a voc�, o nosso her�i/hero�na salvar este mundo da condena��o iminente!"));
            text_write(strcpy(text,"\n"));

            cyan();
            printf("\n\n\n<>");
            reset();
            getch();
        }
    }


    //printf("\n");
    //text_write(strcpy(text,"\n"));
    printf("\n\nAcabou. Tchau!\n\n");
    return 0;
}
