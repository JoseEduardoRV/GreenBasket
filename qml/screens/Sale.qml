import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic

Page {
    id: salePage

    property bool billOpen: false
    property string statusText: "Listo para iniciar una venta"

    background: Rectangle {
        color: "#f4f4f4"
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 10

        Label {
            text: "GreenBasket"
            font.pixelSize: 30
            font.bold: true
            color: "#cfd3d6"
            Layout.alignment: Qt.AlignHCenter
        }

        Label {
            text: "Módulo de venta"
            font.pixelSize: 22
            color: "#444444"
            Layout.alignment: Qt.AlignHCenter
        }

        ScrollView {
            id: contentScroll

            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true

            contentWidth: availableWidth

            ColumnLayout {
                width: contentScroll.availableWidth
                spacing: 10

                GroupBox {
                    title: "Bebidas"
                    Layout.fillWidth: true
                    Layout.preferredHeight: 125

                    ListView {
                        id: drinksList

                        anchors.fill: parent
                        anchors.margins: 8

                        orientation: ListView.Horizontal
                        spacing: 10
                        clip: true

                        model: menuController.drinksModel

                        delegate: Button {
                            required property string name
                            required property string size
                            required property real price
                            required property int index

                            width: 145
                            height: drinksList.height - 16
                            enabled: salePage.billOpen

                            text: name + "\n" + size + "\n$ " + price

                            onClicked: {
                                saleController.addDrink(index, 1)
                                salePage.statusText = "Bebida agregada: " + name
                            }
                        }

                        ScrollBar.horizontal: ScrollBar { }
                    }
                }

                GroupBox {
                    title: "Alimentos"
                    Layout.fillWidth: true
                    Layout.preferredHeight: 125

                    ListView {
                        id: foodList

                        anchors.fill: parent
                        anchors.margins: 8

                        orientation: ListView.Horizontal
                        spacing: 10
                        clip: true

                        model: menuController.foodModel

                        delegate: Button {
                            required property string name
                            required property string size
                            required property real price
                            required property int index

                            width: 165
                            height: foodList.height - 16
                            enabled: salePage.billOpen

                            text: name + "\n" + size + "\n$ " + price

                            onClicked: {
                                saleController.addFood(index, 1)
                                salePage.statusText = "Alimento agregado: " + name
                            }
                        }

                        ScrollBar.horizontal: ScrollBar { }
                    }
                }

                GroupBox {
                    title: "Postres"
                    Layout.fillWidth: true
                    Layout.preferredHeight: 125

                    ListView {
                        id: dessertsList

                        anchors.fill: parent
                        anchors.margins: 8

                        orientation: ListView.Horizontal
                        spacing: 10
                        clip: true

                        model: menuController.dessertsModel

                        delegate: Button {
                            required property string name
                            required property string size
                            required property real price
                            required property int index

                            width: 145
                            height: dessertsList.height - 16
                            enabled: salePage.billOpen

                            text: name + "\n" + size + "\n$ " + price

                            onClicked: {
                                saleController.addDessert(index, 1)
                                salePage.statusText = "Postre agregado: " + name
                            }
                        }

                        ScrollBar.horizontal: ScrollBar { }
                    }
                }
            }
        }

        GroupBox {
            title: "Acciones"
            Layout.fillWidth: true
            Layout.preferredHeight: 100

            RowLayout {
                anchors.fill: parent
                anchors.margins: 10
                spacing: 10

                Button {
                    text: "Abrir cuenta"
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    onClicked: {
                        saleController.openBill()
                        salePage.billOpen = true
                        salePage.statusText = "Cuenta abierta"
                    }
                }

                Button {
                    text: "Cobrar"
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    enabled: salePage.billOpen

                    onClicked: {
                        saleController.closeBill()
                        salePage.billOpen = false
                        salePage.statusText = "Cuenta cobrada"
                    }
                }
            }
        }
    }

    Component.onCompleted: {
        console.log("Bebidas cargadas:",   menuController.drinksModel.rowCount())
        console.log("Alimentos cargados:", menuController.foodModel.rowCount())
        console.log("Postres cargados:",   menuController.dessertsModel.rowCount())
    }
}