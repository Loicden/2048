#include "grille.h"
#include <iostream>
#include "case.h"
using namespace std;


// FONCTIONS DE CREATION DE LA GRILLE

Grille::Grille(int Dim, int Sco, int TempSco)
    {
    Dimension= new int;
    Score=new int;
    Tempscore=new int;
    if(Dim>4){
        *Dimension=Dim;
    }
    else{
        *Dimension=4;
    }

    *Score=Sco;
    *Tempscore=TempSco;

    Case CasesN[Dim][Dim];
    Case CasesAvant[Dim][Dim][5];


    Initialisation();




    }

void Grille::Initialisation(){
    int i;
    int j;
    for(i=0; i<*Dimension; i++){
        for(j=0;j<*Dimension; j++){
            CasesN[i][j]= Case(i,j,0,*Dimension);
        }
    }


}

void Grille::AfficherGrille(){
    int i;
    int j;
    for(i=0;i<*Dimension;i++){
        for(j=0;j<*Dimension;j++){
            Case caseij=CasesN[i][j];
            cout<<caseij.GetValeur()<<" ";
        }
        cout<<endl;
    }

}

void Grille::Changeval(int i, int j, int val){
    CasesN[i][j]= Case(i,j,val,*Dimension);
}
