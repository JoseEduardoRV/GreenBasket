import QtQuick
import QtQuick.Controls.Basic

import GreenBasket.Domain 1.0

ListView {
    id: menuList
    model: saleController.tickets
    clip: true

    delegate: Column {
        width: ListView.view.width
        spacing: 6

        Row{

          width: parent.width

          Text {
             text: modelData.ticketNumber
             font.pixelSize: 20
             font.bold: true
             color: "#263238"
          }

          Text {
             text: modelData.createdAt
             font.pixelSize: 20
             font.bold: true
             color: "#263238"
          }

          Text {
             text: "mesa: " + index
             font.pixelSize: 20
             font.bold: true
             color: "#263238"
          }
        }
     }
}
