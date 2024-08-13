#include <QApplication>
#include <QIcon>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  QApplication::setWindowIcon(QIcon(":/images/3DViewer-Icon.png"));
  MainWindow w;
  w.show();
  return a.exec();
}
