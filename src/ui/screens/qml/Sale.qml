import QtQuick
import QtQuick.Controls.Basic

import GreenBasket.Domain 1.0

import "../qml_ui"

SaleView {
    id: view

    itemsList.model: saleController.bills

    itemsList.delegate: Rectangle {
        width: view.itemsList.width
        height: 48

        color: ListView.isCurrentItem
                       ? "#dbe8b5"
                       : (index % 2 === 0 ? "#ffffff" : "#f2f2f2")

        Row {
            anchors.centerIn: parent
            spacing: 4

            Text {
                text: modelData.ticketNumber +" "+ (index + 1)
                color: "#263238"
                font.pixelSize: 18
                font.bold: true
            }
            Text {
                text: "    " + Qt.formatDateTime(modelData.createdAt, "dd - MMMM - yyyy hh:mm")
                color: "#607D8B"
                font.pixelSize: 18
            }

            Text {
                text: "Total: $" + modelData.total.toFixed(2)
                color: "#263238"
                font.pixelSize: 18
            }
        }

        MouseArea {
            anchors.fill: parent

            onClicked: {
                view.itemsList.currentIndex = index
                saleController.selectBill(modelData)
            }
        }
    }

    changeUserButton.iconSource: "file:///C:/Users/Ing-Eduardo/Documents/Glintec/Proyects/Windows-11/GreenBasket/icons/user.png"
    changeUserButton.text: "Usuario"
    changeUserButton.onClicked: {
        //console.log("Change User Button")
        saleController.changeUser()
    }

    openBillButton.iconSource: "file:///C:/Users/Ing-Eduardo/Documents/Glintec/Proyects/Windows-11/GreenBasket/icons/add.png"
    openBillButton.text: "Nueva cuenta"
    openBillButton.onClicked: {
        //console.log("Open Bill Button")
        saleController.openBill()
    }

    cancelBillButton.iconSource: "file:///C:/Users/Ing-Eduardo/Documents/Glintec/Proyects/Windows-11/GreenBasket/icons/billCancel.png"
    cancelBillButton.text: "Canelar cuenta"
    cancelBillButton.onClicked: {
        //console.log("Cancel Bill Button")
        saleController.cancelBill()
    }

    getPaidBillButton.iconSource: "file:///C:/Users/Ing-Eduardo/Documents/Glintec/Proyects/Windows-11/GreenBasket/icons/creditCard.png"
    getPaidBillButton.text: "Cobrar cuenta"
    getPaidBillButton.onClicked: {
        //console.log("Get Paid Bill Button")
        saleController.getPaidBill()
    }

    showMenuButton.iconSource: "file:///C:/Users/Ing-Eduardo/Documents/Glintec/Proyects/Windows-11/GreenBasket/icons/user.png"
    showMenuButton.text: "Menu"
    showMenuButton.onClicked: {
        //console.log("Show Menu Button")
        saleController.showMenu()
    }

    // Connections {
    //     target: saleController


    // }

    Component.onCompleted: {
        console.log("Sale.qml cargado")
    }
}