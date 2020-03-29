#include "grille.h"
#include <iostream>
#include "case.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

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

void Grille::RandCase(bool Newt){
  int value;

  /* initialize random seed: */
  srand (time(NULL));

  value = 2;
  srand (time(NULL));
  if (Newt == true){
      int proba;
      /* generate secret number between 1 and 10: */
      proba = rand() % 10 + 1;
      cout<<"La proba est : "<<proba<<endl;
      /* On choisit une proba de 3/10 arbitrairement */
      if (proba < 3){
          value = 4;
      }
  }
  cout<<"La valeur de la nouvelle case est "<<value<<endl;

  int randx, randy;
  do{
      randx = rand() % *Dimension ;
      randy = rand() % *Dimension ;
      cout<<"x est "<<randx<<endl;
      cout<<"y est "<<randy<<endl;

  }
  while (CasesN[randx][randy].IsEmpty() == false);
  Changeval(randx,randy,value);
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

void Grille::Coup(int Dir){
    int i;
    int j;
    int Tab[] = {1,2,3,4};
    int Tab_inv[] = {4,3,2,1};

    if (Dir == 1){
        for(i=0; i<*Dimension; i++){
            for (j=0; j<*Dimension; j++){
                cout<<"On observe la case : "<<Tab[i]-1<<";"<<Tab[j]-1<<" de valeur "<<CasesN[Tab[i]-1][Tab[j]-1].GetValeur()<<endl;
            }
        }
    }

    if (Dir == 2){
        for(i=0; i<*Dimension; i++){
            for (j=0; j<*Dimension; j++){
                cout<<"On observe la case : "<<Tab[i]-1<<";"<<Tab_inv[j]-1<<" de valeur "<<CasesN[Tab[i]-1][Tab_inv[j]-1].GetValeur()<<endl;
            }
        }
    }

    if (Dir == 3){
        for(i=0; i<*Dimension; i++){
            for (j=0; j<*Dimension; j++){
                cout<<"On observe la case : "<<Tab[j]-1<<";"<<Tab[i]-1<<" de valeur "<<CasesN[Tab[j]-1][Tab[i]-1].GetValeur()<<endl;
            }
        }
    }

    if (Dir == 3){
        for(i=0; i<*Dimension; i++){
            for (j=0; j<*Dimension; j++){
                cout<<"On observe la case : "<<Tab[j]-1<<";"<<Tab_inv[i]-1<<" de valeur "<<CasesN[Tab[j]-1][Tab_inv[i]-1].GetValeur()<<endl;
            }
        }
    }
    //RandCase();
}
