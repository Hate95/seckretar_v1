#include "competition.h"

Competition::Competition(QObject *parent):
    QObject(parent)
{

}

void Competition::addDistance(Distance* d)
{
    distance.push_back(d);
}

void Competition::delDistance(int i)
{
}

Distance* Competition::getDistance(int i)
{
    return distance[i];
}

int Competition::getSizeDisttance()
{
    return distance.size();
}

void Competition::setConductive(QString c)
{
    conductive=c;
}

void Competition::setTitle(QString t)
{
    title=t;

}

void Competition::setLocation(QString l)
{
    location=l;
}

void Competition::setMainJudge(QString mj)
{
    mainJudge=mj;
}

void Competition::setChiefSecretary(QString cs)
{
    chiefSecretary=cs;
}

void Competition::setDateStart(QDate start)
{
    dateStart=start;
}

void Competition::setDateEnd(QDate end)
{
    dateEnd=end;
}

QString Competition::getConductive()
{
    return conductive;

}

QString Competition::getTitle()
{
    return title;
}

QString Competition::getLocation()
{
    return location;
}

QString Competition::getMainJudge()
{
    return mainJudge;
}

QString Competition::getChiefSecretary()
{
    return chiefSecretary;
}

QDate Competition::getDateStart()
{
    return dateStart;
}

QDate Competition::getDateEnd()
{
    return dateEnd;
}
