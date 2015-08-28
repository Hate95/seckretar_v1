#ifndef DISTANCE_H
#define DISTANCE_H
#include <QVector>
#include "participant.h"
#include <QObject>
class Distance:public QObject
{
    Q_OBJECT
public:
    Distance(QObject* parent=0);

public slots:
    void setDate(QDate d);
    void setLong(LongDistance ld);
    void setLong(int ld);
    void setClassDistance(ClassDistance cd);
    void setClassDistance(int cd);

    void setOffset(Offset o);
    void setOffset(int o);
    void setDlina(int d);
    void setNaborVsot(int nv);

    void setAtap1(QString str);
    void setAtap2(QString str);
    void setAtap3(QString str);
    void setAtap4(QString str);
    void setAtap5(QString str);
    void setAtap6(QString str);
public:
    QDate getDate();
    LongDistance getLong();
    ClassDistance getClassDistance();
    Offset getOffset();
    int getDlina();
    int getNaborVsot();

    QString getAtap(int i);
    void updAtap(int i,QString a);
    int getAtapSize();

    void addParticipantResult(ParticipantResult* pr);
    ParticipantResult *getParticipantResult(int i);
    int getParticipantResultSize();

    QVector<ParticipantResult*>* getBase()
    {
        return base;
    }

private:
    QDate date;
    LongDistance Long;
    ClassDistance classDistance;//класс дистанции
    Offset offset;//зачет
    int dlina;//длина
    int naborVsot;//набор высоты
    QVector<ParticipantResult*>* base;
    struct Atap_block
    {
        QString atap1;
        QString atap2;
        QString atap3;
        QString atap4;
    };

    struct Ataps
    {
        Atap_block atap_block1;
        Atap_block atap_block2;
        Atap_block atap_block3;
        Atap_block atap_block4;
        Atap_block atap_block5;
        Atap_block atap_block6;
    };
    Ataps ataps;
};


#endif // DISTANCE_H
