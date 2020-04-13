#ifndef GRILLE_H
#define GRILLE_H
#include "case.h"
#include <QObject>
#include <string>

class Grille{
public:
    Grille(int Dimension=4, int Score=0, int TempScore=0);
    void afficherGrille();
    void initialisation();
    void randCase(bool Newturn = true);
    void changeval(int i, int j, int val);
    int getval(int i, int j);
    int getScore();
    int getTempScore();
    int getDim();
    void setscore(int score);
    bool testMove(int i, int j, int newi, int newj);
    bool testFuse(int i, int j, int newi, int newj);
    void move(int i, int j, int newi, int newj);
    void reset();
    void fuse(int i, int j, int newi, int newj);
    bool isemptyG(int i, int j);
    void coup(int Direction);
    void test();
    bool canfuse(int i, int j);
    void resetfuse();
    void newGame();
    void back();
    bool TestLose();
    bool TestFull();
    bool CanUp();
    bool CanDown();
    bool CanLeft();
    bool CanRight();

    Case CasesAvant[4][4]; //mémoire des coups précédents



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
    int Lose;
    Case CasesN[4][4];






};





#endif // GRILLE_H
