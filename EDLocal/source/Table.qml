import QtQuick 2.12
import QtQuick.Controls 1.6

TableView {
    id:tableView
    height: parent.height-100
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.bottom: parent.bottom
    anchors.margins: 5
    onSortIndicatorColumnChanged: myModel.sort(sortIndicatorColumn,sortIndicatorOrder)
    onSortIndicatorOrderChanged: myModel.sort(sortIndicatorColumn,sortIndicatorOrder) 
    sortIndicatorVisible: true


    TableViewColumn {
        width: 80
        role: "systems.id"
        title: "ID"
        visible: false
    }

    TableViewColumn {
        role: "systems.name"
        title: "Название"
    }
    TableViewColumn {
        width: 80
        role: "bodycount"
        title: "Кол-во тел"
        visible: false
    }
    TableViewColumn {
        width: 80
        role: "distance"
        title: "Дистанция"
    }
    TableViewColumn {
        width: 80
        role: "allegiance"
        title: "Принадлежность"
        visible: false
    }
    TableViewColumn {
        width: 80
        role: "goverment"
        title: "Правление"
        visible: false
    }
    TableViewColumn {
        width: 80
        role: "faction"
        title: "Фракция"
        visible: false
    }
    TableViewColumn {
        width: 80
        role: "factionState"
        title: "Статус фракции"
        visible: false
    }
    TableViewColumn {
        width: 80
        role: "population"
        title: "Население"
        visible: false
    }
    TableViewColumn {
        width: 80
        role: "security"
        title: "Безопастность"
        visible: false
    }
    TableViewColumn {
        width: 80
        role: "economy"
        title: "Экономика"
        visible: false
    }
    TableViewColumn{
        width: 80
        title:"x"
        role:"x"
        visible: false
    }
    TableViewColumn{
        width: 80
        title:"y"
        role:"y"
        visible: false
    }
    TableViewColumn{
        width: 80
        title:"z"
        role:"z"
        visible: false
    }
    TableViewColumn {
        width: 80
        role: "type"
        title: "Тип звезды"
    }
    TableViewColumn {
        width: 80
        role: "primarystar.name"
        title: "Имя звезды"
    }

    model: myModel
    // Настройка строки в TableView для перехавата левого клика мыши
    rowDelegate: Rectangle {
        anchors.fill: parent
        color: styleData.selected ? 'skyblue' : (styleData.alternate ? 'whitesmoke' : 'white');
//        Rectangle{
//            visible: styleData.selected ? 1:0
//            color:"whitesmoke"
//            width: mainWin.width-40
//            height: 100
//            y:20
//            z:2
//            border.color: "grey"
//            border.width: 2
//            opacity: 0.9
//        }
        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.RightButton | Qt.LeftButton
            onClicked: {
                switch(mouse.button) {
                case Qt.LeftButton:
                    tableView.selection.clear()
                    if(tableView.currentRow !== styleData.row){
                        tableView.selection.select(styleData.row)
                        tableView.currentRow = styleData.row
                        tableView.focus = true
                        console.log(myModel.rowCount())
                    }
                    else tableView.currentRow = -1
                    break
                case Qt.RightButton:
                    tableView.selection.clear()
                    tableView.selection.select(styleData.row)
                    tableView.currentRow = styleData.row
                    tableView.focus = true
                    contexMenu.popup()
                    break
                default:
                    break
                }
            }
        }
    }
}
