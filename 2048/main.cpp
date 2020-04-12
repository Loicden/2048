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
<<<<<<< HEAD

    Grille Grille2048 = Grille();
    Grille2048.NewGame();

=======
    Grille Grille2048 = Grille();
>>>>>>> b9d2922f16f7e28e3c5693c10c799addd44ca8f2
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
