#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QIcon>
#include <QPainter>

static int current_row = 0;
static int current_column = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    import_DB_notes();
    place_logo();

    list_buttons.append(ui->pushButton_add);
    list_buttons.append(ui->pushButton_delete);
    list_buttons.append(ui->pushButton_notions);
    list_buttons.append(ui->pushButton_reference);


    transformMainW();


    //list_buttons = this->findChildren<QPushButton*>();
    connect(ui->pushButton_notions, SIGNAL(clicked()), this, SLOT(openNotions()));
    connect(ui->pushButton_reference, SIGNAL(clicked()), this, SLOT(openReference()));
    connect(ui->pushButton_add, SIGNAL(clicked(bool)), this, SLOT(addNewNote()));
    connect(ui->pushButton_ru, SIGNAL(clicked()), this, SLOT(switchToRus()));
    connect(ui->pushButton_eng, SIGNAL(clicked()), this, SLOT(switchToEng()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QPixmap pix_wallpaper(":/png/wallpaper.jpg");
    painter.drawPixmap(rect(),pix_wallpaper);
}

void MainWindow::transformMainW()
{
    this->setWindowTitle("PasteBin v1.0");
    this->setStyleSheet("MainWindow { background-image: url(:/png/wallpaper.jpg); "
                        "background-repeat: no-repeat; "
                        "background-position: center; }");


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


    set_style_buttons(list_buttons);
    set_reference_properties();

}

void MainWindow::set_style_buttons(QVector<QPushButton *> &list)
{
    QString style = "background-color: rgb(255, 116, 109); color: #FFFFFF;"
                    "border-radius: 5px;"
                    "padding: 5px;";
    for(QPushButton *but : list)
    {
        but->setStyleSheet(style);
    }
}

void MainWindow::changeLanguage(QString lang)
{
    translator.load(lang);
    qApp->installTranslator(&translator);
    ui->retranslateUi(this);
}

void MainWindow::swapTopic(bool flag)
{
    ui->pushButton_add->setVisible(flag);
    ui->pushButton_delete->setVisible(flag);
    for(auto * item : note_list)
    {
        item->setVisible(flag);
    }
    link->setVisible(!flag);
}

void MainWindow::set_reference_properties()
{
    link = new QLabel(this);
    link->setFont(QFont("Arial",15,QFont::Bold));
    link->setStyleSheet("color : green;");

    link->setGeometry(10,20,300,30);
    ui->gridLayout_desk->addWidget(link);
    link->setText(myGithub);
    link->setVisible(false);
}

void MainWindow::import_DB_notes()
{
    QHash<int32_t, Note*> import_content = import.importNotes();
    if(import_content.isEmpty())
        qDebug() << "List is empty";

    foreach (int32_t key, import_content.keys())
    {
        Note *item = import_content.value(key);
        ui->gridLayout_desk->addWidget(item,current_row,current_column);
        current_column++;
        if(current_column >= 3)
        {
            current_column = 0;
            current_row++;
        }
        note_list.append(item);
    }

    max_db_id = *std::max_element(import_content.keyBegin(), import_content.keyEnd());

    //qDebug() << max_db_id << " - max key/id from database";
    import.closeDatabase();
}

void MainWindow::place_logo()
{
    QPixmap pix_logo(":/png/logo.jpg");
    QLabel *logo_lab = new QLabel(this);
    QPixmap scaledPixmap = pix_logo.scaled(QSize(160, 160), Qt::KeepAspectRatio);
    logo_lab->setGeometry(10,400,160,160);
    logo_lab->setPixmap(scaledPixmap);
}

void MainWindow::addNewNote()
{
    Note *new_note = new Note("","Title",this);
    new_note->mId = ++max_db_id;  // prisvaivaem id k novomy Note , otlichniy ot max_db id
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

void MainWindow::openReference()
{
    swapTopic(false);
}

void MainWindow::openNotions()
{
    swapTopic(true);
}


void MainWindow::on_pushButton_delete_clicked()
{
    for(Note *x : note_list)
    {
        x->set_vision(true);
    }
}

