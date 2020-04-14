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
        color: mouseAreaBack.pressed ? "#cdc1b4" : "#f59563"
        radius: 5
        border.color: "#a6a9d0"
        border.width: 0

        Text {
            id: element
            x: 15
            y: 12
            font.family: "Gotham Ultra"
            text: qsTr("Back")
            font.pixelSize: 22
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
    }

}
