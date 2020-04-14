#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include <QtQml>
#include <sstream>
#include "case.h"
#include "grille.h"
#include "qgrille.h"
using namespace std;

int main(int argc, char *argv[])
{
    Grille Grille2048=Grille();
    Grille2048.newGame();
    QGrille GrilleQML(Grille2048);
    GrilleQML.getlist();
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

//    GrilleQML.GrilleG.AfficherGrille();
//    GrilleQML.Coup(2);
//    GrilleQML.GrilleG.AfficherGrille();

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.rootContext()->setContextProperty("vueObjetCpt", &GrilleQML);
    engine.load(url);

    return app.exec();
      return 0;
}
