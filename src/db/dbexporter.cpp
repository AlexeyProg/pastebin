#include "dbexporter.h"

DBExporter::DBExporter()
{

}

QString DBExporter::connectToDB()
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

bool DBExporter::exportNotes(QList<Note*> list)
{
    bool ok = true;
    for(Note *item : list)
    {
         QString title = item->mTitle;
         QString content = item->mContent;
         QString req = QString("INSERT INTO Notes (title,text) VALUES ('%1','%2');").arg(title,content);
         QSqlQuery q(req);   // нужно сделать чтобы qlist состоял из стикеров , которых нет в базе.
         ok = q.exec();
    }
    return ok;
}
