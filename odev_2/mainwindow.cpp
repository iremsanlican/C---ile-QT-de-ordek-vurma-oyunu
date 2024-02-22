#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLabel>
#include<QTimer>
#include<QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
       ui->setupUi(this);
       game = new duck(this);
        setCentralWidget(game);

        setFixedSize(800, 600);


    }


MainWindow::~MainWindow()
{
    delete ui;
}

