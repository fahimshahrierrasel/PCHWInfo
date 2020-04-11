#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QProcess"
#include "unistd.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->infoWidget->setHidden(true);
    if(getuid()){
        ui->welcomeLabel->setText("Please run this application as root or it will not work!!!");
        ui->menuBar->setHidden(true);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionGet_Info_triggered()
{
    ui->welcomeLabel->setHidden(true);
    ui->infoWidget->setHidden(false);
    showComponetOutput("lshw",commands[0]);
}

void MainWindow::showComponetOutput(QString provider, QString command){
    QStringList commandList = command.split(" ");
    QProcess process;
    process.start(provider, commandList);
    process.waitForFinished(-1);
    ui->comonentBrowser->setText(process.readAllStandardOutput());
}

void MainWindow::on_componentList_itemClicked(QListWidgetItem *item)
{
    if(item->text() == "CPU"){
        showComponetOutput("lshw",commands[0]);
    }else if(item->text() == "Memory"){
        showComponetOutput("lshw",commands[1]);
    }else if(item->text() == "Disk"){
        showComponetOutput("lshw",commands[2]);
    }else if(item->text() == "Network"){
        showComponetOutput("lshw",commands[3]);
    }else if(item->text() == "Bios"){
        showComponetOutput("dmidecode",commands[4]);
    }else if(item->text() == "MotherBoard"){
        showComponetOutput("dmidecode",commands[5]);
    }
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}
