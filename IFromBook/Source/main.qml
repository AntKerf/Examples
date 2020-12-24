import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.3
import QtQuick.Dialogs 1.2
import QtGraphicalEffects 1.0

Window {
    visible: true
    width: 1200
    height: 600
    title: qsTr("FromBook")
    //    Image{
    //        anchors.fill: parent
    //        source: "back.jpg"
    //        fillMode: Image.PreserveAspectCrop
    //    }
    FileDialog {
        id: fdopen
        title: "Выбор файлов для оцифровки"
        folder: shortcuts.pictures
        selectMultiple:true
        nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
        onAccepted: {
            console.log("You chose: " + fdopen.fileUrls)
            var t = fdopen.fileUrls.length
            for(var i =0; i<t; i++)
            {
                files.append({"name":(fdopen.fileUrls[i].toString().split("/").pop()), "path":fdopen.fileUrls[i].toString()})
            }
        }
        onRejected: {
            console.log("Canceled")
        }
    }
    FileDialog {
        id: fdsave
        title: "Выбор папки для сохранения"
        folder: shortcuts.documents
        selectMultiple:false
        nameFilters: [ "All files (*)" ]
        selectExisting:false
        selectFolder: true
        onAccepted: {
            console.log("You chose: " + fdsave.fileUrl)
            tsavedir.text=fdsave.fileUrl.toString().slice(8)
        }
        onRejected: {
            console.log("Canceled")
        }
    }


    Component {
        id: complDelegate

        Item {
            width: grid.cellWidth; height: grid.cellHeight


            MouseArea
            {
                width: parent.width
                height: parent.height
                hoverEnabled: true
                onEntered:{grid.currentIndex=grid.indexAt(parent.x,parent.y);}
                onDoubleClicked: if(mouse.button & Qt.LeftButton) {Qt.openUrlExternally("G:/Documents/Diplom/Test/test.txt")}
                Column {
                    anchors.fill: parent
                    padding: 5

                    Image {
                        width: 100
                        height: 100
                        source:"icon_blot.png"
                        fillMode: Image.PreserveAspectFit
                        anchors.horizontalCenter: parent.horizontalCenter

                    }
                    Text {text: name; width:parent.width; elide:Text.ElideRight ;anchors.horizontalCenter: parent.horizontalCenter; horizontalAlignment: Text.AlignHCenter}

                }
            }
        }
    }
    Component {
        id: contactDelegate

        Item {
            width: gridView.cellWidth; height: gridView.cellHeight


            MouseArea
            {
                width: parent.width
                height: parent.height
                hoverEnabled: true
                acceptedButtons: Qt.LeftButton | Qt.RightButton
                onClicked:{
                    if(mouse.button & Qt.LeftButton) {
                        gridView.currentIndex=gridView.indexAt(parent.x,parent.y);}
                    if(mouse.button & Qt.RightButton) {
                        files.remove(gridView.indexAt(parent.x,parent.y));

                    }}
                onDoubleClicked: if(mouse.button & Qt.LeftButton) {Qt.openUrlExternally(path)}
                Column {
                    anchors.fill: parent
                    padding: 5

                    Image {
                        width: 100
                        height: 100
                        source:path
                        fillMode: Image.PreserveAspectFit
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    Text {text: name;color:"white"; width:100; elide:Text.ElideRight ;anchors.horizontalCenter: parent.horizontalCenter}
                }
            }
        }
    }
    Rectangle//сетка очереди
    {
        // border.color: "green"
        height: parent.height*0.9
        width: parent.width*0.8
        y:0
        color: "#1F1F1F"
        Text
        {
            id:ts
            text: "\t\tДобавьте скан \n (Двойной клик - открыть; ПКМ - удалить)"
            font.family: "Times New Roman"
            font.pointSize: 24
            font.capitalization: Font.MixedCase
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            color: "grey"
            visible: files.count>0 ? 0:1
        }
        GridView {
            id: gridView
            x: 5
            y: 0
            width:parent.width
            height: parent.height
            cacheBuffer: 316
            layoutDirection: Qt.LeftToRight
            flow: GridView.FlowLeftToRight
            antialiasing: true
            contentHeight: 1
            highlightRangeMode: GridView.NoHighlightRange
            flickableDirection: Flickable.AutoFlickDirection
            boundsBehavior: Flickable.StopAtBounds
            cellHeight: 120
            cellWidth: 105
            highlightFollowsCurrentItem: true
            keyNavigationEnabled: true
            focus:true
            highlight: Rectangle { color: "#20B2AA"; radius: 5 }
            delegate:contactDelegate
            model:
                ListModel {
                id:files

            }
        }
    }
    Rectangle{//кнопки
        id:btns
        x:0
        y:parent.height*0.9
        height: parent.height*0.1
        width: parent.width*0.8

        //        border.color: "black"
        //        border.pixelAligned: true
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#90000000" }
        }
        ProgressBar {
            id:bar
            value: 0
            width: parent.width
            y:0
            background: Rectangle {
                implicitWidth: 200
                implicitHeight: 6
                color: "#e6e6e6"
                radius: 3
            }
            contentItem: Item {
                implicitWidth: 200
                implicitHeight: 4
                Rectangle {
                    width: bar.visualPosition * parent.width
                    height: parent.height
                    radius: 2
                    color: "#17a81a"
                }
            }
            Timer {
                id:timer
                interval: 50; running: false; repeat: true
                onTriggered: { bar.value+=0.01;
                    if(bar.value>=1)
                    {
                        timer.stop()
                        bar.value=0
                        console.log(files.get(0).name)
                        var name=files.get(0).name.toString().replace(/.jpg/i,".txt")
                        console.log(name)
                        completed.append({"name":name})
                        files.remove(0)
                        if(files.count>0)  timer.restart()
                    }
                }
            }
        }
        Button{//add
            x: 5
            id:add
            text:"Открыть скан"
            focusPolicy: Qt.TabFocus
            anchors.verticalCenter: parent.verticalCenter
            spacing: 7
            highlighted: true
            y:5
            onClicked:fdopen.open()
            width: 100
            height: 40
            background: Rectangle{
                radius: 5
                color: parent.pressed ? "grey" : parent.hovered ? "#20B2AA" : "#1F1F1F"          // как цвет фона
                //  border.color: parent.hovered ? "white" : "black"     // так и границы
                //  border.width: 2

            }
        }
        Button{//go
            id: control
            x: 110
            text:"Начать оцифровку!"
            focusPolicy: Qt.ClickFocus
            spacing: 7
            anchors.verticalCenter: parent.verticalCenter
            highlighted: true
            y:5
            width: 200
            height: 40
            background: Rectangle{
                radius: 5
                color: parent.pressed ? "grey" : parent.hovered ? "#20B2AA" : "#1F1F1F"           // как цвет фона
                //  border.color: parent.hovered ? "white" : "black"     // так и границы
                //  border.width: 2
            }
            onClicked:{if(files.count>0) timer.start()}
        }

        Button{//save
            id: bsavedir
            x: 315
            text:"Путь сохр."
            focusPolicy: Qt.ClickFocus
            spacing: 7
            highlighted: true
            y:5
            anchors.verticalCenter: parent.verticalCenter
            width: 100
            height: 40
            background: Rectangle{
                radius: 5
                color: parent.pressed ? "grey" : parent.hovered ? "#20B2AA" : "#1F1F1F"           // как цвет фона
                //  border.color: parent.hovered ? "white" : "black"    // так и границы
                //  border.width: 2


            }
            onClicked:fdsave.open()

        }
        TextField//dir
        {
            x:420
            // width: parent.width
            width: 300
            height: 40
            color: "black"
            id:tsavedir
            text:applicationDirPath
            verticalAlignment: Text.AlignVCenter
            cursorVisible: true
            readOnly: false
            font.family: "Times New Roman"
            font.pointSize: 11
            anchors.verticalCenter: parent.verticalCenter
            background:Rectangle{
                width: parent.width
                height: parent.height
                anchors.verticalCenter: parent.verticalCenter
                radius:5
                MouseArea{
                    width: parent.width
                    height: parent.height
                    onDoubleClicked: Qt.openUrlExternally('file:/'+tsavedir.text)}
            }
        }
        Button{//dop
            id: dop
            x:parent.width*0.94
            focusPolicy: Qt.ClickFocus
            spacing: 7
            highlighted: true
            anchors.verticalCenter: parent.verticalCenter
            width: parent.width*0.05
            height: 40
            background: Rectangle{
                radius: 5
                color: "#00000000"
                Image{
                    anchors.fill: parent
                    fillMode: Image.PreserveAspectFit
                    smooth: true
                    source: "icon_menu.png"
                    ColorOverlay {
                        anchors.fill: parent
                        source: parent
                        color: parent.parent.parent.hovered ? "#20B2AA" : "#1F1F1F"
                    }
                }
            }
            Menu {
                id: menu
                width: 250
                MenuItem {
                    text: "Новая книга(В разработке)"
                    enabled: false
                }
                MenuItem {
                    enabled: false
                    SwitchDelegate{
                        anchors.fill: parent
                        text: "Dark theme(в разработке)"

                    }
                }

                MenuItem {
                    text: "Очистить всё"
                    onClicked: {files.clear(); completed.clear(); timer.stop(); bar.value=0;}

                }
            }
            onClicked: menu.open()

        }
    }


    Rectangle//готовые доки
    {
        border.color: "black"
        y:0
        x:parent.width*0.8
        height: parent.height
        width: parent.width*0.2
        gradient: Gradient {
            GradientStop { position: 0.0; color: "grey" }
            GradientStop { position: 1; color: "white" }}
        Text
        {
            id:tc
            text: "Готовые\nдокументы"
            font.family: "Times New Roman"
            font.pointSize: 24
            font.capitalization: Font.MixedCase
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            color: "grey"
            visible: completed.count>0 ? 0:1
        }
        GridView {
            id: grid
            x: 5
            y: 0
            width:parent.width
            height: parent.height
            cacheBuffer: 316
            layoutDirection: Qt.LeftToRight
            flow: GridView.FlowLeftToRight
            antialiasing: true
            contentHeight: 1
            highlightRangeMode: GridView.NoHighlightRange
            flickableDirection: Flickable.AutoFlickDirection
            boundsBehavior: Flickable.StopAtBounds
            cellHeight: 120
            cellWidth: parent.width-10
            highlightFollowsCurrentItem: true
            keyNavigationEnabled: true
            focus:true
            highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
            delegate:complDelegate
            model:
                ListModel {
                id:completed


            }
        }
    }

}
