#include "grille.h"
#include <iostream>
#include "case.h"
#include "grille.h"
#include <QObject>

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

// FONCTIONS DE CREATION DE LA GRILLE

Grille::Grille(int Dim, int Sco, int TempSco)
{
    Dimension= new int;
    Tempscore=new int;
    if(Dim>4){
        *Dimension=Dim;
    }
    else{
        *Dimension=4;
    }

    setscore(Sco);
    *Tempscore=TempSco;
    Case CasesN[Dim][Dim];
    Case CasesAvant[Dim][Dim];
    initialisation();
}

bool Grille::canfuse(int i, int j){
    return CasesN[i][j].getfuse();
}

void Grille::resetfuse(){
    int k;
    int j;
    for(k=0;k<*Dimension+1; k++){
        for(j=0;j<*Dimension+1;j++){
            CasesN[k][j].setfuse(true);
        }
    }
}

void Grille::initialisation(){
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

void Grille::randCase(bool Newt){
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

  while (CasesN[randx][randy].isEmpty() == false);
  changeval(randx,randy,value);
}

void Grille::tomemory(){
    int i;
    int j;
    for(i=0;i<getDim();i++){
        for(j=0;j<getDim();j++){
            CasesAvant[i][j].setValeur(CasesN[i][j].getValeur());
        }
    }
    *Tempscore=getScore();

}

void Grille::back(){
    int i;
    int j;
    for(i=0;i<getDim();i++){
        for(j=0;j<getDim();j++){
            CasesN[i][j].setValeur(CasesAvant[i][j].getValeur());
        }
    }
    setscore(*Tempscore);
}

void Grille::showmemory(){
    int i;
    int j;
    for(i=0;i<*Dimension;i++){
        for(j=0;j<*Dimension;j++){
            cout<<CasesAvant[i][j].getValeur()<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Grille::afficherGrille(){
    int i;
    int j;
    for(i=0;i<*Dimension;i++){
        for(j=0;j<*Dimension;j++){
            cout<<CasesN[i][j].getValeur()<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Grille::reset(){
    int i;
    int j;
    for(i=0; i<*Dimension+1; i++){
        for(j=0;j<*Dimension+1; j++){
            CasesN[i][j].setValeur(0);
        }
    }
}

void Grille::changeval(int i, int j, int val){
    CasesN[i][j]=Case(i,j,val);
}


int Grille::getScore(){
    return Score;
}

int Grille::getTempScore(){
    return *Tempscore;
}

int Grille::getDim(){
    return *Dimension;
}

bool Grille::TestFull(){
    int i;
    int j;
    for (i=0;i<getDim()-1;i++){
        for (j=0;j<getDim()-1;j++){

           if(isemptyG(i,j)){
               return false;
           }
        }
    }
    return true;
}

bool Grille::TestLose(){
        int i;
        int j;
        for (i=0;i<getDim()-1;i++){
            for (j=0;j<getDim()-1;j++){
                if(getval(i,j)==0){
                    return false;
                }
                if(testFuse(i,j,i+1,j) or testFuse(i,j,i-1,j) or testFuse(i,j,i,j+1) or testFuse(i,j,i,j-1)){
                    return false;
                }
                if(testMove(i,j,i+1,j) or testMove(i,j,i-1,j) or testMove(i,j,i,j+1) or testMove(i,j,i,j-1)){
                    return false;
                }
            }
        }
        return false;
    }



void Grille::setscore(int score){
    Score=score;
}

bool Grille::canUp(){
    int i;
    int j;
    for(i=0;i<getDim();i++){
        for(j=0;j<getDim();j++){
            if(testFuse(i,j,i-1,j) and getval(i,j)!=0){
                return true;
            }
            if(testMove(i,j,i-1,j)){
                return true;
            }
        }
    }
    return false;
}

bool Grille::canDown(){
    int i;
    int j;
    for(i=0;i<getDim();i++){
        for(j=0;j<getDim();j++){
            if(testFuse(i,j,i+1,j) and getval(i,j)!=0){
                return true;
            }
            if(testMove(i,j,i+1,j)){
                return true;
            }
        }
    }
    return false;
}

bool Grille::canLeft(){
    int i;
    int j;
    for(i=0;i<getDim();i++){
        for(j=0;j<getDim();j++){
            if(testFuse(i,j,i,j-1) and getval(i,j)!=0){
                return true;
            }
            if(testMove(i,j,i,j-1)){
                return true;
            }
        }
    }
    return false;
}

bool Grille::canRight(){
    int i;
    int j;
    for(i=0;i<getDim();i++){
        for(j=0;j<getDim();j++){
            if(testFuse(i,j,i,j+1) and getval(i,j)!=0){
                return true;
            }
            if(testMove(i,j,i,j+1)){
                return true;
            }
        }
    }
    return false;
}


bool Grille::testMove(int i, int j, int newi, int newj){
    Case TriedTile;
    TriedTile=CasesN[i][j];
    if (TriedTile.getValeur()==0){
        return false;
    }
    else if (newi < 0 or newj < 0 or newi > getDim()-1 or newj > getDim()-1){
        return false;
    }
    else if(i!=newi && j!=newj){
        return false;
    }



    else if (CasesN[newi][newj].getValeur()==0){
        return true;
    }

    return false;


}

bool Grille::testFuse(int i, int j, int newi, int newj){
    Case TriedTile;
    Case NextTile;
    TriedTile=CasesN[i][j];
    NextTile=CasesN[newi][newj];
    if(newi<0 or newi>getDim()-1 or newj<0 or newj>getDim()-1)
        return false;
    if(NextTile.getfuse()==false){
        return false;
    }
    if (TriedTile.getValeur()==0){
        return false;
    }
    if(i!=newi && j!=newj){
        return false;}
    else if (TriedTile.getValeur()==NextTile.getValeur()){
        return true;
    }
    return false;

}

void Grille::move(int i, int j, int newi, int newj){

        int newval=CasesN[i][j].getValeur();
        CasesN[i][j].setValeur(0);
        if (newi>*Dimension-1){
            CasesN[*Dimension-1][newj].setValeur(newval);

        }
        else if (newi<0){
            CasesN[0][newj].setValeur(newval);

        }
        else if(newj>*Dimension-1){
            CasesN[newi][*Dimension-1].setValeur(newval);

        }
        else if (newj<0){
            CasesN[newi][0].setValeur(newval);

        }
        else {
            CasesN[newi][newj].setValeur(newval);
        }
}

void Grille::fuse(int i, int j, int newi, int newj){
    int newval=2*CasesN[i][j].getValeur();
    CasesN[newi][newj].setValeur(newval);
    CasesN[i][j].setValeur(0);
    CasesN[newi][newj].setfuse(false);
    if(newval==2048){
        Win=1;
    }
    setscore(getScore()+newval);



}


bool Grille::isemptyG(int i, int j){
    return CasesN[i][j].isEmpty();
}

void Grille::coup(int Dir){
    tomemory();
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

//            cout<<"On observe la case : "<<x_it<<";"<<y_it<<" de valeur "<<CasesN[x_it][y_it].getValeur()<<endl;

            int deplacement = 1;
            if (CasesN[x_it][y_it].getValeur() != 0){
                if (Dir == 1){
                    if (y_it-(deplacement-1) != 0){
//                        cout<<endl;
//                        cout<<"On deplace a gauche"<<endl;
                        while(testMove(x_it, y_it, x_it, y_it-(deplacement))){
                                deplacement += 1;
//                                cout<<"On deplace de "<<deplacement<<endl;
                            }
                        if (testFuse(x_it, y_it, x_it, y_it-(deplacement))){
                            fuse(x_it, y_it, x_it, y_it-(deplacement));
//                            cout<<"On fusionne avec "<<x_it<<";"<<y_it-(deplacement)<<endl;
                        }
                        else if (deplacement != 1){
                            move(x_it, y_it, x_it, y_it-(deplacement-1));
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
                        while(testMove(x_it, y_it, x_it, y_it+(deplacement)) and y_it+(deplacement) < *Dimension){
                                deplacement += 1;
//                                cout<<"On deplace de "<<deplacement<<endl;
                            }
                        if (testFuse(x_it, y_it, x_it, y_it+(deplacement))){
                            fuse(x_it, y_it, x_it, y_it+(deplacement));
//                            cout<<"On fusionne avec "<<x_it<<";"<<y_it+(deplacement)<<endl;
                        }
                        else if (deplacement != 1){
                            move(x_it, y_it, x_it, y_it+(deplacement-1));
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
                        while(testMove(x_it, y_it, x_it-(deplacement), y_it)){
                                deplacement += 1;
//                                cout<<"On deplace de "<<deplacement<<endl;
                            }
                        if (testFuse(x_it, y_it, x_it-(deplacement), y_it)){
                            fuse(x_it, y_it, x_it-(deplacement), y_it);
//                            cout<<"On fusionne avec "<<x_it-(deplacement)<<";"<<y_it<<endl;
                        }
                        else if (deplacement != 1){
                            move(x_it, y_it, x_it-(deplacement-1), y_it);
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
                        while(testMove(x_it, y_it, x_it+(deplacement), y_it) and x_it+(deplacement) < *Dimension){
                                deplacement += 1;
//                                cout<<"On deplace de "<<deplacement<<endl;
                            }
                        if (testFuse(x_it, y_it, x_it+(deplacement), y_it)){
                            fuse(x_it, y_it, x_it+(deplacement), y_it);
//                            cout<<"On fusionne avec "<<x_it+(deplacement)<<";"<<y_it<<endl;
                        }
                        else if (deplacement != 1){
                            move(x_it, y_it, x_it+(deplacement-1), y_it);
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
    cout<<canUp()<<canDown()<<canLeft()<<canRight();
    if (TestLose()){
        cout<<"perdu!";
        newGame();
    }
    if(Win){
        cout<<"bravo!";
        newGame();
    }
    randCase();

    resetfuse();





}

int Grille::getval(int i, int j){
    return(CasesN[i][j].getValeur());
}


void Grille::newGame(){
    tomemory();
    reset();
    resetfuse();
    setscore(0);
    randCase(false);
    randCase(false);
    Win=0;
}


