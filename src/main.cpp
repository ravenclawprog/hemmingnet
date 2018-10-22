#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <consoleio.h>
#include <hemmingnet.h>
#include <QImage>
#include <qmath.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    hemmingNet H;//Сеть Хэмминга
    Out("Обучаем сеть\n");
        H.teachFromImage("sphere.bmp",0);
        H.teachFromImage("romb.bmp",1);
        H.teachFromImage("square.bmp",2);
        H.teachFromImage("triangle.bmp",3);
        H.teachFromImage("nothing.bmp",4);
    Out("Загружаем пример...\n");
    H.setXFromImage("sphere.bmp");
    Out("Образ больше всего похож на "+QString::number(H.result())+'\n');
    H.drawih(H.result());
    return a.exec();
}
