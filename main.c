#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debugmalloc.h"

#include "strukturak.h"
#include "beolvas.h"
#include "menu.h"
#include "szervizfuggvenyek.h"
#include "autofuggvenyek.h"
/*A main f�ggv�ny tartalmaz k�t pointert mely a k�t l�ncolt lista els� elem�re mutat.
  Ezen fel�l a main f�ggv�nyben t�rt�nik a tov�bbi f�ggv�nyek megh�v�sa,
  A main szerkezet�n l�tszik a program szerkezete. F�jlok beolvas�sa->elt�rol�s->adatok manipul�ci�ja
  ->f�jlok fel�l�r�sa->felszabad�t�s*/

int main()
{
    // aut�k.txt �s szerviz.txt beolvas�sa �s a pointer visszaad�sa.
    autok *autotomb=autokbeolvas();
    szerviz *szerviztomb=szervizbeolvas();
    //men� megnyit�sa
    menu(autotomb,szerviztomb);
    //sz�veges dokumentumok fel�l�r�sa
    automent(autotomb);
    szervizment(szerviztomb);
    //lefoglalt mem�ria felszabad�t�sa
    autofree(autotomb);
    szervizfree(szerviztomb);

    return 0;
}
