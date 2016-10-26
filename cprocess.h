#ifndef CPROCESS_H
#define CPROCESS_H

#include <QObject>
#include <QProcess>
#include <memory>

class CProcess : public QObject
{
    Q_OBJECT
public:
    explicit CProcess(QObject *parent = 0);
    CProcess(const QString& program, const QStringList& arguments);
    virtual ~CProcess();
    QString run();

signals:
    void catchStdout(const QString& stdout);

public slots:

private:
    std::shared_ptr<QProcess> m_process;

};

#endif // CPROCESS_H
