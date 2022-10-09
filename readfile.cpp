#include "readfile.h"
#include "sortArray.h"
readFile::readFile(QObject *parent) : QObject(parent)
{
    read();
    //readColor();
    //    qDebug() << getData(0,1);
    //qDebug() << getRow() << " " << getColumn();
}

QString readFile::read()
{
    twoArray.clear();
    QFile file(sourceFile);
    //    QString fileConent;
    if (file.open(QIODevice::ReadOnly)) {
        QString line;
        QTextStream t(&file);
        do {
            line = t.readLine();
            QStringList word = line.split("; ");
            if (word.value(0) != "")
            {
                QVector<QString> a;
                for (int j = 0; j < word.size(); j++)
                {
                    a.push_back(word.value(j));
                }
                twoArray.push_back(a);
            }
        }
        while(!line.isNull());

//        for (int i = 0; i < twoArray.size(); i++)
//        {
//            for (int j = 0; j < twoArray[i].size() ; j++)
//            {
//                qDebug() << twoArray[i][j] << " ";
//            }
//            //            qDebug() << "\n";
//        }
        //        for (int j = 0; j < twoArray.size() ; j++)
        //        {
        //            qDebug() << twoArray[j][0].toLongLong();
        //        }
        file.close();
        //qDebug() << twoArray[1][0];
    }
    else {
        qDebug() << "Unable to open the file";
        return QString();
    }
//    quickSort(twoArray,0,14);
//    qDebug() << "?: " + twoArray[0][0];
    return "";
}

QString readFile::getData(int x, int y)
{
    return twoArray[x][y];
}

int readFile::getColumn()
{
    //read();
    return twoArray[1].size();
}

int readFile::getRow()
{
    //read();
    return twoArray.size();
}
void readFile::readColor()
{
    QFile file("D:/anhthong/DS_training/trainDs/trainDS/file/config.json");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = file.readAll();
    file.close();

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(data, &error);
    if(doc.isNull()) {
        qDebug() << "Parse failed";
    }
    QJsonObject rootObject = doc.object();
    //qDebug() << rootObject.value("level1").toString();
    for (int i = 0; i <= 4; i++)
    {
        colorConfig.push_back(rootObject.value("level" + QString::number(i+1)).toString());
        qDebug() << colorConfig[i];
    }
}

QString readFile::getColor(int index)
{
    return colorConfig[index];
}

void readFile::sapXep(int id)
{
    switch(id)
    {
    case 1:
        quickSort(twoArray,0,14,1);
        break;
    case 2:
        quickSort(twoArray,0,14,2);
        break;
    }
}
