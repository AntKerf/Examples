import QtQuick 2.0

Rectangle {
    implicitWidth: 48
    implicitHeight: 26
    anchors.verticalCenter: parent.verticalCenter
    radius: 13
    color: parent.checked ? "orange" : "#f6f6f6"
    border{
        color: "grey"
        width: 2
    }
    Behavior on color {
        enabled: !parent.pressed
        ColorAnimation { duration: 200 }
    }

    Rectangle {
        x: parent.parent.checked ? parent.width - width : 0
        width: 26
        height: 26
        radius: 13
        border.color: "black"
        Behavior on x {
            enabled: !parent.pressed
            SmoothedAnimation { velocity: 200 }
        }
    }
}
