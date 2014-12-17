import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    id: mainWindow
    title: qsTr("Launcher")
    width: 900
    height: 70
    x: 510
    y: 250
    visible: true

    flags: Qt.FramelessWindowHint
    color: "transparent"

    Launcher {
        anchors.fill: parent
        id: launcher
    }
}
