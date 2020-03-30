#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include "case.h"
#include "grille.h"
using namespace std;

int main(int argc, char *argv[])
{
/*

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
*/
      Grille Grille2048 = Grille();
/*
      Grille2048.AfficherGrille();
      Grille2048.RandCase(false);
      Grille2048.AfficherGrille();
      Grille2048.RandCase(false);
      Grille2048.AfficherGrille();
      Grille2048.RandCase();
      Grille2048.AfficherGrille();
*/
      //Grille2048.Changeval(0,0,2);
      Grille2048.Changeval(0,3,2);
      Grille2048.Changeval(0,2,2);
      Grille2048.AfficherGrille();
      /*
      cout<<Grille2048.TestMove(0,3,0,2)<<endl;
      cout<<Grille2048.TestMove(0,3,1,2)<<endl;
      cout<<Grille2048.TestMove(0,3,0,0)<<endl;
      cout<<Grille2048.TestMove(0,3,3,3)<<endl;
      Grille2048.Move(0,3,0,2);
      cout<<Grille2048.TestFuse(0,2,0,0)<<endl;
      cout<<Grille2048.TestFuse(0,2,0,1)<<endl;
      Grille2048.Move(0,2,0,3);
      cout<<Grille2048.TestFuse(0,3,0,0)<<endl;
      cout<<Grille2048.TestFuse(0,3,3,3)<<endl;
      Grille2048.Fuse(0,3,0,0);
      Grille2048.AfficherGrille();

*/
      //Grille2048.Coup(1);     //Gauche
      //Grille2048.AfficherGrille();
      Grille2048.Changeval(0,3,2);
      //Grille2048.AfficherGrille();

      //Grille2048.Coup(2);     //Droite
      //Grille2048.AfficherGrille();
      Grille2048.Changeval(2,0,2);
      Grille2048.AfficherGrille();

      Grille2048.Coup(3);     //Haut
      Grille2048.AfficherGrille();
      Grille2048.Changeval(3,0,2);
      Grille2048.AfficherGrille();

      Grille2048.Coup(4);     //Bas
      Grille2048.AfficherGrille();

//int k;
//int n;
//for (k=0;k<Grille2048.GetDim();k++){
//    for (n=0;n<Grille2048.GetDim();n++){
//        Grille2048.Changeval(k,n,2);
//        Grille2048.AfficherGrille();
//        Grille2048.Reset();}
//}

return 0;
}
