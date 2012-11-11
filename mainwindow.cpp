#include "mainwindow.h"
#include "ui_mainwindow.h"

// global declarations
QString path;
QString type = "-hd";
QString format = "-mode=flat";
QString Size;
Ui_MainWindow mainWindow;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{      
    // setup ui
    ui->setupUi(this);

    // set window name
    setWindowTitle("bxui (A bximage GUI)");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// when exit is pressed
void MainWindow::on_Exit_clicked()
{
    // exit
    exit(0);
}

// when about is pressed
void MainWindow::on_About_clicked()
{
    // declarations
    QMessageBox About;

    // set About properties and execute messagebox
    About.setWindowTitle("About");
    About.setText("bxUI\nv1.0\n(c)2012 @ioshomebrew (Beecher Adams)");
    About.setStandardButtons(QMessageBox::Ok);
    About.setDefaultButton(QMessageBox::Ok);
    About.exec();
}

// when browse is pressed
void MainWindow::on_Browse_clicked()
{
    // open file dialog
    path = QFileDialog::getSaveFileName(this, "Save File", "", "Disk Image (*.img);;VMware Disk Image (*.vmdk);;Virtual Hard Disk(*.vhd)");

    // print path
    qDebug() << path;

    // set path
    ui->path->setText(path);
}

// when create is pressed
void MainWindow::on_Create_clicked()
{
    // declarations
    QMessageBox Finished;
    QString Message;
    QProcess bximage;
    QString program = "C:/Program Files (x86)/Bochs-2.5.1/bximage.exe";
    QStringList arguments;
    int size2;
    bool ok;
    size_t BufSize = 1024;
    char buf[BufSize];

    // make size argument
    size2 = Size.toInt(&ok, 10);
    snprintf(buf, BufSize, "-size=%i", size2);
    Size = QString::fromAscii(buf);

    // put bximage arugments in arguments
    arguments << type << format;
    arguments << Size << "-q";
    arguments << path;

    // print arguments
    for(int count = 0; count < 5; count++)
        qDebug() << arguments[count];

    // make messagebox
    Message = path + QString(" has been created");
    Finished.setWindowTitle("Finished");
    Finished.setText(Message);
    Finished.setIcon(QMessageBox::Information);
    Finished.exec();

    // start bximage
    bximage.start(program, arguments);
}

// when Type changed
void MainWindow::on_Type_currentIndexChanged(int index)
{
    // change type
    if(index == 0)
    {
        // change type to hd
        type = "-hd";

        // change format back to flat
        ui->Format->setCurrentIndex(0);

        // set format to flat
        format = "-mode=flat";

        // enable format box
        ui->Format->setEnabled(true);
    }
    else
    {
        // change type to fd
        type = "-fd";

        // null out format
        format = "";

        // grey out format box
        ui->Format->setEnabled(false);
    }

    // print type
    qDebug() << type;
}

void MainWindow::on_Format_currentIndexChanged(int index)
{
    // change type
    switch(index)
    {
        case 0:
        {
            format = "-mode=flat";
        }
        break;

        case 1:
        {
            format = "-mode=concat";
        }
        break;

        case 2:
        {
            format = "-mode=sparse";
        }
        break;

        case 3:
        {
            format = "-mode=vmware3";
        }
        break;

        case 4:
        {
            format = "-mode=vmware4";
        }
        break;

        case 5:
        {
            format = "-mode=undoable";
        }
        break;

        case 6:
        {
            format = "-mode=growing";
        }
        break;

        case 7:
        {
            format = "-mode=volatile";
        }
        break;

        case 8:
        {
            format = "-mode=virtualpc";
        }
        break;

        case 9:
        {
            format = "-mode=vvat";
        }
        break;
    }

    // print format
    qDebug() << format;
}

// when text is changed
void MainWindow::on_size_textChanged(const QString &arg1)
{
    // set size
    Size = arg1;

    // print size
    qDebug() << Size;
}
