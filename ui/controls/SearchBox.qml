import QtQuick 2.12
import QtQuick.Controls 2.12

Row {
    id: root
    property alias placeholderText: textField.placeholderText
    property alias borderColor: background.borderColor

    TextField {
        id: textField
        background: Rectangle {
            id: background

            property color borderColor: "#000000"

            radius: 8
            border.color: borderColor
            border.width: 1
        }
        width: 158
        height: 20
        text: ""
        color: '#000'
        placeholderTextColor: '#000'
        horizontalAlignment: Text.AlignLeft
        font.italic: true
        onFocusChanged: {
            if (!focus) {
                clear()
            }
        }
    }
}







/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
