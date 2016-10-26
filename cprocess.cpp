#include "cprocess.h"
#include <QDebug>

CProcess::CProcess(QObject *parent) : QObject(parent)
{
}
CProcess::~CProcess()
{
}

CProcess::CProcess(const QString& program, const QStringList& arguments) {
    m_process = std::make_shared<QProcess>();
    m_process->setProgram(program);
    m_process->setArguments(arguments);
    m_process->setProcessChannelMode(QProcess::MergedChannels);
}

QString CProcess::run()
{
    m_process->start();
    m_process->waitForReadyRead();
    std::shared_ptr<QTextStream> stream = std::make_shared<QTextStream>(m_process->readAllStandardOutput());
    QStringList allLines;
    QString line = stream->readLine();
    while (!line.isNull()) {
        allLines << line;
        qDebug() << "Line -> " << line;
        emit catchStdout(line);
        line = stream->readLine();
    }
    return QString(allLines.join("\n"));
}
