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
      Grille2048.Changeval(0,0,1);
      Grille2048.Changeval(0,1,2);
      Grille2048.Changeval(0,2,3);
      Grille2048.Changeval(0,3,4);
      Grille2048.Changeval(1,0,5);
      Grille2048.Changeval(1,1,6);
      Grille2048.Changeval(1,2,7);
      Grille2048.Changeval(1,3,8);
      Grille2048.Changeval(2,0,9);
      Grille2048.Changeval(2,1,10);
      Grille2048.Changeval(2,2,11);
      Grille2048.Changeval(2,3,12);
      Grille2048.Changeval(3,0,13);
      Grille2048.Changeval(3,1,14);
      Grille2048.Changeval(3,2,15);
      Grille2048.Changeval(3,3,16);
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
      Grille2048.Coup(1);     //Gauche
      Grille2048.Coup(2);     //Droite
      Grille2048.Coup(3);     //Haut
      Grille2048.Coup(4);     //Bas


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
