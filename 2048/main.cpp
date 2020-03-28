#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include "case.h"
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

      Case case1 = Case(1,3);
      case1.AffichePoint();
      case1.SetValeur(4);
      case1.AffichePoint();
return 0;
}
