#ifndef PANELSETINGSCOMPETITION_H
#define PANELSETINGSCOMPETITION_H

#include <QDebug>
#include <QTextEdit>
#include <QMainWindow>
#include <QVector>
#include <QStandardItemModel>
#include <QAbstractItemModel>
#include <QModelIndex>
#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>
#include <QDateEdit>
#include <QComboBox>
#include <QMenu>
#include "competition.h"
#include "mymodel.h"
namespace Ui {
class PanelSetingsCompetition;
}

class PanelSetingsCompetition : public QMainWindow
{
    Q_OBJECT

public:
    explicit PanelSetingsCompetition(QVector<Competition*>* _c, QWidget *parent = 0);
    ~PanelSetingsCompetition();

    void addCompetition();
public slots:
    void updTree();
    void func(int id);

signals:
    void signalsAddCompetition();
    void upd();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PanelSetingsCompetition *ui;
    QVector<Competition*>* competition;
    QStandardItemModel* model;
};

#endif // PANELSETINGSCOMPETITION_H
