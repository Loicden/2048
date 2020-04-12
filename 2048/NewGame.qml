import QtQuick 2.0

Item {
    width: 150
    height: 50
    property alias elementText: element.text // Permet d'avoir accès au texte (Inutile ici car le texte ne change pas)
    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 150
        height: 50
        color: mouseAreaNewGame.pressed ? "#d5d9ea" : "#cdc1b4"
        radius: 5
        border.color: "#a6a9d0"
        border.width: 0

        Text {
            id: element
            x: 17
            y: 12
            font.family : "Gotham Ultra"
            text: qsTr("New Game")
            font.pixelSize: 22
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
    }

}
