import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.2

//навигация состоит из кнопок и селектора выбора номера страницы,
//а так же из селектора выбора количества строк для отображения

Rectangle{
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.bottom: tableView.top
    height: 40
    anchors.margins: 5
    color: "transparent"
    //кнопки переключения страниц
    Rectangle{
        visible: countRow.currentIndex<5 ? 1:0
        width: 210
        height: 30
        anchors.verticalCenter: parent.verticalCenter
        Button{
            id:firstpage
            width: 35
            height: 30
            anchors.margins: 5
            anchors.verticalCenter: parent.verticalCenter
            visible: Number(pageselect.text) > 1 ? 1:0
            text: "<<"
            background: StyleBackground{}
            onClicked: {pageselect.text = 1;pageselect.accepted();}
        }
        Button{
            id:prevpage
            width: 30
            height: 30
            anchors.margins: 5
            anchors.left: firstpage.right
            anchors.verticalCenter: parent.verticalCenter
            visible: Number(pageselect.text) > 1 ? 1:0
            text: "<"
            background: StyleBackground{}
            onClicked: {pageselect.text = Number(pageselect.text)-1;pageselect.accepted()}
        }
        TextField{
            id:pageselect
            anchors.margins: 5
            height: 30
            anchors.left: prevpage.visible ? prevpage.right : parent.left
            inputMethodHints:Qt.ImhDigitsOnly
            horizontalAlignment:TextInput.AlignRight
            validator: IntValidator {bottom: 1; top: Number(maxpage.text);}
            maximumLength: 5
            z:1
            width: 50
            text: qsTr((myModel.getNumPage()).toString())
       //     onTextChanged: myModel.setNumPage(Number(pageselect.text))
            background: StyleBackground{}
            onAccepted: myModel.setNumPage(Number(pageselect.text))
        }
        TextField{
            id:maxpage
            readOnly: true
            height: 30
            width: 90
            z:0
            horizontalAlignment:TextInput.AlignRight
            anchors.verticalCenter: parent.verticalCenter
            x:pageselect.x
            anchors.margins: 5
            text:qsTr((Math.ceil(myModel.countSelectSystems/countRow.currentText)).toString())
            background: StyleBackground{color:"orange"}
        }
        Button{
            id:nextpage
            width: 30
            height: 30
            anchors.margins: 5
            anchors.left: maxpage.right
            anchors.verticalCenter: parent.verticalCenter
            visible: Number(pageselect.text) < Number(maxpage.text) ? 1:0
            text: ">"
            background: StyleBackground{}
            onClicked: {pageselect.text = Number(pageselect.text)+1;pageselect.accepted();}
        }
        Button{
            id:lastpage
            width: 35
            height: 30
            anchors.margins: 5
            anchors.left: nextpage.right
            anchors.verticalCenter: parent.verticalCenter
            visible: Number(pageselect.text) < Number(maxpage.text) ? 1:0
            text: ">>"
            background: StyleBackground{}
            onClicked: {
                tableView.sortIndicatorOrder = !tableView.sortIndicatorOrder
                pageselect.text = Number(1);pageselect.accepted()
            }
        }


    }
    // Выбор кол-ва строк для отображения
    ComboBox {
        id: countRow
        width: 80
        height: 30
        anchors.right: parent.right
        wheelEnabled: true
        anchors.verticalCenter: parent.verticalCenter
        editable: false
        background: StyleBackground{}
        model: ListModel {
            id: countEl
            ListElement { text: "50";}
            ListElement { text: "100";}
            ListElement { text: "250";}
            ListElement { text: "500";}
            ListElement { text: "1000";}
            ListElement { text: "Все";}
        }
        onCurrentTextChanged:{
            if(countRow.currentIndex<5){
                myModel.setCountRowVisible(countRow.currentText);}
            else dialogShowAll.open();
        }
    }
    Text{
        id:tcountRow
        anchors.right: countRow.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.margins: 5
        text: "Кол-во строк"
    }
    // Диалог подтверждения загрузки всех записей
    MessageDialog {
        id: dialogShowAll
        title: qsTr("Просмотр всех записей")
        text: qsTr("Вы точно хотите загрузить все записи?\n В случае большого объема"
                   +" данных возможна длительная загрузка и временное зависание программы")
        icon: StandardIcon.Question
        standardButtons: StandardButton.Yes | StandardButton.No

        // При положительном ответе ...
        onYes: {
            dialogconnecting.open()
            myModel.setCountRowVisible(countRow.currentText)
            dialogconnecting.close()
        }
        onNo: {
            countRow.currentIndex = 0
        }
    }
    MessageDialog {
        id: dialogconnecting
        title: qsTr("Загрузка записей")
        text: qsTr("Ожидайте, идет загрузка записей")
        icon: StandardIcon.Warning
    }
}

