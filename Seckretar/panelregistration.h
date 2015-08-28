#ifndef PANELREGISTRATION_H
#define PANELREGISTRATION_H

#include <QMainWindow>
#include "components.h"
#include "participant.h"
#include "competition.h"
#include "mymodel.h"
#include <QVector>
namespace Ui {
class PanelRegistration;
}

class PanelRegistration : public QMainWindow
{
    Q_OBJECT

public:
    explicit PanelRegistration(QVector<Competition*> *_c, QWidget *parent = 0);
    ~PanelRegistration();
    void setNumber(int _c, int _d);
public slots:
    void func(const QModelIndex &index);
    void func3(int num);
    void updTable();
    void on_pushButton_clicked();
    void disconnectParticipant(int num);

signals:
    void func2(int num);
private:
    Ui::PanelRegistration *ui;
    QVector<Competition*>* competition;
    TableModel* model;
    int number;
    Offset offset;
    int numberCompetition;
    int numberDistance;
};

#endif // PANELREGISTRATION_H
