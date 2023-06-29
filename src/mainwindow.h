#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QVector>
#include <QTranslator>
#include <QLabel>
#include <QFont>
#include <QMap>
#include "db/dbimporter.h"

#include "note.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QString myGithub = "GitHub link : https://github.com/AlexeyProg";
    QLabel *link;       // dlya github link
    DBImporter import;  // database

    int32_t max_db_id;

    void paintEvent(QPaintEvent *event) override;
    QTranslator translator;
    void transformMainW();
    Ui::MainWindow *ui;
    QVector<Note*> note_list;

    QVector<QPushButton*> list_buttons;

    void set_style_buttons(QVector<QPushButton*> &list);

    void changeLanguage(QString lang);

    void swapTopic(bool flag);

    void set_reference_properties();

    void import_DB_notes();
public slots:
    void addNewNote();
    void switchToEng();
    void switchToRus();
    void openReference();
    void openNotions();

private slots:
    void on_pushButton_delete_clicked();
};
#endif // MAINWINDOW_H
