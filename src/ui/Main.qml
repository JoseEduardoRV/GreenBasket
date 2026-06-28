import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "../ui/screens/qml_ui"

ApplicationWindow {
    width: 800
    height: 1200
    visible: true
    title: "GreenBasket"

    SaleView {
        anchors.fill: parent
    }
}
