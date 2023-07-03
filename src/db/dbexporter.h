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
    bool exportNotes(QList<Note*> &list, int32_t id);
private:
    QSqlDatabase db;
};

#endif // DBEXPORTER_H
