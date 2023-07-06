#include "note.h"
#include <QLabel>
#include <QLineEdit>

#include <QSqlError>
#include <QSqlQuery>


Note::Note(QString mText, QString title, QWidget *parent) : QWidget(parent), mTitle(title), mContent(mText)
{
    Q_UNUSED(parent);
    setFixedSize(250, 150);


    titleLabel = new QLineEdit(this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("background-color: green;");
    titleLabel->setGeometry(0, 0,200, 30);
    titleLabel->setText(mTitle);

    text_edit = new QTextEdit(this);
    text_edit->setGeometry(0, 35, 200, 100);
    text_edit->setStyleSheet("background-color: yellow;"
                             "color : rgb(139,0,0);");
    text_edit->setText(mContent);
    generate_buttons();

    connect(text_edit, &QTextEdit::textChanged, this, &Note::changedContent);
    connect(titleLabel, &QLineEdit::textChanged, this, &Note::changedTitle);


    connect(check_cross, SIGNAL(clicked()), this, SLOT(deleteNote()));
}

void Note::generate_buttons()
{

    check_cross = new QPushButton(this);
    check_cross->setGeometry(170,2,25,25);
    check_cross->setText("X");
}

void Note::changedContent()
{
    mContent = text_edit->toPlainText();
}

void Note::changedTitle()
{
    mTitle = titleLabel->text();
}

void Note::deleteNote()
{

    QString str = QString("DELETE FROM Notes WHERE note_id = %1").arg(this->mId);
    QSqlQuery q(str);
    bool res = q.exec();
    if(res)
    {
        qDebug() << "not deleted from db";
        qDebug() << q.lastError();
    }

    deleteLater();
}
