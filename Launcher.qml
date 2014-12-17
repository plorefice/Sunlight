import QtQuick 2.3
import QtQuick.Layouts 1.1

Item {
    objectName: "launcherWindow"
    id: launcherWindow
    width: 900
    height: 70

    signal inputChanged(string txt)
    signal returnPressed(string txt)

    ColumnLayout {
        id: launcherLayout
        width: 0
        height: 0

        Rectangle {
            id: background
            width: 900
            height: 70
            color: "#eef6f5f6"
            radius: 5
            border.color: "#eeb6b6b6"
            border.width: 1
        }
    }

    Image {
        id: findIcon
        x: 24
        y: 17
        width: 36
        height: 36
        z: 1
        antialiasing: true
        fillMode: Image.PreserveAspectFit
        source: "/res/icons/sl_find_lo.png"
    }

    Text {
        objectName: "mainText"
        id: mainText
        x: 75
        y: 14
        z: 0.5
        width: 730
        height: 48
        color: "#aaaaaa"
        text: qsTr("")
        horizontalAlignment: Text.AlignLeft
        font.pixelSize: 33
    }

    TextInput {
        id: mainInput
        x: 75
        y: 14
        z: 1
        width: 730
        height: 48
        color: "#424242"
        text: qsTr("")
        selectionColor: "#4d4d4d"
        focus: true
        activeFocusOnPress: true
        cursorVisible: true
        horizontalAlignment: Text.AlignLeft
        font.pixelSize: 33

        onTextChanged: launcherWindow.inputChanged(text)
        Keys.onReturnPressed: launcherWindow.returnPressed(text)
    }

    Image {
        id: appIcon
        x: 829
        y: 11
        width: 48
        height: 48
        z: 1
        transformOrigin: Item.Center
        source: "qrc:/qtquickplugin/images/template_image.png"
    }

    states: [
        State {
            name: "expanded"
            when: (mainInput.text != "")

            PropertyChanges { target: mainWindow; height: 560 }
            PropertyChanges { target: launcherWindow; height: 560 }
            PropertyChanges { target: background; height: 560 }
        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "expanded"
            reversible: true

            ParallelAnimation {
                NumberAnimation { target: mainWindow; property: "height"; duration: 150; easing.type: Easing.OutQuad }
                NumberAnimation { target: launcherWindow; property: "height"; duration: 150; easing.type: Easing.OutQuad }
                NumberAnimation { target: background; property: "height"; duration: 150; easing.type: Easing.OutQuad }
            }
        }
    ]
}
