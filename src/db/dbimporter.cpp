#include "dbimporter.h"
#include <QSqlQuery>

DBImporter::DBImporter()
{
    connectToDatabase();
}

QString DBImporter::connectToDatabase()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setPort(5432);
    db.setDatabaseName("pastebin");
    if(db.open())
        return "Successful connection to database!";
    else
        return "Connection error!";
}

QHash<int32_t, Note *> DBImporter::importNotes()
{
    QHash<int32_t, Note*> notes_from_db;

    QString request = QString("SELECT * from Notes;");
    QSqlQuery q(request);
    while(q.next())
    {
        int32_t id = q.value(0).toInt();
        Note *new_note = new Note(q.value(2).toString(), q.value(1).toString());
        new_note->mId = id;
        notes_from_db.insert(id,new_note);
    }
    return notes_from_db;
}

void DBImporter::closeDatabase()
{
    db.close();
    qDebug() << "Database was closed";
}
