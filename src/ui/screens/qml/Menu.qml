import QtQuick
import QtQuick.Controls.Basic

ListView {
    id: menuList
    model: 10
    clip: true

    delegate: Rectangle {

        width: ListView.view.width
        height: 48

        color: ListView.isCurrentItem
               ? "#dbe8b5"
               : (index % 2 === 0 ? "#ffffff" : "#f2f2f2")

        Text {
            text: "modelData.name"
            color: "black"
            font.pixelSize: 24
            font.bold: true
        }

        MouseArea {
            anchors.fill: parent

            onClicked: {
                menuList.currentIndex = index
                console.log("index seleccionado " + index)
            }
        }
    }
}

