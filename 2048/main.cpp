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
    Grille Grille2048=Grille();         // Création de l'objet Grille2048
    Grille2048.newGame();               // On lance la partie à partir de cette objet
    QGrille GrilleQML(Grille2048);      // On créer l'objet QGrille
    GrilleQML.getlist();                // On obtient la valeur des tuiles
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.rootContext()->setContextProperty("vueObjetCpt", &GrilleQML);
    engine.load(url);

    return app.exec();      // On execute
    return 0;               // Code de réussite
}
