#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QVector>
#include <QTranslator>

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
    void paintEvent(QPaintEvent *event) override;

    QTranslator translator;
    void transformMainW();
    Ui::MainWindow *ui;
    QVector<Note*> note_list;

    QVector<QPushButton*> list_buttons;
    void set_style_buttons(QVector<QPushButton*> &list);

    void changeLanguage(QString lang);

public slots:
    void addNewNote();
    void switchToEng();
    void switchToRus();

private slots:
    void on_pushButton_delete_clicked();
};
#endif // MAINWINDOW_H
