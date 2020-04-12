#ifndef GRILLE_H
#define GRILLE_H
#include "case.h"
#include <QObject>


class Grille : public QObject{
public:
    Grille(int Dimension=4, int Score=0, int TempScore=0);

    Q_INVOKABLE void AfficherGrille();
    Q_INVOKABLE void Initialisation();
    Q_INVOKABLE void RandCase(bool Newturn = true);
    Q_INVOKABLE void Changeval(int i, int j, int val);
    Q_INVOKABLE int GetScore();
    Q_INVOKABLE int GetTempScore();
    Q_INVOKABLE int GetDim();
    Q_INVOKABLE void Setscore(int score);
    Q_INVOKABLE bool TestMove(int i, int j, int newi, int newj);
    Q_INVOKABLE bool TestFuse(int i, int j, int newi, int newj);
    Q_INVOKABLE void Move(int i, int j, int newi, int newj);
    Q_INVOKABLE void Reset();
    Q_INVOKABLE void Fuse(int i, int j, int newi, int newj);
    Q_INVOKABLE bool IsemptyG(int i, int j);
    Q_INVOKABLE void Coup(int Direction);
    Q_INVOKABLE void Test();
    Q_INVOKABLE bool Canfuse(int i, int j);
    Q_INVOKABLE void Resetfuse();
    Q_INVOKABLE void newGame();
    Q_INVOKABLE void Back();
    Q_INVOKABLE void ShiftMemoryLeft();
    Q_INVOKABLE void ShiftMemoryRight();



private:
    int *Dimension;
    int Score;
    int *Tempscore;
    int valuecheck;
    int randx;
    int randy;
    int Direction;
    int Tab;
    int Tab_inv;
    int Win;
    Case CasesN[4][4];
    Case CasesAvant[4][4][5]; //mémoire des coups précédents





};





#endif // GRILLE_H
