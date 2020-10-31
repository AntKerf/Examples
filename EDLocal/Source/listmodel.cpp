#include "listmodel.h"

ListModel::ListModel(QObject *parent) : QSqlQueryModel(parent)
{
    this->select();
    _countSelectSysytems();
}
// Метод для получения данных из модели
QVariant ListModel::data(const QModelIndex & index, int role) const {

    // Определяем номер колонки, адрес так сказать, по номеру роли
    int columnId = role - Qt::UserRole - 1;
    // Создаём индекс с помощью новоиспечённого ID колонки
    QModelIndex modelIndex = this->index(index.row(), columnId);

    /* И с помощью уже метода data() базового класса
     * вытаскиваем данные для таблицы из модели
     * */
    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}
// Метод для получения имен ролей через хешированную таблицу.
QHash<int, QByteArray> ListModel::roleNames() const {
    /* То есть сохраняем в хеш-таблицу названия ролей
     * по их номеру
     * */
    QHash<int, QByteArray> roles;
    roles[IdRole] = "systems.id";
    roles[NameRole] = "systems.name";
    roles[BodyRole] = "bodycount";
    roles[DistanceRole] = "distance";
    roles[xRole] = "x";
    roles[yRole] = "y";
    roles[zRole] = "z";
    roles[allegianceRole]="allegiance";
    roles[govermentRole]="goverment";
    roles[factionRole]="faction";
    roles[factionStateRole]="factionState";
    roles[populationRole]="population";
    roles[securityRole]="security";
    roles[economyRole]="economy";
    roles[typeRole]="type";
    roles[starnameRole]="primarystar.name";
    return roles;
}
// Метод обновления таблицы в модели представления данных
void ListModel::updateModel()
{
    // Обновление производится SQL-запросом к базе данных
    this->setQuery("SELECT systems.id, systems.name, bodycount, distance, x, y,"
                   " z, allegiance, goverment, faction, factionState, population,"
                   " security, economy, type, primarystar.name "
                   "FROM systems "
                   "iNNER JOIN coords ON systems.id = coords.id "
                   "LEFT OUTER JOIN information ON systems.id = information.id "
                   "LEFT OUTER JOIN primarystar ON systems.id = primarystar.id "
                   "LIMIT " + QString::number(numPage-1*countRowToVisible)+", " + QString::number(countRowToVisible));
    _countSelectSysytems();
}

// Получение id из строки в модели представления данных
int ListModel::getId(int row)
{
    return this->data(this->index(row, 0), IdRole).toInt();
}

QString ListModel::getName(int row)
{
    return this->data(this->index(row, 0), NameRole).toString();

}
void ListModel::select() {
    QString query = queryClause;

    if (sortKeyColumn >= 0) {
        QString orderClause;
        orderClause = "ORDER BY " + QString::number(sortKeyColumn + 1) + " " +
                ((sortOrder == Qt::AscendingOrder) ? "ASC" : "DESC");
        query.append("SELECT systems.id, systems.name, bodycount, distance, x, y,"
                     " z, allegiance, goverment, faction, factionState, population,"
                     " security, economy, type, primarystar.name "
                     "FROM systems "
                     "iNNER JOIN coords ON systems.id = coords.id "
                     "LEFT OUTER JOIN information ON systems.id = information.id "
                     "LEFT OUTER  JOIN primarystar ON systems.id = primarystar.id "
                     + queryFilters
                     + orderClause +
                     " LIMIT " + QString::number((numPage-1)*countRowToVisible)+", "+ QString::number(countRowToVisible));
    }
    QSqlQueryModel::setQuery(query);
}
int ListModel::getCountSelectSystems()
{
    return countSelectSystems;
}
void ListModel::_queryFilters()
{
    queryFilters.clear();
    if(stringSearch.size()>0 || filterPrimaryStar.size()>0 || filterAllegiance.size()>0){
        queryFilters.append("WHERE ");
        if(stringSearch.size()>0){
            queryFilters.append(stringSearch);
        }
        if(filterPrimaryStar.size()>0){
            queryFilters.size()>6 ? queryFilters.append(" AND "),queryFilters.append(filterPrimaryStar) : queryFilters.append(filterPrimaryStar);
        }
        if(filterAllegiance.size()>0){
             queryFilters.size()>6 ? queryFilters.append(" AND "),queryFilters.append(filterAllegiance) : queryFilters.append(filterAllegiance);
        }
    }
    qDebug()<< queryFilters;
    select();
    _countSelectSysytems();
}

void ListModel::_countSelectSysytems()
{
    QSqlQuery query;
    int count =0;
    if(queryFilters.size()>0)
    {
        query.prepare("SELECT COUNT(systems.id) FROM systems "
                          "iNNER JOIN coords ON systems.id = coords.id "
                          "LEFT OUTER JOIN information ON systems.id = information.id "
                          "LEFT OUTER  JOIN primarystar ON systems.id = primarystar.id "
                          + queryFilters);
    }
    else{
        query.prepare("SELECT COUNT(systems.id) FROM systems ");
    }
    if(query.exec()){
        while (query.next()) {
            count = query.value(0).toInt();
        }
    }
    countSelectSystems = count;
    emit countSelectSystemsChanged();
}

void ListModel::setCountRowVisible(int countRow)
{
    if(countRow!=countRowToVisible)
    {
        if(countRow>0)
            countRowToVisible=countRow;
        else
            countRowToVisible=2000000;
        select();
    }
}

int ListModel::getCountRowVisible()
{
    return countRowToVisible;
}

int ListModel::getNumPage()
{
    return numPage;
}

void ListModel::setNumPage(int PageSelect)
{
    if(numPage!=PageSelect)
    {
        numPage=PageSelect;
        select();
    }
}

void ListModel::setSearchString(QString str)
{
    stringSearch.clear();
    if (str.size()>0)
    {
        stringSearch.append("(systems.name LIKE ('%"+str+"%') or systems.id LIKE ('%"+str+"%'))");
    }
    _queryFilters();
}

void ListModel::setFilterPrimaryStar(QString str)
{
    filterPrimaryStar.clear();
    if(str.size()>0)
    {
        filterPrimaryStar.append("(primarystar.type LIKE('"+str+"%'))");
    }
    _queryFilters();
}

void ListModel::setFilterAllegiance(QString str)
{
    filterAllegiance.clear();
    if(str.size() > 0)
    {
        filterAllegiance.append("(information.allegiance LIKE('"+str+"%'))");
    }
    _queryFilters();
}

void ListModel::setSort(int column, Qt::SortOrder order) {
    sortKeyColumn = column;
    sortOrder = order;
}

void ListModel::sort(int column, Qt::SortOrder order) {
    if ((sortKeyColumn != column) || (sortOrder != order)) {
        setSort(column, order);
        select();
    }
}
