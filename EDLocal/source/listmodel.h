#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QObject>
#include <QSqlQueryModel>
#include <QThread>
#include <qdebug.h>
#include <QSqlQuery>
#include <QSqlError>

class ListModel : public QSqlQueryModel {
    Q_OBJECT
    Q_PROPERTY(int countSelectSystems READ getCountSelectSystems NOTIFY countSelectSystemsChanged)
public:

    enum Roles {
        IdRole = Qt::UserRole + 1,      // id
        NameRole,
        BodyRole,
        DistanceRole,
        xRole,
        yRole,
        zRole,
        allegianceRole,
        govermentRole,
        factionRole,
        factionStateRole,
        populationRole,
        securityRole,
        economyRole,
        typeRole,
        starnameRole
    };

    explicit ListModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:

    QHash<int, QByteArray> roleNames() const;

signals:

   void countSelectSystemsChanged();

public slots:

    int getId(int row);
    int getCountRowVisible();
    int getNumPage();
    int getCountSelectSystems();
    QString getName(int row);

    void setCountRowVisible(int countRow);
    void setNumPage(int PageSelect);
    void setSearchString(QString str);
    void setFilterPrimaryStart(QString str);

    virtual void setSort (int column, Qt::SortOrder order);
    virtual void sort (int column, Qt::SortOrder order);

private slots:

    void updateModel();
    void select();
    void _queryFilters();
    void _countSelectSysytems();

private:

    QString queryClause;
    QString queryFilters;
    QString stringSearch;
    QString filterPrimaryStar;
    int sortKeyColumn = 0;
    int countSelectSystems;
    Qt::SortOrder sortOrder = Qt::SortOrder::AscendingOrder;
    int countRowToVisible = 50;
    int numPage=1;
};

#endif // LISTMODEL_H
