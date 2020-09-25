import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.2

Rectangle {
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.bottom: navigation.top
    anchors.top:parent.top
    color: "transparent"

    TextField{
        id:textsearch
        anchors.margins: 5
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        placeholderText: "Поиск по id, name"
        width: 150
        height: 30
        background: StyleBackground{}
        onTextChanged: myModel.setSearchString(textsearch.text)
    }

    Button {
        id: btnfilters
        anchors.margins: 5
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        text: qsTr("Фильтр")
        background: StyleBackground{}
        height: 30
        width: 100
        onClicked: winfilter.show()

    }
    Button {
        id: btnsettinftable
        anchors.margins: 5
        anchors.left: btnfilters.right
        anchors.verticalCenter: parent.verticalCenter
        text: qsTr("Настройка таблицы")
        background: StyleBackground{}
        height: 30
        width: 100
        onClicked: {winsettingtable.show();}

    }
    ApplicationWindow{
        id:winfilter
        width: 300
        height: 200
        minimumHeight: 200
        minimumWidth: 200
        title: qsTr("Фильтр")
        Rectangle{
            id:primarystarfilterrect
            anchors.left: parent.left
            anchors.top: parent.top
            width: parent.width
            height: 40
            Text{
                id:tfstar
                anchors.margins: 5
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                text: "Класс звезды"
            }
            ComboBox {
                id: fstar
                width: 150
                height: 30
                anchors.margins: 5
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: tfstar.right
                wheelEnabled: true
                editable: false
                background: StyleBackground{}
                model: ListModel {
                    id: fstars
                    ListElement { text: "";}
                    ListElement { text: "O (Blue-White) Star";}
                    ListElement { text: "B (Blue-White) Star";}
                    ListElement { text: "A (Blue-White) Star";}
                    ListElement { text: "F (White) Star";}
                    ListElement { text: "G (White-Yellow) Star";}
                    ListElement { text: "K (Yellow-Orange) Star";}
                    ListElement { text: "K (Yellow-Orange giant) Star";}
                    ListElement { text: "M (Red dwarf) Star";}
                    ListElement { text: "M (Red giant) Star";}
                    ListElement { text: "T (Brown dwarf) Star";}
                    ListElement { text: "T Tauri Star";}
                    ListElement { text: "Y (Brown dwarf) Star";}
                    ListElement { text: "L (Brown dwarf) Star";}
                    ListElement { text: "White Dwarf";}
                    ListElement { text: "Wolf-Rayet Star";}
                }
                onCurrentTextChanged: {myModel.setFilterPrimaryStar(fstar.currentText);navigation.update()}
            }
        }

        Rectangle{
            id:allegiancefilterrect
            anchors.left: parent.left
            anchors.top: primarystarfilterrect.bottom
            width: parent.width
            height: 40
            Text{
                id:talleg
                anchors.margins: 5
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                text: "Принадлежность системы"
            }
            ComboBox {
                id: fallegiance
                width: 150
                height: 30
                anchors.margins: 5
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: talleg.right
                wheelEnabled: true
                editable: false
                background: StyleBackground{}
                model: ListModel {
                    id: falleg
                    ListElement { text: "";}
                    ListElement { text: "Alliance";}
                    ListElement { text: "Empire";}
                    ListElement { text: "Federation";}
                    ListElement { text: "Independent";}
                    ListElement { text: "Pilots Federation";}
                }
                onCurrentTextChanged: {myModel.setFilterAllegiance(fallegiance.currentText);navigation.update()}
            }
        }
    }
    ApplicationWindow{
        id:winsettingtable
        width: 300
        height: 200
        minimumHeight: 200
        minimumWidth: 200
        title: qsTr("Настройка таблицы")

        Switch{
            id:switchid
            text: qsTr("ID")
            anchors.margins: 5
            anchors.top: parent.top
            anchors.left: parent.left
            position: 0.0
            checked: false
            width: 170
            indicator: StyleIndicator{}
            onPositionChanged: {
                for(var i =0; i<tableView.columnCount;i++)
                {
                    if(tableView.getColumn(i).title === qsTr("ID"))
                        tableView.getColumn(i).visible=position
                }
            }
        }
        Switch{
            id:switchname
            text: qsTr("Название")
            anchors.margins: 5
            anchors.top: switchid.bottom
            anchors.left: parent.left
            position: 1.0
            checked: true
            width: 170
            indicator: StyleIndicator{}
            onPositionChanged: {
                for(var i =0; i<tableView.columnCount;i++)
                {
                    if(tableView.getColumn(i).title === qsTr("Название"))
                        tableView.getColumn(i).visible=position
                }
            }
        }
        Switch{
            id:switchbodysc
            text: qsTr("Кол-во тел")
            anchors.margins: 5
            anchors.top: switchname.bottom
            anchors.left: parent.left
            position: 0.0
            checked: false
            width: 170
            indicator: StyleIndicator{}
            onPositionChanged: {
                for(var i =0; i<tableView.columnCount;i++)
                {
                    if(tableView.getColumn(i).title === qsTr("Кол-во тел"))
                        tableView.getColumn(i).visible=position
                }
            }
        }
        Switch{
            id:switchdistance
            text: qsTr("Дистанция")
            anchors.margins: 5
            anchors.top: switchbodysc.bottom
            anchors.left: parent.left
            position: 1.0
            checked: true
            width: 170
            indicator: StyleIndicator{}
            onPositionChanged: {
                for(var i =0; i<tableView.columnCount;i++)
                {
                    if(tableView.getColumn(i).title === qsTr("Дистанция"))
                        tableView.getColumn(i).visible=position
                }
            }
        }
        Switch{
            id:switchcoords
            text: qsTr("Координаты")
            anchors.margins: 5
            anchors.top: parent.top
            width: 170
            anchors.right: parent.right
            position: 0.0
            checked: false
            indicator: StyleIndicator{}
            onPositionChanged: {
                for(var i =0; i<tableView.columnCount;i++)
                {
                    if(tableView.getColumn(i).title === qsTr("x"))
                        tableView.getColumn(i).visible=position
                    if(tableView.getColumn(i).title === qsTr("y"))
                        tableView.getColumn(i).visible=position
                    if(tableView.getColumn(i).title === qsTr("z"))
                        tableView.getColumn(i).visible=position
                }
            }
        }
        Switch{
            id:switinfo
            text: qsTr("Информация")
            anchors.margins: 5
            width: 170
            anchors.top: switchcoords.bottom
            anchors.right: parent.right
            position: 0.0
            checked: false
            indicator: StyleIndicator{}
            onPositionChanged: {
                for(var i =0; i<tableView.columnCount;i++)
                {
                    if(tableView.getColumn(i).title === qsTr("Принадлежность"))
                        tableView.getColumn(i).visible=position
                    if(tableView.getColumn(i).title === qsTr("Правление"))
                        tableView.getColumn(i).visible=position
                    if(tableView.getColumn(i).title === qsTr("Фракция"))
                        tableView.getColumn(i).visible=position
                    if(tableView.getColumn(i).title === qsTr("Статус фракции"))
                        tableView.getColumn(i).visible=position
                    if(tableView.getColumn(i).title === qsTr("Население"))
                        tableView.getColumn(i).visible=position
                    if(tableView.getColumn(i).title === qsTr("Безопастность"))
                        tableView.getColumn(i).visible=position
                    if(tableView.getColumn(i).title === qsTr("Экономика"))
                        tableView.getColumn(i).visible=position
                }
            }
        }
        Switch{
            id:switchprimstartype
            text: qsTr("Тип главной звезды")
            anchors.margins: 5
            width: 170
            anchors.top: switinfo.bottom
            anchors.right: parent.right
            position: 1.0
            checked: true
            indicator: StyleIndicator{}
            onPositionChanged: {
                for(var i =0; i<tableView.columnCount;i++)
                {
                    if(tableView.getColumn(i).title === qsTr("Тип звезды"))
                        tableView.getColumn(i).visible=position
                }
            }
        }
        Switch{
            id:switchprimstarname
            text: qsTr("Имя главной звезды")
            anchors.margins: 5
            width: 170
            anchors.top: switchprimstartype.bottom
            anchors.right: parent.right
            position: 1.0
            checked: true
            indicator: StyleIndicator{}
            onPositionChanged: {
                for(var i =0; i<tableView.columnCount;i++)
                {
                    if(tableView.getColumn(i).title === qsTr("Имя звезды"))
                        tableView.getColumn(i).visible=position
                }
            }
        }
    }
}

