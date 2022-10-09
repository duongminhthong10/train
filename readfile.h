#ifndef READFILE_H
#define READFILE_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QVector>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
//#include "sortArray.h"
#define sourceFile ":/file/accounts.txt"
class readFile : public QObject
{
    Q_OBJECT
public:
    explicit readFile(QObject *parent = nullptr);
    Q_INVOKABLE QString read();
    Q_INVOKABLE QString getData(int x, int y);
    Q_INVOKABLE int getColumn();
    Q_INVOKABLE int getRow();
    Q_INVOKABLE void readColor();
    Q_INVOKABLE QString getColor(int index);
    Q_INVOKABLE void sapXep(int id);
private:
     QVector<QString> colorConfig;
     QVector<QString> fileArray;
     QVector<QVector<QString>> twoArray;

signals:

};

#endif // READFILE_H
