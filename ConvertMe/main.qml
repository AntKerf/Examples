import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.XmlListModel 2.0

import convert 1.0

Window {
    visible: true
    width: 350
    height: 500
    title: qsTr("ConvertMe")
    maximumHeight: 500
    maximumWidth: 350

    XmlListModel
    {
        id:xmldata
        source: "https://www.cbr-xml-daily.ru/daily_utf8.xml"
        query: "/ValCurs/Valute"
        onSourceChanged: reload();
        XmlRole { name: "Name"; query: "Name/string()" }
        XmlRole { name: "Value"; query: "Value/string()" }
        XmlRole { name: "Nominal"; query: "Nominal/string()" }
    }

    Convert
    {
        id:convert
    }
    Rectangle//ожидание подключения
    {
        width: parent.width
        height: parent.height
        color: "black"
        x:0
        y:0
        z:1
        Text
        {
            text:"Подключение к серверу..."
            color:"orange"
            font.bold: true
            font.pixelSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }
        NumberAnimation on opacity{
            from:1
            to:0
            duration: 2000
            running: xmldata.progress
        }
    }
    ScrollView{//просмотр валют
        clip: true
        id:scroll
        x:0
        y:0
        width: parent.width
        height: 400
        focusPolicy: Qt.TabFocus
        ListView {
            id: listView
            x: 0
            y: 0
            width: parent.width
            orientation: ListView.Vertical
            boundsBehavior: Flickable.StopAtBounds
            keyNavigationWraps: true
            model:xmldata
            delegate: Item {
                x: 0
                width: parent.width
                height: 42
                Row{
                    x:0
                    width: parent.width
                    height: 40
                    Rectangle {
                        width: parent.width*0.75
                        height: 40
                        color: "white"
                        border.color: "black"
                        border.pixelAligned: true
                        activeFocusOnTab: true

                        MouseArea{
                            height: parent.height
                            width: parent.width
                            hoverEnabled: true
                            onEntered:  parent.color="orange"
                            onExited: parent.color="white"

                            acceptedButtons: Qt.LeftButton | Qt.RightButton
                            onClicked:
                            {
                                if( mouse.button & Qt.LeftButton)
                                {
                                    convert.name=Name
                                    convert.nominal=Nominal
                                    convert.kurs=Value
                                }
                                if(mouse.button & Qt.RightButton)
                                {
                                    if(Name != tname1.text )
                                    {
                                        tname1.visible = true
                                        convert.name1=Name
                                        convert.nominal1=Nominal
                                        convert.kurs1=Value
                                        convert.Convert_N_Rf=true
                                        if(convert.mode)convert.calcValue1()
                                        else convert.calcValue()
                                    }
                                    else
                                    {
                                        tname1.visible = false
                                        convert.nominal1=1
                                        convert.kurs1=1
                                        convert.name1=1
                                        convert.Convert_N_Rf=false
                                        if(convert.mode)convert.calcValue1()
                                        else convert.calcValue()
                                    }
                                    parent.focus=true
                                }
                            }
                            Text {
                                text: Name
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.horizontalCenter: parent.horizontalCenter
                            }
                        }
                    }
                    Rectangle {
                        width: parent.width*0.25
                        height: 40
                        color: "white"
                        border.color: "black"
                        Text
                        {
                            text:Nominal+":"+Value
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                        }


                    }

                }

            }
        }
    }

    Rectangle//форма заполнения
    {
        id:ltext
        x:0
        y:400
        height: 100
        width: parent.width
        border.color:"black"
        Text
        {
            id:defnamerf
            anchors.horizontalCenter: parent.horizontalCenter
            y:50
            text:"Рубль РФ"
            visible:!tname1.visible
        }
        Text
        {
            id:tname1
            anchors.horizontalCenter: parent.horizontalCenter
            y:50
            text:convert.name1
            visible: false
        }
        Text
        {
            anchors.horizontalCenter: parent.horizontalCenter
            y:10
            text:convert.name
        }
        TextField
        {
            id:defnom
            validator: DoubleValidator{bottom: -2^63; top:2^63 }
            anchors.horizontalCenter: parent.horizontalCenter
            y:25
            height: 25
            text:convert.value
            //            visible:!tval.visible
            onTextEdited: convert.value = text
        }
        TextField
        {
            id:defvalrf
            validator: DoubleValidator{bottom: -2^63; top:2^63 }
            anchors.horizontalCenter: parent.horizontalCenter
            y:65
            height: 25
            text:convert.value1
            //            visible:!tval1.visible
            onTextEdited: convert.value1 = text
            onFocusChanged: convert.mode=!convert.mode //bool
        }
    }
}
