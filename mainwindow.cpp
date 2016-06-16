#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle("Library Synthesizer");
    classCombinerUserInterface = new ClassCombinerUserInterface();
    this->setCentralWidget(classCombinerUserInterface);
}

MainWindow::~MainWindow()
{

}
