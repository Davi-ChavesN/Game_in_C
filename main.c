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
            magenta();
            printf("\nVoz misteriosa: ");
            reset();
            text_write(strcpy(text,"Olá! "));
            Sleep(800);
            text_write(strcpy(text,"Oiee!"));
            Sleep(800);
            magenta();
            printf("\nVoz misteriosa: ");
            reset();
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
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Ah, ótimo! Você acordou."));
            Sleep(800);
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Muito prazer, eu sou ####. Qual é o seu nome?"));
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
            text_write(strcpy(text,"Impressionante, né?"));
            printf("\n");
            printf("\t1.Uau! Com certeza impressionante.\n");
            printf("\t2.Não muito.");
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
                text_write(strcpy(text,": Não muito."));
            }
            else
            {
                system("cls");
            }
            choice=0;

            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Enfim, você provavelmente sabe do que se trata isso."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Ir para outro mundo, lutar contra monstros, salvar pessoas, etc."));
            Sleep(800);
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Mas antes de você continuar para a parte divertida vamos terminar com a papelada."));
            Sleep(800);
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Você pode escolher ir para sua aventura como uma das seguintes raças."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Humano, elfo, anão, draconato, tiefling ou autômato."));
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
            text_write(strcpy(text,"\nO ser misterioso pega uma folha de papel do nada e começa a murmurar como se estivesse procurando algo escrito na folha."));
            printf("\n\n");
            Sleep(800);
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Ah, sim!"));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Você precisa escolher uma classe também."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"As classes são as seguintes."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Bárbaro, patrulheiro, paladino, mago, druida e bruxo."));

            class_choice(character);
            system("cls");

            player_id(character);
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Ótimo, ótimo."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Agora você está pronto para sua aventura."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Agora vou te dizer o que você precisa fazer neste mundo."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"De maneira simples, você só tem que derrotar o Soberano Sombrio que tomou conta deste mundo."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Nada muito complicado. Eu mesmo faria isso, mas, infelizmente não posso interferir no mundo físico diretamente."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Agora que você sabe o que precisa ser feito você tem alguma dúvida?"));

            printf("\n");
            printf("\t1.Sem dúvidas.\n");
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
                text_write(strcpy(text,": Sem dúvidas."));
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
                text_write(strcpy(text,"Err, porque você é especial. Você possui uma energia diferente. Um potencial latente."));
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
                text_write(strcpy(text,"Assim que você completar essa minha missão eu te envio de volta."));
            }
            else
            {
                system("cls");
            }

            Sleep(500);
            magenta();
            printf("\nSer misterioso: ");
            reset();
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
            char enemy_list[tam];
            strcpy(enemy_list,"2220000000");
            enemy_generation(enemies, enemy_list);
            battle(character, enemies);
            level_up(character);

            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nApós derrotar os goblins que lhe atacaram, os demais começam a correr em direção a floresta que fica próxima à vila."));
            text_write(strcpy(text,"\nAgora o único barulho que ainda toma conta do lugar que você se encontra é o crepitar das chamas que continuam a incendiar partes da vila."));
            text_write(strcpy(text,"\nApós algum tempo um habitante da vila se aproxima de você."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            blue();
            printf("\nAldeão: ");
            reset();
            text_write(strcpy(text,"Obrigado por nos salvar viajante."));
            blue();
            printf("\nAldeão: ");
            reset();
            text_write(strcpy(text,"Se não fosse por você nós estaríamos perdidos."));
            blue();
            printf("\nGideão, o Chefe da Vila: ");
            reset();
            text_write(strcpy(text,"Meu nome é Gideão, sou o chefe desta vila."));
            blue();
            printf("\nGideão, o Chefe da Vila: ");
            reset();
            text_write(strcpy(text,"Essas criaturas já vem nos causando problemas há algum tempo."));
            blue();
            printf("\nGideão, o Chefe da Vila: ");
            reset();
            text_write(strcpy(text,"Porém, é a primeira vez que eles atacam tão ferozmente."));
            blue();
            printf("\nGideão, o Chefe da Vila: ");
            reset();
            text_write(strcpy(text,"Geralmente eles apenas roubam coisas na vila, mas desta vez…"));
            blue();
            printf("\nGideão, o Chefe da Vila: ");
            reset();
            text_write(strcpy(text,"De qualquer forma, obrigado novamente por nos salvar."));
            blue();
            printf("\nGideão, o Chefe da Vila: ");
            reset();
            text_write(strcpy(text,"Não temos muito a oferecer no momento, mas caso precise de um lugar para ficar a taverna não sofreu muitos danos, basta falar com o taverneiro e ele lhe dará um quarto."));
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
                text_write(strcpy(text,"\nVocê chega ao lado de fora da taverna, algumas pessoas estão paradas do lado de fora, algumas com expressões tristes em seus rostos, outras tentando confortar algumas dessas pessoas."));
                text_write(strcpy(text,"\nVocê entra na taverna, lá dentro não está tão diferente do lado de fora, mais pessoas com semblantes abatidos preenchem o ambiente, você se dirige ao balcão onde um homem alto e magro com um grande bigode se encontra."));
                text_write(strcpy(text,"\nAo se aproximar mais o homem começa a falar com você."));
                printf("\n<>");
                getch();

                tavern:
                system("cls");
                player_id(character);
                blue();
                printf("\nTaverneiro: ");
                reset();
                text_write(strcpy(text,"Ora ora, não é todo dia que vemos novos rostos por aqui."));
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
                    text_write(strcpy(text,"Bom, os quartos não estão nas melhores condições, mas temos alguns quartos vagos no segundo andar."));
                    blue();
                    printf("\nTaverneiro: ");
                    reset();
                    text_write(strcpy(text,"Vou pegar uma chave para você, só um momento. "));
                    text_write(strcpy(text,"O taverneiro vai até algum lugar atrás do balcão e retorna com uma chave."));
                    blue();
                    printf("\nTaverneiro: ");
                    reset();
                    text_write(strcpy(text,"Aqui está, segundo quarto à direita no segundo andar."));

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
                    text_write(strcpy(text,"Infelizmente não muita coisa, o ataque desses malditos goblins acabou destruindo boa parte do meu estoque, vai levar um tempo até conseguirmos organizar tudo."));
                    printf("\n<>");
                    getch();
                    goto tavern;
                }
                printf("\n<>");
                getch();
            }
            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nVocê pega a chave e sobe as escadas em direção ao segundo andar."));
            text_write(strcpy(text,"\nAo entrar no quarto você anda em direção a cama, ao sentar nela uma estranha sensação de sonolência toma conta de você."));
            text_write(strcpy(text,"\nSeus olhos começam a pesar até você perder a consciência."));
            text_write(strcpy(text,"\nAo abrir os olhos você se encontra novamente em um lugar conhecido, um ambiente branco preenchido por uma fraca névoa é onde você se encontra mais uma vez."));
            text_write(strcpy(text,"\nAquela estranha figura aparece novamente em sua frente e começa a conversar com você."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Olá novamente "));
            green();
            printf("%s ",character->bloco.name);
            reset();
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Você fez muito bem em defender a vila, gostei de ver."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Agora que você está aqui, vou te contar mais sobre a situação deste mundo."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Este mundo está sendo corroído pela sombra, e o Soberano Sombrio é a fonte dessa corrupção."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Para derrotá-lo, você precisa reunir fragmentos de uma antiga relíquia, a Lâmina da Aurora."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Cada fragmento está escondido em locais perigosos, protegidos por guardiões poderosos."));
            magenta();
            printf("\nSer misterioso: ");
            reset();
            text_write(strcpy(text,"Sua primeira pista está na Floresta do Crepúsculo. Lá você encontrará o Guardião da Sombra."));

            printf("\n1. Estou pronto para enfrentar o Guardião.");
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
                text_write(strcpy(text,"Estou pronto para enfrentar o Guardião."));

                magenta();
                printf("\nSer misterioso: ");
                reset();
                text_write(strcpy(text,"Claro, mas antes, você precisa explorar a vila, comprar equipamentos na loja ou conversar com os habitantes para obter informações."));
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
                text_write(strcpy(text,"Claro, você pode explorar a vila, comprar equipamentos na loja ou conversar com os habitantes para obter informações."));
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
                text_write(strcpy(text,"O silêncio também é uma opção. "));
                Sleep(500);
                text_write(strcpy(text,"Bom, mesmo que não queira falar comigo você deveria andar pela vila um pouco antes de ir para a floresta."));
            }
            printf("\n<>");
            getch();

            rest(character);

            system("cls");
            text_write(strcpy(text,"\nVocê decide explorar a vila em busca de informações e recursos antes de enfrentar o Guardião da Sombra."));
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
                    text_write(strcpy(text,"Bem-vindo! Se precisar de armas, poções ou qualquer coisa, estou aqui para ajudar."));
                    printf("\n<>");
                    getch();

                    while(choice!=0)
                    {
                        if(flagShop==1)
                        {
                            system("cls");
                            player_id(character);
                            printf("\n1. Por favor, me mostre os itens à venda.");
                            printf("\n2. Você tem informações sobre a Floresta do Crepúsculo?");
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
                                text_write(strcpy(text,"Claro, temos espadas, arcos, poções de cura e até mesmo algumas relíquias antigas. Dê uma olhada."));
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
                                text_write(strcpy(text,"Ah, a Floresta do Crepúsculo, um lugar sombrio e cheio de mistérios. Dizem que o Guardião da Sombra protege um dos fragmentos da Lâmina lá."));
                                printf("\n<>");
                                getch();
                                flagShop=2;
                            }
                            else if(choice!=0)
                            {
                                blue();
                                printf("\nComerciante: ");
                                reset();
                                text_write(strcpy(text,"E então... Vai querer algo ou vai ficar apenas parado aí?"));
                                Sleep(500);
                            }
                            if(flagInhabitant==2 && flagShop==2)
                            {
                                flagMap=2;
                            }
                        }
                        if(flagShop==2)
                        {
                            printf("\n1. Por favor, me mostre os itens à venda.");
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
                                text_write(strcpy(text,"Claro, temos espadas, arcos, poções de cura e até mesmo algumas relíquias antigas. Dê uma olhada."));
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
                                text_write(strcpy(text,"E então... Vai querer algo ou vai ficar apenas parado aí?"));
                                Sleep(500);
                            }
                        }
                    }
                }
                else if(move_opc==2)
                {
                    system("cls");
                    player_id(character);
                    text_write(strcpy(text,"\nVocê encontra um morador local, um jovem curioso."));
                    printf("\n<>");
                    getch();

                    choice=-1;
                    system("cls");
                    player_id(character);
                    blue();
                    printf("\nMorador: ");
                    reset();
                    text_write(strcpy(text,"Ei, você é a pessoa que salvou a vila? Fascinante! Se precisar de alguma informação, estou aqui."));
                    printf("\n<>");
                    getch();

                    while(choice!=0)
                    {
                        if(flagInhabitant==1)
                        {
                            system("cls");
                            player_id(character);
                            printf("\n1. Conte-me mais sobre a Floresta do Crepúsculo.");
                            printf("\n2. Você conhece o Guardião da Sombra?");
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
                                text_write(strcpy(text,"YODÃO, MATA O KHAZIX PELO MENOS MENOR, MEU DEUS DO CÉU YODA, ME AJUDA, ME AJUDAAAA!!"));
                                printf("\n<>");
                                getch();
                            }
                        }
                        if(choice==1 && flagInhabitant==1)
                        {
                            blue();
                            printf("\nMorador: ");
                            reset();
                            text_write(strcpy(text,"A Floresta do Crepúsculo é assustadora, mas dizem que quem sobrevive encontra tesouros incríveis."));
                            printf("\n<>");
                            getch();
                        }
                        else if(choice==2 && flagInhabitant==1)
                        {
                            blue();
                            printf("\nMorador: ");
                            reset();
                            text_write(strcpy(text,"O Guardião da Sombra é um lacaio do Soberano Sombrio, ele se esconde na Floresta do Crepúsculo, vigiando e protegendo os seres sombrios que causam mal a nossa vila"));
                            printf("\n<>");
                            getch();
                            flagInhabitant=2;
                        }
                        else if(choice!=0 && choice!=1 && choice!=2 && flagInhabitant==1)
                        {
                            blue();
                            printf("\nMorador: ");
                            reset();
                            text_write(strcpy(text,"Hmm... Não tá afim de conversar?"));
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
            printf("\n1. Ir para a Floresta do Crepúsculo");
            printf("\n>.");
            fflush(stdin);
            scanf("%d",&move_opc);

            while(move_opc!=1)
            {
                system("cls");
                player_id(character);
                printf("\nEscolha inválida!\n");
                printf("\n1. Ir para a Floresta do Crepúsculo");
                printf("\n>.");
                fflush(stdin);
                scanf("%d",&move_opc);
            }

            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nVocê parte em direção a Floresta do Crepúsculo."));
            text_write(strcpy(text,"\nAo se aproximar da Floresta uma pequena criatura com asas voa até você."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            cyan();
            printf("\nPixie: ");
            reset();
            text_write(strcpy(text,"Ei, você! Não entre nessa floresta, coisas estranhas acontecem lá dentro e apenas a morte lhe aguarda."));

            printf("\n1. Recuar não é uma opção fadinha.");
            printf("\n2. Bem que eu gostaria, mas estão contando comigo.");
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
                text_write(strcpy(text,"Recuar não é uma opção fadinha."));
                cyan();
                printf("\nPixie: ");
                reset();
                text_write(strcpy(text,"Primeiramente não sou uma fada, sou uma pixie. Não consegue perceber a diferença?"));
                cyan();
                printf("\nThelxie: ");
                reset();
                text_write(strcpy(text,"Aliás, meu nome é Thelxie, e já que você não quer ir embora mesmo, ao menos deixe-me te acompanhar, posso ao menos te guiar dentro da floresta para que você não se perca."));
            }
            else if(choice==2)
            {
                system("cls");
                player_id(character);
                green();
                printf("\n%s: ",character->bloco.name);
                reset();
                text_write(strcpy(text,"Bem que eu gostaria, mas estão contando comigo."));
                cyan();
                printf("\nPixie: ");
                reset();
                text_write(strcpy(text,"Hunf, vocês aventureiros são todos iguais. Sempre prontos a ir em direção à morte certa."));
                cyan();
                printf("\nPixie: ");
                reset();
                text_write(strcpy(text,"Enfim, como você vai de qualquer forma, agradeça pois eu irei contigo, posso ao menos lhe guiar dentro da floresta."));
                cyan();
                printf("\nThelxie: ");
                reset();
                text_write(strcpy(text,"Aliás, meu nome é Thelxie, prazer em te conhecer."));
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
                text_write(strcpy(text,"Você realmente vai me ignorar? Está tão desesperado assim para encontrar o seu fim?"));
                cyan();
                printf("\nPixie: ");
                reset();
                text_write(strcpy(text,"Pois bem, eu irei presenciar os seus momentos finais. Assim pelo menos sua alma poderá descansar depois de sua morte."));
                cyan();
                printf("\nThelxie: ");
                reset();
                text_write(strcpy(text,"Mesmo que você não queira saber, meu nome é Thelxie, agradeça por ter cruzado meu caminho aventureiro."));
            }
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nAo entrar na floresta, as sombras parecem se contorcer, e um silêncio perturbador preenche o ar."));
            text_write(strcpy(text,"\nVocê encontra um orc, uma criatura imponente que exala força."));
            strcpy(enemy_list,"5000000000");
            enemy_generation(enemies, enemy_list);
            battle(character, enemies);
            level_up(character);

            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nApós uma batalha intensa, o orc é derrotado. No local onde ele estava, um brilho revela o primeiro fragmento da Lâmina da Aurora."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            cyan();
            printf("\nThelxie: ");
            reset();
            text_write(strcpy(text,"Uau. Eu não esperava que você fosse forte o suficiente para derrotar um Orc."));
            cyan();
            printf("\nThelxie: ");
            reset();
            text_write(strcpy(text,"Parabéns, eu acho! Não que eu estivesse torcendo por você."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nVocê se sente mais confiante, mas a jornada está apenas começando. O mundo misterioso aguarda novos desafios e descobertas. Você decide continuar na Floresta do Crepúsculo."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nAo avançar mais na Floresta do Crepúsculo, você chega a uma clareira onde a escuridão parece mais densa. No centro, uma fonte misteriosa emite uma luz fraca."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            cyan();
            printf("\nThelxie: ");
            reset();
            text_write(strcpy(text,"Bom, chegamos na Fonte do Crepúsculo, não sei o que você queria fazer aqui mas é bom tomar cuidado."));
            cyan();
            printf("\nThelxie: ");
            reset();
            text_write(strcpy(text,"Dizem que ela é alimentada pela sombra que permeia esta floresta. Fique atento, podemos ser atacados a qualquer momento."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nUm grupo de sombras se manifesta, formando criaturas sombrias que avançam na sua direção."));
            printf("\n<>");
            getch();

            strcpy(enemy_list,"4440000000");
            enemy_generation(enemies, enemy_list);
            battle(character, enemies);
            level_up(character);

            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nApós uma árdua batalha, as sombras são dispersas. A Fonte do Crepúsculo emite uma luz mais brilhante, parece mais purificada."));
            text_write(strcpy(text,"\nAs sombras hesitam por um momento, como se considerassem sua força, mas de repente, voltam a te atacar. A batalha continua."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            cyan();
            printf("\nThelxie: ");
            reset();
            text_write(strcpy(text,"Bom, parece que ainda não acabou, boa sorte com isso."));
            printf("\n<>");
            getch();

            strcpy(enemy_list,"4400000000");
            enemy_generation(enemies, enemy_list);
            battle(character, enemies);
            level_up(character);

            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nApós a batalha, a Fonte do Crepúsculo emite um brilho ainda mais intenso. Um enigma misterioso aparece na sua frente."));
            printf("\n<>");
            getch();

            Enigma:
            system("cls");
            player_id(character);
            red();
            printf("\nEnigma: ");
            reset();
            text_write(strcpy(text,"A luz que purifica, a sombra que corrompe. Resolva este enigma para avançar."));

            printf("\n1. A resposta é a aurora.");
            printf("\n2. A resposta é a meia-noite.");
            printf("\n2. A resposta é o entardecer.");
            printf("\n>.");
            fflush(stdin);
            scanf("%d",&choice);

            if(choice==1)
            {
                system("cls");
                player_id(character);
                text_write(strcpy(text,"\nO enigma ressoa com a sua escolha, e a Fonte do Crepúsculo emite uma luz vibrante. Um caminho se revela."));
            }
            else if(choice==2||choice==3)
            {
                system("cls");
                player_id(character);
                text_write(strcpy(text,"\nO enigma parece não se encaixar, e as sombras ao redor começam a se agitar."));
                printf("\n<>");
                getch();
                goto Enigma;
            }

            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nAo seguir o caminho iluminado, você chega a uma clareira mais profunda da floresta. Lá, o Guardião da Sombra se revela, uma figura sinistra coberta por sombras."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            red();
            printf("\nGuardião da Sombra: ");
            reset();
            text_write(strcpy(text,"Você ousa interromper nosso domínio? Pagarás por sua ousadia com sua própria sombr- quero dizer… VIDA!"));
            printf("\n<>");
            getch();

            strcpy(enemy_list,"G000000000");
            enemy_generation(enemies, enemy_list);
            battle(character, enemies);
            level_up(character);

            system("cls");
            player_id(character);
            text_write(strcpy(text,"\nApós uma batalha árdua, o Guardião da Sombra é derrotado, dissipando-se em sombras escuras. No local onde ele estava, um fragmento brilhante da Lâmina da Aurora aparece."));
            printf("\n<>");
            getch();

            system("cls");
            player_id(character);
            cyan();
            printf("\nThelxie: ");
            reset();
            text_write(strcpy(text,"Então era isto que você estava procurando. Impressionante, você não é tão ruim quanto eu imaginei."));
            printf("\n<>");
            getch();

            fragmento1:
            printf("\n1. Pegar o fragmento da Lâmina da Aurora.");
            printf("\n>.");
            fflush(stdin);
            scanf("%d",&choice);

            if(choice==1)
            {
                system("cls");
                player_id(character);
                text_write(strcpy(text,"\nAo pegar o fragmento, você sente uma energia poderosa fluindo através dele. Uma voz feminina suave ecoa na sua mente."));
                printf("\n<>");
                getch();

                cyan();
                printf("\nVoz Mística: ");
                reset();
                text_write(strcpy(text,"Você é o escolhido, "));
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
            text_write(strcpy(text,"\nEnquanto reflete, a névoa ao redor se dissipa, revelando uma visão clara da Floresta do Crepúsculo. Você percebe que a jornada está apenas começando."));
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
            printf("\nJogo Criado para a Matéria de Extensão 2");
            printf("\ndo Curso de Análise e Desenvolvimento de Sistemas");
            printf("\ndo Instituto Federal de Educação, Ciência e Tecnologia do Triângulo Mineiro");
            printf("\n\nProfessor: ");
            green();
            text_write(strcpy(text,"\nJefferson Beethoven Martins"));
            reset();

            printf("\n\nAlunos responsáveis pela criação do jogo: ");
            cyan();
            text_write(strcpy(text,"\nBreno Domingos Silva\nDavi de Oliveira Chaves\nGabriel Lucas Silva Seabra\nLuiz Alberto Cury Andalécio"));
            reset();

            printf("\n\nStakeholders: ");
            red();
            text_write(strcpy(text,"\nDavid Gabriel Beilfuss Jorge\nMurillo Sampaio Oliveira Antonio"));
            reset();

            printf("\n\nSobre o Jogo:");
            text_write(strcpy(text,"\nO jogo criado é um jogo do gênero Text Adventure."));
            text_write(strcpy(text,"\n\nNa narrativa deste jogo, você será transportado para outro mundo, o qual possui diversos elementos inspirados e baseados em Jogos RPG de Mesa."));
            text_write(strcpy(text,"\n\nVocê será posto a prova conforme avança em sua aventura lutando contra criaturas persversas que desejam destruir este mundo, e cabe a você, o nosso herói/heroína salvar este mundo da condenação iminente!"));
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
