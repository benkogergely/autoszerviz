#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debugmalloc.h"

#include "strukturak.h"
#include "beolvas.h"
#include "menu.h"
#include "szervizfuggvenyek.h"
#include "autofuggvenyek.h"
/*A main függvény tartalmaz két pointert mely a két láncolt lista elsõ elemére mutat.
  Ezen felül a main függvényben történik a további függvények meghívása,
  A main szerkezetén látszik a program szerkezete. Fájlok beolvasása->eltárolás->adatok manipulációja
  ->fájlok felülírása->felszabadítás*/

int main()
{
    // autók.txt és szerviz.txt beolvasása és a pointer visszaadása.
    autok *autotomb=autokbeolvas();
    szerviz *szerviztomb=szervizbeolvas();
    //menü megnyitása
    menu(autotomb,szerviztomb);
    //szöveges dokumentumok felülírása
    automent(autotomb);
    szervizment(szerviztomb);
    //lefoglalt memória felszabadítása
    autofree(autotomb);
    szervizfree(szerviztomb);

    return 0;
}
