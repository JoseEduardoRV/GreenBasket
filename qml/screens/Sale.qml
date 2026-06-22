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

        Repeater {
            model: menuController.productsModel.categoryIds

            delegate: GroupBox {
                required property int modelData

                property int currentCategoryId: modelData

                title: menuController.productsModel.categoryName(currentCategoryId)

                Layout.fillWidth: true
                Layout.preferredHeight: 130

                ListView {
                    id: productList

                    anchors.fill: parent
                    anchors.margins: 8

                    orientation: ListView.Horizontal
                    spacing: 10
                    clip: true

                    model: menuController.productsModel

                    delegate: Button {
                        required property int productRow
                        required property string name
                        required property string size
                        required property real price
                        required property int categoryId

                        visible: categoryId === currentCategoryId

                        width: visible ? 150 : 0
                        height: visible ? 90 : 0

                        text: name + "\n" + size + "\n$ " + price

                        onClicked: {
                            saleController.addProductByRow(productRow, 1)
                            salePage.statusText = "Producto agregado: " + name
                        }
                    }

                    ScrollBar.horizontal: ScrollBar { }
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
        console.log("menuController:", menuController)
        console.log("productsModel:", menuController.productsModel)

        if (menuController.productsModel !== undefined) {
            console.log("categoryIds:", menuController.productsModel.categoryIds)
        }
    }
}