#ifndef NOTE_H
#define NOTE_H

#include <QWidget>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QPushButton>

class Note : public QWidget
{
    Q_OBJECT
public:
    explicit Note(QString mText, QString title = "Title", QWidget *parent = nullptr);

    QString mName;
    QString mTitle;
    QString mContent;
    int mId;
    void set_vision(bool ok);
private:
    QPushButton *check_mark;

    QPushButton *check_cross;
    void generate_buttons();

signals:

};

#endif // NOTE_H
