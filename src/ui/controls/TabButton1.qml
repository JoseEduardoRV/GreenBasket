import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic

import "../shapes"

Button {
    id: root

    property color primaryColor:   "#3D4C15"
    property color secondaryColor: "#566B1E"
    property color bordeColor :    "#93B833"

    property int textFont: 24
    property color textColor : "#FFFFFF"

    property int borderWidth: 2
    property real radius:     20

    readonly property real offset: tab.cornerRadius

    padding: 0

    text: "Texto"

    background: Tab {
        id: tab

        implicitWidth:  430
        implicitHeight: 80

        fillColor: root.down ? primaryColor : secondaryColor
        borderColor: root.bordeColor
        borderWidth: root.borderWidth
        cornerRadius: root.radius

        anchors.fill: parent
    }

    contentItem: Item {

        anchors.top:  parent.top
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.rightMargin: parent.width - tab.tabWidth

            Text {

                text: root.text
                color: root.textColor
                font.pixelSize: root.textFont
                font.bold: true

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter

                anchors.fill: parent
            }
    }
}