#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "debugmalloc.h"

void menu(autok *autotomb,szerviz *szerviztomb)
{
    int valasz;
    do
    {
        //Menü megjelenítése és menüpont bekérése
        printf("[1]Adatok rogzitese\n"
               "[2]Adatok torlese\n"
               "[3]Kereses\n"
               "[4]Javitasok rogzitese\n"
               "[5]Szerviztortenet megjelenitese auto alapjan\n"
               "[6]Kozelben lejaro forgalmik megjelenitese\n"
               "[7]Kilepes\n"
               "Menu sorszama: ");
        scanf("%d",&valasz);
        //case kiválasztása a menüpont alapján, további függvényhívás
        switch(valasz)
        {
        case 1:
            autohozzaad(autotomb);
            break;
        case 2:
            autotorol(autotomb);
            break;
        case 3:
            autokeres(autotomb);
            break;
        case 4:
            szervizhozzaad(szerviztomb);
            break;
        case 5:
            szervizkeres(szerviztomb);
            break;
        case 6:
            autoforgalmi(autotomb);
            break;
        case 7:
            printf("Program bezarasa!\n");
            break;
        default:
            break;
        }
    }
    while(valasz!=7);
    return;
}
