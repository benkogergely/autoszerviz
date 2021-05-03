#ifndef BEOLVAS_H_INCLUDED
#define BEOLVAS_H_INCLUDED

#include "strukturak.h"
#include "menu.h"
#include "szervizfuggvenyek.h"
#include "autofuggvenyek.h"

autok* autokbeolvas();
szerviz* szervizbeolvas();
void automent(autok *first);
void autofree(autok *first);
void szervizment(szerviz *first2);
void szervizfree(szerviz *first2);
autok* addauto(autok* prev,char *ttulaj, char *teler,char *trendszam,char *ttipus,int tev,int tho,int tnap);
szerviz* addszerviz(szerviz* prev, char* trendszam, char* tszerviz,int tar,int tev,int tho,int tnap);


#endif // BEOLVAS_H_INCLUDED
