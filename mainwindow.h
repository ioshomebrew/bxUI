#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QProcess>
#include <QComboBox>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void convert(int type, int format, int size, QString name);
    ~MainWindow();
    
private slots:


    void on_Exit_clicked();

    void on_About_clicked();

    void on_Browse_clicked();

    void on_Create_clicked();

    void on_Type_currentIndexChanged(int index);

    void on_Format_currentIndexChanged(int index);

    void on_size_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
