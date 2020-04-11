#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionGet_Info_triggered();

    void on_componentList_itemClicked(QListWidgetItem *item);

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    QString commands[6] = {"-C cpu", "-C memory", "-C disk", "-C network", "-t bios", "-t baseboard"};
    void showComponetOutput(QString provider, QString command);
};

#endif // MAINWINDOW_H
