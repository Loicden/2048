#include "qgrille.h"
#include <iostream>
#include <QtQml>
#include <sstream>
#include "case.h"
#include "grille.h"
#include "qgrille.h"
#include <string>
#include <math.h>
using namespace std;




QGrille::QGrille(Grille Gril, QObject *parent) : QObject(parent)
{
    getlist();

    length=Gril.getDim()*Gril.getDim();
    GrilleG=Gril;

}

void QGrille::coup(int coup){
    GrilleG.coup(coup);
    getlist();
}

void QGrille::newGame(){
    GrilleG.newGame();
    getlist();
    afficher();
}

void QGrille::getlist(){
    int i;
    int j;
    int D=GrilleG.getDim();
    for(i=0;i<D;i++){
        for(j=0;j<D;j++){
            int val=GrilleG.getval(i,j);
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
    cout<<endl;
}

QString QGrille::color(QString string){
    int k=string.toInt();
    if (k==0){
        return colors[0];

    }
    return colors[int(log2(k))];
}

QString QGrille::colortext(QString string){
    int k=string.toInt();
    if (k==0){
        return colorstext[0];

    }
    return colorstext[int(log2(k))];
}

