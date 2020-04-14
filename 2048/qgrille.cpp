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
    if(coup==1 and GrilleG.canLeft()){
        GrilleG.coup(coup);
    }
    if(coup==2 and GrilleG.canRight()){
        GrilleG.coup(coup);
    }
    if(coup==3 and GrilleG.canUp()){
        GrilleG.coup(coup);
    }
    if(coup==4 and GrilleG.canDown()){
        GrilleG.coup(coup);
    }
    getlist();
    case0changed();
    case1changed();
    case2changed();
    case3changed();
    case4changed();
    case5changed();
    case6changed();
    case7changed();
    case8changed();
    case9changed();
    case10changed();
    case11changed();
    case12changed();
    case13changed();
    case14changed();
    case15changed();
    Scorechanged();
    HighScoreChanged();

}

void QGrille::newGame(){
    GrilleG.newGame();
    getlist();
    case0changed();
    case1changed();
    case2changed();
    case3changed();
    case4changed();
    case5changed();
    case6changed();
    case7changed();
    case8changed();
    case9changed();
    case10changed();
    case11changed();
    case12changed();
    case13changed();
    case14changed();
    case15changed();
    Scorechanged();
    HighScoreChanged();

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


void QGrille::back(){
    GrilleG.back();
    getlist();
    case0changed();
    case1changed();
    case2changed();
    case3changed();
    case4changed();
    case5changed();
    case6changed();
    case7changed();
    case8changed();
    case9changed();
    case10changed();
    case11changed();
    case12changed();
    case13changed();
    case14changed();
    case15changed();
    Scorechanged();
    HighScoreChanged();
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

