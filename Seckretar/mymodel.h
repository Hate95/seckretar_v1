#ifndef MYMODEL_H
#define MYMODEL_H
#include <QAbstractListModel>
#include <QHash>
#include <QDebug>
#include <QTableView>
#include <QString>
// ======================================================================
class TableModel : public QAbstractTableModel
{
    Q_OBJECT
private:
    int m_nRows;//строки
    int m_nColumns;//столбцы
    QHash<QModelIndex, QVariant> m_hash;
    QVector<QString> header;
public:
// -----------------------------------------------------------------
    TableModel(int _c,QObject* pobj = 0)
        : QAbstractTableModel(pobj)
        , m_nRows(0)
        , m_nColumns(_c)
    {
        for(int i=0;i<_c;i++)
        {
            header.push_back("");
        }

    }
    void clear()
    {
        m_nRows=0;
        m_hash.clear();
    }
    void setHeader(int i,QString str)
    {
     if(m_nColumns>i)
     {
         header[i]=str;
     }
    }

    void addDate(QVector<QString> str)
    {
        if(str.size()==m_nColumns)
        {
            m_nRows++;
            for(int i=0;i<m_nColumns;i++)
            {
                setData(this->index(m_nRows-1, i, QModelIndex()),str[i],Qt::EditRole);
            }
            emit layoutChanged();
        }
    }
    QVariant data(const QModelIndex& index, int nRole) const
    {
        if (!index.isValid())
        {
            return QVariant();
        }

        return (nRole == Qt::DisplayRole || nRole == Qt::EditRole)
            ? m_hash.value(index)
            : QVariant();
    }
// -----------------------------------------------------------------
    bool setData(const QModelIndex& index,
        const QVariant& value,
        int nRole)
    {
        if (index.isValid() && nRole == Qt::EditRole)
        {
            m_hash[index] = value;
            emit dataChanged(index, index);
            return true;
        }
        return false;
    }

    QVariant headerData(int nSection,
        Qt::Orientation orientation,
        int nRole=Qt::DisplayRole
        ) const
    {
        if (nRole != Qt::DisplayRole)
        {
            return QVariant();
        }
        if(orientation == Qt::Horizontal)
        {
            return header[nSection];
        }
        else
        {
            return QString::number(nSection+1);
        }
    }
// -----------------------------------------------------------------
    int rowCount(const QModelIndex&) const
    {
        return m_nRows;
    }
// -----------------------------------------------------------------
    int columnCount(const QModelIndex&) const
    {
        return m_nColumns;
    }
// -----------------------------------------------------------------
    Qt::ItemFlags flags(const QModelIndex& index) const
    {
        Qt::ItemFlags flags = QAbstractTableModel::flags(index);
        return index.isValid() ? (flags | Qt::ItemIsEditable)
            : flags;
    }
    void signalChanged()
    {
        emit layoutChanged();
    }
};

#include <QLabel>
#include <QTextEdit>
#include <QMenu>
#include <QAction>
#include <QContextMenuEvent>
// ======================================================================
class ContextMenu : public QLabel {
Q_OBJECT
private:
QMenu* m_pmnu;
int id;
protected:
virtual void contextMenuEvent(QContextMenuEvent* pe)
{
m_pmnu->exec(pe->globalPos());
}
public:
ContextMenu(int _id,QWidget* pwgt = 0)
: QLabel(pwgt)
{
    id=_id;
//setReadOnly(true);
m_pmnu = new QMenu(this);
m_pmnu->addAction("&Добавить");
connect(m_pmnu,
SIGNAL(triggered(QAction*)),
SLOT(slotActivated(QAction*))
);
}
signals:
void addComp(int _id);
public slots:
void slotActivated(QAction* pAction)
{
    emit addComp(id);
}
};

#endif // MYMODEL_H
