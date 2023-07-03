#include "note.h"
#include <QLabel>
#include <QLineEdit>


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


    // test
    connect(check_cross, SIGNAL(clicked()), this, SLOT(deleteNote()));
}

void Note::generate_buttons()
{

    check_cross = new QPushButton(this);
    check_cross->setGeometry(170,2,25,25);
    check_cross->setText("X");
    check_cross->setVisible(false);       //нужно юзать setvisible

    // step1 : delete note from database -> step2 : thiswidget->close();
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
    this->close();
}

void Note::set_vision(bool ok)
{
    if(ok)
    {
        check_cross->setVisible(true);
    }
    else
    {
        check_cross->setVisible(false);
    }
}

