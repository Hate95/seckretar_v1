#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include <QDate>
#include <QVector>
#include <QString>
#include <QStringList>
#include "components.h"
#include <QObject>

/**
@class Participant
Участник
**/
class Participant:public QObject
{
    Q_OBJECT
public:
    Participant(QObject* parent=0);
    ~Participant();
public slots:
    void setFio(QString _fio);
    void setDate(QDate _date);
    void setFlooring(Flooring _flooring);
    void setSportsCategory(SportsCategory _sc);
public:
    QString getFio();
    QDate getDate();
    Flooring getFlooring();
    SportsCategory getSportsCategory();
private:
    QString fio;//ФИО
    QDate date_of_birth;//дата рождения
    Flooring F;//пол
    SportsCategory SC;//спортивный разряд
};

class ParticipantResult:public QObject
{
    Q_OBJECT
private:
    struct Fine
    {
        int fine1;//штравные балы(при штрафной системе)
        QString fine2;//сн
    };
public:
    ParticipantResult(QObject* parent=0);
    ~ParticipantResult();

    void addParticipant(Participant* addparticipant);
    Participant *getParticipant(int i);
    int getParticipantSize();
public slots:
    void setNumber(int n);
    void setIdCard(int ic);
    void setOffset(Offset o);
    void setFlooring(Flooring f);
    void setTimeStart(QTime s);
    void setTimeEnd(QTime e);

    void setDelegation(QString _delegation);
    void setTerritory(QString _territory);
    void setRepresentative(QString _fio);

    void setFineSize(int s);
    int getFineSize();
    void setFineValue(int i,Fine f);
public:
    QString getDelegation();
    QString getTerritory();
    QString getRepresentative();

    int getNumber();
    int getIdCard();
    Offset getOffset();
    Flooring getFlooring();
    QTime getTimeStart();
    QTime getTimeEnd();

private:
    int number;
    int idCard;

    QString delegation;//делигация
    QString territory;//теретория
    QString representative;//предстовитель
    Offset offset;
    QVector<Participant*> participant;//участики
    Flooring flooring;//пол
    QTime timeStert;
    QTime timeEnd;
    QVector<Fine> fine;
};

#endif // PARTICIPANT_H
