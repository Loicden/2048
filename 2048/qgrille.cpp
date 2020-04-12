#include "qgrille.h"
#include <iostream>
#include <QtQml>
#include <sstream>
#include "case.h"
#include "grille.h"
#include "qgrille.h"
using namespace std;




QGrille::QGrille(Grille Gril, QObject *parent) : QObject(parent)
{
    getlist();

    length=Gril.GetDim()*Gril.GetDim();
    GrilleG=Gril;

}

void QGrille::Coup(int coup){
    GrilleG.Coup(coup);
    getlist();
}

void QGrille::NewGame(){
    GrilleG.newGame();
    GrilleG.AfficherGrille();
}

void QGrille::getlist(){
    int i;
    int j;
    int D=GrilleG.GetDim();
    for(i=0;i<D;i++){
        for(j=0;j<D;j++){
            int val=GrilleG.Getval(i,j);
            cases[D*i+j]=val;
        }
    }
}

void QGrille::afficher(){
    int k;
    getlist();
    for(k=0;k<length;k++){
        cout<<cases[k];
    }
}
