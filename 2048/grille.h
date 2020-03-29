#ifndef GRILLE_H
#define GRILLE_H
#include "case.h"


class Grille
{
public:
    Grille(int Dimension=4,int Score=0, int Tempscore=0);
    void AfficherGrille();
    void Initialisation();
    void RandCase(bool Newturn = true);
    void Changeval(int i, int j, int val);
    int GetScore();
    int GetTempScore();
    int GetDim();
    void Setscore(int score);
    bool TestMove(int i, int j, int newi, int newj);
    bool TestFuse(int i, int j, int newi, int newj);
    void Move(int i, int j, int newi, int newj);
    void Reset();
    void Fuse(int i, int j, int newi, int newj);
    bool IsemptyG(int i, int j);
    void Coup(int Direction);
    void Test();



private:
    int *Dimension;
    int *Score;
    int *Tempscore;
    int valuecheck;
    int randx;
    int randy;
    int Direction;
    int Tab;
    int Tab_inv;
    Case CasesN[4][4];
    Case CasesAvant[4][4][5]; //mémoire des coups précédents





};





#endif // GRILLE_H
