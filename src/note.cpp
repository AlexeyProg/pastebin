#include "note.h"
#include <QLabel>
#include <QLineEdit>


Note::Note(QString mText, QWidget *parent) : QWidget(parent), mContent(mText)
{
    Q_UNUSED(parent);
    setFixedSize(250, 150);


    QLineEdit *titleLabel = new QLineEdit(this);
    titleLabel->setText("Title");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("background-color: green;");
    titleLabel->setGeometry(0, 0,200, 30);

    QTextEdit *text_edit = new QTextEdit(this);
    text_edit->setGeometry(0, 35, 200, 100);
    text_edit->setText(mContent);
    text_edit->setStyleSheet("background-color: yellow;");
    generate_buttons();
}

void Note::generate_buttons()
{

    check_cross = new QPushButton(this);
    check_cross->setGeometry(170,2,25,25);
    check_cross->setText("NO");
    check_cross->setVisible(false);       //нужно юзать setvisible

    check_mark = new QPushButton(this);
    check_mark->setGeometry(140,2,25,25);
    check_mark->setText("YES");
    check_mark->setVisible(false);

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

