#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_2->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //调用窗口打开文件
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("open image"),
                                                    ".",
                                                    tr("Image file(*.png *.jpg *.bmp)"));
    image = imread(filename.toLocal8Bit().data());
    if(image.data) {
        ui->pushButton_2->setEnabled(true);
    }
    //将Mat图像转换为QImage图像，才能显示在label上
    QImage img = QImage((const unsigned char*)(image.data),
                        image.cols, image.rows, QImage::Format_RGB888);
    //设定图像大小自适应label窗口的大小
    img = img.scaled(ui->label->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_2_clicked()
{
    flip(image, image, 1);
    QImage img = QImage((const unsigned char*)(image.data),
                        image.cols, image.rows, QImage::Format_RGB888);
    img = img.scaled(ui->label->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    ui->label->clear();
    ui->label->setPixmap(QPixmap::fromImage(img));
}
