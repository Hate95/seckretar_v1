#include "panelsetingscompetition.h"
#include "ui_panelsetingscompetition.h"
#include <QTreeWidget>
PanelSetingsCompetition::PanelSetingsCompetition(QVector<Competition*>* _c,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PanelSetingsCompetition)
{
    ui->setupUi(this);
    competition=_c;
    model=new QStandardItemModel(0,3,this);
    ui->treeWidget->setColumnCount(9);
    ui->treeWidget->setHeaderLabels(QStringList()<<""<<""<<""<<""<<""<<""<<""<<""<<"");
}

void PanelSetingsCompetition::updTree()
{
    QTreeWidgetItem* pItem;
    model->clear();
    ui->treeWidget->clear();
    for(int i=0;i<competition->size();i++)
    {
        QDateEdit* date;
        QLineEdit* line;
        QLabel* str;
        QTreeWidgetItem* ptwItem;
        QCheckBox* check;

        str=new QLabel;
        str->setText(competition[0][i]->getTitle());
        pItem = new QTreeWidgetItem(ui->treeWidget);
        //ui->treeWidget->setItemWidget(pItem,0,new QLabel(competition[0][i]->getTitle()));
        ui->treeWidget->setItemWidget(pItem,0,str);

        ptwItem=new QTreeWidgetItem(pItem);
        ptwItem->setText(1,"Названия Соревнований");
        line=new QLineEdit();
        line->setText(competition[0][i]->getTitle());
        connect(line,SIGNAL(textChanged(QString)),competition[0][i],SLOT(setTitle(QString)));
        connect(line,SIGNAL(textChanged(QString)),str,SLOT(setText(QString)));
        connect(line,SIGNAL(textChanged(QString)),this,SIGNAL(upd()));
        ui->treeWidget->setItemWidget(ptwItem,2,line);

        ptwItem=new QTreeWidgetItem(pItem);
        ptwItem->setText(1, "Проводящия организация");
        line=new QLineEdit();
        line->setText(competition[0][i]->getConductive());
        connect(line,SIGNAL(textChanged(QString)),competition[0][i],SLOT(setConductive(QString)));
        connect(line,SIGNAL(textChanged(QString)),this,SIGNAL(upd()));
        ui->treeWidget->setItemWidget(ptwItem,2,line);


        ptwItem=new QTreeWidgetItem(pItem);
        ptwItem->setText(1, "Место провидения");
        line=new QLineEdit();
        line->setText(competition[0][i]->getLocation());
        connect(line,SIGNAL(textChanged(QString)),competition[0][i],SLOT(setLocation(QString)));
        connect(line,SIGNAL(textChanged(QString)),this,SIGNAL(upd()));
        ui->treeWidget->setItemWidget(ptwItem,2,line);

        ptwItem=new QTreeWidgetItem(pItem);
        ptwItem->setText(1, "Дата начала соревнований");
        date=new QDateEdit;
        date->setDate(competition[0][i]->getDateStart());
        connect(date,SIGNAL(dateChanged(QDate)),competition[0][i],SLOT(setDateStart(QDate)));
        connect(date,SIGNAL(dateChanged(QDate)),this,SIGNAL(upd()));
        ui->treeWidget->setItemWidget(ptwItem,2,date);

        ptwItem=new QTreeWidgetItem(pItem);
        ptwItem->setText(1, "Дата начала соревнований");
        date=new QDateEdit;
        date->setDate(competition[0][i]->getDateEnd());
        connect(date,SIGNAL(dateChanged(QDate)),competition[0][i],SLOT(setDateEnd(QDate)));
        connect(date,SIGNAL(dateChanged(QDate)),this,SIGNAL(upd()));
        ui->treeWidget->setItemWidget(ptwItem,2,date);

        ptwItem=new QTreeWidgetItem(pItem);
        ptwItem->setText(1, "Гл. Судья");
        line=new QLineEdit();
        line->setText(competition[0][i]->getMainJudge());
        connect(line,SIGNAL(textChanged(QString)),competition[0][i],SLOT(setMainJudge(QString)));
        connect(line,SIGNAL(textChanged(QString)),this,SIGNAL(upd()));
        ui->treeWidget->setItemWidget(ptwItem,2,line);

        ptwItem=new QTreeWidgetItem(pItem);
        ptwItem->setText(1, "Гл. Секретарь");
        line=new QLineEdit();
        line->setText( competition[0][i]->getChiefSecretary());
        connect(line,SIGNAL(textChanged(QString)),competition[0][i],SLOT(setChiefSecretary(QString)));
        connect(line,SIGNAL(textChanged(QString)),this,SIGNAL(upd()));

        ui->treeWidget->setItemWidget(ptwItem,2,line);

        ptwItem=new QTreeWidgetItem(pItem);

        ContextMenu* text=new ContextMenu(i);
        text->setText("Дистанции");
        ui->treeWidget->setItemWidget(ptwItem,1,text);
        connect(text,SIGNAL(addComp(int)),this,SLOT(func(int)));


        for(int j=0;j<(*competition)[i]->getSizeDisttance();j++)
        {
            QComboBox* box;
            pItem=new QTreeWidgetItem(ptwItem);
            str=new QLabel;
            str->setText(QString::number(j+1));
            ui->treeWidget->setItemWidget(pItem,2,str);

            QTreeWidgetItem* ptItem=new QTreeWidgetItem(pItem);
            str=new QLabel;
            str->setText("Зачет");
            ui->treeWidget->setItemWidget(ptItem,3,str);
            box=new QComboBox;
            box->addItem("Личный");
            box->addItem("Свзки");
            box->addItem("Группа");
            box->setCurrentIndex((*competition)[i]->getDistance(j)->getOffset());
            connect(box,SIGNAL(currentIndexChanged(int)),(*competition)[i]->getDistance(j),SLOT(setOffset(int)));
            connect(box,SIGNAL(currentIndexChanged(int)),this,SIGNAL(upd()));
            ui->treeWidget->setItemWidget(ptItem,4,box);

            ptItem=new QTreeWidgetItem(pItem);
            str=new QLabel;
            str->setText("Класс");
            ui->treeWidget->setItemWidget(ptItem,3,str);
            box=new QComboBox;
            box->addItem("1");
            box->addItem("2");
            box->addItem("3");
            box->addItem("4");
            box->addItem("5");
            box->addItem("6");
            box->setCurrentIndex((*competition)[i]->getDistance(j)->getClassDistance());
            connect(box,SIGNAL(currentIndexChanged(int)),(*competition)[i]->getDistance(j),SLOT(setClassDistance(int)));
            connect(box,SIGNAL(currentIndexChanged(int)),this,SIGNAL(upd()));

            ui->treeWidget->setItemWidget(ptItem,4,box);

            ptItem=new QTreeWidgetItem(pItem);
            str=new QLabel;
            str->setText("Длина");
            ui->treeWidget->setItemWidget(ptItem,3,str);
            box=new QComboBox;
            box->addItem("Короткая");
            box->addItem("Длиная");
            box->setCurrentIndex((*competition)[i]->getDistance(j)->getLong());
            connect(box,SIGNAL(currentIndexChanged(int)),(*competition)[i]->getDistance(j),SLOT(setLong(int)));
            connect(box,SIGNAL(currentIndexChanged(int)),this,SIGNAL(upd()));
            ui->treeWidget->setItemWidget(ptItem,4,box);
        }
    }
}

void PanelSetingsCompetition::func(int id)
{

    Distance* dist=new Distance(this);
    dist->setClassDistance(I_class);
    dist->setOffset(LICCKO);
    dist->setLong(LENGTH);
    competition[0][id]->addDistance(dist);
    emit upd();
    updTree();
}

PanelSetingsCompetition::~PanelSetingsCompetition()
{
    delete ui;
}

void PanelSetingsCompetition::on_pushButton_clicked()
{
    competition->push_back(new Competition(parent()));
    updTree();
}
