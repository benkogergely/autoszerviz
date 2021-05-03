#include <stdio.h>
#include <string.h>
#include "autofuggvenyek.h"
#include "debugmalloc.h"
/*Az autohozzaad függvény egyesével bekéri a felhasználótól az adatokat.
Lefoglal egy memóraiterületet melyhez hozzácsatolja az adatokat.
Ezt a memóriacímet hozzáfûzi a láncolt listához */
void autohozzaad(autok* act)
{
    //Memória lefoglalás
    autok *temp=(autok*)malloc(sizeof(autok));
    //adatok bekérése és memóriához csatolása
    printf("Tulajdonos neve: ");
    scanf("%s",temp->tulaj);
    printf("Elerhetoseg: ");
    scanf("%s",temp->elerhetoseg);
    printf("Rendszam: ");
    scanf("%s",temp->rendszam);
    printf("Tipus: ");
    scanf("%s",temp->tipus);
    printf("Forgalmi ev: ");
    scanf("%d",&(temp->fev));
    printf("Forgalmi ho: ");
    scanf("%d",&(temp->fho));
    printf("Forgalmi nap: ");
    scanf("%d",&(temp->fnap));
    //null pointer átállítása
    temp->next=NULL;

    if(act == NULL)
    {
        act=temp;
    }

    autok *mozgo = act;
    while(mozgo->next != NULL)
        mozgo = mozgo->next;
    mozgo->next = temp;
}

void autotorol(autok *first)
{
    //rendszám bekérés
    char trendszam[7+1];
    printf("Add meg a torlendo rendszamot: ");
    scanf("%s",trendszam);
    //két pointer létrehozása és értékadás
    autok *mozgo=first;
    autok *lemarado=NULL;
    //ciklus elindítása
    while(mozgo!=NULL && strcmp(mozgo->rendszam,trendszam)!=0)
    {
        lemarado=mozgo;
        mozgo=mozgo->next;
    }
    //hibás adat
    if(mozgo==NULL)
    {
        printf("Nincs ilyen adat!");
    }
    else
    {
        //Ha a törölni kívánt elem az első
        if(lemarado==NULL)
        {
            strcpy(mozgo->tulaj,mozgo->next->tulaj);
            strcpy(mozgo->elerhetoseg,mozgo->next->elerhetoseg);
            strcpy(mozgo->rendszam,mozgo->next->rendszam);
            mozgo->fev=mozgo->next->fev;
            mozgo->fho=mozgo->next->fho;
            mozgo->fnap=mozgo->next->fnap;
            lemarado=mozgo;
            mozgo=mozgo->next;
        }
        lemarado->next=mozgo->next;
        free(mozgo);
    }
    return;
}
void autokeres(autok *first)
{
    //Rendszám és/vagy név bekérése
    printf("Kereses nev es/vagy rendszam alapjan.\nHa csak az egyik alapjan szeretnenk keresni akkor a masik helyere X karaktert kell tenni!\n");
    char neve[30+1];
    char rendszama[7+1];
    printf("Tulajdonos neve: ");
    scanf("%s",neve);
    printf("Rendszama: ");
    scanf("%s",rendszama);
    //pointer létrehozása
    autok *mozgo;
    // megfelelő rendszám-név kombináció kiválasztása
    if(strcmp(neve,"X")==0 && strcmp(rendszama,"X")!=0)
    {
        //ciklussal léptetés és keresés
        for(mozgo=first; mozgo!=NULL; mozgo=mozgo->next)
        {
            if(strcmp(mozgo->rendszam,rendszama)==0)
                printf("%s\t%s\t%s\t%s\t%d.%d.%d\n",mozgo->tulaj,mozgo->elerhetoseg,mozgo->rendszam, mozgo->tipus,mozgo->fev,mozgo->fho,mozgo->fnap);
        }
    }
    else if(strcmp(neve,"X")!=0 && strcmp(rendszama,"X")==0)
    {
        for(mozgo=first; mozgo!=NULL; mozgo=mozgo->next)
        {
            if(strcmp(mozgo->tulaj,neve)==0)
                printf("%s\t%s\t%s\t%s\t%d.%d.%d\n",mozgo->tulaj,mozgo->elerhetoseg,mozgo->rendszam, mozgo->tipus,mozgo->fev,mozgo->fho,mozgo->fnap);
        }
    }
    else
    {
        for(mozgo=first; mozgo!=NULL; mozgo=mozgo->next)
        {
            if(strcmp(mozgo->tulaj,neve)==0 && strcmp(mozgo->rendszam,rendszama)==0)
                printf("%s\t%s\t%s\t%s\t%d.%d.%d\n",mozgo->tulaj,mozgo->elerhetoseg,mozgo->rendszam, mozgo->tipus,mozgo->fev,mozgo->fho,mozgo->fnap);
        }
    }
}
void autoforgalmi(autok *first)
{
    //aktuális dátum bekérése
    int ev,ho,nap;
    printf("Kerem a mai datumot!\n");
    printf("Ev: ");
    scanf("%d",&ev);
    printf("Honap: ");
    scanf("%d",&ho);
    printf("Nap: ");
    scanf("%d",&nap);
    //pointer létrehozása
    autok *mozgo;
    //for ciklussal végigléptet az összes listaelemen. Minden elemnél elvégzi a számítást
    for(mozgo=first; mozgo!=NULL; mozgo=mozgo->next)
    {
        //változók létrehozása
        int evakt=mozgo->fev;
        int hoakt=mozgo->fho;
        int napakt=mozgo->fnap;

        int evdif, hodif, napdif;
        if(napakt < nap)
        {
            if (hoakt == 3)
            {
                //szökőév
                if ((evakt % 4 == 0 && evakt % 100 != 0) || (evakt % 400 == 0))
                {
                    napakt += 29;
                }
                else
                {
                    napakt += 28;
                }
            }
            //honap napjainak meghatározása
            else if (hoakt == 5 || hoakt == 7 || hoakt == 10 || hoakt == 12)
            {
                napakt += 30;
            }
            else
            {
                napakt += 31;
            }
            hoakt--;
        }
        if (hoakt < ho)
        {
            hoakt += 12;
            evakt -= 1;
        }
        //különbségek kiszámítása
        napdif = napakt - nap;
        hodif = hoakt - ho;
        evdif = evakt - ev;
        //lejárt/15 napon belül lejár kiíratása
        if(napdif<0 || hodif<0 || evdif<0)
        {
            printf("%s\t%s\t%s\tLEJART\n",mozgo->rendszam,mozgo->tipus,mozgo->tulaj);
        }
        else if(napdif<=15 && evdif==0 && hodif==0)
        {
            printf("%s\t%s\t%s\t%d-NAP MULVA LEJAR\n",mozgo->rendszam,mozgo->tipus,mozgo->tulaj,napdif);
        }
    }
    return;
}
