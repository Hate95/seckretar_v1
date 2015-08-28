#include "controlpanel.h"
#include <QApplication>
#include <QRegExp>
#include <QString>
int main(int argc, char *argv[])
{
/*
      Competition* c=new Competition;
    c->setTitle("Чемпионат 2015");
    c->setMainJudge("Прилошкевич Григорий Владимирович");
    c->setChiefSecretary("Зарубин Дмитрий Николаевич");
    c->setConductive("МБУ'СДЦ'Созвездие''");
    c->setDateStart(QDate(2015,9,20));
    c->setDateEnd(QDate(2015,9,20));
    c->setLocation("Борский район,село Останкино.");

    Distance* dist=new Distance();
    dist->setClassDistance(II_class);
    dist->setDate(QDate(2015,9,20));
    dist->setDlina(600);
    dist->setNaborVsot(18);
    dist->setLong(LENGTH);
    dist->setOffset(LICCKO);
    dist->addAtap("подем по склону");
    dist->addAtap("перепава по бревну маетником");
    dist->addAtap("навесная переправа");
    dist->addAtap("паралельные перила");
    dist->addAtap("спуск по склону в два приема");

    ParticipantResult* pr=new ParticipantResult;
    Participant* p=new Participant();
    p->setDate(QDate(26,5,1995));
    p->setFio("Зарубин Дмитрий Николаевич");
    p->setFlooring(M);
    p->setSportsCategory(I);
    pr->addParticipant(p);
    pr->setIdCard(10001);
    pr->setFineSize(dist->getAtapSize());
    pr->setNumber(1);
    pr->setOffset(LICCKO);
    dist->addParticipantResult(pr);

    pr=new ParticipantResult;
    p=new Participant();
    p->setDate(QDate(26,5,1995));
    p->setFio("Антонов Михаил");
    p->setFlooring(M);
    p->setSportsCategory(I);
    pr->addParticipant(p);
    pr->setIdCard(10002);
    pr->setFineSize(dist->getAtapSize());
    pr->setNumber(2);
    pr->setOffset(LICCKO);
    dist->addParticipantResult(pr);

    pr=new ParticipantResult;
    p=new Participant();
    p->setDate(QDate(26,5,1995));
    p->setFio("Котов Алексей");
    p->setFlooring(M);
    p->setSportsCategory(I);
    pr->addParticipant(p);
    pr->setIdCard(10003);
    pr->setFineSize(dist->getAtapSize());
    pr->setNumber(3);
    pr->setOffset(LICCKO);
    dist->addParticipantResult(pr);

    pr=new ParticipantResult;
    p=new Participant();
    p->setDate(QDate(26,5,1995));
    p->setFio("Беспавлова Ольга");
    p->setFlooring(J);
    p->setSportsCategory(I);
    pr->addParticipant(p);
    pr->setIdCard(10001);
    pr->setFineSize(dist->getAtapSize());
    pr->setNumber(1);
    pr->setOffset(LICCKO);
    dist->addParticipantResult(pr);

    c->addDistance(dist);

    dist=new Distance();
    dist->setClassDistance(II_class);
    dist->setDate(QDate(2015,9,20));
    dist->setDlina(600);
    dist->setNaborVsot(18);
    dist->setLong(LENGTH);
    dist->setOffset(BUNCH);
    dist->addAtap("подем по склону");
    dist->addAtap("перепава по бревну маетником");
    dist->addAtap("навесная переправа");
    dist->addAtap("паралельные перила");
    dist->addAtap("спуск по склону в два приема");

    pr=new ParticipantResult;
    p=new Participant();
    p->setDate(QDate(26,5,1995));
    p->setFio("Зарубин Дмитрий Николаевич");
    p->setFlooring(M);
    p->setSportsCategory(I);
    pr->addParticipant(p);
    p=new Participant();
    p->setDate(QDate(26,5,1995));
    p->setFio("Антонов Михаил");
    p->setFlooring(M);
    p->setSportsCategory(I);
    pr->addParticipant(p);
    pr->setIdCard(10001);
    pr->setFineSize(dist->getAtapSize());
    pr->setNumber(1);
    pr->setOffset(BUNCH);
    dist->addParticipantResult(pr);

    pr=new ParticipantResult;
    p=new Participant();
    p->setDate(QDate(26,5,1995));
    p->setFio("Котов Алексей");
    p->setFlooring(M);
    p->setSportsCategory(I);
    pr->addParticipant(p);
    p=new Participant();
    p->setDate(QDate(26,5,1995));
    p->setFio("Логинов Евгений");
    p->setFlooring(M);
    p->setSportsCategory(I);
    pr->addParticipant(p);
    pr->setIdCard(10003);
    pr->setFineSize(dist->getAtapSize());
    pr->setNumber(3);
    pr->setOffset(BUNCH);
    dist->addParticipantResult(pr);

    c->addDistance(dist);

//*/
    QApplication a(argc, argv);
    ControlPanel w;

    w.show();

    return a.exec();
}
