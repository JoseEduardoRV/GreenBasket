import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic

import "qml/screens"

ApplicationWindow {
    width: 420
    height: 720
    visible: true
    title: "GreenBasket"

    Sale {
        anchors.fill: parent
    }
}
