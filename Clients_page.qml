import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

Rectangle {
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

    ColumnLayout
    {
        anchors.fill: parent

    Header
    {
        name_page: "Клиенты"
        id_page: clients_page
    }

    RowLayout
    {
        Layout.alignment: Qt.AlignLeft
        Layout.topMargin: parent.height * 0.05
        Layout.preferredWidth: parent.width
        Layout.preferredHeight: parent.height *0.9 - parent.height * 0.05

        ColumnLayout
        {
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredHeight: parent.height
            Layout.preferredWidth: parent.width* 0.4

            Repeater
            {
                model: 5
                Rectangle
                {
                    Layout.alignment: Qt.AlignHCenter
                    Layout.preferredHeight: parent.height*0.075
                    Layout.preferredWidth: parent.width *0.9
                    color: "#0B5FA5"
                    border.color: "black"
                    border.width: parent.height * 0.0025
                    clip: true
                    Text {
                        anchors
                        {
                            verticalCenter: parent.verticalCenter
                            left: parent.left
                            leftMargin: parent.width * 0.05
                        }
                        font.pixelSize: parent.height * 0.7
                        font.bold: true
                        color: "white"

                        text: qsTr(parameters_name[index])
                    }
                }
            }

            Item
            {
                Layout.preferredHeight: parent.height * 0.3
                Layout.preferredWidth: parent.width
            }
        }

        ColumnLayout
        {
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredHeight: parent.height
            Layout.preferredWidth: parent.width* 0.4

            Rectangle
            {
                Layout.alignment: Qt.AlignLeft
                Layout.preferredHeight: parent.height*0.075
                Layout.preferredWidth: parent.width *0.9
                color: "#00733E"
                enabled: false
                border.color: "black"
                border.width: parent.height * 0.0025
                clip: true
                TextInput {
                    id: text_numer
                    anchors
                    {
                        verticalCenter: parent.verticalCenter
                        right: parent.right
                        rightMargin: parent.width * 0.05
                    }
                    width: parent.width * 0.95
                    height: parent.height
                    font.pixelSize: parent.height * 0.8
                    color: "black"
                    text: Client_com.getClientsIndex(0)+1
                    horizontalAlignment: TextInput.AlignRight
                }

            }
            Repeater
            {
                model: Client_com.Clients_vector.length-1
                Rectangle
                {
                    Layout.alignment: Qt.AlignLeft
                    Layout.preferredHeight: parent.height*0.075
                    Layout.preferredWidth: parent.width *0.9
                    color: "#C0E8FF"
                    border.color: "black"
                    border.width: parent.height * 0.0025
                    clip: true
                    TextInput {
                        id: text_textInput
                        anchors
                        {
                            verticalCenter: parent.verticalCenter
                            right: parent.right
                            rightMargin: parent.width * 0.05
                        }
                        width: parent.width * 0.95
                        height: parent.height
                        font.pixelSize: parent.height * 0.8
                        color: "black"
                        text: qsTr(Client_com.Clients_vector[index+1])
                        horizontalAlignment: TextInput.AlignRight

                        onTextChanged:
                        {
                            Client_com.Clients_vector[index+1] = text_textInput.text
                        }
                    }
                }
            }

            Item
            {
                Layout.preferredHeight: parent.height * 0.3
                Layout.preferredWidth: parent.width
            }
        }

    }

    RowLayout
    {
        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
        Layout.preferredHeight: parent.height * 0.2
        Layout.preferredWidth: parent.width

        Repeater
        {
            model: 5
            Button
            {
                Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
                Layout.topMargin: parent.height * 0.1
                Layout.preferredHeight: parent.height * 0.4
                Layout.preferredWidth: parent.width * 0.15
                background: Rectangle
                {
                    color: parent.pressed ? "#00733E" : (parent.hovered ? "#00B060" : "#00733E")

                    radius: parent.height * 0.1
                    border.color: "black"
                    border.width: parent.width * 0.01
                }
                Image
                {
                    anchors.centerIn: parent
                    source: button_name[index]
                    width: parent.width * 0.7
                    height: parent.height * 0.7
                    fillMode: Image.PreserveAspectFit
                    mirror: index ===0? true: false
                }

                onClicked:
                {
                    switch(index)
                    {
                    case 0:
                        if(newData)
                            newData = false
                        if(Client_com.getClientsIndex(0) > 0)
                             Client_com.setClients_vector(Database.getDataVector(Client_com.getClientsIndex(-1),"Clients","client_id"));
                        //image_textInput.text = Transport_company.Clients_vector[6];
                        text_numer.text = Client_com.getClientsIndex(0)+1;
                        break;
                    case 1:
                        Client_com.clients_clearVector();
                        newData = true;
                        text_numer.text = Client_com.getClientsMaxIndex()+1;
                        break;
                    case 2:
                        console.log(Client_com.Clients_vector)
                        if(newData)
                        {
                            Database.clients_createNewData(Client_com.Clients_vector)
                            Client_com.setClientsMaxIndex( Client_com.getClientsMaxIndex()+1)
                            Client_com.setClients_vector(Database.getDataVector(Client_com.getClientsIndex(0),"Clients","client_id"));
                            text_numer.text = Client_com.getClientsIndex(0)+1;
                        }
                        else
                            Database.clients_addNewData(Client_com.Clients_vector);
                        break;
                    case 3:
                        Database.delete_Data(Client_com.Clients_vector[0], "Clients","client_id");
                        if(Client_com.getClientsIndex(0) < Client_com.getClientsMaxIndex()-1)
                           Client_com.setClients_vector(Database.getDataVector(Client_com.getClientsIndex(0),"Clients","client_id"));
                        else
                            Client_com.setClients_vector(Database.getDataVector(Client_com.getClientsIndex(-1),"Clients","client_id"));
                        Client_com.setClientsMaxIndex( Client_com.getClientsMaxIndex()-1)
                        text_numer.text = Client_com.getClientsIndex(0)+1;
                        break;
                    case 4:
                        if(newData)
                            newData = false
                        if(Client_com.getClientsIndex(0) < Client_com.getClientsMaxIndex()-1)
                             Client_com.setClients_vector(Database.getDataVector(Client_com.getClientsIndex(1),"Clients","client_id"));
                        //image_textInput.text = Transport_company.Clients_vector[6];
                        text_numer.text = Client_com.getClientsIndex(0)+1;
                        break;
                    }
                }
            }
        }
    }
    }
}
