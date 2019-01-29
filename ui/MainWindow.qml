import QtQuick 2.12
import QtQuick.Controls 2.12
import "controls"

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("GameCommandeer")

    header: ToolBar {
        id: toolBar
        contentWidth: parent.width
        ToolButton {
            id: toolButton
            text: "\u2630"
        }

        SearchBox {
            placeholderText: "Stuff"
            borderColor: "#00ff00"

        }


    }
}



































/*##^## Designer {
    D{i:3;anchors_height:20;anchors_width:158;anchors_x:482;anchors_y:14}
}
 ##^##*/
