#include "dbexporter.h"

DBExporter::DBExporter()
{

}

bool DBExporter::exportNotes(QList<Note *> &list, int32_t id)
{
    bool ok = true;
    for(Note *item : list)
    {
        if(item->mId > id)
        {
            QString title = item->mTitle;
            QString content = item->mContent;
            QString req = QString("INSERT INTO Notes (title,text) VALUES ('%1','%2');").arg(title,content);
            QSqlQuery q(req);   // нужно сделать чтобы qlist состоял из стикеров , которых нет в базе.
            ok = q.exec();
        }
    }
    return ok;
}
