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




QGrille::QGrille(Grille Gril, QObject *parent) : QObject(parent)    // Definition de l'objet QGrille hérité de la classe QObjet
{
    getlist();

    length=Gril.getDim()*Gril.getDim();
    GrilleG=Gril;

}

void QGrille::updateDisplay(){
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

void QGrille::coup(int coup){           // Si on appuie sur une direction, on fait appel à la fonction Coup de GrilleG
                                        // D'abord, on vérifie si le coup est possible
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

    // On signal à l'affichage que la grille a changé
    updateDisplay();

}

void QGrille::newGame(){
    GrilleG.newGame();
    // On signal à l'affichage que la grille a changé
    updateDisplay();

}

void QGrille::getlist(){    // On met à jour la liste des valeurs des tuiles
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

void QGrille::afficher(){      // Affiche la liste des valeurs des tuiles (pour les tests)
    int k;
    getlist();
    for(k=0;k<length;k++){
        cout<<cases[k];
    }
    cout<<endl;
}


void QGrille::back(){           // Appelle la fonction back de Grille
    GrilleG.back();
    // On signal à l'affichage que la grille a changé
    updateDisplay();
}

QString QGrille::color(QString string){        // Renvoie une couleur en fonction de la valeur de la tuile (pour la couleur de la case)
    int k=string.toInt();
    if (k==0){
        return colors[0];

    }
    return colors[int(log2(k))];
}

QString QGrille::colortext(QString string){        // Renvoie une couleur en fonction de la valeur de la tuile (pour la couleur du texte de la case)
    int k=string.toInt();
    if (k==0){
        return colorstext[0];

    }
    return colorstext[int(log2(k))];
}

