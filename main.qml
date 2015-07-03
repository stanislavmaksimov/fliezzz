import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1
import QtGraphicalEffects 1.0
import Fliezzz 1.0

ApplicationWindow {
    width: 1000
    height: 600
    visible: true

    property int __cellSize: 50

    Controller {
        id: controller
    }

    ScrollView {
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: settings.left
        Item {
            height: controller.size * __cellSize
            width: height
            Grid {
                anchors.fill: parent
                columns: controller.size
                Repeater {
                    model: controller.size * controller.size
                    Item {
                        height: __cellSize
                        width: __cellSize
                        Rectangle {
                            anchors.fill: parent
                            anchors.margins: 1
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: controller.addFly(Qt.point(index % controller.size, (index - (index % controller.size)) / controller.size))
                        }
                    }
                }
            }

            Repeater {
                id: repeater
                model: controller.model
                delegate: flyComponent
            }
        }
    }

    Component {
        id: flyComponent
        Item {
            height: __cellSize
            width: __cellSize
            x: fly_data_position_role.x * __cellSize
            y: fly_data_position_role.y * __cellSize
            Behavior on x { NumberAnimation { duration: fly_data_doucheness_role * 1.1 } }
            Behavior on y { NumberAnimation { duration: fly_data_doucheness_role * 1.1 } }
            Behavior on rotation { NumberAnimation { duration: fly_data_doucheness_role / 2 } }
            rotation: fly_data_angle_role
            Image {
                id: img
                source: "qrc:/housefly-30645_640.png"
                anchors.centerIn: parent
                sourceSize.width: __cellSize
                visible: false
            }
            ColorOverlay {
                anchors.fill: img
                source: img
                color: fly_data_color_role
                visible: true
            }
        }
    }

    Rectangle {
        id: settings
        width: 470//settingsMouseArea.containsMouse ? 500 : 50
        //Behavior on width { NumberAnimation { duration: 100 } }
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        GridLayout {
            anchors.fill: parent
            anchors.margins: 10
            columns: 3
            columnSpacing: 10
            rowSpacing: 10
            Text {
                text: qsTr("Размер поля")
            }
            Slider {
                minimumValue: 1
                maximumValue: 30
                value: 10
                stepSize: 1
                onValueChanged: controller.size = value
            }
            Text {
                text: controller.size
            }
            Text {
                text: qsTr("Мухоемкость")
            }
            Slider {
                minimumValue: 1
                maximumValue: 10
                value: 3
                stepSize: 1
                onValueChanged: controller.capacity = value
            }
            Text {
                text: controller.capacity
            }
            ScrollView {
                Layout.columnSpan: 3
                Layout.fillHeight: true
                Layout.fillWidth: true
                ListView {
                    model: controller.model
                    delegate: Text {
                        text: fly_data_description_role
                        color: fly_data_color_role
                    }
                    onContentHeightChanged: {
                        if (atYEnd) {
                            if (contentHeight > height) {
                                contentY = contentHeight + originY - height
                            }
                        }
                    }
                }
            }
        }
        MouseArea {
            id: settingsMouseArea
            anchors.fill: parent
            acceptedButtons: Qt.NoButton
            hoverEnabled: true
        }
    }
}
