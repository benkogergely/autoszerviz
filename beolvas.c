#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "beolvas.h"
#include "debugmalloc.h"
/*A beolvasó függvények mûködése megegyezik. Elõször megnyitják a szükséges fájlt, majd lefoglalják a memóriaterületet.
Ha a fájl elsõ eleme kerül lefoglalásra akkor hozzáadják a memóriaterülethez. Különben meghívják a hozzáadó függvényt.
A végén visszatérnek az elsõ elemre mutató pointerrel. */
autok* autokbeolvas()
{
    //fájl megnyitása
    autok *first=NULL;
    FILE *fa;
    fa= fopen("autok.txt","rt");
    //memória lefoglalása
    autok* act=(autok*) malloc(sizeof(autok));
    //soronként való beolvasás
    char tomb[200+1];
    while(fgets(tomb,201,fa)!=0)
    {
        char ttulaj[30+1];
        char teler[30+1];
        char trendszam[7+1];
        char ttipus[30+1];
        int tev,tho,tnap;
        //ha az elso elem akkor hozzáadja a területhez
        if(first==NULL)
        {

            sscanf(tomb,"%s\t%s\t%s\t%s\t%d.%d.%d",act->tulaj,act->elerhetoseg,act->rendszam,act->tipus,&act->fev,&act->fho,&act->fnap);
            act->next=NULL;
            first=act;
        }
        // ha a második akkor meghívja az autoadd függvényt
        else
        {
            sscanf(tomb,"%s\t%s\t%s\t%s\t%d.%d.%d",ttulaj,teler,trendszam,ttipus,&tev,&tho,&tnap);
            act=addauto(act,ttulaj,teler,trendszam,ttipus,tev,tho,tnap);
        }

    }
    // fájl bezárása
    fclose(fa);
    return first;
}
szerviz* szervizbeolvas()
{
    // fájl megnyitása
    szerviz *first2=NULL;
    FILE *fsz;
    fsz=fopen("szerviz.txt","rt");
    //memória lefoglalása
    szerviz* act2=(szerviz*) malloc(sizeof(szerviz));
    //soronként való beolvasás
    char tomb2[200+1];
    while(fgets(tomb2,201,fsz)!=0)
    {
        char trendszam[7+1];
        char tszerviz[30+1];
        int tar,tev,tho,tnap;
        //ha az elso elem akkor hozzáadja a területhez
        if(first2==NULL)
        {
            sscanf(tomb2,"%s\t%s\t%d\t%d.%d.%d",act2->rendszam,act2->szerviz,&act2->ar,&act2->szev,&act2->szho,&act2->sznap);
            act2->next=NULL;
            first2=act2;

        }
        // ha a második akkor meghívja az autoadd függvényt
        else
        {
            sscanf(tomb2,"%s\t%s\t%d\t%d.%d.%d",trendszam,tszerviz,&tar,&tev,&tho,&tnap);
            act2=addszerviz(act2,trendszam,tszerviz,tar,tev,tho,tnap);
        }

    }
    // fájl bezárása
    fclose(fsz);
    return first2;
}
/*Az mentésre szolgáló függvények megnyitják a fájlt, majd felülírják a tartalmát a láncolt lista elemeivel. */
void automent(autok *first)
{
    //fájl megnyitása
    FILE *fa;
    fa= fopen("autok.txt","w");
    //for ciklussal végigléptet és listán, megfelelő elemet kiíratja
    for(autok *mozgo3=first; mozgo3!=NULL; mozgo3=mozgo3->next)
    {
        fprintf(fa,"%s\t%s\t%s\t%s\t%d.%d.%d\n",mozgo3->tulaj,mozgo3->elerhetoseg,mozgo3->rendszam, mozgo3->tipus,mozgo3->fev,mozgo3->fho,mozgo3->fnap);
    }
    //fájl bezárása
    fclose(fa);
}
/*Mivel a mentés megtörtént ezért a törlõ függvények egyesével felszabadítják a lefoglalt memóriaterületeket */
void autofree(autok *first)
{
    //pointerek létrehozása és értékadás
    autok *mozgo = first;
    autok *next = NULL;
    //ciklussal végighalad a listán és felszabadítja
    while(mozgo != NULL)
    {
        next = mozgo->next;
        //felszabadítás
        free(mozgo);
        mozgo = next;
    }
}
void szervizment(szerviz *first2)
{
    //fájl megnyitása
    FILE *fsz;
    fsz= fopen("szerviz.txt","w");
    //for ciklussal végigléptet és listán, megfelelő elemet kiíratja
    for(szerviz *mozgo4=first2; mozgo4!=NULL; mozgo4=mozgo4->next)
        fprintf(fsz,"%s\t%s\t%d\t%d.%d.%d\n",mozgo4->rendszam,mozgo4->szerviz,mozgo4->ar,mozgo4->szev,mozgo4->szho,mozgo4->sznap);
    //fájl bezárása
    fclose(fsz);

}
void szervizfree(szerviz *first2)
{
    //pointerek létrehozása és értékadás
    szerviz *mozgo = first2;
    szerviz *next = NULL;
    //ciklussal végighalad a listán és felszabadítja
    while(mozgo != NULL)
    {
        next = mozgo->next;
        //felszabadítás
        free(mozgo);
        mozgo = next;
    }
}
autok* addauto(autok* prev,char *ttulaj, char *teler,char *trendszam,char *ttipus,int tev,int tho,int tnap)
{
    //memória lefoglalása
    autok* new_autok=(autok*) malloc(sizeof(autok));
    //memóriához adás
    strcpy(new_autok->tulaj,ttulaj);
    strcpy(new_autok->elerhetoseg,teler);
    strcpy(new_autok->rendszam,trendszam);
    strcpy(new_autok->tipus,ttipus);
    new_autok->fev=tev;
    new_autok->fho=tho;
    new_autok->fnap=tnap;
    //hozzáfűzés
    new_autok->next=NULL;
    prev->next=new_autok;
    //visszatérés
    return new_autok;
}
szerviz* addszerviz(szerviz* prev, char* trendszam, char* tszerviz,int tar,int tev,int tho,int tnap)
{
    //memória lefoglalása
    szerviz* new_szerviz=(szerviz*) malloc(sizeof(szerviz));
    //memóriához adás
    strcpy(new_szerviz->rendszam,trendszam);
    strcpy(new_szerviz->szerviz,tszerviz);
    new_szerviz->ar=tar;
    new_szerviz->szev=tev;
    new_szerviz->szho=tho;
    new_szerviz->sznap=tnap;
    //hozzáfűzés
    new_szerviz->next=NULL;
    prev->next=new_szerviz;
    //visszatérés
    return new_szerviz;
}
