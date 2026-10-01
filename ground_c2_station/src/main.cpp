#include
#include
#include
#include "TacticalC2Server.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    TacticalC2Server c2Backend;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("C2Backend", &c2Backend);
    engine.load(QUrl(QStringLiteral("qrc:/qml/TacticalDashboard.qml")));

    return app.exec();
}