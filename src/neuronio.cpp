#include "neuronio.h"
#include <QTextStream>

void rOut(QString s){
    QTextStream out(stdout);
#ifdef Q_OS_WIN
    out.setCodec("CP866");
#endif
    out<<QString::fromUtf8(s.toStdString().c_str())<<flush;
}

QString nOut(dinamycNeuron& d,QString command){
    QString res = ""; // результат функции
    if(command == "y"){
        res =  "y = "+QString::number(d.getResult())+";\n";
    }else
    if(command == "N"){
        res = "N = "+QString::number(d.getN())+";\n";
    }
    else
    if(command == "x"){

        for(int i=0;i<d.getN();i++){
            res += "x["+QString::number(i)+"]="+QString::number(d.getX(i))+'\n';
        }
    }
    else
    if(command=="w"){
        for(int i=-1;i<d.getN();i++){
            res += "w["+QString::number(i)+"]="+QString::number(d.getW(i))+'\n';
        }
    }else
    if(command=="w0"){
        res = "w[-1]="+QString::number(d.getW(-1));
    }
    if(command=="d"){
        res = "d="+QString::number(d.getD());
    }
    return res;
}
QString lOut(Layer &l, QString command){
    QString res = ""; // результат функции
    if(command == "y"){
        for(int i = 0;i<l.getN();i++){
            res += "Нейрон №"+QString::number(i)+"\n";
            res +=  "y = "+QString::number(l.getResult(i))+";\n";
        }
    }else
    if(command == "N"){
        res = "N = "+QString::number(l.getN())+";\n";
    }
    else
    if(command == "K"){
        res = "K = " + QString::number(l.getK())+";\n";
    }else
    if(command == "x"){

        for(int i=0;i<l.getN();i++){
            res += "Нейрон №"+QString::number(i)+"\n";
            for(int j=0;j<l.getK();j++){
            res += "x["+QString::number(j)+"]="+QString::number(l.getNeuronp(i)->getX(j))+'\n';
            }
        }
    }
    else
    if(command=="w"){
        for(int i=0;i<l.getN();i++){
            res += "Нейрон №"+QString::number(i)+"\n";
            for(int j=0;j<l.getK();j++){
            res += "w["+QString::number(j)+"]="+QString::number(l.getNeuronp(i)->getW(j))+'\n';
            }
        }
    }else
    if(command=="w0"){
        for(int i=0;i<l.getN();i++){
            res += "Нейрон №" + QString::number(i)+"\n";
            res += "w[-1]="+QString::number(l.getNeuronp(i)->getW(-1))+'\n';
        }
    }else
        if(command=="d"){
            for(int i=0;i<l.getN();i++){
                res += "Нейрон №" + QString::number(i)+"\n";
                res += "d="+QString::number(l.getNeuronp(i)->getD())+'\n';
            }
        }
    return res;
}

QString vOut(double *t, int n){
    QString res = ""; //строка результат
    for(int i=0;i<n;i++){
        res += "V["+QString::number(i)+"]="+
                QString::number(t[i])+"\n";
    }
    return res;
}

