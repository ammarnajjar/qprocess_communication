#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QObject>

class Connector : public QObject
{
    Q_OBJECT
public:
    explicit Connector(QObject *parent = 0);

signals:

public slots:
    void dealwith(const QString& stdout);
};

#endif // CONNECTOR_H
