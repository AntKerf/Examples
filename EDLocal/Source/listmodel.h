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
        FavRole = Qt::UserRole + 1,
        IdRole,
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
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

protected:

    QHash<int, QByteArray> roleNames() const override;

signals:

   void countSelectSystemsChanged();

public slots:

    int getId(int row);
    int getCountRowVisible();
    int getNumPage();
    int getCountSelectSystems();
    QString getName(int row);

    void setOnlyFavorite(bool check);
    void swapFavorite(int row);
    void setCountRowVisible(int countRow);
    void setNumPage(int PageSelect);
    void setSearchString(QString str);
    void setFilterPrimaryStar(QString str);
    void setFilterAllegiance(QString str);

    virtual void setSort (int column, Qt::SortOrder order);
    virtual void sort (int column, Qt::SortOrder order);

private slots:

    void updateModel();
    void select();
    void _queryFilters();
    void _countSelectSysytems();

private:

    bool onlyFavorite = false;
    QString queryClause;
    QString queryFilters;
    QString stringSearch;
    QString filterPrimaryStar;
    QString filterAllegiance;
    int sortKeyColumn = 1;
    int countSelectSystems;
    Qt::SortOrder sortOrder = Qt::SortOrder::AscendingOrder;
    int countRowToVisible = 50;
    int numPage=1;
};

#endif // LISTMODEL_H
