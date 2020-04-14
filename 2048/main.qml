import QtQuick 2.2
import QtQuick.Window 2.2

Window {
    id: window
    visible: true
    color: "#ffffff"
    width: 400
    height: 535
    title: qsTr("Jeu du 2048")
    property alias elementText: element.text
    property alias tuile1ElementText: tuile1.elementText






    Grille {
        id: grille

        x: 20
        y: 80
    }

    Tuile {
        id: tuile1
        x: 20
        y: 80
        elementText: vueObjetCpt.case0
        visible: {
            if (0 === 0)
                true
            else
                false
        }

    }

    Tuile {
        id: tuile2
        x: 110
        y: 80
        elementText: vueObjetCpt.case1
    }


    Tuile {
        id: tuile3
        x: 200
        y: 80

        elementText: vueObjetCpt.case2
    }

    Tuile {
        id: tuile4
        x: 290
        y: 80
        elementText: vueObjetCpt.case3
    }



    Tuile {
        id: tuile5
        x: 20
        y: 170
        elementText: vueObjetCpt.case4
    }

    Tuile {
        id: tuile6
        x: 110
        y: 170
        elementText: vueObjetCpt.case5
    }

    Tuile {
        id: tuile7
        x: 200
        y: 170
        elementText: vueObjetCpt.case6
    }

    Tuile {
        id: tuile8
        x: 290
        y: 170
        elementText: vueObjetCpt.case7
    }

    Tuile {
        id: tuile9
        x: 20
        y: 260
        elementText: vueObjetCpt.case8
    }

    Tuile {
        id: tuile10
        x: 110
        y: 260
        elementText: vueObjetCpt.case9
    }

    Tuile {
        id: tuile11
        x: 200
        y: 260
        elementText: vueObjetCpt.case10
    }

    Tuile {
        id: tuile12
        x: 290
        y: 260
        elementText: vueObjetCpt.case11
    }

    Tuile {
        id: tuile13
        x: 20
        y: 350
        elementText: vueObjetCpt.case12
    }

    Tuile {
        id: tuile14
        x: 110
        y: 350
        elementText: vueObjetCpt.case13
    }
    Tuile {
        id: tuile15
        x: 200
        y: 350
        elementText: vueObjetCpt.case14
    }

    Tuile {
        id: tuile16
        x: 290
        y: 350
        elementText: vueObjetCpt.case15

    }

    Text {
        id: textscore
        x: 90
        y: 23
        text: qsTr("Score :")
        font.pixelSize: 30
        font.family: "verdana"
        font.bold: true
    }

    Text {
        id: element
        x: 240
        y: 23
        text: vueObjetCpt.QScore
        font.pixelSize: scorearea.containsMouse ? 34 : 30
        font.family: "Verdana"
        font.bold: true
        color: scorearea.containsMouse ?  '#f59563' : '#000000'


        MouseArea{
            id: scorearea
            hoverEnabled: true
            x:-18
            y:-8
            width: 150
            height: 50

        }
    }

    NewGame {
        id: newGame
        x: 230
        y: 463
        focus: true
        scale:  mouseAreaNewGame.containsMouse ? 1.0 : 0.9

            Keys.onPressed: {
                switch (event.key) {
                case Qt.Key_Left:
                    vueObjetCpt.coup(1);
                    break;
                case Qt.Key_Right:
                    vueObjetCpt.coup(2);
                    break;
                case Qt.Key_Up:
                    vueObjetCpt.coup(3);
                    break;
                case Qt.Key_Down:
                    vueObjetCpt.coup(4);
                    break;

                }
            }

        MouseArea {
            id: mouseAreaNewGame
            x: 0
            y: 0
            width: 150
            height: 50
            hoverEnabled: true
            onClicked:{

                vueObjetCpt.newGame()}
        }
    }

    Back {
        id: back
        x: 20
        y: 463
        focus: true
        scale:  mouseAreaBack.containsMouse ? 1.0 : 0.9

        MouseArea {
            id: mouseAreaBack
            x: 0
            y: 0
            width: 90
            height: 50
            onClicked: vueObjetCpt.back()
            hoverEnabled: true

        }
    }



}

