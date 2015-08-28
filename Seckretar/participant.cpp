#include "participant.h"

Participant::Participant(QObject *parent):QObject(parent)
{

}

Participant::~Participant()
{

}

void Participant::setFio(QString _fio)
{
    fio=_fio;
}

void Participant::setDate(QDate _date)
{
    date_of_birth=_date;
}

void Participant::setFlooring(Flooring _flooring)
{
    F=_flooring;
}

void Participant::setSportsCategory(SportsCategory _sc)
{
    SC=_sc;

}

QString Participant::getFio()
{
    return fio;
}

QDate Participant::getDate()
{
    return date_of_birth;
}

Flooring Participant::getFlooring()
{
    return F;
}

SportsCategory Participant::getSportsCategory()
{
    return SC;
}


//################################

ParticipantResult::ParticipantResult(QObject *parent):QObject(parent)
{

}

ParticipantResult::~ParticipantResult()
{

}

void ParticipantResult::addParticipant(Participant* addparticipant)
{
    participant.push_back(addparticipant);
}

Participant* ParticipantResult::getParticipant(int i)
{
    return participant[i];
}
int ParticipantResult::getParticipantSize()
{
    return participant.size();
}

void ParticipantResult::setNumber(int n)
{
    number=n;

}

void ParticipantResult::setIdCard(int ic)
{
    idCard=ic;
}

void ParticipantResult::setOffset(Offset o)
{
    offset=o;
}

void ParticipantResult::setFlooring(Flooring f)
{
    flooring=f;
}

void ParticipantResult::setTimeStart(QTime s)
{
    timeStert=s;
}

void ParticipantResult::setTimeEnd(QTime e)
{
    timeEnd=e;
}

int ParticipantResult::getNumber()
{
    return number;
}

int ParticipantResult::getIdCard()
{
    return idCard;
}

Offset ParticipantResult::getOffset()
{
    return offset;
}

Flooring ParticipantResult::getFlooring()
{
    return flooring;
}

QTime ParticipantResult::getTimeStart()
{
    return timeStert;
}

QTime ParticipantResult::getTimeEnd()
{
    return timeEnd;
}

void ParticipantResult::setFineSize(int s)
{
    for(int i=fine.size();i<s;i++)
    {
        fine.push_back(Fine());
    }
}

int ParticipantResult::getFineSize()
{
    return fine.size();
}

void ParticipantResult::setFineValue(int i,Fine f)
{
    fine[i]=f;
}

void ParticipantResult::setDelegation(QString _delegation)
{
    delegation=_delegation;
}

void ParticipantResult::setTerritory(QString _territory)
{
    territory=_territory;
}

void ParticipantResult::setRepresentative(QString _fio)
{
    representative=_fio;
}
QString ParticipantResult::getDelegation()
{
    return delegation;
}

QString ParticipantResult::getTerritory()
{
    return territory;
}

QString ParticipantResult::getRepresentative()
{
    return representative;
}
