#include "mainview.h"
#include <QApplication>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
    MainView myMainView;
    myMainView.show();
	return app.exec();
}
