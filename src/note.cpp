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
}

void Note::generate_buttons()
{

    check_cross = new QPushButton(this);
    check_cross->setGeometry(170,2,30,25);
    check_cross->setText("NO");
    check_cross->setVisible(false);       //нужно юзать setvisible

    check_mark = new QPushButton(this);
    check_mark->setGeometry(140,2,30,25);
    check_mark->setText("YES");
    check_mark->setVisible(false);

}

void Note::changedContent()
{
    mContent = text_edit->toPlainText();
}

void Note::changedTitle()
{
    mTitle = titleLabel->text();
}

void Note::set_vision(bool ok)
{
    if(ok)
    {
        check_cross->setVisible(true);
        check_mark->setVisible(true);
    }
    else
    {
        check_cross->setVisible(false);
        check_mark->setVisible(false);
    }
}

