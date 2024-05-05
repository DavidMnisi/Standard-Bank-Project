#include "sumgenerator.h"

#include <QApplication>
#include <QFile> //to read qss


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Set app style sheet
    QFile file(":/qss/Qss/Cstartpage.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    a.setStyleSheet(styleSheet);

    SumGenerator w;
    w.setWindowTitle("Sum Generator");
    //sets the icon using resource files
    w.setWindowIcon(QIcon(":/img/img/Math.jpg"));
    w.show();

    return a.exec();
}
