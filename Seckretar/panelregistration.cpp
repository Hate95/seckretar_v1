#include "panelregistration.h"
#include "ui_panelregistration.h"

PanelRegistration::PanelRegistration(QVector<Competition *>* _c,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PanelRegistration)
{
    number=0;
    ui->setupUi(this);
    competition=_c;
    model=new TableModel(2,this);
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->tableView,SIGNAL(clicked(QModelIndex)),this,SLOT(func(QModelIndex)));
    connect(this,SIGNAL(func2(int)),this,SLOT(func3(int)));
    model->setHeader(0,"Номер");
    model->setHeader(1,"ФИО участников");

}

PanelRegistration::~PanelRegistration()
{
    delete ui;
}

void PanelRegistration::updTable()
{
    model->clear();
    switch(offset)
    {
    case(LICCKO):
        ui->groupBox->setEnabled(true);
        ui->groupBox_2->setEnabled(false);
        ui->groupBox_3->setEnabled(false);
        ui->groupBox_4->setEnabled(false);
        break;
    case(BUNCH):
        ui->groupBox->setEnabled(true);
        ui->groupBox_2->setEnabled(true);
        ui->groupBox_3->setEnabled(false);
        ui->groupBox_4->setEnabled(false);
        break;
    case(RUPP):
        ui->groupBox->setEnabled(true);
        ui->groupBox_2->setEnabled(true);
        ui->groupBox_3->setEnabled(true);
        ui->groupBox_4->setEnabled(true);
        break;

    }

    for(int i=0;i<(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResultSize();i++)
    {
        QVector<QString> str;
        str.push_back(QString::number((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(i)->getNumber()));
        QString str2="";
        for(int j=0;j<(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(i)->getParticipantSize();j++)
        {
            str2+=(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(i)->getParticipant(j)->getFio()+' ';
        }
        str.push_back(str2);
        model->addDate(str);
    }
}

void PanelRegistration::setNumber(int _c,int _d)
{
    numberCompetition=_c;
    numberDistance=_d;
    offset=(*competition)[_c]->getDistance(_d)->getOffset();
    updTable();
}

void PanelRegistration::func(const QModelIndex& index)
{
    disconnectParticipant(number);
    number=index.row();
    ui->tableView->selectionModel()->select(ui->tableView->model()->index(index.row(),0),QItemSelectionModel::Select);
    ui->tableView->selectionModel()->select(ui->tableView->model()->index(index.row(),1),QItemSelectionModel::Select);
    emit func2(number);
}


void PanelRegistration::disconnectParticipant(int num)
{
    disconnect(ui->number_spinBox,SIGNAL(valueChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num),SLOT(setNumber(int)));
    disconnect(ui->idCard_spinBox,SIGNAL(valueChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num),SLOT(setIdCard(int)));
    disconnect(ui->territory_line,SIGNAL(textChanged(QString)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num),SLOT(setTerritory(QString)));
    disconnect(ui->delegation_line,SIGNAL(textChanged(QString)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num),SLOT(setDelegation(QString)));
    disconnect(ui->representative_line,SIGNAL(textChanged(QString)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num),SLOT(setRepresentative(QString)));

    switch((*competition)[numberCompetition]->getDistance(numberDistance)->getOffset())
    {
    case(LICCKO):
        disconnect(ui->name_1,SIGNAL(textChanged(QString)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setFio(QString)));
        disconnect(ui->date_1,SIGNAL(timeChanged(QTime)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setDate(QDate)));
        disconnect(ui->sportsCategory_1,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setSportsCategory(SportsCategory)));
        disconnect(ui->fluring_1,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setFlooring(Flooring)));
        break;
    case(BUNCH):
        disconnect(ui->name_1,SIGNAL(textChanged(QString)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setFio(QString)));
        disconnect(ui->date_1,SIGNAL(timeChanged(QTime)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setDate(QDate)));
        disconnect(ui->sportsCategory_1,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setSportsCategory(SportsCategory)));
        disconnect(ui->fluring_1,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setFlooring(Flooring)));
        disconnect(ui->name_2,SIGNAL(textChanged(QString)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1),SLOT(setFio(QString)));
        disconnect(ui->date_2,SIGNAL(timeChanged(QTime)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1),SLOT(setDate(QDate)));
        disconnect(ui->sportsCategory_2,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1),SLOT(setSportsCategory(SportsCategory)));
        disconnect(ui->fluring_2,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1),SLOT(setFlooring(Flooring)));
        break;
    case(RUPP):
        disconnect(ui->name_1,SIGNAL(textChanged(QString)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setFio(QString)));
        disconnect(ui->date_1,SIGNAL(timeChanged(QTime)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setDate(QDate)));
        disconnect(ui->sportsCategory_1,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setSportsCategory(SportsCategory)));
        disconnect(ui->fluring_1,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setFlooring(Flooring)));
        disconnect(ui->name_2,SIGNAL(textChanged(QString)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1),SLOT(setFio(QString)));
        disconnect(ui->date_2,SIGNAL(timeChanged(QTime)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1),SLOT(setDate(QDate)));
        disconnect(ui->sportsCategory_2,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1),SLOT(setSportsCategory(SportsCategory)));
        disconnect(ui->fluring_2,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1),SLOT(setFlooring(Flooring)));
        disconnect(ui->name_3,SIGNAL(textChanged(QString)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(2),SLOT(setFio(QString)));
        disconnect(ui->date_3,SIGNAL(timeChanged(QTime)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(2),SLOT(setDate(QDate)));
        disconnect(ui->sportsCategory_3,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(2),SLOT(setSportsCategory(SportsCategory)));
        disconnect(ui->fluring_3,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(2),SLOT(setFlooring(Flooring)));
        disconnect(ui->name_4,SIGNAL(textChanged(QString)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(3),SLOT(setFio(QString)));
        disconnect(ui->date_4,SIGNAL(timeChanged(QTime)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(3),SLOT(setDate(QDate)));
        disconnect(ui->sportsCategory_4,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(3),SLOT(setSportsCategory(SportsCategory)));
        disconnect(ui->fluring_4,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(3),SLOT(setFlooring(Flooring)));
        break;
    }
}

void PanelRegistration::func3(int num)
{
    ui->number_spinBox->setValue((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getNumber());
    ui->idCard_spinBox->setValue((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getIdCard());
    ui->territory_line->setText((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getTerritory());
    ui->delegation_line->setText((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getDelegation());
    ui->representative_line->setText((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getRepresentative());
    connect(ui->number_spinBox,SIGNAL(valueChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num),SLOT(setNumber(int)));
    connect(ui->idCard_spinBox,SIGNAL(valueChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num),SLOT(setIdCard(int)));
    connect(ui->territory_line,SIGNAL(textChanged(QString)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num),SLOT(setTerritory(QString)));
    connect(ui->delegation_line,SIGNAL(textChanged(QString)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num),SLOT(setDelegation(QString)));
    connect(ui->representative_line,SIGNAL(textChanged(QString)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num),SLOT(setRepresentative(QString)));
    switch((*competition)[numberCompetition]->getDistance(numberDistance)->getOffset())
    {
    case(LICCKO):
        ui->name_1->setText((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0)->getFio());
        ui->date_1->setDate((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0)->getDate());
        ui->sportsCategory_1->setCurrentIndex((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0)->getSportsCategory());
        ui->fluring_1->setCurrentIndex((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0)->getFlooring());
        connect(ui->name_1,SIGNAL(textChanged(QString)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setFio(QString)));
        connect(ui->date_1,SIGNAL(timeChanged(QTime)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setDate(QDate)));
        connect(ui->sportsCategory_1,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setSportsCategory(SportsCategory)));
        connect(ui->fluring_1,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setFlooring(Flooring)));
        break;
    case(BUNCH):
        qDebug()<<"sizeP="<<(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipantSize();
        ui->name_1->setText((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0)->getFio());
        ui->date_1->setDate((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0)->getDate());
        ui->sportsCategory_1->setCurrentIndex((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0)->getSportsCategory());
        ui->fluring_1->setCurrentIndex((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0)->getFlooring());

        ui->name_2->setText((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1)->getFio());
        ui->date_2->setDate((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1)->getDate());
        ui->sportsCategory_2->setCurrentIndex((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1)->getSportsCategory());
        ui->fluring_2->setCurrentIndex((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1)->getFlooring());

        connect(ui->name_1,SIGNAL(textChanged(QString)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setFio(QString)));
        connect(ui->date_1,SIGNAL(timeChanged(QTime)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setDate(QDate)));
        connect(ui->sportsCategory_1,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setSportsCategory(SportsCategory)));
        connect(ui->fluring_1,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setFlooring(Flooring)));
        connect(ui->name_2,SIGNAL(textChanged(QString)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1),SLOT(setFio(QString)));
        connect(ui->date_2,SIGNAL(timeChanged(QTime)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1),SLOT(setDate(QDate)));
        connect(ui->sportsCategory_2,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1),SLOT(setSportsCategory(SportsCategory)));
        connect(ui->fluring_2,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1),SLOT(setFlooring(Flooring)));
        break;
    case(RUPP):
        ui->name_1->setText((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0)->getFio());
        ui->date_1->setDate((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0)->getDate());
        ui->sportsCategory_1->setCurrentIndex((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0)->getSportsCategory());
        ui->fluring_1->setCurrentIndex((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0)->getFlooring());

        ui->name_2->setText((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1)->getFio());
        ui->date_2->setDate((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1)->getDate());
        ui->sportsCategory_2->setCurrentIndex((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1)->getSportsCategory());
        ui->fluring_2->setCurrentIndex((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1)->getFlooring());

        ui->name_3->setText((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(2)->getFio());
        ui->date_3->setDate((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(2)->getDate());
        ui->sportsCategory_3->setCurrentIndex((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(2)->getSportsCategory());
        ui->fluring_3->setCurrentIndex((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(2)->getFlooring());

        ui->name_4->setText((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(3)->getFio());
        ui->date_4->setDate((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(3)->getDate());
        ui->sportsCategory_4->setCurrentIndex((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(3)->getSportsCategory());
        ui->fluring_4->setCurrentIndex((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(3)->getFlooring());
        connect(ui->name_1,SIGNAL(textChanged(QString)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setFio(QString)));
        connect(ui->date_1,SIGNAL(timeChanged(QTime)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setDate(QDate)));
        connect(ui->sportsCategory_1,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setSportsCategory(SportsCategory)));
        connect(ui->fluring_1,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(0),SLOT(setFlooring(Flooring)));
        connect(ui->name_2,SIGNAL(textChanged(QString)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1),SLOT(setFio(QString)));
        connect(ui->date_2,SIGNAL(timeChanged(QTime)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1),SLOT(setDate(QDate)));
        connect(ui->sportsCategory_2,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1),SLOT(setSportsCategory(SportsCategory)));
        connect(ui->fluring_2,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(1),SLOT(setFlooring(Flooring)));
        connect(ui->name_3,SIGNAL(textChanged(QString)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(2),SLOT(setFio(QString)));
        connect(ui->date_3,SIGNAL(timeChanged(QTime)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(2),SLOT(setDate(QDate)));
        connect(ui->sportsCategory_3,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(2),SLOT(setSportsCategory(SportsCategory)));
        connect(ui->fluring_3,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(2),SLOT(setFlooring(Flooring)));
        connect(ui->name_4,SIGNAL(textChanged(QString)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(3),SLOT(setFio(QString)));
        connect(ui->date_4,SIGNAL(timeChanged(QTime)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(3),SLOT(setDate(QDate)));
        connect(ui->sportsCategory_4,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(3),SLOT(setSportsCategory(SportsCategory)));
        connect(ui->fluring_4,SIGNAL(currentIndexChanged(int)),(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(num)->getParticipant(3),SLOT(setFlooring(Flooring)));
        break;
    }
}

void PanelRegistration::on_pushButton_clicked()
{
    int num=1;
    if((*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResultSize()!=0)
    {
        num=(*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResult(
                (*competition)[numberCompetition]->getDistance(numberDistance)->getParticipantResultSize()-1)->getNumber()+1;
    }
    ParticipantResult* pr=new ParticipantResult;
    pr->setNumber(num);
    pr->setIdCard(0);
    pr->setOffset((*competition)[numberCompetition]->getDistance(numberDistance)->getOffset());
    Participant* newPart;
    int i=0;
    switch(pr->getOffset())
    {
    case(LICCKO):
        i=1;
        break;
    case(BUNCH):
        i=2;
        break;
    case(RUPP):
        i=4;
        break;
    }

    for(int j=0;j<i;j++)
    {
        newPart=new Participant();
        pr->addParticipant(newPart);
    }
    (*competition)[numberCompetition]->getDistance(numberDistance)->addParticipantResult(pr);
    updTable();
}
