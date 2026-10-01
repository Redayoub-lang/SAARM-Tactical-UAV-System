import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 1024
    height: 768
    title: "SAARM Tactical Ground Control Station"
    color: "#0f141d"

    Rectangle {
        anchors.centerIn: parent
        width: 600
        height: 200
        color: "#1a2332"
        border.color: "#00ffcc"
        border.width: 2
        radius: 10

        Text {
            anchors.centerIn: parent
            text: "C2 LINK: " + C2Backend.systemStatus
            color: "#00ffcc"
            font.pixelSize: 24
            font.bold: true
        }
    }
}