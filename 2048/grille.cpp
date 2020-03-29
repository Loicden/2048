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
            Case Newcase;
            Newcase=Case(i,j,0);
            CasesN[i][j]= Newcase;
        }
    }


}

void Grille::AfficherGrille(){
    int i;
    int j;
    for(i=0;i<*Dimension;i++){
        for(j=0;j<*Dimension;j++){
            cout<<CasesN[i][j].GetValeur()<<" ";
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
    CasesN[i][j]=Case(i,j,val);
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





bool Grille::TestMove(int i, int j, int newi, int newj){
    Case TriedTile;
    TriedTile=CasesN[i][j];
    if (TriedTile.GetValeur()==0){
        return false;
    }
    if(i!=newi && j!=newj){
        return false;

    }
    else if (CasesN[newi][newj].GetValeur()==0){
        return true;
    }
    return false;


}

bool Grille::TestFuse(int i, int j, int newi, int newj){
    Case TriedTile;
    Case NextTile;
    TriedTile=CasesN[i][j];
    NextTile=CasesN[newi][newj];
    if (TriedTile.GetValeur()==0){
        return false;
    }
    if(i!=newi && j!=newj){
        return false;}
    else if (TriedTile.GetValeur()==NextTile.GetValeur()){
        return true;
    }
    return false;

}
void Grille::Move(int i, int j, int newi, int newj){

        int newval=CasesN[i][j].GetValeur();
        CasesN[i][j].SetValeur(0);
        if (newi>*Dimension-1){
            CasesN[*Dimension-1][newj].SetValeur(newval);

        }
        else if (newi<0){
            CasesN[0][newj].SetValeur(newval);

        }
        else if(newj>*Dimension-1){
            CasesN[newi][*Dimension-1].SetValeur(newval);

        }
        else if (newj<0){
            CasesN[newi][0].SetValeur(newval);

        }
        else {
            CasesN[newi][newj].SetValeur(newval);
        }
}

void Grille::Fuse(int i, int j, int newi, int newj){
    int newval=2*CasesN[i][j].GetValeur();
    CasesN[newi][newj].SetValeur(newval);
    CasesN[i][j].SetValeur(0);


}


bool Grille::IsemptyG(int i, int j){
    return CasesN[i][j].IsEmpty();
}
