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

    Setscore(Sco);
    *Tempscore=TempSco;

    Case CasesN[Dim][Dim];
    Case CasesAvant[Dim][Dim][5];


    Initialisation();




    }

void Grille::Initialisation(){
    int i;
    int j;
    for(i=0; i<*Dimension+1; i++){
        for(j=0;j<*Dimension+1; j++){
            Case NewCase=Case(i,j,0,*Dimension);
            CasesN[i][j]= NewCase;
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
cout<<endl;
}

void Grille::Reset(){
    int i;
    int j;
    for(i=0; i<*Dimension+1; i++){
        for(j=0;j<*Dimension+1; j++){
            CasesN[i][j].SetValeur(0);
        }
    }
}

void Grille::Changeval(int i, int j, int val){
    CasesN[i][j].SetValeur(val);
}


int Grille::GetScore(){
    return *Score;
}

int Grille::GetTempScore(){
    return *Tempscore;
}

int Grille::GetDim(){
    return *Dimension;
}

void Grille::Setscore(int score){
    *Score=score;
}

bool Grille::TestMove(int i, int j, int direction){
    Case TriedTile;
    Case NextTile;
    TriedTile=CasesN[i][j];
    if(direction==1){
        if (i==0){
                return false;
        }
        else {
                    NextTile=CasesN[i-1][j];
                    if(NextTile.GetValeur()!=0){
                        return false;
                    }
                    return true;
                }
    }

    if(direction==2){
        if (j==*Dimension){
            return false;
        }
        else {
            NextTile=CasesN[i][j+1];
            if(NextTile.GetValeur()!=0){
                return false;
            }
            return true;
        }
    }

    if(direction==3){
        if (i==*Dimension){
            return false;
        }
        else {
            NextTile=CasesN[i+1][j];
            if(NextTile.GetValeur()!=0){
                return false;
            }
            return true;
        }
    }
    if(direction==4){
        if (j==0){
            return false;
        }
        else {
            NextTile=CasesN[i][j-1];
            if(NextTile.GetValeur()!=0){
                return false;
            }
            return true;
        }
    }


}

bool Grille::TestFuse(int i, int j, int direction){
    Case TriedTile;
    Case NextTile;
    TriedTile=CasesN[i][j];
    if (direction==1){
        NextTile=CasesN[i-1][j];
        if(NextTile.GetValeur()==TriedTile.GetValeur()){
            return true;
        }
        return false;
    }
    if (direction==2){
        NextTile=CasesN[i][j+1];
        if(NextTile.GetValeur()==TriedTile.GetValeur()){
            return true;
        }
        return false;
    }
    if (direction==3){
        NextTile=CasesN[i+1][j];
        if(NextTile.GetValeur()==TriedTile.GetValeur()){
            return true;
        }
        return false;
    }
    if (direction==4){
        NextTile=CasesN[i][j-1];
        if(NextTile.GetValeur()==TriedTile.GetValeur()){
            return true;
        }
        return false;
    }

return false;
}

void Grille::Move(int i, int j, int direction){
    int newval=CasesN[i][j].GetValeur();
    CasesN[i][j].SetValeur(0);
    if(direction==1){
        CasesN[i-1][j].SetValeur(newval);
    }
    else if(direction==2){
        CasesN[i][j+1].SetValeur(newval);
    }
    else if(direction==3){
        CasesN[i+1][j].SetValeur(newval);
    }
    else if(direction==4){
        CasesN[i][j-1].SetValeur(newval);
    }
}
