#include "case.h"
#include <iostream>
using namespace std;


// FONCTIONS DE CREATION DE LA CASE

int Case::GetX(){
    return *x;
}

void Case::Setfuse(bool fuse){

    Canfuse=fuse;
}


bool Case::Getfuse(){
    return Canfuse;
}

void Case::SetX(int abs){
    *x=abs;
}
int Case::GetY(){
    return *y;
}
void Case::SetY(int ord){
    *y=ord;
}

int Case::GetValeur(){
    return *valeur;
}
char Case::GetCouleur(){
    return *couleur;
}
int Case::GetDimension(){
    return DimensionGrille;
}
int Case::GetDirection(){
    return directionmove;
}
void Case::SetValeur(int val){
    *valeur=val;
}
void Case::SetCouleur(char coul){
    *couleur=coul;
}
void Case::SetDimension(int Dim){
    DimensionGrille=Dim;
}
void Case::SetDirection(int dir){
    directionmove=dir;
}


Case::Case(int abs, int ord, int val,int Dim, char coul,int direction)
    {
    x = new int;
    y = new int;
    valeur = new int;
    couleur = new char;
    SetX(abs);
    SetY(ord);
    SetValeur(val);
    SetDimension(Dim);
    SetCouleur(coul);
    SetDirection(direction);
    Setfuse(true);



    }


bool Case::IsEmpty(){
    if(GetValeur()==0){
        return true;
    }
    return false;
}

//fonction test pour vérifier que tout ça marche bien
void Case::AffichePoint(){
    cout<<"abscisse :"<<GetX()<<endl;
    cout<<"ordonnee :"<<GetY()<<endl;
    cout<<"couleur :"<<GetCouleur()<<endl;
    cout<<"valeur :"<<GetValeur()<<endl;
    cout<<"Vide :"<<IsEmpty()<<endl;
    cout<<""<<endl;
}



