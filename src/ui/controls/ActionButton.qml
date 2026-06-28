import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic

import "../controls"

IconButton {
    id: root

    property color textColor: "#FFFFFF"

    property int textFont: 24

    text: "Texto"

    contentItem: Item {

        anchors.fill:    parent
        anchors.margins: 10

        ColumnLayout {

            anchors.fill: parent

            Image {
                id: icon_

                source: root.iconSource

                fillMode: Image.PreserveAspectFit

                Layout.minimumWidth:  parent.height * 0.6
                Layout.maximumWidth:  parent.height * 0.7
                Layout.minimumHeight: parent.height * 0.6
                Layout.maximumHeight: parent.height * 0.7
                Layout.alignment:     Qt.AlignHCenter
            }

            Text {
                id: label_

                text:  root.text
                color: root.textColor
                font.pixelSize: root.textFont
                font.bold:      true

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment:   Text.AlignVCenter

                Layout.fillWidth:  true
                Layout.fillHeight: true
            }
        }
    }
}
