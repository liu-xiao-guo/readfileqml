#include <QtQml>
#include <QtQml/QQmlContext>
#include "backend.h"
#include "mytype.h"
#include "fileio.h"


void BackendPlugin::registerTypes(const char *uri)
{
    Q_ASSERT(uri == QLatin1String("ReadFileQML"));

    qmlRegisterType<MyType>(uri, 1, 0, "MyType");
    qmlRegisterType<FileIO>(uri, 1, 0, "FileIO");
}

void BackendPlugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
    QQmlExtensionPlugin::initializeEngine(engine, uri);
}

