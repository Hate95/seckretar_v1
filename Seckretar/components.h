#ifndef COMPONENTS
#define COMPONENTS
#include <QString>
#include <QRegExp>
enum LongDistance{LENGTH,SHOR};//короткая, длиная

enum Offset{LICCKO,BUNCH,RUPP};//личные, связки, група

enum ClassDistance{I_class,II_class,III_class,IV_class,V_class,VI_class};

enum TypeCompetition{CHAMPIONSHIP,PREVENSTVO};//Чемпионат,Первенство

///@enum SportsCategory
/// спортивный разряд
enum SportsCategory{B_R,IIIu,IIu,Iu,III,II,I,KMC,MC};

///@enum Flooring
/// пол
enum Flooring{M,J};

///@struct FIO
/// Фамилия Имя Отчество
struct FIO
{
    QString name;
    QString surname;
    QString patronymic;
    FIO()
    {
    }

    FIO(QString F,QString I,QString O)
    {
        surname=F;
        name=I;
        patronymic=O;
    }
    QString toString()
    {
        return surname+' '+name+' '+patronymic;
    }

    FIO& operator=(QString str)
    {
        FIO res;
        QRegExp rx("([a-zA-Z]+) ([a-zA-Z]+) ([a-zA-Z]+)");
        int pos = 0;
        while ((pos = rx.indexIn(str, pos)) != -1)
        {
            res.name = rx.cap(1);
            pos += rx.matchedLength();
        }
        return res;
    }
};

#endif // COMPONENTS

