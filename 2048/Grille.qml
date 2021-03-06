import QtQuick 2.0

// Damier sur lequel on va positionner les cases

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
        color: "#bbada0"

        // Petits rectangles pour le style (motifs du damier)
        Rectangle {
            id: rectangle1
            x: 0
            y: 0
            width: 80
            height: 80
            color: "#ffffff"
        }

        Rectangle {
            id: rectangle2
            x: 180
            y: 0
            width: 90
            height: 90
            color: "#ffffff"
        }

        Rectangle {
            id: rectangle3
            x: 270
            y: 270
            width: 90
            height: 90
            color: "#ffffff"
        }

        Rectangle {
            id: rectangle4
            x: 0
            y: 180
            width: 90
            height: 90
            color: "#ffffff"
        }

        Rectangle {
            id: rectangle5
            x: 90
            y: 270
            width: 90
            height: 90
            color: "#ffffff"
        }

        Rectangle {
            id: rectangle6
            x: 90
            y: 90
            width: 90
            height: 90
            color: "#ffffff"
        }

        Rectangle {
            id: rectangle7
            x: 270
            y: 90
            width: 90
            height: 90
            color: "#ffffff"
        }

        Rectangle {
            id: rectangle8
            x: 180
            y: 180
            width: 90
            height: 90
            color: "#ffffff"
        }
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
