#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<Controller>("Fliezzz", 1, 0, "Controller");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
