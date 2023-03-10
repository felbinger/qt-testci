#include "mainview.h"
#include "picview.h"
/* ToDo: add includes */
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>

MainView::MainView() : QMainWindow() {
    /* ToDo: create menubar  */
    QMenuBar *myMenuBar = new QMenuBar(this);

    /* ToDo: create menus  */
    QMenu *myFileMenu = new QMenu("&File",this);
    myFileMenu->addAction("Close", this, SLOT(close()));
    myMenuBar->addMenu(myFileMenu);

    QMenu *myViewMenu = new QMenu("&View",this);
    myFileMenu->addAction("Full Screen", this, SLOT(showFullScreen()));
#if QT_VERSION >= 0x060400
    myViewMenu->addAction("Windowed", Qt::Key_Escape, this, SLOT(showNormal()));
#else
    myViewMenu->addAction("Windowed", this, SLOT(showNormal()), Qt::Key_Escape);
#endif
    myMenuBar->addMenu(myViewMenu);

    /* ToDo: create toolbar  */
    QToolBar *myBar = new QToolBar(this);

    /* ToDo: set central Widget */
    setCentralWidget(new PicView(myFileMenu, myViewMenu, myBar));

    /* ToDo: set menubar */
    this->setMenuBar(myMenuBar);

    /* ToDo: add toolbar */
    this->addToolBar(myBar);
}
