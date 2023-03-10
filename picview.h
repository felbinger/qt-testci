#pragma once
/* ToDo: add includes */
#include <QGraphicsView>
#include <QMenu>
#include <QToolBar>

class PicView : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene* scene;
public:
    PicView(QMenu* fileMenu, QMenu* viewMenu, QToolBar* toolbar);
public slots:
    void fileOpen(const QString& fileName);
    void zoomIn();
    void zoomOut();
    void normalView();
    void rotateLeft();
    void rotateRight();
    void showAbout();
};
