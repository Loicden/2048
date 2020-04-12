#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include <sstream>
#include "case.h"
#include "grille.h"
#include <QtQml>

using namespace std;

int main(int argc, char *argv[])
{

    Grille Grille2048 = Grille();
    Grille2048.NewGame();

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

}
