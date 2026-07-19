import QtQuick
import QtQuick.Controls.Basic

ListView {
    id: menuList
    model: 10
    clip: true

    delegate: Column {
        width: ListView.view.width
        spacing: 6

        Row{

          width: parent.width

          Text {
             text: "modelData.ticketNumber"
             font.pixelSize: 20
             font.bold: true
             color: "#263238"
          }

          Text {
             text: "modelData.createdAt"
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
