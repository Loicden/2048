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

    int getX(); //Permet d'attraper les attributs
    int getY();
    int getValeur();
    char getCouleur();
    int getDimension();
    int getDirection();

    void setX(int abs); //Permet de changer les attributs
    void setY(int ord);
    void setValeur(int val);
    void setCouleur(char coul);
    void setDimension(int Dim);
    void setDirection(int dir);
    bool getfuse();
    void setfuse(bool fuse);

    bool isEmpty(); //teste si une case est vide (de valeur 0)




    void affichePoint(); //Fonction test pour le debug qui affiche les coordonnées et la valeur

private:

    int *x;
    int *y;
    int *valeur;

    int directionmove;      //direction dans laquelle la case doit bouger
    int DimensionGrille; //Dimension de la grille à laquelle est rattachée la case
    char *couleur;
    bool Canfuse;      //Attribut indiquant si une case peut fusionner



};

#endif // CASE_H
