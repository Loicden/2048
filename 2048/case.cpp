#include "case.h"
#include <iostream>
#include <QObject>
using namespace std;


// FONCTIONS DE CREATION DE LA CASE

int Case::getX(){
    return *x;
}

void Case::setfuse(bool fuse){

    Canfuse=fuse;
}


bool Case::getfuse(){
    return Canfuse;
}

void Case::setX(int abs){
    *x=abs;
}
int Case::getY(){
    return *y;
}
void Case::setY(int ord){
    *y=ord;
}

int Case::getValeur(){
    return *valeur;
}
char Case::getCouleur(){
    return *couleur;
}
int Case::getDimension(){
    return DimensionGrille;
}
int Case::getDirection(){
    return directionmove;
}
void Case::setValeur(int val){
    *valeur=val;
}
void Case::setCouleur(char coul){
    *couleur=coul;
}
void Case::setDimension(int Dim){
    DimensionGrille=Dim;
}
void Case::setDirection(int dir){
    directionmove=dir;
}


Case::Case(int abs, int ord, int val,int Dim, char coul,int direction)
    {
    x = new int;
    y = new int;
    valeur = new int;
    couleur = new char;
    setX(abs);
    setY(ord);
    setValeur(val);
    setDimension(Dim);
    setCouleur(coul);
    setDirection(direction);
    setfuse(true);



    }


bool Case::isEmpty(){
    if(getValeur()==0){
        return true;
    }
    return false;
}

//fonction test pour vérifier que tout ça marche bien
void Case::affichePoint(){
    cout<<"abscisse :"<<getX()<<endl;
    cout<<"ordonnee :"<<getY()<<endl;
    cout<<"couleur :"<<getCouleur()<<endl;
    cout<<"valeur :"<<getValeur()<<endl;
    cout<<"Vide :"<<isEmpty()<<endl;
    cout<<""<<endl;
}



