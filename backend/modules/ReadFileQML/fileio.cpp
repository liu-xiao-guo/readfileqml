#include "fileio.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileInfo>
#include <QTextCodec>

FileIO::FileIO(QObject *parent) : QObject(parent)
{
    datapath = getenv("TMPDIR")  + "/";
    qDebug() << "datapath: " + datapath;
}

QString FileIO::read()
{    
    qDebug() << "reading ....!";

    if (mSource.isEmpty()){
        emit error("source is empty");
        return QString();
    }

    QFile file(datapath + mSource);
    QFileInfo fileInfo(file.fileName());
    qDebug() << "file path: " << fileInfo.absoluteFilePath();

    QString fileContent;
    if ( file.open(QIODevice::ReadOnly) ) {
        QString line;

        QTextCodec *gbk = QTextCodec::codecForName("GBK");
        QTextStream t( &file );
        t.setCodec(gbk);

        do {
            line = t.readLine();
            fileContent += line;
        } while (!line.isNull());

        file.close();
        return fileContent;
    } else {
        emit error("Unable to open the file");
        return QString();
    }

//    QTextCodec::ConverterState state;
//    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
//    QByteArray array = fileContent.toUtf8();

//    const QString text = codec->toUnicode(array.constData(), array.size(), &state);
//    if (state.invalidChars > 0) {
//        qDebug() << "Not a valid UTF-8 sequence.";

//        QTextCodec * codec = QTextCodec::codecForLocale();
//        if (!codec)
//            return "";

//        return codec->toUnicode(array);
//    } else {
//        qDebug() << "it is a valid UTF-8 sequence.";

//        return text;
//    }
}

bool FileIO::write(const QString& data)
{
    qDebug() << "writing.....";

    if (mSource.isEmpty())
        return false;

    QFile file(datapath + mSource);
    QFileInfo fileInfo(file.fileName());
    qDebug() << "file path: " << fileInfo.absoluteFilePath();
    if (!file.open(QFile::WriteOnly | QFile::Truncate))
        return false;

    QTextStream out(&file);
    out << data;

    file.close();

    return true;
}

QString FileIO::getenv(const QString envVarName) const
{
    QByteArray result = qgetenv(envVarName.toStdString().c_str());
    QString output = QString::fromLocal8Bit(result);
    qDebug() << envVarName << " value is: "  << output;
    return output;
}
