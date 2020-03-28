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
      cout<<""<<endl;
      Grille2048.Changeval(1,2,2);
      Grille2048.AfficherGrille();
return 0;
}
