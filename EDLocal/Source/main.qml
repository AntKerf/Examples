import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id:mainWin
    visible: true
    width: 680
    height: 480
    minimumHeight: 200
    minimumWidth: 400
    title: qsTr("EDLocal")
    onActiveChanged:{
        if(!database.isConnected()){
            dialogerroedb.open()
        }
    }
    //Фильтры
    Filters{
        id:filters
    }

    // Кнопки навигации
    Navigation{
        id:navigation
    }
    // Таблица с данными
    Table{
        id:tableView
    }

    Menu
    {
        id:contexMenu
        MenuItem {
            text: "Открыть в EDSM"
            onClicked:Qt.openUrlExternally("https://www.edsm.net/en/system/id/"+myModel.getId(tableView.currentRow)+"/name/"+myModel.getName(tableView.currentRow))

        }
        MenuItem { text: "Подробнее"}
    }
    MessageDialog {
        id: dialogerroedb
        title: qsTr("Ошибка базы данных")
        text: qsTr("Не удается открыть базу данных! \n Повторить?")
        icon: StandardIcon.Warning
        standardButtons: StandardButton.Ok | StandardButton.Cancel
        onAccepted: database.openDataBase()
        onRejected: mainWin.close()
    }
}

