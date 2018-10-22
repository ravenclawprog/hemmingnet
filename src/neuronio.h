#ifndef NEURONIO_H
#define NEURONIO_H
#include <QString>
#include <perceptron.h>


void rOut(QString s);// вывод кириллицей
QString nOut(dinamycNeuron& d,QString command); // вывод значений нейрона
QString vOut(double *t,int n); // вывод вектора t размерностью n
QString lOut(Layer& l,QString command);

#endif // NEURONIO_H
