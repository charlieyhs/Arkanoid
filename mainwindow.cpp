#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Arkanoid.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mArkanoid = new Arkanoid(ui->graphicsView,this);
    setCentralWidget(ui->graphicsView);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionIniciar_Juego_triggered()
{
    mArkanoid->starGame();
}

void MainWindow::on_actionSalir_triggered()
{
    mArkanoid->stopGame();
    close();
}
