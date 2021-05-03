#include <stdio.h>
#include <string.h>
#include "debugmalloc.h"

#include "szervizfuggvenyek.h"
/*Az szervizhozzaad függvény egyesével bekéri a felhasználótól az adatokat.
Lefoglal egy memóraiterületet melyhez hozzácsatolja az adatokat.
Ezt a memóriacímet hozzáfûzi a láncolt listához */
void szervizhozzaad(szerviz* act2)
{
    //Memória lefoglalás
    szerviz *temp=(szerviz*)malloc(sizeof(szerviz));
    //adatok bekérése és memóriához csatolása
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
    //null pointer átállítása
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
/*A függvény bekéri a felhasználótól a listázni kivánt rendszámot.
Indít egy for ciklust amelyben egy feltétel hasonlítja össze a bekért rendszámot a sorhoz tartozó rendszámmal.
Ha a kettõ egyezik, akkor kiírja az egész sort. */
void szervizkeres(szerviz *first2)
{
    //változó létrehozása, rendszám bekérése
    char trendszam[7+1];
    printf("Adj meg egy rendszamot: ");
    scanf("%s",trendszam);
    //for ciklussal végighalad a listán
    szerviz *mozgo2;
    for(mozgo2=first2; mozgo2!=NULL; mozgo2=mozgo2->next)
    {
        //Az aktuális sor rendszámának és a bekért rendszám összehasonlítása, kiíratás
        if(strcmp(mozgo2->rendszam,trendszam)==0)
            printf("%s\t%s\t%d\t%d.%d.%d\n",mozgo2->rendszam,mozgo2->szerviz,mozgo2->ar,mozgo2->szev,mozgo2->szho,mozgo2->sznap);
    }
}
