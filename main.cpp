#include <QProcess>
#include <QDebug>
#include <memory>
#include <QThread>
#include <QtConcurrent>
#include "cprocess.h"
#include "connector.h"


QString start(QString& program, QStringList& arguments)
{
    std::shared_ptr<CProcess> process = std::make_shared<CProcess>(program, arguments);
    std::shared_ptr<Connector> connector = std::make_shared<Connector>();
    QObject::connect(process.get(), SIGNAL(catchStdout(const QString&)), connector.get(), SLOT(dealwith(const QString&)));

    QString result = process->run();
    return result;
}


int main(int argc, char *argv[])
{
    QString program = "python";
    QStringList arguments = {"py.py"};
    QFuture<QString> future = QtConcurrent::run(&start, program, arguments);
    future.waitForFinished();
    qDebug() << "future results = " << future.results();
    return 0;
}
