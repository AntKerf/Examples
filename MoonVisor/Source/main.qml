import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import Telescope 1.0

Window {
    visible: true
    width: 650
    height: 480
    title: qsTr("MoonVisor")
    Telescope
    {
        id:teles
        apperture: 1
        focusT: 1
        focusO: 1
        onFocusOChanged: computeOptZoom()
        onFocusTChanged: computeOptZoom()
        onAppertureChanged: computeExEye()
        onOptZoomChanged: computeExEye()
    }
Rectangle
{
    id:mr
    width: 200
    height: parent.height
    x:parent.width-width
    y:0
    color: "grey"
    Text{
        x:25
        y:5
        text: "Апертура (мм)"
        font.pixelSize: 12
    }
    TextField {
        id: appertura
        x: 25
        y: 25
        width: 150
        height: 25
        text: "1"
        font.pixelSize: 12
        background:Rectangle{
            width: parent.width
            height: parent.height
            anchors.verticalCenter: parent.verticalCenter
            radius:5}
        onTextEdited: teles.apperture=text
    }
    Text{
        x:25
        y:55
        text: "Фокусное расстояние(mm)"
        font.pixelSize: 12
    }
    TextField {
        id: fteles
        x: 25
        y: 75
        width: 150
        height: 25
        text:"1"
        font.pixelSize: 12
        background:Rectangle{
            width: parent.width
            height: parent.height
            anchors.verticalCenter: parent.verticalCenter
            radius:5}
        onTextEdited: teles.focusT=text
    }
    Text{
        x:25
        y:105
        text: "Ф. растояние окуляра(mm)"
        font.pixelSize: 12
    }
    TextField {
        id: fokul
        x: 25
        y: 125
        width: 150
        height: 25
        text:"1"
        font.pixelSize: 12
        background:Rectangle{
            width: parent.width
            height: parent.height
            anchors.verticalCenter: parent.verticalCenter
            radius:5}
        onTextEdited: teles.focusO = text
    }
    Button{
        id:accept
        text:"Применить"
        width: 100
        height: 20
        x:50
        y:155
        background: Rectangle{
            radius: 5
            color: parent.pressed ? "grey" : parent.hovered ? "#20B2AA" : "white"}
        onClicked: teles.computeOptZoom()

    }
    TextInput{
    text:"Увеличение(крат): "+teles.optZoom
    horizontalAlignment: Text.AlignLeft
    id: zoom
    x: 25
    y: 180
    width: 150
    height: 20
    font.pixelSize: 12
    }
    TextInput{
    text:"Выходной зрачок(мм): "+teles.exEye
    horizontalAlignment: Text.AlignLeft
    id: exeye
    x: 25
    y: 210
    width: 150
    height: 20
    font.pixelSize: 12
    }
}
Rectangle{
    x:0
    y:0
    z:-1
    width: parent.width-200
    height: parent.height
    color: "black"
            Image {
                id: image
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                width: 75+(75*teles.optZoom/4)
                mipmap: true
                fillMode: Image.PreserveAspectFit
                source: "qrc:/Moon.jpg"
            }
    }
}
