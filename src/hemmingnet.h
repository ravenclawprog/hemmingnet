#ifndef HEMMINGNET_H
#define HEMMINGNET_H
#include <QString>
const int n = 1024; //размер входного вектора
const int m = 12; //число образов
const double f_max=600;//ограничение функтора
class hemmingNet
{
private:
    double w1[m][n];//весовые пороги 1-го слоя
    double y1[m];//выход сети 1-го слоя
    double y2[m];//выход сети второго слоя
    double oldy2[m];
    double x[n];//вход сети
    double t;//порог функции активации
    double mu;//величина тормозящих синапсов
    bool truly();
    double dabs(double d);
    double f(double x);
public:
    hemmingNet();//конструктор сети Хэмминга
    ~hemmingNet();//деструктор сети Хэмминга
    void teach(double *xx,int kk);//обучение сети
    int result();//выдать результат
    void teachFromFile(QString fName,int k1);
    void teachFromImage(QString fName,int k1);
    double getY2(int i);//получить выход сети
    void setXFromFile(QString fName);
    void setXFromImage(QString fName);
    void drawih(int i);
};

#endif // HEMMINGNET_H
