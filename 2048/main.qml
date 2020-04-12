import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: window
    visible: true
    width: 400
    height: 535
    title: qsTr("Jeu du 2048")
    property alias elementText: element.text
    property alias tuile1ElementText: tuile1.elementText

    Keys.onPressed: {           // Nouvelle partie quand on appuie sur R (reset)
        switch (event.key) {
        case Qt.Key_R:
            new vueObjetCpt.NewGame();
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
        elementText: qsTr("8")
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
        elementText: vueObjetCpt.GrilleQML[1]
    }


    Tuile {
        id: tuile3
        x: 200
        y: 80
        elementText: vueObjetCpt.GrilleQML[2]
    }

    Tuile {
        id: tuile4
        x: 290
        y: 80
        elementText: vueObjetCpt.GrilleQML[3]
    }



    Tuile {
        id: tuile5
        x: 20
        y: 170
        elementText: vueObjetCpt.GrilleQML[4]
    }

    Tuile {
        id: tuile6
        x: 110
        y: 170
        elementText: vueObjetCpt.GrilleQML[5]
    }

    Tuile {
        id: tuile7
        x: 200
        y: 170
        elementText: vueObjetCpt.GrilleQML[6]
    }

    Tuile {
        id: tuile8
        x: 290
        y: 170
        elementText: vueObjetCpt.GrilleQML[7]
    }

    Tuile {
        id: tuile9
        x: 20
        y: 260
        elementText: vueObjetCpt.GrilleQML[8]
    }

    Tuile {
        id: tuile10
        x: 110
        y: 260
        elementText: vueObjetCpt.GrilleQML[9]
    }

    Tuile {
        id: tuile11
        x: 200
        y: 260
        elementText: vueObjetCpt.GrilleQML[10]
    }

    Tuile {
        id: tuile12
        x: 290
        y: 260
        elementText: vueObjetCpt.GrilleQML[11]
    }

    Tuile {
        id: tuile13
        x: 20
        y: 350
        elementText: vueObjetCpt.GrilleQML[12]
    }

    Tuile {
        id: tuile14
        x: 110
        y: 350
        elementText: vueObjetCpt.GrilleQML[13]
    }

    Tuile {
        id: tuile15
        x: 200
        y: 350
        elementText: vueObjetCpt.GrilleQML[14]
    }

    Tuile {
        id: tuile16
        x: 290
        y: 350
        elementText: vueObjetCpt.GrilleQML[15]
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
        text: vueObjetCpt.CcoreQML
        font.pixelSize: 30
    }

    NewGame {
        id: newGame
        x: 230
        y: 463
        focus: true

        MouseArea {
            id: mouseAreaNewGame
            x: 250
            y: 0
            width: 150
            height: 50
            onClicked: new vueObjetCpt.NewGame()
        }
    }

    Back {
        id: back
        x: 20
        y: 463
        focus: true

        MouseArea {
            id: mouseAreaBack
            x: 0
            y: 0
            width: 90
            height: 50
            onClicked: new vueObjetCpt.Back()
        }
    }

    Keys.onPressed: {
        switch (event.key) {
        case Qt.Key_Left:
            new vueObjetCpt.Coup(1);
            break;
        case Qt.Key_Right:
            new vueObjetCpt.Coup(2);
            break;
        case Qt.Key_Up:
            new vueObjetCpt.Coup(3);
            break;
        case Qt.Key_Down:
            new vueObjetCpt.Coup(4);
            break;
        }
    }
}
