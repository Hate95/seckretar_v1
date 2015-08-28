#include "distance.h"

Distance::Distance(QObject *parent):
    QObject(parent)
{
    base=new QVector<ParticipantResult*>;
}


void Distance::setDate(QDate d)
{
    date=d;
}

void Distance::setLong(LongDistance ld)
{
    Long=ld;
}

void Distance::setLong(int ld)
{
    switch(ld)
    {
    case(0):
        Long=LENGTH;
        break;
    case(1):
        Long=SHOR;
        break;
    }
}

void Distance::setClassDistance(ClassDistance cd)
{
    classDistance=cd;
}
void Distance::setClassDistance(int cd)
{
    switch(cd)
    {
    case(0):
        classDistance=I_class;
        break;
    case(1):
        classDistance=II_class;
        break;
    case(2):
        classDistance=III_class;
        break;
    case(3):
        classDistance=IV_class;
        break;
    case(4):
        classDistance=V_class;
        break;
    case(5):
        classDistance=VI_class;
        break;

    }
}

void Distance::setOffset(Offset o)
{
    offset=o;
}

void Distance::setOffset(int o)
{
    switch(o)
    {
    case(0):
        offset=LICCKO;
        break;
    case(1):
        offset=BUNCH;
        break;
    case(2):
        offset=RUPP;
    }
}

void Distance::setDlina(int d)
{
    dlina=d;
}

void Distance::setNaborVsot(int nv)
{
    naborVsot=nv;
}

QDate Distance::getDate()
{
    return date;
}

LongDistance Distance::getLong()
{
    return Long;
}

ClassDistance Distance::getClassDistance()
{
    return classDistance;
}

Offset Distance::getOffset()
{
    return offset;
}

int Distance::getDlina()
{
    return dlina;
}

int Distance::getNaborVsot()
{
    return naborVsot;
}

void Distance::addAtap(QString a)
{
    Atap.push_back(a);
}

QString Distance::getAtap(int i)
{
    return Atap[i];
}

void Distance::updAtap(int i,QString a)
{
    Atap[i]=a;
}

int Distance::getAtapSize()
{
    return Atap.size();
}

void Distance::addParticipantResult(ParticipantResult* pr)
{
    base->push_back(pr);
}

ParticipantResult* Distance::getParticipantResult(int i)
{
    return base[0][i];
}

int Distance::getParticipantResultSize()
{
    return base->size();
}
