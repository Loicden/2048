import QtQuick 2.0

Item {
    width: 360
    height: 360
    // Grand rectangle (support de jeu, damier)
    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 360
        height: 360
        color: "#ffffff"

        // Petits rectangles pour le style (motifs du damier)
        Rectangle {
            id: rectangle1
            x: 0
            y: 0
            width: 90
            height: 90
            color: "#e8e8e8"
        }

        Rectangle {
            id: rectangle2
            x: 180
            y: 0
            width: 90
            height: 90
            color: "#e8e8e8"
        }

        Rectangle {
            id: rectangle3
            x: 270
            y: 270
            width: 90
            height: 90
            color: "#e8e8e8"
        }

        Rectangle {
            id: rectangle4
            x: 0
            y: 180
            width: 90
            height: 90
            color: "#e8e8e8"
        }

        Rectangle {
            id: rectangle5
            x: 90
            y: 270
            width: 90
            height: 90
            color: "#e8e8e8"
        }

        Rectangle {
            id: rectangle6
            x: 90
            y: 90
            width: 90
            height: 90
            color: "#e8e8e8"
        }

        Rectangle {
            id: rectangle7
            x: 270
            y: 90
            width: 90
            height: 90
            color: "#e8e8e8"
        }

        Rectangle {
            id: rectangle8
            x: 180
            y: 180
            width: 90
            height: 90
            color: "#e8e8e8"
        }
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
