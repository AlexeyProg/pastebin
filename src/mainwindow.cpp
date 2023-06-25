#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QIcon>

static int current_row = 0;
static int current_column = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    transformMainW();


    connect(ui->pushButton_add, SIGNAL(clicked(bool)), this, SLOT(addNewNote()));
    connect(ui->pushButton_ru, SIGNAL(clicked()), this, SLOT(switchToRus()));
    connect(ui->pushButton_eng, SIGNAL(clicked()), this, SLOT(switchToEng()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::transformMainW()
{
    this->setWindowTitle("PasteBin v1.0");
    this->setStyleSheet("background-color:grey;");

    QPixmap pix_ru(":/png/rus.png");
    QIcon icon_ru(pix_ru);
    ui->pushButton_ru->setIcon(icon_ru);
    ui->pushButton_ru->setIconSize(QSize(35,35));
    ui->pushButton_ru->setFlat(true);

    QPixmap pix_eng(":/png/eng.png");
    QIcon icon_eng(pix_eng);
    ui->pushButton_eng->setIcon(icon_eng);
    ui->pushButton_eng->setIconSize(QSize(35,35));
    ui->pushButton_eng->setFlat(true);

}

void MainWindow::changeLanguage(QString lang)
{
    translator.load(lang);
    qApp->installTranslator(&translator);
    ui->retranslateUi(this);
}

void MainWindow::addNewNote()
{
    Note *new_note = new Note("Empty",this);
    ui->gridLayout_desk->addWidget(new_note, current_row,current_column);
    current_column++;
    if(current_column >= 3)
    {
        current_column = 0;
        current_row++;
    }
    note_list.append(new_note);
}

void MainWindow::switchToEng()
{
    changeLanguage(":/pastebin_eng.qm");
}

void MainWindow::switchToRus()
{
    changeLanguage(":/pastebin_ru.qm");
}


void MainWindow::on_pushButton_delete_clicked()
{
    for(Note *x : note_list)
    {
        x->set_vision(true);
    }
}

