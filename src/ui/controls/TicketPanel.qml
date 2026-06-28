import QtQuick
import QtQuick.Shapes
import QtQuick.Layouts
import QtQuick.Controls.Basic

import "../shapes"

Item {
    id: root

    property color primaryColor:   "#3D4C15"
    property color secondaryColor: "#566B1E"
    property color bordeColor :    "#93B833"
    property color softBackground: "#C4C4c4"

    property int textFont: 24
    property color textColor : "#FFFFFF"

    property int borderWidth: 2
    property real radius:     20

    property string text: "Texto"

    default property alias lists: list.data

    implicitWidth:  380
    implicitHeight: 520

    TabButton1 {
        id: tabButton

        text: "Tickets"

        primaryColor:   root.primaryColor
        secondaryColor: root.secondaryColor
        bordeColor:     root.bordeColor

        textFont:  root.textFont
        textColor: root.textColor

        borderWidth: root.borderWidth
        radius:      root.radius

        width: parent.width
        height: 80 // Tengo que poner aqui que sea por un porcentaje
    }
    Rectangle {
        width:  parent.width
        radius: root.radius
        border.color: root.bordeColor
        border.width: root.borderWidth

        anchors.top:       tabButton.top
        anchors.topMargin: tabButton.height - tabButton.offset
        anchors.bottom:    parent.bottom

        Item {
            id: list

            anchors.fill: parent
            anchors.margins: 10

        }
    }

}

