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
    new int;
    Tempscore=new int;
    if(Dim>4){
        *Dimension=Dim;
    }
    else{
        *Dimension=4;
    }

    Setscore(Sco);
    *Tempscore=TempSco;
    Win=0;
    Case CasesN[Dim][Dim];
    Case CasesAvant[Dim][Dim][5];




    Initialisation();




}

bool Grille::Canfuse(int i, int j){
    return CasesN[i][j].Getfuse();
}

void Grille::Resetfuse(){
    int k;
    int j;
    for(k=0;k<*Dimension+1; k++){
        for(j=0;j<*Dimension+1;j++){
            CasesN[k][j].Setfuse(true);
        }
    }
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
      /* On choisit une proba de 3/10 arbitrairement */
      if (proba < 3){
          value = 4;
      }
  }

  int randx, randy;
  do{
      randx = rand() % *Dimension ;
      randy = rand() % *Dimension ;
//      cout<<"x est "<<randx<<endl;
//      cout<<"y est "<<randy<<endl;

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
    return Score;
}

int Grille::GetTempScore(){
    return *Tempscore;
}

int Grille::GetDim(){
    return *Dimension;
}

void Grille::Setscore(int score){
    Score=score;
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
    else if (newi < 0 or newj < 0 or newi > *Dimension-1 or newj > *Dimension-1){
        cout<<"On est hors du canevas"<<endl;
        return false;
    }
    return false;


}

bool Grille::TestFuse(int i, int j, int newi, int newj){
    Case TriedTile;
    Case NextTile;
    TriedTile=CasesN[i][j];
    NextTile=CasesN[newi][newj];
    if(NextTile.Getfuse()==false){
        return false;
    }
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
    CasesN[newi][newj].Setfuse(false);
    if(newval==2048){
        Win=1;
    }
    Setscore(GetScore()+newval);



}


bool Grille::IsemptyG(int i, int j){
    return CasesN[i][j].IsEmpty();
}

