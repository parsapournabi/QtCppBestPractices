import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import ClockCircle 1.0
// import QPaintClockCircle 1.0

ApplicationWindow {
    id: root
    width: 1000
    height: 850
    visible: true
    title: qsTr("Scene Graph")

    QPaintClockCircle {
        id: clockCircle
        // Set its positioning and dimensions
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.horizontalCenter: parent.horizontalCenter
        width: 200
        height: 200

        // Determine the properties that Q_PROPERTY
        backend.name: "clock"
        backend.backgroundColor: "whiteSmoke"
        backend.borderActiveColor: "LightSlateGray"
        backend.borderNonActiveColor: "LightSteelBlue"

        // Add the text that will be put up timer
        Text {
            id: textTimer
            anchors.centerIn: parent
            font.bold: true
            font.pixelSize: 24
        }

        // If you change the time, put the time on the timer
        backend.onCircleTimeChanged: (circleTime) => {
            textTimer.text = Qt.formatTime(circleTime, "mm:ss.zzz")
        }
    }

    Button {
        id: start
        text: "Start"
        onClicked: clockCircle.backend.start(); // Start timer
        anchors {
            left: parent.left
            leftMargin: 20
            bottom: parent.bottom
            bottomMargin: 20
        }
    }

    Button {
        id: stop
        text: "Stop"
        onClicked:  clockCircle.backend.stop(); // Stop timer
        anchors {
            horizontalCenter: parent.horizontalCenter
            bottom: parent.bottom
            bottomMargin: 20
        }
    }

    Button {
        id: clear
        text: "Clear"
        onClicked: clockCircle.backend.clear(); // clean timer
        anchors {
            right: parent.right
            rightMargin: 20
            bottom: parent.bottom
            bottomMargin: 20
        }
    }

}
