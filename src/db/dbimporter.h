#ifndef DBIMPORTER_H
#define DBIMPORTER_H

#include "../note.h"
#include <QSqlDatabase>


class DBImporter
{

public:
    DBImporter();
    QString connectToDatabase();
    QList<Note*> importNotes();

private:
    QSqlDatabase db;
};

#endif // DBIMPORTER_H
