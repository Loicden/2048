#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include "case.h"
#include "grille.h"
using namespace std;

int main(int argc, char *argv[])
{
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

//    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    const QUrl url(QStringLiteral("qrc:/main.qml"));
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);
//    engine.load(url);

//    return app.exec();

      Grille Grille2048 = Grille();
      Grille2048.AfficherGrille();
//      Grille2048.Changeval(1,2,2);
//      Grille2048.Changeval(3,3,2);
//      Grille2048.Changeval(0,0,4);
//      Grille2048.AfficherGrille();
//      Grille2048.Reset();
//      Grille2048.AfficherGrille();
//      cout<<Grille2048.TestMove(0,0,1);
//      cout<<Grille2048.TestMove(0,0,2);
//      cout<<Grille2048.TestMove(0,0,3);
//      cout<<Grille2048.TestMove(0,0,4);
//      cout<<Grille2048.TestMove(1,2,1);
//      cout<<Grille2048.TestMove(1,2,2);
//      cout<<Grille2048.TestMove(1,2,3);
//      cout<<Grille2048.TestMove(1,2,4);
//      cout<<Grille2048.TestFuse(1,2,2);
//      cout<<Grille2048.TestFuse(1,2,1);
//      Grille2048.Changeval(3,0,8);
//      Grille2048.AfficherGrille();
//      Grille2048.Move(1,2,2);
//      Grille2048.AfficherGrille();
int k;
int n;
for (k=0;k<Grille2048.GetDim();k++){
    for (n=0;n<Grille2048.GetDim();n++){
        Grille2048.Changeval(k,n,2);
        Grille2048.AfficherGrille();
        Grille2048.Reset();}
}

return 0;
}
