import QtQuick 2.0

Item {
    width: 90
    height: 50
    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 90
        height: 50
        color: "#d5d9ea"
        radius: 13
        border.color: "#a6a9d0"
        border.width: 3

        Text {
            id: element
            x: 14
            y: 8
            text: qsTr("Back")
            font.pixelSize: 30
        }
    }

}
