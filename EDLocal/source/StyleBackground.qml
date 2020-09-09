import QtQuick 2.0

Rectangle{
    radius: 20
    color: parent.down ? "orange" : "#f6f6f6"
    border{
        color: "grey"
        width: 2
    }
}
