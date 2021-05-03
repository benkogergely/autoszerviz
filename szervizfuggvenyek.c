#include <stdio.h>
#include <string.h>
#include "debugmalloc.h"

#include "szervizfuggvenyek.h"
/*Az szervizhozzaad f�ggv�ny egyes�vel bek�ri a felhaszn�l�t�l az adatokat.
Lefoglal egy mem�raiter�letet melyhez hozz�csatolja az adatokat.
Ezt a mem�riac�met hozz�f�zi a l�ncolt list�hoz */
void szervizhozzaad(szerviz* act2)
{
    //Mem�ria lefoglal�s
    szerviz *temp=(szerviz*)malloc(sizeof(szerviz));
    //adatok bek�r�se �s mem�ri�hoz csatol�sa
    printf("Rendszam: ");
    scanf("%s",temp->rendszam);
    printf("Javitas leirasa: ");
    scanf("%s",temp->szerviz);
    printf("Ar: ");
    scanf("%d",&temp->ar);
    printf("Ev: ");
    scanf("%d",&temp->szev);
    printf("Honap: ");
    scanf("%d",&temp->szho);
    printf("Nap: ");
    scanf("%d",&temp->sznap);
    //null pointer �t�ll�t�sa
    temp->next=NULL;

    if(act2 == NULL)
    {
        act2=temp;
    }

    autok *mozgo = act2;
    while(mozgo->next != NULL)
        mozgo = mozgo->next;
    mozgo->next = temp;
}
/*A f�ggv�ny bek�ri a felhaszn�l�t�l a list�zni kiv�nt rendsz�mot.
Ind�t egy for ciklust amelyben egy felt�tel hasonl�tja �ssze a bek�rt rendsz�mot a sorhoz tartoz� rendsz�mmal.
Ha a kett� egyezik, akkor ki�rja az eg�sz sort. */
void szervizkeres(szerviz *first2)
{
    //v�ltoz� l�trehoz�sa, rendsz�m bek�r�se
    char trendszam[7+1];
    printf("Adj meg egy rendszamot: ");
    scanf("%s",trendszam);
    //for ciklussal v�gighalad a list�n
    szerviz *mozgo2;
    for(mozgo2=first2; mozgo2!=NULL; mozgo2=mozgo2->next)
    {
        //Az aktu�lis sor rendsz�m�nak �s a bek�rt rendsz�m �sszehasonl�t�sa, ki�rat�s
        if(strcmp(mozgo2->rendszam,trendszam)==0)
            printf("%s\t%s\t%d\t%d.%d.%d\n",mozgo2->rendszam,mozgo2->szerviz,mozgo2->ar,mozgo2->szev,mozgo2->szho,mozgo2->sznap);
    }
}
