#include "controlpanel.h"
#include "ui_controlpanel.h"

#include <QStringListModel>
#include <QStringList>
#include <QItemSelectionModel>
#include <QHBoxLayout>
#include <QAbstractItemView>
#include <QModelIndex>
#include <QItemSelectionModel>
ControlPanel::ControlPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControlPanel)
{
    ui->setupUi(this);
    competition=new QVector<Competition*>;
    PSC=new PanelSetingsCompetition(competition,this);
    PR= new PanelRegistration(competition,this);
    
    connect(PSC,SIGNAL(upd()),this,SLOT(updTable1()));

    numberDist=0;
    numberParticipant=0;
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->tableView,SIGNAL(clicked(const QModelIndex&)),this,SLOT(func(const QModelIndex&)));
    connect(ui->tableView_2,SIGNAL(clicked(const QModelIndex&)),this,SLOT(func5(const QModelIndex&)));
    connect(this,SIGNAL(func2(Distance*)),this,SLOT(func3(Distance*)));
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(func6()));

    model=new TableModel(5,this);
    model->setHeader(0,"Соревнования");
    model->setHeader(1,"Дистанция");
    model->setHeader(2,"Класс дистанции");
    model->setHeader(3,"Длина");
    model->setHeader(4,"Дата");

    modelP= new TableModel(6,this);
    modelP->setHeader(0,"Номер");
    modelP->setHeader(1,"ФИО Участников");
    modelP->setHeader(2,"Пол");
    modelP->setHeader(3,"Делигация");
    modelP->setHeader(4,"Теретория");
    modelP->setHeader(5,"Придставитель");

    ui->tableView->setModel(model);
    ui->tableView_2->setModel(modelP);
}

ControlPanel::~ControlPanel()
{
    delete ui;
}

void ControlPanel::func5(const QModelIndex &index)
{
    numberParticipant=index.row();
    ui->tableView_2->selectionModel()->select(ui->tableView_2->model()->index(index.row(),0),QItemSelectionModel::Select);
    ui->tableView_2->selectionModel()->select(ui->tableView_2->model()->index(index.row(),1),QItemSelectionModel::Select);
    ui->tableView_2->selectionModel()->select(ui->tableView_2->model()->index(index.row(),2),QItemSelectionModel::Select);
    ui->tableView_2->selectionModel()->select(ui->tableView_2->model()->index(index.row(),3),QItemSelectionModel::Select);
    ui->tableView_2->selectionModel()->select(ui->tableView_2->model()->index(index.row(),4),QItemSelectionModel::Select);
    ui->tableView_2->selectionModel()->select(ui->tableView_2->model()->index(index.row(),5),QItemSelectionModel::Select);
}

void ControlPanel::func3(Distance *dist)
{
    modelP->clear();
    for(int i=0;i<dist->getParticipantResultSize();i++)
    {
        QVector<QString> str;
        str.push_back(QString::number(dist->getParticipantResult(i)->getNumber()));
        QString str2;
        for(int j=0;j<dist->getParticipantResult(i)->getParticipantSize();j++)
        {
            str2+=dist->getParticipantResult(i)->getParticipant(j)->getFio()+' ';
        }
        str.push_back(str2);
        switch(dist->getParticipantResult(i)->getFlooring())
        {
        case(M):str.push_back("Муж");
            break;
        case(J):str.push_back("Жен");
            break;
        default:str.push_back(" ");
        }
        str.push_back(" ");
        str.push_back(" ");
        str.push_back(" ");
        modelP->addDate(str);
    }
    modelP->signalChanged();
}

void ControlPanel::func(const QModelIndex& index)
{
    ui->tableView->selectionModel()->select(ui->tableView->model()->index(index.row(),0),QItemSelectionModel::Select);
    ui->tableView->selectionModel()->select(ui->tableView->model()->index(index.row(),1),QItemSelectionModel::Select);
    ui->tableView->selectionModel()->select(ui->tableView->model()->index(index.row(),2),QItemSelectionModel::Select);
    ui->tableView->selectionModel()->select(ui->tableView->model()->index(index.row(),3),QItemSelectionModel::Select);
    ui->tableView->selectionModel()->select(ui->tableView->model()->index(index.row(),4),QItemSelectionModel::Select);
    numberDist=index.row();
    int n=index.row();
    for(int i=0;i<competition->size();i++)
    {
        if(n>=competition[0][i]->getSizeDisttance())
        {
            n-=competition[0][i]->getSizeDisttance();
        }
        else
        {
            emit func2(competition[0][i]->getDistance(n));
            break;
        }
    }
}

void ControlPanel::addCompetition(Competition* add)
{
     competition->push_back(add);
     updTable1();
}
void ControlPanel::updTable1()
{
    qDebug()<<"Обновление таблицы дистанций";
    model->clear();
    for(int j=0;j<competition->size();j++)
    {
     for(int i=0;i<(*competition)[j]->getSizeDisttance();i++)
     {
         QVector<QString> str;
         str.push_back((*competition)[j]->getTitle());
         switch((*competition)[j]->getDistance(i)->getOffset())
         {
         case(LICCKO):
            str.push_back("Личные");
            break;
         case(BUNCH):
            str.push_back("Связки");
            break;
         case(RUPP):
            str.push_back("Група");
            break;
         default:
             str.push_back("");
         }
         str.push_back(QString::number((*competition)[j]->getDistance(i)->getClassDistance()+1));
         switch((*competition)[j]->getDistance(i)->getLong())
         {
            case(LENGTH):
                str.push_back("Короткая");
                break;
            case(SHOR):
                str.push_back("Длиная");
                break;
         default:
             str.push_back("");
         }
         str.push_back((*competition)[j]->getDistance(i)->getDate().toString());
         model->addDate(str);
     }
    }
 }

void ControlPanel::on_pushButton_clicked()
{
    int n=numberDist;
    for(int i=0;i<competition->size();i++)
    {
        if(n>=competition[0][i]->getSizeDisttance())
        {
            n-=competition[0][i]->getSizeDisttance();
        }
        else
        {
            PR->setNumber(i,n);
            break;
        }
    }
    PR->updTable();
    PR->show();
}
void ControlPanel::func6()
{
    PSC->updTree();
    PSC->show();
}

void ControlPanel::func4()
{

}

void ControlPanel::on_action_triggered()
{
    PSC->updTree();
    PSC->show();
}
