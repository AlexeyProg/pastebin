#include "mainwindow.h"
#include "ui_mainwindow.h"

static int current_row = 0;
static int current_column = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    transformMainW();

    connect(ui->pushButton_add, SIGNAL(clicked(bool)), this, SLOT(addNewNote()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::transformMainW()
{
    this->setWindowTitle("PasteBin v1.0");
    this->setStyleSheet("background-color:grey;");

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


void MainWindow::on_pushButton_delete_clicked()
{
    for(Note *x : note_list)
    {
        x->set_vision(true);
    }
}

