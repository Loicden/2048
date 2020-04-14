import QtQuick 2.0

Item {
    width: 90
    height: 90
    property alias elementText: element.text // Permet d'avoir accès au texte (valeur des cases)
    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 90
        height: 90
        color: vueObjetCpt.color(elementText)
        radius: 0
        border.width: 4
        border.color: "#bbada0"

        Text {
            id: element
            x: 23
            y: 23
            width: 44
            color: vueObjetCpt.colortext(elementText)
            text: qsTr("0")
            font.family: "Verdana"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 35
        }
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
