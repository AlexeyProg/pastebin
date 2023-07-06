#ifndef NOTE_H
#define NOTE_H

#include <QWidget>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>

class Note : public QWidget
{
    Q_OBJECT
public:
    explicit Note(QString mText, QString title = "Title", QWidget *parent = nullptr);

    QString mTitle;
    QString mContent;
    int mId;
private:
    QTextEdit *text_edit;
    QLineEdit *titleLabel;
    QPushButton *check_cross;
    void generate_buttons();

public slots:
    void changedContent();
    void changedTitle();
    void deleteNote();


signals:
    void deleteNoteSignal();
};

#endif // NOTE_H
