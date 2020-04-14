#ifndef GRILLE_H
#define GRILLE_H
#include "case.h"
#include <QObject>
#include <string>
#include <iostream>
#include <fstream>

class Grille{
public:
    Grille(int Dimension=4, int Score=0, int TempScore=0);



    void afficherGrille();      //Fonction de débug qui permet d'afficher la grille dans la console
    void initialisation();      //Initialisation d'une grille vide
    void randCase(bool Newturn = true); //Création d'une case au hasard dans la grille
    void changeval(int i, int j, int val);  //Changement de la valeur de la case i,j
    int getval(int i, int j);           //Récupération de la valeur de la case i,j
    int getScore();                     //Récupération du score
    int getTempScore();                 //Récupération du score pour l'affichage QML
    int getDim();                       //Récupération de la dimension de la grille
    void setscore(int score);           //Changement du score
    bool testMove(int i, int j, int newi, int newj);    //vérifie si la case i,j peut bouger vers newi, newj
    bool testFuse(int i, int j, int newi, int newj);    //vérifie si la case i,j peut fusionner avec newi,newj
    void move(int i, int j, int newi, int newj);        //bouge la case i,j
    void reset();                                       //remet les valeurs de la grille à 0
    void fuse(int i, int j, int newi, int newj);        //fusionne deux cases
    bool isemptyG(int i, int j);                        //vérifie si une case est vide
    void coup(int Direction);                           //fonction effectuant un coup en entier
    void test();
    bool canfuse(int i, int j);                         //vérifie si une case est apte à fusionner (attribut fuse)
    void resetfuse();                                   //permet à toutes les cases de fusionner
    void newGame();                                     //lance toutes les fonctions nécessaires à une nouvelle partie
    void back();                                        //revient un coup en arrière
    void tomemory();                                    //stocke la grille dans la mémoire des coups
    bool TestLose();                                    //Teste si la partie est perdue
    bool TestFull();                                    //Teste si la grille est pleine
    void showmemory();                                  //Fonction débug pour afficher la mémoire
    bool canUp();                                       //Vérifient si les coups vers le haut,bas, gauche,droite, sont possibles
    bool canDown();
    bool canLeft();
    bool canRight();
    int GetHighScore();                                 //Récupère le high score (non fonctionnel)
    void WriteHighScore();                              //Ecrit le high score dans un fichier (fonctionnel)



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
    Case CasesN[4][4];      //Grille à proprement parler
    Case CasesAvant[4][4]; //mémoire des coups précédents

};





#endif // GRILLE_H
