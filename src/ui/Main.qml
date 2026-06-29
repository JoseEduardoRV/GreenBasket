import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "../ui/screens/qml"

ApplicationWindow {
    width: 800
    height: 1200
    visible: true
    title: "GreenBasket"

    Sale {
        anchors.fill: parent
    }
}
