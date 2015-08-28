#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QMainWindow>
#include <QVector>
#include "competition.h"
#include "mymodel.h"
#include "panelregistration.h"
#include "panelsetingscompetition.h"
namespace Ui {
class ControlPanel;
}

class ControlPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit ControlPanel(QWidget *parent = 0);
    ~ControlPanel();
    void addCompetition(Competition* add);
private slots:
    void func(const QModelIndex& index);
    void func3(Distance* dist);
    void func4();
    void func5(const QModelIndex& index);
    void func6();
    void on_pushButton_clicked();
    void updTable1();

    void on_action_triggered();

signals:
    void func2(Distance* dist);
private:
    int numberDist;
    int numberParticipant;
    Ui::ControlPanel *ui;
    TableModel* model;
    TableModel* modelP;
    QVector<Competition*>* competition;

    PanelSetingsCompetition* PSC;
    PanelRegistration* PR;
};

#endif // CONTROLPANEL_H
