import QtQuick
import QtQuick.Controls.Basic

import GreenBasket.Domain 1.0

import "../qml_ui"

SaleView {
    id: view

    Component {
        id: ticketsListPage

        ListView {
            id: list

    model: ticketsController.bills

    delegate: Rectangle {
        width: ListView.view.width
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
                list.currentIndex = index
                view.itemsStack.push(ticketDetailPage)
                //saleController.selectBill(modelData)
            }
        }
    }

        }}

    Component {
        id: ticketDetailPage

        Rectangle {
            color: "blue"
            Text {
                text: "Ticket: " + saleController.selectedBill.ticketNumber + " Fecha" + saleController.selectedBill.createdAt
                color: "white"
                font.pixelSize: 24
                font.bold: true
            }
        }
    }

    Component {
        id: ticket
        TicketList {
            id: ticketList
        }
    }

    Component {
        id: menu
        Menu {
            id: menuList
        }
    }


    changeUserButton.iconSource: "file:///C:/Users/Ing-Eduardo/Documents/Glintec/Proyects/Windows-11/GreenBasket/icons/user.png"
    changeUserButton.text: "Usuario"
    changeUserButton.onClicked: {
        //console.log("Change User Button")
        greenBasket.changeUser()
    }

    openBillButton.iconSource: "file:///C:/Users/Ing-Eduardo/Documents/Glintec/Proyects/Windows-11/GreenBasket/icons/add.png"
    openBillButton.text: "Nueva cuenta"
    openBillButton.onClicked: {
        //console.log("Open Bill Button")
        greenBasket.openBill()
    }

    cancelBillButton.iconSource: "file:///C:/Users/Ing-Eduardo/Documents/Glintec/Proyects/Windows-11/GreenBasket/icons/billCancel.png"
    cancelBillButton.text: "Canelar cuenta"
    cancelBillButton.onClicked: {
        //console.log("Cancel Bill Button")
        greenBasket.cancelBill()
    }

    getPaidBillButton.iconSource: "file:///C:/Users/Ing-Eduardo/Documents/Glintec/Proyects/Windows-11/GreenBasket/icons/creditCard.png"
    getPaidBillButton.text: "Cobrar cuenta"
    getPaidBillButton.onClicked: {
        //view.itemsStack.push(ticket)
        greenBasket.getPaidBill()
    }

    showMenuButton.iconSource: "file:///C:/Users/Ing-Eduardo/Documents/Glintec/Proyects/Windows-11/GreenBasket/icons/user.png"
    showMenuButton.text: "Menu"
    showMenuButton.onClicked: {
        //view.itemsStack.push(menu)
        greenBasket.showMenu()
    }

    tabButton.onDoubleClicked: {
        //view.itemsStack.push(ticket)
        greenBasket.showTickets()
    }

    // Connections {
    //     target: saleController


    // }

    Component.onCompleted: {
        view.itemsStack.push(ticketsListPage)
        console.log("Sale.qml cargado")
    }
}