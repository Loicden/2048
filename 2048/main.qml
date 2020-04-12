import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: window
    visible: true
    width: 400
    height: 535
    title: "Jeu du 2048"
    property alias elementText: element.text
    property alias tuile1ElementText: tuile1.elementText

    Keys.onPressed: {           // Nouvelle partie quand on appuie sur R (reset)
        switch (event.key) {
        case Qt.Key_R:
            Grille2048.newgame();
            new Grille2048.NewGame();
            break;
        }
    }

    Grille {
        id: grille
        x: 20
        y: 80
    }

    Tuile {
        id: tuile1
        x: 20
        y: 80
        elementText: qsTr("2")
        //elementText: qsTr(CasesN[0][0].GetValeur())
        visible: true

    }

    Tuile {
        id: tuile2
        x: 110
        y: 80
        elementText: qsTr("2")
    }


    Tuile {
        id: tuile3
        x: 200
        y: 80
        elementText: qsTr("2")
    }

    Tuile {
        id: tuile4
        x: 290
        y: 80
        elementText: qsTr("2")
    }



    Tuile {
        id: tuile5
        x: 20
        y: 170
        elementText: qsTr("2")
    }

    Tuile {
        id: tuile6
        x: 110
        y: 170
        elementText: qsTr("2")
    }

    Tuile {
        id: tuile7
        x: 200
        y: 170
        elementText: qsTr("2")
    }

    Tuile {
        id: tuile8
        x: 290
        y: 170
        elementText: qsTr("2")
    }

    Tuile {
        id: tuile9
        x: 20
        y: 260
        elementText: qsTr("2")
    }

    Tuile {
        id: tuile10
        x: 110
        y: 260
        elementText: qsTr("2")
    }

    Tuile {
        id: tuile11
        x: 200
        y: 260
        elementText: qsTr("2")
    }

    Tuile {
        id: tuile12
        x: 290
        y: 260
        elementText: qsTr("2")
    }

    Tuile {
        id: tuile13
        x: 20
        y: 350
        elementText: qsTr("2")
    }

    Tuile {
        id: tuile14
        x: 110
        y: 350
        elementText: qsTr("2")
    }

    Tuile {
        id: tuile15
        x: 200
        y: 350
        elementText: qsTr("2")
    }

    Tuile {
        id: tuile16
        x: 290
        y: 350
        elementText: qsTr("2")
    }

    Text {
        id: textscore
        x: 110
        y: 23
        text: qsTr("Score :")
        font.pixelSize: 30
    }

    Text {
        id: element
        x: 247
        y: 23
        text: qsTr("0")
        font.pixelSize: 30
    }

    NewGame {
        id: newGame
        x: 125
        y: 463
        focus: true

        MouseArea {
            id: mouseArea
            x: 0
            y: 0
            width: 150
            height: 50
            onClicked: new Grille2048.NewGame()
        }
    }

    Keys.onPressed: {
        switch (event.key) {
        case Qt.Key_Left:
            new Grille2046.Coup(1);
            break;
        case Qt.Key_Right:
            new Grille2046.Coup(2);
            break;
        case Qt.Key_Up:
            new Grille2046.Coup(3);
            break;
        case Qt.Key_Down:
            new Grille2046.Coup(4);
            break;
        }
    }
}
