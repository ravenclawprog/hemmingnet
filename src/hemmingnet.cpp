#include "hemmingnet.h"
#include <QFile>
#include <QTextStream>
#include <consoleio.h>
#include <QImage>
#include <qmath.h>

hemmingNet::hemmingNet()
{
    t = n/2.0;
    mu = 1.0/(double)m;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            w1[i][j] = 0.0;
        }
        y1[i] = 0.0;
        y2[i] = 0.0;
        oldy2[i] = 0.0;
    }
}
hemmingNet::~hemmingNet(){
//деструктор
}
void hemmingNet::teach(double *xx, int kk){
    for(int i=0;i<n;i++){
        w1[kk][i] = xx[i]/2.0;
    }
}
double hemmingNet::f(double x){
    if(x>0){
    return x;
    }else{
    return 0;
    }
    /*if(x>0&&x<f_max){
       return x;
       }
    if(x<=0){
        return 0;
    }
    if(x>=f_max){
        return f_max;
    }*/
}
double hemmingNet::dabs(double d){
    if(d<0){
        return -d;
    }else{
        return d;
    }
}

bool hemmingNet::truly(){
   bool res1 = false;//у нас только один победитель
   bool res2 = false;//если все элементы не обновляются более, чем на mu
   int sum =0;
   for(int i=0;i<m;i++){
    if(y2[i]==0.0){
        sum++;
    }
   }
   if(sum==(m-1)){
       res1 = true;
   }
   sum = 0;
   for(int i=0;i<m;i++){
       if(dabs(y2[i]-oldy2[i])<mu){
         sum++;}
       oldy2[i] = y2[i];
   }
   if(sum==m){
       res2=true;
   }
   return (res1||res2);
}

int hemmingNet::result(){
   int res = 0;
   for(int i=0;i<m;i++){
       y1[i] = 0.0;
       for(int j=0;j<n;j++){
           y1[i]+=w1[i][j]*x[j];
       }
       y1[i]+=t;
       y2[i] = y1[i];
   }
   do{
    for(int i=0;i<m;i++){
        double sum=0.0;
        for(int j=0;j<m;j++){
            if(j==i){
                continue;
            }else{
                sum+=y2[j];
            }
        }
        y2[i] = f(y2[i]-mu*sum);
    }
   }while(!truly());
   double max = y2[0];
   for(int i=0;i<m;i++){
       if(y2[i]>=max){
           max = y2[i];
           res =i;
       }
   }
   return res;
}
void hemmingNet::teachFromFile(QString fName, int k1){
    QFile f(fName);
    f.open(QIODevice::ReadOnly);
    QTextStream ff(&f);
    double *xx = new double[n];
    int ii=0;
    while(!ff.atEnd()){
        ff>>xx[ii];
        ii++;
    }
    teach(xx,k1);
    delete [] xx;
    f.close();
}
double hemmingNet::getY2(int i){
    return y2[i];
}
void hemmingNet::teachFromImage(QString fName, int k1){
    QImage img = QImage(fName);
    int i1=0;
    int i2=0;
    double *xx = new double[n];
    for(int i=0;i<n;i++){
        QRgb r;
        r=img.pixel(i2,i1);
        i2++;
        if(r!=qRgb(255,255,255)){
         xx[i]=1;
        }else{
          xx[i]=-1;
        }
       if((i2)%(int)qSqrt(n)==0){
            i1++;i2=0;
       }
    }
    teach(xx,k1);
    delete [] xx;
}
void hemmingNet::setXFromFile(QString fName){
    QFile f(fName);
    f.open(QIODevice::ReadOnly);
    QTextStream ff(&f);
    int ii=0;
    while(!ff.atEnd()){
        ff>>x[ii];
        ii++;
    }
    f.close();
}
void hemmingNet::setXFromImage(QString fName){
    QImage img = QImage(fName);
    int i1=0;
    int i2=0;
    for(int i=0;i<n;i++){
        QRgb r;
        r=img.pixel(i2,i1);
        i2++;
        if(r!=qRgb(255,255,255)){
        x[i]=1;
        }else{
          x[i]=-1;
        }
       if((i2)%(int)qSqrt(n)==0){
            i1++;i2=0;
       }
    }
}
void hemmingNet::drawih(int i){
    for(int j=0;j<n;j++){
        if(w1[i][j]>0){
            Out("█");
        }else{
            Out(" ");
        }
       if((j+1)%(int)qSqrt(n)==0){
           Out("\n");
       }
    }
}
