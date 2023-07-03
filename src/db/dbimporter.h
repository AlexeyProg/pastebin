#ifndef DBIMPORTER_H
#define DBIMPORTER_H

#include "../note.h"
#include <QSqlDatabase>
#include <QHash>


class DBImporter
{

public:
    DBImporter();
    QString connectToDatabase();
    QHash<int32_t, Note *> importNotes();
    void closeDatabase();
    QSqlDatabase db;
};

#endif // DBIMPORTER_H
