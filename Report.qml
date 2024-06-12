import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

Rectangle {
    id: hui
    anchors.fill: parent
    color: "lightgray"


    property var parameters_name: ["№ Клиентa:","ФИО:","Номер телефона:","Email:","Адрес проживания:"]
    property var button_name:  ["qrc:/Image/ButtonIcon/leftArrow.png","qrc:/Image/ButtonIcon/add.png","qrc:/Image/ButtonIcon/save.png","qrc:/Image/ButtonIcon/delete.png","qrc:/Image/ButtonIcon/leftArrow.png"]
    property bool newData: false

    Image
    {
        source: "qrc:/Image/detail.png"
        anchors.centerIn: parent
        width: parent.width* 0.8
        height: parent.height * 0.8
        fillMode: Image.PreserveAspectFit
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 5

        Header {
            id: report_header
            name_page: "Отчет Клиентов"
            id_page: report_page
        }

        Rectangle
        {
            color: "white"
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredHeight: parent.height * 0.9
            Layout.preferredWidth: parent.width * 0.9

            ScrollView {
                anchors.fill: parent
                clip: true
                ScrollBar.vertical.policy: ScrollBar.AlwaysOff

                ColumnLayout {
                    id: my_food_column
                    anchors.fill: parent
                    spacing: 5

                    // Вывод каждого элемента из вектора
                    Repeater {
                        model: Client_com.Report_Clients_Vector.length
                        Rectangle
                        {
                            color: index%5 === 0? "#00B060": "transparent";
                            Layout.preferredHeight: hui.height * 0.05
                            Layout.preferredWidth: hui.width * 0.9
                            Layout.alignment: Qt.AlignHCenter

                            Item
                            {
                                anchors.fill: parent
                                Text
                                {
                                    anchors.left: parent.left
                                    anchors.leftMargin: parent.width * 0.05
                                    text: parameters_name[index%5]
                                    font.pixelSize: parent.height * 0.5
                                }

                                Text
                                {
                                    anchors.right: parent.right
                                    anchors.rightMargin: parent.width * 0.05
                                    text: Client_com.Report_Clients_Vector[index]
                                    font.pixelSize: parent.height * 0.5
                                }
                            }
                        }
                    }
                }
            }

        }
    }


}
