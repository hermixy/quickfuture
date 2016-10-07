#include <QtConcurrent>
#include "fileactor.h"

FileActor::FileActor(QObject *parent) : QObject(parent)
{

}

QFuture<QString> FileActor::read(const QString &fileName)
{
    return QtConcurrent::run([fileName]() -> QString {

        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            return "";
        }

        return file.readAll();
    });
}

QFuture<void> FileActor::dummy()
{
    return QtConcurrent::run([]() -> void {
        return;
                             });
}

QFuture<void> FileActor::alreadyFinished()
{
    return QFuture<void>();
}
