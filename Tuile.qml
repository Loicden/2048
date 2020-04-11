import QtQuick 2.0

Item {
    Rectangle {
        id: rectangle
        x: 275
        y: 195
        width: 90
        height: 90
        color: "#ffca91"
        radius: 13
        border.width: 2
        border.color: "#ffa33f"

        Text {
            id: element
            x: 23
            y: 21
            width: 44
            text: qsTr("Text")
            font.family: "Verdana"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 40
        }
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
