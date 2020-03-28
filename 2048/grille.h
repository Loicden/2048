#ifndef GRILLE_H
#define GRILLE_H
#include "case.h"


class Grille
{
public:
    Grille(int Dimension=4,int Score=0, int Tempscore=0);
    void AfficherGrille();
    void Initialisation();
    void Changeval(int i, int j, int val);



private:

    int *Dimension;
    int *Score;
    int *Tempscore;
    Case CasesN[3][3];
    Case CasesAvant[3][3][5]; //mémoire des coups précédents

};

#endif // GRILLE_H