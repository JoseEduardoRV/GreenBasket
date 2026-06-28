import QtQuick
import QtQuick.Controls.Basic

Button {
    id: root
    property color primaryColor:   "#3D4C15"
    property color secondaryColor: "#566B1E"
    property color bordeColor :    "#93B833"

    property int borderWidth: 2
    property real radius:     20

    property url iconSource: "file:///C:/Users/Ing-Eduardo/Documents/Glintec/Proyects/Windows-11/GreenBasket/icons/user.png"

    padding: 0

    background: Rectangle {

        implicitWidth:  256
        implicitHeight: 256

        opacity: enabled ? 1 : 0.3

        color:        root.secondaryColor
        border.color: root.down ? root.bordeColor : root.secondaryColor

        border.width: root.borderWidth

        radius: root.radius
    }

    contentItem: Image {

        source: root.iconSource

        fillMode: Image.PreserveAspectFit

        anchors.fill:    parent
        anchors.margins: 5
    }
}