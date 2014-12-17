import QtQuick 2.3

Item {
    property alias text: searchInput.text

    signal inputChanged(string text)
    signal returnPressed(string text)

    Text {
        id: hintText
        anchors.fill: parent
        z: 0

        text: qsTr("")
        color: "#aaaaaa"
        horizontalAlignment: Text.AlignLeft
        font.pixelSize: 33
    }

    TextInput {
        id: searchInput
        anchors.fill: parent
        z: 1

        text: qsTr("")
        color: "#424242"
        selectionColor: "#4d4d4d"
        cursorVisible: true
        horizontalAlignment: Text.AlignLeft
        font.pixelSize: 33

        focus: true
        activeFocusOnPress: true

        onTextChanged: searchBox.inputChanged(text)
        Keys.onReturnPressed: searchBox.returnPressed(text)
    }
}

