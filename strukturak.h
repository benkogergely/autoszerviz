#ifndef STRUKTURAK_H_INCLUDED
#define STRUKTURAK_H_INCLUDED
typedef struct autok
{
    char tulaj[30+1];
    char elerhetoseg[30+1];
    char rendszam[7+1];
    char tipus[30+1];
    int fev,fho,fnap;
    struct autok* next;
} autok;
typedef struct szerviz
{
    char rendszam[7+1];
    char szerviz[30+1];
    int ar,szev,szho,sznap;
    struct szerviz* next;

} szerviz;


#endif // STRUKTURAK_H_INCLUDED
