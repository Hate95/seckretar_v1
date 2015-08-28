#ifndef COMPETITION_H
#define COMPETITION_H
#include <QObject>
#include <qobject.h>
#include <QVector>
#include <QString>
#include "distance.h"
#include <QDate>
/**
 * Соревнование
 */
class Competition:public QObject
{
    Q_OBJECT
public:
    Competition(QObject* parent=0);

    void addDistance(Distance* d);
    void delDistance(int i);
    Distance *getDistance(int i);
    int getSizeDisttance();
public slots:
    void setConductive(QString c);
    void setTitle(QString t);
    void setLocation(QString l);
    void setMainJudge(QString mj);
    void setChiefSecretary(QString cs);
    void setDateStart(QDate start);
    void setDateEnd(QDate end);
public:
    QString getConductive();
    QString getTitle();
    QString getLocation();
    QString getMainJudge();
    QString getChiefSecretary();
    QDate getDateStart();
    QDate getDateEnd();

private:
    TypeCompetition type;

    ///Проводящие организации
    QString conductive;
    ///Названия соревнований
    QString title;
    ///место проведения
    QString location;
    ///дистанции
    QVector<Distance*> distance;
    ///Гл. Судья
    QString mainJudge;
    ///Гл. Секретарь
    QString chiefSecretary;
    ///дата начала
    QDate dateStart;
    ///дата окончения
    QDate dateEnd;
};

#endif // COMPETITION_H
