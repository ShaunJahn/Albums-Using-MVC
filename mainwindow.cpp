#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include <QList>
#include <QColor>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new MusicModel(this);
    ui->tableView->setModel(model);

    // QTableView view set up in GUI
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addItem()));
}

void MainWindow::addItem()
{
    // get values
    QString composer = ui->composer->text();
    QString album = ui->album->text();
    float price = ui->price->value();
    int rating = ui->rating->value();

    // reset GUI
    ui->composer->clear();
    ui->album->clear();
    ui->price->setValue(0.0);
    ui->rating->setValue(0);
    ui->composer->setFocus();

    // add to model
    CD *cd = new CD(composer, album, price, rating);
    model->addCD(cd);
}

MainWindow::~MainWindow()
{
    delete ui;
}
