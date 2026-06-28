import QtQuick
import QtQuick.Shapes

Item {
    id: root

    width: 430
    height: 80

    property color fillColor: "white"
    property color borderColor: "black"

    property real borderWidth: 1
    property real cornerRadius: 20

    readonly property real tabWidth: root.width / 3
    readonly property real tabHeight: root.height - root.cornerRadius

    Shape {

        anchors.fill: parent

        antialiasing: true

        ShapePath {
            strokeColor: root.borderColor
            strokeWidth: root.borderWidth
            fillColor: root.fillColor

            startX: 0
            startY: root.tabHeight

            // Inicio
            PathLine {
                x: 0
                y: root.cornerRadius
            }

            // Esquina superior izquierda.
            PathQuad {
                x: root.cornerRadius
                y: 0
                controlX: 0
                controlY: 0
            }

            // Largo de la estaña.
            PathLine {
                x: root.tabWidth - root.cornerRadius
                y: 0
            }

            // Esquina superior derecha
            PathQuad {
                x: root.tabWidth
                y: root.cornerRadius
                controlX: root.tabWidth
                controlY: 0
            }

            // ancho pestaña
            PathLine {
                x: root.tabWidth
                y: root.tabHeight - root.cornerRadius
            }

            // Curva de entrada al cuerpo.
            PathQuad {
                x: root.tabWidth + root.cornerRadius
                y: root.tabHeight
                controlX: root.tabWidth
                controlY: root.tabHeight
            }

            // Parte superior del cuerpo.
            PathLine {
                x: root.width - root.cornerRadius
                y: root.tabHeight
            }

            // Esquina superior derecha del cuerpo.
            PathQuad {
                x: root.width
                y: root.tabHeight + root.cornerRadius
                controlX: root.width
                controlY: root.tabHeight
            }

            //Cierre
            PathLine {
                x: 0
                y: root.tabHeight +  root.cornerRadius
            }
        }
    }
}