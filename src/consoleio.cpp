#include "consoleio.h"
#include <QTextStream>

void Out(QString s){
    QTextStream out(stdout);
#ifdef Q_OS_WIN
    out.setCodec("CP866");
#endif
    out<<QString::fromUtf8(s.toStdString().c_str())<<flush;
}
QString vectOut(double *t, int n){
    QString res = ""; //строка результат
    for(int i=0;i<n;i++){
        res += "V["+QString::number(i)+"]="+
                QString::number(t[i])+"\n";
    }
    return res;
}
