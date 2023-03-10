#include "picview.h"
#include <QGraphicsScene>
#include <QFileDialog>
#include <QPushButton>
#include <QMessageBox>

PicView::PicView(QMenu* fileMenu, QMenu* viewMenu, QToolBar* toolbar) : QGraphicsView() {
    this->scene = new QGraphicsScene();
    setScene(this->scene);
    fileOpen("/home/nicof2000/Studium/8_Trimester/WPM_MOP2/Praktische-Uebung/Uebung7/picviewer/Images/IMG_0940.png");

    QFileDialog* myFileDialog = new QFileDialog(this);
    fileMenu->addAction("Open", myFileDialog, SLOT(exec()));

    /* route file dialog to FileOpen */
    connect(myFileDialog, SIGNAL(fileSelected(QString)), this, SLOT(fileOpen(QString)));

    // f)
    QPushButton* fileOpenBtn = new QPushButton();
    fileOpenBtn->setIcon(QIcon(":/Images/fileopen.png"));
    toolbar->addWidget(fileOpenBtn);
    connect(fileOpenBtn, SIGNAL(clicked()), myFileDialog, SLOT(exec()));

    // g)
    QAction *zoomIn = new QAction("Zoom In");
    zoomIn->setShortcut(Qt::Key_Plus);
    zoomIn->setIcon(QIcon(":/Images/zoomin.png"));
    connect(zoomIn, SIGNAL(triggered()), this, SLOT(zoomIn()));
    viewMenu->addAction(zoomIn);

    QAction *zoomOut = new QAction("Zoom Out");
    zoomOut->setShortcut(Qt::Key_Minus);
    zoomOut->setIcon(QIcon(":/Images/zoomout.png"));
    connect(zoomOut, SIGNAL(triggered()), this, SLOT(zoomOut()));
    viewMenu->addAction(zoomOut);

    // i
    QAction *turnLeft = new QAction("Turn left");
    turnLeft->setIcon(QIcon(":/Images/turnleft.png"));
    connect(turnLeft, SIGNAL(triggered()), this, SLOT(rotateLeft()));
    viewMenu->addAction(turnLeft);

    QPushButton* turnLeftBtn = new QPushButton();
    turnLeftBtn->setIcon(QIcon(":/Images/turnleft.png"));
    toolbar->addWidget(turnLeftBtn);
    connect(turnLeftBtn, SIGNAL(clicked()), this, SLOT(rotateLeft()));

    QAction *turnRight = new QAction("Turn right");
    turnRight->setIcon(QIcon(":/Images/turnright.png"));
    connect(turnRight, SIGNAL(triggered()), this, SLOT(rotateRight()));
    viewMenu->addAction(turnRight);

    QPushButton* turnRightBtn = new QPushButton();
    turnRightBtn->setIcon(QIcon(":/Images/turnright.png"));
    toolbar->addWidget(turnRightBtn);
    connect(turnRightBtn, SIGNAL(clicked()), this, SLOT(rotateRight()));

    // j
    fileMenu->addAction("Über picviewer", this, SLOT(showAbout()));
}

void PicView::fileOpen(const QString& fileName) {
    this->scene->clear();
    this->scene->addPixmap(QPixmap(fileName));
    this->normalView();
}

void PicView::zoomIn() {
    scale(1.1, 1.1);
}

void PicView::zoomOut() {
    scale(0.9, 0.9);
}

void PicView::normalView() {
    resetTransform();
}

void PicView::rotateLeft() {
    this->rotate(-90);
}

void PicView::rotateRight() {
    this->rotate(90);
}

void PicView::showAbout() {
    QMessageBox::information(this, "Application Name", "Meine erste Qt App!");
}
