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


//text-colors
void reset()
{
    printf("\033[0m");
}

void black()
{
    printf("\033[0;30m");
}

void red()
{
    printf("\033[0;31m");
}

void green()
{
    printf("\033[0;32m");
}

void yellow()
{
    printf("\033[0;33m");
}

void blue()
{
    printf("\033[0;34m");
}

void magenta()
{
    printf("\033[0;35m");
}

void cyan()
{
    printf("\033[0;36m");
}

void white()
{
    printf("\033[0;37m");
}


//background-colors
void bkg_black()
{
    printf("\033[0;40m");
}

void bkg_red()
{
    printf("\033[0;41m");
}

void bkg_green()
{
    printf("\033[0;42m");
}

void bkg_yellow()
{
    printf("\033[0;43m");
}

void bkg_blue()
{
    printf("\033[0;44m");
}

void bkg_magenta()
{
    printf("\033[0;45m");
}

void bkg_cyan()
{
    printf("\033[0;46m");
}

void bkg_white()
{
    printf("\033[0;47m");
}

