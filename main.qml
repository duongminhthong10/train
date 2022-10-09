import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    id: appwin
    visible: true
    width: 1280
    height: 800
    title: qsTr("Hello World")
    property alias wW: appwin.width
    property alias wH: appwin.height
    property string level1: file.getColor(0)
    property string level2: file.getColor(1)
    property string level3: file.getColor(2)
    property string level4: file.getColor(3)
    property string level5: file.getColor(4)
    property bool check: false
    Rectangle
    {
        width: wW * 0.95
        height: wH * 0.95
        anchors.centerIn: parent
        color: "red"
        Column {
            id: mainView
            spacing: 3
            anchors.horizontalCenter: parent.horizontalCenter
            /*header*/
            Row {
                Repeater {
                    model: file.getColumn()
                    Rectangle {
                        id: rectHeader
                        function setIndexHeader ()
                        {
                            switch(index) {
                            case 0:
                                headerText.text = "Id"
                                break;
                            case 1:
                                headerText.text = "Accounts"
                                break;
                            case 2:
                                headerText.text = "Country"
                                break;
                            case 3:
                                headerText.text = "Level"
                                break;
                            }
                        }

                        Component.onCompleted:  {
                            setIndexHeader()
                        }
                        Timer {
                            id: test
                            interval: 100; running: true
                            onTriggered: {
                                setIndexHeader()
                            }
                        }

                        MouseArea {
                            id: hihi
                            anchors.fill: parent
                            onClicked:
                            {
                                iconSort.visible = true
                                if(iconSort.source == "qrc:/file/up.png")
                                {
                                    iconSort.source = "qrc:/file/down.png"
                                }
                                else {
                                    iconSort.source = "qrc:/file/up.png"
                                }
                                if (headerText.text == "Id")
                                {
                                    if (check == true)
                                    {
                                        file.sapXep(2)
                                        check = false
                                        test.start()
                                    }
                                    else {
                                        file.sapXep(1)
                                        check = true
                                        test.start()
                                    }
                                }
                                else if (headerText.text == "Level")
                                {
                                    //file.sapXep(3)
                                }

                            }
                        }
                        width: wW * 0.2
                        height: wH * 0.05
                        border.color: "white"
                        border.width: 3
                        color: "black"
                        Image {
                            id: iconSort
                            visible: false
                            source: "qrc:/file/down.png"
                            width: 0.01 * wW
                            height: 0.018 * wH
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: parent.left
                            anchors.leftMargin: 10
                        }
                        Text {
                            id: headerText
                            color: "white"
                            font.pixelSize: 15
                            anchors.centerIn: parent
                        }
                    }
                }
            }
            Grid {
                columns: file.getColumn()
                rows: file.getRow()
                //                spacing: 3
                Repeater {
                    id: itemData
                    model: file.getColumn() * file.getRow()
                    Rectangle {
                        Component.onCompleted: {
                            //for (var i = 0; i < file.getColumn() * file.getRow(); i++) {
                            textData.text = file.getData(parseInt(index/4),parseInt(index%4))
                            //}
                        }

                        width: wW * 0.2
                        height: wH * 0.05
                        border.color: "white"
                        border.width: 3
                        color: "black"
                        function colorset() {
                            switch (textData.text)
                            {
                            case "1":
                                textData.color = level1
                                break;
                            case "2":
                                textData.color = level2
                                break;
                            case "3":
                                textData.color = level3
                                break;
                            case "4":
                                textData.color = level4
                                break;
                            case "5":
                                textData.color = level5
                                break;
                            default:
                                textData.color = "white"
                                break;
                            }
                        }
                        Text {

                            Component.onCompleted: {
                                colorset()
                            }
                            id: textData
                            color: "white"
                            font.pixelSize: 15
                            anchors.centerIn: parent
                            Timer {
                                id: reload
                                interval: 100; running: true; repeat: true
                                onTriggered: {
                                    textData.text = file.getData(parseInt(index/4),parseInt(index%4))
                                    colorset()
                                }
                            }
                        }
                    }
                }
            }
        }

    }
}

