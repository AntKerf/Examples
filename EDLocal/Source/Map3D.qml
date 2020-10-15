//! [0]
import QtQuick 2.1
import QtQuick.Layouts 1.0
import QtDataVisualization 1.0
import "."
//! [0]

//! [1]
Rectangle {
    id: mainView
    //! [1]
    width: 500
    height: 500

    //! [13]
    Theme3D {
        id: themeIsabelle
        type: Theme3D.ThemeIsabelle
        font.family: "Lucida Handwriting"
        font.pointSize: 40
    }
    //! [13]

    Theme3D {
        id: themeArmyBlue
        type: Theme3D.ThemeArmyBlue
    }

    //! [8]
    //! [9]
    Item {
        id: dataView
        anchors.bottom: parent.bottom
        //! [9]
        width: parent.width
        height: parent.height - buttonLayout.height
        //! [8]

        //! [2]
        Scatter3D {
            id: scatterGraph
            width: dataView.width
            height: dataView.height
            //! [2]
            //! [3]
            theme: themeIsabelle
            shadowQuality: AbstractGraph3D.ShadowQualitySoftLow
            //! [3]
            //! [6]
            axisX.segmentCount: 3
            axisX.subSegmentCount: 2
            axisX.labelFormat: "%.2f"
            axisZ.segmentCount: 2
            axisZ.subSegmentCount: 2
            axisZ.labelFormat: "%.2f"
            axisY.segmentCount: 2
            axisY.subSegmentCount: 2
            axisY.labelFormat: "%.2f"
            //! [6]
            //! [5]
            Scatter3DSeries {
                id: scatterSeries
                //! [5]
                //! [10]
                itemLabelFormat: "@xLabel"
                //! [10]

                //! [11]
                ItemModelScatterDataProxy {
                    itemModel: myModel
                    rotationRole: "systems.name"
                    xPosRole: "x"
                    yPosRole: "y"
                    zPosRole: "z"
                }
                //! [11]
            }
        }
    }

    RowLayout {
        id: buttonLayout
        Layout.minimumHeight: cameraToggle.height
        width: parent.width
        anchors.left: parent.left
        spacing: 0
        //! [7]
        NewButton {
            id: shadowToggle
            Layout.fillHeight: true
            Layout.fillWidth: true
            text: scatterGraph.shadowsSupported ? "Hide Shadows" : "Shadows not supported"
            enabled: scatterGraph.shadowsSupported
            onClicked: {
                if (scatterGraph.shadowQuality === AbstractGraph3D.ShadowQualityNone) {
                    scatterGraph.shadowQuality = AbstractGraph3D.ShadowQualitySoftLow;
                    text = "Hide Shadows";
                } else {
                    scatterGraph.shadowQuality = AbstractGraph3D.ShadowQualityNone;
                    text = "Show Shadows";
                }
            }
        }
        //! [7]

        NewButton {
            id: smoothToggle
            Layout.fillHeight: true
            Layout.fillWidth: true
            text: "Use Smooth for Series One"
            onClicked: {
                if (scatterSeries.meshSmooth === false) {
                    text = "Use Flat for Series One";
                    scatterSeries.meshSmooth = true;
                } else {
                    text = "Use Smooth for Series One"
                    scatterSeries.meshSmooth = false;
                }
            }
        }

        NewButton {
            id: cameraToggle
            Layout.fillHeight: true
            Layout.fillWidth: true
            text: "Change Camera Placement"
            onClicked: {
                if (scatterGraph.scene.activeCamera.cameraPreset === Camera3D.CameraPresetFront) {
                    scatterGraph.scene.activeCamera.cameraPreset =
                            Camera3D.CameraPresetIsometricRightHigh;
                } else {
                    scatterGraph.scene.activeCamera.cameraPreset = Camera3D.CameraPresetFront;
                }
            }
        }

        NewButton {
            id: themeToggle
            Layout.fillHeight: true
            Layout.fillWidth: true
            text: "Change Theme"
            onClicked: {
                if (scatterGraph.theme.type === Theme3D.ThemeArmyBlue) {
                    scatterGraph.theme = themeIsabelle
                } else {
                    scatterGraph.theme = themeArmyBlue
                }
                if (scatterGraph.theme.backgroundEnabled === true) {
                    backgroundToggle.text = "Hide Background";
                } else {
                    backgroundToggle.text = "Show Background";
                }
            }
        }

        NewButton {
            id: backgroundToggle
            Layout.fillHeight: true
            Layout.fillWidth: true
            text: "Hide Background"
            onClicked: {
                if (scatterGraph.theme.backgroundEnabled === true) {
                    scatterGraph.theme.backgroundEnabled = false;
                    text = "Show Background";
                } else {
                    scatterGraph.theme.backgroundEnabled = true;
                    text = "Hide Background";
                }
            }
        }

        NewButton {
            id: exitButton
            Layout.fillHeight: true
            Layout.fillWidth: true
            text: "Quit"
            onClicked: Qt.quit(0);
        }
    }
}
