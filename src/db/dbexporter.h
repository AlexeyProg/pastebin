#ifndef DBEXPORTER_H
#define DBEXPORTER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "../note.h"


class DBExporter
{
public:
    DBExporter();
    QString connectToDB();
    bool exportNotes(QList<Note*> list);
private:
    QSqlDatabase db;
};

#endif // DBEXPORTER_H
