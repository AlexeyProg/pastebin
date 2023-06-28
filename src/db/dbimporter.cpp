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

QList<Note *> DBImporter::importNotes()
{
    QList<Note*> notes_from_db;

    QString request = QString("SELECT * from Notes;");
    QSqlQuery q(request);
    while(q.next())
    {
        Note *new_note = new Note(q.value(2).toString(), q.value(1).toString());
        qDebug() << q.value(1) << q.value(2);
        notes_from_db.append(new_note);
    }
    return notes_from_db;
}
