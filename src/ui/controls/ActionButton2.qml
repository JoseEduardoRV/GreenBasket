import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic

import "../controls"

ActionButton {
	id: root

    implicitWidth:  512
    implicitHeight: 256

    text: "Texto"

    contentItem: Item {

            anchors.fill:    parent
            anchors.margins: 10

            RowLayout {
                    anchors.fill: parent

                    Image {
                            id: icon_

                            source: root.iconSource

                            fillMode: Image.PreserveAspectFit

                            Layout.minimumWidth:  parent.height * 0.7
                            Layout.maximumWidth:  parent.height * 0.8
                            Layout.minimumHeight: parent.height * 0.7
                            Layout.maximumHeight: parent.height * 0.8
                    }

                    Text {
                            id: label_

                            text:  root.text
                            color: root.textColor
                            font.pixelSize: root.textFont
                            font.bold:      true

                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment:   Text.AlignVCenter

                            Layout.fillWidth:     true
                            Layout.minimumHeight: icon_.height
                            Layout.maximumHeight: icon_.height
                    }
                }
        }
}
