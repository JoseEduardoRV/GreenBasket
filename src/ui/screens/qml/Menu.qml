import QtQuick
import QtQuick.Controls.Basic

import GreenBasket.Domain 1.0

ListView {
    id: menuList
    model: menuController.submenus
    clip: true

    delegate: Column {
        width: ListView.view.width
        spacing: 6

        property var submenu: modelData
        property int submenuIndex: index

        Text {
            text: submenuIndex + ". " + submenu.name
            font.pixelSize: 20
            font.bold: true
            color: "#263238"
        }

        Repeater {
            model: submenu.itemCount

            delegate: Text {
                property int productIndex: index

                text: "   "
                      + productIndex
                      + ". "
                      + submenu.productName(productIndex)
                      + " "
                      + submenu.productPresentation(productIndex)
                      + " $"
                      + submenu.productPrice(productIndex).toFixed(2)

                font.pixelSize: 16
                color: "#263238"
            }
        }
    }
}

