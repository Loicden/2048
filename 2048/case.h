#ifndef CASE_H
#define CASE_H
//#include "Grille.h"
#include <QObject>
#include <QWidget>
#include <string>

class Case
{
public:
    Case(int x=1, int y=1, int valeur=0, int DimensionGrille=4, char couleur='w',int directionmove=0);

    int getX();
    int getY();
    int getValeur();
    char getCouleur();
    int getDimension();
    int getDirection();

    void setX(int abs);
    void setY(int ord);
    void setValeur(int val);
    void setCouleur(char coul);
    void setDimension(int Dim);
    void setDirection(int dir);
    bool getfuse();
    void setfuse(bool fuse);

    bool isEmpty();




    void affichePoint();

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
