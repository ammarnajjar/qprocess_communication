#include "connector.h"
#include <QDebug>

Connector::Connector(QObject *parent) : QObject(parent)
{
}

void Connector::dealwith(const QString& stdout) {
    qDebug() << "deal with: " << stdout;
}