void Grille::Coup(int Dir){
    int i;
    int j;
    int Tab[] = {1,2,3,4};
    int Tab_inv[] = {4,3,2,1};
    int x_it;
    int y_it;
    for(i=0; i<*Dimension; i++){
        for (j=0; j<*Dimension; j++){

            if (Dir == 1){x_it = Tab[i]-1; y_it = Tab[j]-1;}
            else if (Dir == 2){x_it = Tab[i]-1; y_it = Tab_inv[j]-1;}
            else if (Dir == 3){x_it = Tab[j]-1; y_it = Tab[i]-1;}
            else{x_it = Tab_inv[j]-1; y_it = Tab[i]-1;}

//            cout<<"On observe la case : "<<x_it<<";"<<y_it<<" de valeur "<<CasesN[x_it][y_it].GetValeur()<<endl;

            int deplacement = 1;
            if (CasesN[x_it][y_it].GetValeur() != 0){
                if (Dir == 1){
                    if (y_it-(deplacement-1) != 0){
//                        cout<<endl;
//                        cout<<"On deplace a gauche"<<endl;
                        while(TestMove(x_it, y_it, x_it, y_it-(deplacement))){
                                deplacement += 1;
//                                cout<<"On deplace de "<<deplacement<<endl;
                            }
                        if (TestFuse(x_it, y_it, x_it, y_it-(deplacement))){
                            Fuse(x_it, y_it, x_it, y_it-(deplacement));
//                            cout<<"On fusionne avec "<<x_it<<";"<<y_it-(deplacement)<<endl;
                        }
                        else if (deplacement != 1){
                            Move(x_it, y_it, x_it, y_it-(deplacement-1));
//                            cout<<"On bouge sur "<<x_it<<";"<<y_it-(deplacement-1)<<endl;
                        }
                    }
                    else{
//                        cout<<"On ne fait rien"<<endl;
                    }
                }
                else if (Dir == 2){
                    if (y_it+(deplacement-1) != 3){
//                        cout<<endl;
//                        cout<<"On deplace a droite"<<endl;
                        while(TestMove(x_it, y_it, x_it, y_it+(deplacement)) and y_it+(deplacement) < *Dimension){
                                deplacement += 1;
//                                cout<<"On deplace de "<<deplacement<<endl;
                            }
                        if (TestFuse(x_it, y_it, x_it, y_it+(deplacement))){
                            Fuse(x_it, y_it, x_it, y_it+(deplacement));
//                            cout<<"On fusionne avec "<<x_it<<";"<<y_it+(deplacement)<<endl;
                        }
                        else if (deplacement != 1){
                            Move(x_it, y_it, x_it, y_it+(deplacement-1));
//                            cout<<"On bouge sur "<<x_it<<";"<<y_it+(deplacement-1)<<endl;
                        }
                    }
                    else{
//                        cout<<"On ne fait rien"<<endl;
                    }
                }
                else if (Dir == 3){
                    if (x_it-(deplacement-1) != 0){
//                        cout<<endl;
//                        cout<<"On deplace en haut"<<endl;
                        while(TestMove(x_it, y_it, x_it-(deplacement), y_it)){
                                deplacement += 1;
//                                cout<<"On deplace de "<<deplacement<<endl;
                            }
                        if (TestFuse(x_it, y_it, x_it-(deplacement), y_it)){
                            Fuse(x_it, y_it, x_it-(deplacement), y_it);
//                            cout<<"On fusionne avec "<<x_it-(deplacement)<<";"<<y_it<<endl;
                        }
                        else if (deplacement != 1){
                            Move(x_it, y_it, x_it-(deplacement-1), y_it);
//                            cout<<"On bouge sur "<<x_it-(deplacement-1)<<";"<<y_it<<endl;
                        }
                    }
                    else{
//                        cout<<"On ne fait rien"<<endl;
                    }
                }
                else if (Dir == 4){
                    if (x_it+(deplacement-1) != 3){
//                        cout<<endl;
//                        cout<<"On deplace en bas"<<endl;
                        while(TestMove(x_it, y_it, x_it+(deplacement), y_it) and x_it+(deplacement) < *Dimension){
                                deplacement += 1;
//                                cout<<"On deplace de "<<deplacement<<endl;
                            }
                        if (TestFuse(x_it, y_it, x_it+(deplacement), y_it)){
                            Fuse(x_it, y_it, x_it+(deplacement), y_it);
//                            cout<<"On fusionne avec "<<x_it+(deplacement)<<";"<<y_it<<endl;
                        }
                        else if (deplacement != 1){
                            Move(x_it, y_it, x_it+(deplacement-1), y_it);
//                            cout<<"On bouge sur "<<x_it+(deplacement-1)<<";"<<y_it<<endl;
                        }
                    }
                    else{
//                        cout<<"On ne fait rien"<<endl;
                    }
                }
            }
        }
    }
    cout<<endl;
    RandCase();
    Resetfuse();
    for(i=0;i<*Dimension;i++){

    }
    if(Win){
        cout<<"vous avez gagné!"<<endl;
    }
}

void Grille::NewGame(){
    Reset();
    Resetfuse();
    Setscore(0);
    RandCase(false);
    RandCase(false);
    cout<<"New Game"<<endl;
}

void Grille::ShiftMemoryLeft(){
    int i;
    int j;
    for (i=0;i<*Dimension-1;i++){
        for(j=0;j<*Dimension-1;j++){
            CasesN[i][j]=CasesAvant[i][j][0];
        }
    }
    int k;
    for(k=5;k>0;k--){
        for(i=0;i<*Dimension+1;i++){
            for(j=0;j<*Dimension+1;j++){
                CasesAvant[i][j][k]=CasesAvant[i][j][k-1];
            }
        }
    }
}

void Grille::ShiftMemoryRight(){
    int i;
    int j;
    for (i=0;i<*Dimension-1;i++){
        for(j=0;j<*Dimension-1;j++){
            CasesAvant[i][j][0]=CasesN[i][j];
        }
    }
    int k;
    for(k=0;k<5;k++){
        for(i=0;i<*Dimension+1;i++){
            for(j=0;j<*Dimension+1;j++){
                CasesAvant[i][j][k]=CasesAvant[i][j][k+1];
            }
        }
    }
}
