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
        color: "#d5d9ea"
        radius: 13
        border.color: "#a6a9d0"
        border.width: 3

        Text {
            id: element
            x: 11
            y: 9
            text: qsTr("New Game")
            font.pixelSize: 27
        }
    }

}
