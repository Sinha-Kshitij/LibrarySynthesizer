#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    classCombinerUserInterface = new ClassCombinerUserInterface();
    this->setCentralWidget(classCombinerUserInterface);
}

MainWindow::~MainWindow()
{
    delete ui;
}
