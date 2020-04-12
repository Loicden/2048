#ifndef CASE_H
#define CASE_H
//#include "Grille.h"
#include <QObject>
#include <QWidget>

class Case
{
public:
    Case(int x=1, int y=1, int valeur=0, int DimensionGrille=4, char couleur='w',int directionmove=0);

int GetX();
int GetY();
int GetValeur();
char GetCouleur();
int GetDimension();
int GetDirection();

void SetX(int abs);
void SetY(int ord);
void SetValeur(int val);
void SetCouleur(char coul);
void SetDimension(int Dim);
void SetDirection(int dir);
bool Getfuse();
void Setfuse(bool fuse);

bool IsEmpty();
    void AffichePoint();

private:

    int *x;
    int *y;
    int *valeur;

    int directionmove;
    int DimensionGrille;
    char *couleur;
    bool Canfuse;



};

#endif // CASE_H
