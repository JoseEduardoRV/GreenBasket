import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic

import "../../controls"

Item {
    id: root

    implicitWidth:  430
    implicitHeight: 820

    property alias changeUserButton:  changeUserButton
    property alias openBillButton:    openBillButton
    property alias cancelBillButton:  cancelBillButton
    property alias getPaidBillButton: getPaidBillButton
    property alias showMenuButton:    showMenuButton
    property alias itemsList:         itemsList

    //Propiedades para definir el color de la interfaz

    property color primaryColor:   "#3D4C15"
    property color secondaryColor: "#566B1E"
    property color bordeColor :    "#93B833"
    property color softBackground: "#C4C4c4"

    property int textFont: 24
    property color textColor : "#FFFFFF"

    property int borderWidth: 2
    property real radius:     20

    //Propiedades para definir el tipo de fuente
    property string appFont: "Segoe UI Semibold"

    Rectangle {
        id: background_

        color: root.secondaryColor

        radius: root.radius

        anchors.fill: parent

        RowLayout {
            id: dead // Debo de darle un mejor nombre

            height: 100 // Me gustaria asignar un tamaño dinamicaoque sea proporcional al tamaño de  la ventata que se despliegue

            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right

            ActionButton2 {
                id: changeUserButton

                textColor : root.textColor
                textFont:   root.textFont

                primaryColor :   root.primaryColor
                secondaryColor : root.secondaryColor
                bordeColor:      root.secondaryColor

                borderWidth: root.borderWidth
                radius: root.radius

                Layout.fillHeight: true
                Layout.minimumWidth: parent.width / 2
                Layout.maximumWidth: parent.width / 2
            }

            ColumnLayout {

                Layout.fillWidth: true
                Layout.fillHeight: true

                Label {

                    text: "26 - junio - 2026"
                    //font.family: root.appFont
                    font.pixelSize: 24
                    font.bold: true
                    //font.weight: Font.Medium
                    color: root.textColor

                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter

                    Layout.fillWidth: true
                    Layout.fillHeight: true
                }

                Label {

                    text: "Hora: 11:00 horas"
                    //font.family: root.appFont
                    font.pixelSize: 24
                    font.bold: true
                    //font.weight: Font.Medium
                    color: root.textColor

                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter

                    Layout.fillWidth: true
                    Layout.fillHeight: true
                }
            }
        }

        Rectangle {
            id: spaceWork

            color: root.primaryColor
            border.color: root.bordeColor

            border.width: root.borderWidth

            radius: 20

            anchors.top: dead.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom

            ColumnLayout {

                spacing: 20

                anchors.fill: parent
                anchors.margins: 20

                RowLayout {
                    id: toolbar

                    Layout.fillWidth: true
                    Layout.minimumHeight: 100
                    Layout.maximumHeight: 100

                    ActionButton {
                        id: openBillButton

                        textColor: root.textColor
                        textFont:  16 // Falta configurar una propiedad de auto ajuste del tamaño de la fuente

                        primaryColor:    root.primaryColor
                        secondaryColor : root.secondaryColor
                        bordeColor:      root.bordeColor

                        borderWidth: root.borderWidth
                        radius: root.radius

                        Layout.fillHeight: true
                        Layout.fillWidth: true
                    }

                    ActionButton {
                        id: cancelBillButton

                        textColor:  root.textColor
                        textFont:   16 // Falta configurar una propiedad de auto ajuste del tamaño de la fuente

                        primaryColor :   root.primaryColor
                        secondaryColor : root.secondaryColor
                        bordeColor:      root.bordeColor

                        borderWidth: root.borderWidth
                        radius: root.radius

                        Layout.fillHeight: true
                        Layout.fillWidth: true
                    }

                    ActionButton {
                        id: getPaidBillButton

                        textColor:  root.textColor
                        textFont:   16 // Falta configurar una propiedad de auto ajuste del tamaño de la fuente

                        primaryColor :   root.primaryColor
                        secondaryColor : root.secondaryColor
                        bordeColor:      root.bordeColor

                        borderWidth: root.borderWidth
                        radius: root.radius

                        Layout.fillHeight: true
                        Layout.fillWidth: true
                    }
                }

                TicketPanel {
                    id: itemsPanel

                    text: "Tickets"

                    primaryColor: root.primaryColor
                    secondaryColor: root.secondaryColor
                    bordeColor: root.bordeColor
                    softBackground: root.softBackground

                    textFont: root.textFont
                    textColor: root.textColor

                    borderWidth: root.borderWidth
                    radius: root.radius

                    ListView {
                        id: itemsList

                        clip: true

                        anchors.fill: parent
                    }

                    Layout.fillWidth: true
                    Layout.fillHeight: true
                }

                ActionButton2 {
                    id: showMenuButton

                    textColor:  root.textColor
                    textFont:   root.textFont

                    primaryColor:    root.primaryColor
                    secondaryColor:  root.secondaryColor
                    bordeColor:      root.bordeColor

                    borderWidth: root.borderWidth
                    radius: root.radius

                    Layout.minimumHeight: 100
                    Layout.maximumHeight: 100
                    Layout.minimumWidth:  300
                    Layout.maximumWidth:  300
                    Layout.alignment:     Qt.AlignHCenter
                }
            }
        }
    }
}