#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDir>

#include <QDebug>
#include <QPluginLoader>

class BadgeInterface {
public:
    virtual ~BadgeInterface() {}
    virtual void Alert() = 0;
};

#define BadgeInterface_iid "org.test.BadgeInterface/1.0"

Q_DECLARE_INTERFACE(BadgeInterface, BadgeInterface_iid)

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/ui/MainWindow.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    auto pluginsDir = QDir(app.applicationDirPath());

    pluginsDir.cd("plugins");

        qInfo() << pluginsDir.path();

    const auto entryList = pluginsDir.entryList(QDir::Files);

    for (const QString &fileName : entryList) {
            QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
            QObject *plugin = loader.instance();
            qInfo() << "Loading " <<  pluginsDir.absoluteFilePath(fileName);
            if (plugin) {
                qInfo() << "Loaded " <<  pluginsDir.absoluteFilePath(fileName);
                auto iPlugin = qobject_cast<BadgeInterface *>(plugin);
                iPlugin->Alert();
            }
        }
    //engine.load(QUrl(QStringLiteral("qrc:/testbadge/main.qml")));

    return app.exec();
}
