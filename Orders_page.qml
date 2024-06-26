import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window 2.15

Rectangle {
    anchors.fill: parent
    color: "lightgray"

    property var parameters_name: ["№ Заказа:","Клиент:","Водитель:","Дата поставки:","Адрес:"]
    property var button_name:  ["qrc:/Image/ButtonIcon/leftArrow.png","qrc:/Image/ButtonIcon/add.png","qrc:/Image/ButtonIcon/save.png","qrc:/Image/ButtonIcon/delete.png","qrc:/Image/ButtonIcon/leftArrow.png"]
    property var label_name: ["Поставщик","Материал","Гарантия","Партия","Количество","Скидка","Итоговая цена"]

    property var supplier_vector_order
    property var model_vector_order
    property var clients_vector_order
    property var drivers_vector_order

    property var marksComboBox: Database.getSupplierVectorName(indexVector)
    property var modelsComboBox: Database.getMaterialsVectorName(indexVector)
    property var saleText: []
    property var kolText: []

    property var volume: []
    property var power: []
    property var cost: []

    property var driver_temp: Database.getDriverName(Transport_company.Order_vector[2])
    property var clients_temp: Database.getClientName(Transport_company.Order_vector[1])

    property var indexVector: Transport_company.getInvoiceIndex(0)

    property var vectorSum: []

    property var newData: false

    function vectorPlus(vec)
    {
        var temp = 0
        for(let i = 0; i < vec.length; i++)
            temp += vec[i]
        return temp
    }

    ColumnLayout
    {

        property int test_r: 3
        anchors.fill: parent
        Header
        {
            name_page: "Заказы"
            id_page: orders_page
        }

        RowLayout
        {
            Layout.alignment: Qt.AlignHCenter
            Layout.leftMargin: parent.width * 0.05
            Layout.topMargin: parent.height * 0.05
            Layout.preferredWidth: parent.width * 0.9
            Layout.preferredHeight: parent.height *0.7 - parent.height * 0.05

            ColumnLayout
            {
                Layout.preferredHeight: parent.height
                Layout.preferredWidth: parent.width* 0.3

                Repeater
                {
                    model: 5
                    Rectangle
                    {
                        Layout.alignment: Qt.AlignHCenter
                        Layout.preferredHeight: parent.height*0.1
                        Layout.preferredWidth: parent.width *0.9
                        color: "#0B5FA5"
                        border.color: "black"
                        border.width: parent.height * 0.005
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
            }

            ColumnLayout
            {
                Layout.preferredHeight: parent.height
                Layout.preferredWidth: parent.width* 0.3

                Rectangle
                {
                    Layout.alignment: Qt.AlignLeft
                    Layout.preferredHeight: parent.height*0.1
                    Layout.preferredWidth: parent.width *0.9
                    color: "#00733E"
                    border.color: "black"
                    border.width: parent.height * 0.005
                    clip: true

                    TextInput {
                        id: text_idInput
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
                        text: qsTr(Transport_company.Order_vector[0])
                        horizontalAlignment: TextInput.AlignRight

                        onTextChanged:
                        {
                            Transport_company.Order_vector[0] = text_idInput.text
                        }
                    }
                }

                Rectangle
                {
                    Layout.alignment: Qt.AlignLeft
                    Layout.preferredHeight: parent.height*0.1
                    Layout.preferredWidth: parent.width *0.9
                    color: "#00733E"
                    border.color: "black"
                    border.width: parent.width * 0.001
                    clip: true

                     ComboBox {
                        id: comboBox_clients
                        anchors
                        {
                            verticalCenter: parent.verticalCenter
                            left: parent.left
                        }
                        width: parent.width
                        height: parent.height

                        model: clients_vector_order

                        currentIndex: 0

                        background: Rectangle {
                            color: "#00733E"
                        border.width: parent && parent.activeFocus ? 2 : 1
                        }

                        contentItem: Text {
                            id: client_text
                            text: clients_temp
                            color: "black"
                            font.pixelSize: parent.height * 0.6
                            horizontalAlignment: TextInput.AlignRight
                            verticalAlignment: TextInput.AlignVCenter
                            onTextChanged:
                            {
                                clients_temp = client_text.text
                            }
                        }


                            onActivated: {
                                client_text.text = comboBox_clients.currentText
                        }
                    }
                }

                Rectangle
                {
                    Layout.alignment: Qt.AlignLeft
                    Layout.preferredHeight: parent.height*0.1
                    Layout.preferredWidth: parent.width *0.9
                    color: "#00733E"
                    border.color: "black"
                    border.width: parent.width * 0.001
                    clip: true

                     ComboBox {
                        id: comboBox_driver
                        anchors
                        {
                            verticalCenter: parent.verticalCenter
                            left: parent.left
                        }
                        width: parent.width
                        height: parent.height

                        model: drivers_vector_order

                        currentIndex: 0

                        background: Rectangle {
                            color: "#00733E"
                        border.width: parent && parent.activeFocus ? 2 : 1
                        }

                        contentItem: Text {
                            id: text_driver
                            text: driver_temp
                            color: "black"
                            font.pixelSize: parent.height * 0.6
                            horizontalAlignment: TextInput.AlignRight
                            verticalAlignment: TextInput.AlignVCenter
                            onTextChanged:
                            {
                                driver_temp = text_driver.text
                            }
                        }


                            onActivated: {
                                text_driver.text = comboBox_driver.currentText
                        }
                    }
                }

                Repeater
                {
                    model: 2
                    Rectangle
                    {
                        Layout.alignment: Qt.AlignLeft
                        Layout.preferredHeight: parent.height*0.1
                        Layout.preferredWidth: parent.width *0.9
                        color: "#C0E8FF"
                        border.color: "black"
                        border.width: parent.height * 0.005
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
                            text: qsTr(Transport_company.Order_vector[index+3])
                            horizontalAlignment: TextInput.AlignRight

                            onTextChanged:
                            {
                                Transport_company.Order_vector[index+3] = text_textInput.text
                            }
                        }

                    }
                }
            }

            ColumnLayout
            {
                Layout.alignment: Qt.AlignHCenter
                Layout.preferredHeight: parent.height
                Layout.preferredWidth: parent.width* 0.4

                Item
                {
                    Layout.alignment: Qt.AlignLeft
                    Layout.preferredHeight: parent.height * 0.075
                    Layout.preferredWidth: parent.width * 0.85

                    Text
                    {
                        anchors
                        {
                            verticalCenter: parent.verticalCenter
                            right: cost_rect.left
                            rightMargin: parent.width * 0.075
                        }
                        text: qsTr("Итог: ")
                        font.pixelSize: parent.height * 0.6
                        font.bold: true
                    }
                    Rectangle
                    {
                        id: cost_rect
                        anchors
                        {
                            verticalCenter: parent.verticalCenter
                            right: parent.right
                        }
                        height: parent.height
                        width: parent.width * 0.5
                        color: "white"
                        border.color: "black"
                        clip: true

                        Text
                        {
                            id: cost_text_sum
                            anchors
                            {
                                verticalCenter: parent.verticalCenter
                                right: parent.right
                                rightMargin: parent.width * 0.05
                            }
                            text: vectorPlus(vectorSum)
                            font.pixelSize: parent.height* 0.4
                            horizontalAlignment: Text.AlignRight
                        }
                    }
                }

                Item
                {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }
            }
        }


        Item
        {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Rectangle
        {
            id: my_food_list
            Layout.alignment: Qt.alignTop | Qt.AlignHCenter
            Layout.preferredHeight: parent.height * 0.3
            Layout.preferredWidth: parent.width * 0.9
            clip: true
            border.color: "black"
            color: "#121212"

            Item
            {
                id: name_type
                anchors
                {
                    horizontalCenter: parent.horizontalCenter
                    top: parent.top
                }
                width: parent.width
                height: parent.height * 0.1

                RowLayout {
                    height: parent.height
                    width: parent.width
                    spacing: 0

                    Repeater
                    {
                        model: 7
                        Rectangle
                        {
                            Layout.alignment: Qt.AlignHCenter
                            Layout.preferredWidth: parent.width/7.05
                            Layout.preferredHeight: parent.height
                            color: "#00733E"
                            border.color: "black"
                            border.width: parent.width * 0.001

                            Text {
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
                                text: label_name[index]
                                horizontalAlignment: TextInput.AlignHCenter
                            }
                        }
                    }
                }
            }

            Item {
                anchors
                {
                    horizontalCenter: parent.horizontalCenter
                    top: name_type.bottom
                }
                width: parent.width
                height: parent.height - name_type.height

            ScrollView
            {
                anchors.fill: parent
                clip: true
                ScrollBar.vertical.policy: ScrollBar.AlwaysOff
                contentHeight: my_food_column.height

            ColumnLayout {
                id: my_food_column
                width: parent.width
                spacing: 0
                anchors
                {
                horizontalCenter: parent.horizontalCenter
                verticalCenter: parent.verticalCenter
                }

                    Repeater {
                        id: my_food_list_repeater
                        model: marksComboBox.length+1

                        RowLayout {
                            property var ebanIndex: index
                            Layout.preferredHeight: my_food_list.height* 0.2
                            Layout.preferredWidth: my_food_list.width
                            spacing: 0

                            Rectangle
                            {
                                Layout.alignment: Qt.AlignHCenter
                                Layout.preferredWidth: parent.width/7.05
                                Layout.preferredHeight: parent.height
                                color: "white"
                                border.color: "black"
                                border.width: parent.width * 0.001
                                clip: true

                                 ComboBox {
                                    id: comboBox
                                    anchors
                                    {
                                        verticalCenter: parent.verticalCenter
                                        left: parent.left
                                    }
                                    width: parent.width
                                    height: parent.height

                                    model: supplier_vector_order

                                    background: Rectangle {
                                        color: "white"
                                    border.width: parent && parent.activeFocus ? 2 : 1
                                    }

                                    contentItem: Text {
                                        id: marks_text
                                        text: marksComboBox[ebanIndex]
                                        color: "black"
                                        font.bold: true
                                        font.pixelSize: comboBox.height * 0.3
                                        horizontalAlignment: TextInput.AlignHCenter
                                        verticalAlignment: TextInput.AlignVCenter

                                        onTextChanged:
                                        {

                                            marksComboBox[ebanIndex] = marks_text.text
                                            comboBox1.model = Database.getAllModelMaterials(Database.getTextSupplier(Transport_company.Invoice_vector[(ebanIndex*6)+1]),true)
                                        }
                                    }


                                        onActivated: {
                                            Transport_company.Invoice_vector[(ebanIndex*6)+1] = comboBox.currentIndex
                                            marks_text.text = comboBox.currentText
                                            comboBox1.model = Database.getAllModelMaterials(comboBox.textAt(comboBox.currentIndex),true)
                                            model_text.text = ""
                                            }

                                             onActiveFocusChanged:
                                            {
                                                if(my_food_list_repeater.model-index === 1)
                                                {
                                                     my_food_list_repeater.model = ++my_food_list_repeater.model
                                                }


                                            }
                                        }
                                    }

                            Rectangle
                            {
                                Layout.alignment: Qt.AlignHCenter
                                Layout.preferredWidth: parent.width/7.05
                                Layout.preferredHeight: parent.height
                                color: "white"
                                border.color: "black"
                                border.width: parent.width * 0.001
                                clip: true

                                 ComboBox {
                                    id: comboBox1
                                    anchors
                                    {
                                        verticalCenter: parent.verticalCenter
                                        left: parent.left
                                    }
                                    width: parent.width
                                    height: parent.height

                                    model: Database.getAllModelMaterials("123",false)

                                    currentIndex: 0

                                    background: Rectangle {
                                        color: "white"
                                    border.width: parent && parent.activeFocus ? 2 : 1
                                    }

                                    contentItem: Text {
                                        id: model_text
                                        text: modelsComboBox[ebanIndex]
                                        color: "black"
                                        font.bold: true
                                        font.pixelSize: comboBox1.height * 0.3
                                        horizontalAlignment: TextInput.AlignHCenter
                                        verticalAlignment: TextInput.AlignVCenter

                                        onTextChanged:
                                        {
                                            modelsComboBox[ebanIndex] = model_text.text
                                            volume_text.text = Database.getItemMaterials(model_text.text,5)
                                            volume[ebanIndex] = volume_text.text
                                            power_text.text = Database.getItemMaterials(model_text.text,6)
                                            power[ebanIndex] = power_text.text
                                            cost_text.text = Database.getItemMaterials(model_text.text,7)
                                            cost[ebanIndex] = cost_text.text

                                            if(kol_text.text==="0")
                                                kol_text.text = 1;
                                            var temp = (cost[ebanIndex]*kol_text.text)*((100-parseInt(sale_text.text))/100)
                                           cost_text.text = temp
                                            vectorSum[ebanIndex] = temp
                                            console.log(vectorPlus(vectorSum))

                                            if(marks_text.text === "")
                                                model_text.text = " "
                                        }
                                    }

                                    onActivated: {
                                        model_text.text = comboBox1.currentText;
                                        volume_text.text = Database.getItemMaterials(model_text.text,5)
                                        volume[ebanIndex] = volume_text.text
                                        power_text.text = Database.getItemMaterials(model_text.text,6)
                                        power[ebanIndex] = power_text.text
                                        cost_text.text = Database.getItemMaterials(model_text.text,7)
                                        cost[ebanIndex] = cost_text.text

                                        if(kol_text.text==="0")
                                            kol_text.text = 1;
                                        var temp = (cost[ebanIndex]*kol_text.text)*((100-parseInt(sale_text.text))/100)
                                        cost_text.text = temp
                                        if(marks_text.text === "")
                                            model_text.text = " "
                                    }
                                }
                            }

                            Rectangle
                            {
                                Layout.alignment: Qt.AlignHCenter
                                Layout.preferredWidth: parent.width/7.05
                                Layout.preferredHeight: parent.height
                                color: "lightgray"
                                border.color: "black"
                                border.width: parent.width * 0.001
                                clip: true
                                Text {
                                    id: volume_text
                                    anchors
                                    {
                                        verticalCenter: parent.verticalCenter
                                        right: parent.right
                                        rightMargin: parent.width * 0.05
                                    }
                                    width: parent.width * 0.95
                                    height: parent.height
                                    color: "black"
                                    font.bold: true
                                    font.pixelSize: comboBox.height * 0.3
                                    text: volume[ebanIndex]
                                    horizontalAlignment: TextInput.AlignHCenter
                                    verticalAlignment: TextInput.AlignVCenter
                                }
                            }

                            Rectangle
                            {
                                Layout.alignment: Qt.AlignHCenter
                                Layout.preferredWidth: parent.width/7.05
                                Layout.preferredHeight: parent.height
                                color: "lightgray"
                                border.color: "black"
                                border.width: parent.width * 0.001
                                clip: true
                                Text {
                                    id: power_text
                                    anchors
                                    {
                                        verticalCenter: parent.verticalCenter
                                        right: parent.right
                                        rightMargin: parent.width * 0.05
                                    }
                                    width: parent.width * 0.95
                                    height: parent.height
                                    color: "black"
                                    font.bold: true
                                    font.pixelSize: comboBox.height * 0.3
                                    text: power[ebanIndex]
                                    horizontalAlignment: TextInput.AlignHCenter
                                    verticalAlignment: TextInput.AlignVCenter
                                }
                            }

                            Rectangle
                            {
                                Layout.alignment: Qt.AlignHCenter
                                Layout.preferredWidth: parent.width/7.05
                                Layout.preferredHeight: parent.height
                                color: "white"
                                border.color: "black"
                                border.width: parent.width * 0.001
                                clip: true
                                TextInput {
                                    id: kol_text
                                    anchors
                                    {
                                        verticalCenter: parent.verticalCenter
                                        right: parent.right
                                        rightMargin: parent.width * 0.05
                                    }
                                    width: parent.width * 0.95
                                    height: parent.height
                                    color: "black"
                                    font.bold: true
                                    font.pixelSize: comboBox.height * 0.3
                                    text: if(newData) return kolText[ebanIndex]
                                            else return Transport_company.Invoice_vector[(ebanIndex*6)+3]
                                    horizontalAlignment: TextInput.AlignHCenter
                                    verticalAlignment: TextInput.AlignVCenter

                                    onTextChanged:
                                    {
                                        kolText[ebanIndex] = kol_text.text
                                        if(kol_text.text==="0")
                                            kol_text.text = 1;
                                        var temp  = (cost[ebanIndex]*kol_text.text)*((100-parseInt(sale_text.text))/100)
                                        cost_text.text = temp
                                        vectorSum[ebanIndex] = temp
                                        cost_text_sum.text = vectorPlus(vectorSum)

                                    }

                                    onActiveFocusChanged:
                                    {
                                        if(my_food_list_repeater.model-index === 1)
                                            my_food_list_repeater.model = ++my_food_list_repeater.model
                                    }

                                    onAccepted: {
                                        if(kol_text.text==="0")
                                            kol_text.text = 1;
                                        var temp  = (cost[ebanIndex]*kol_text.text)*((100-parseInt(sale_text.text))/100)
                                        vectorSum[ebanIndex] = temp
                                        cost_text_sum.text = vectorPlus(vectorSum)
                                    }
                                }
                            }

                            Rectangle
                            {
                                Layout.alignment: Qt.AlignHCenter
                                Layout.preferredWidth: parent.width/7.05
                                Layout.preferredHeight: parent.height
                                color: "white"
                                border.color: "black"
                                border.width: parent.width * 0.001
                                clip: true
                                TextInput {
                                    id: sale_text
                                    anchors
                                    {
                                        verticalCenter: parent.verticalCenter
                                        right: parent.right
                                        rightMargin: parent.width * 0.05
                                    }
                                    width: parent.width * 0.95
                                    height: parent.height
                                    color: "black"
                                    font.bold: true
                                    font.pixelSize: comboBox.height * 0.3
                                    text: if(newData) return saleText[ebanIndex]
                                            else return Transport_company.Invoice_vector[(ebanIndex*6)+4]
                                    horizontalAlignment: TextInput.AlignHCenter
                                    verticalAlignment: TextInput.AlignVCenter

                                    onTextChanged:
                                    {
                                        saleText[ebanIndex] = sale_text.text
                                    }

                                    onActiveFocusChanged:
                                    {
                                        if(my_food_list_repeater.model-index === 1)
                                            my_food_list_repeater.model = ++my_food_list_repeater.model
                                    }

                                    onAccepted: {
                                        if(kol_text.text==="0")
                                            kol_text.text = 1;
                                        var temp  = (cost[ebanIndex]*kol_text.text)*((100-parseInt(sale_text.text))/100)
                                        cost_text.text = temp
                                        vectorSum[ebanIndex] = temp
                                        cost_text_sum.text = vectorPlus(vectorSum)
                                    }
                                }
                            }

                            Rectangle
                            {
                                Layout.alignment: Qt.AlignHCenter
                                Layout.preferredWidth: parent.width/7.05
                                Layout.preferredHeight: parent.height
                                color: "lightgray"
                                border.color: "black"
                                border.width: parent.width * 0.001
                                clip: true
                                Text {
                                    id: cost_text
                                    anchors
                                    {
                                        verticalCenter: parent.verticalCenter
                                        right: parent.right
                                        rightMargin: parent.width * 0.05
                                    }
                                    width: parent.width * 0.95
                                    height: parent.height
                                    color: "black"
                                    font.bold: true
                                    font.pixelSize: comboBox.height * 0.3
                                    text: cost[ebanIndex]
                                    horizontalAlignment: TextInput.AlignHCenter
                                    verticalAlignment: TextInput.AlignVCenter

                                    onTextChanged:
                                    {
                                        if(marks_text.text === "")
                                            cost_text.text = " "
                                    }
                                }
                            }
                        }
                    }
                }
            }
       }
        }

        Item
        {
            Layout.fillHeight: true
            Layout.fillWidth: true
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
                    Layout.preferredHeight: parent.height * 0.6
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
                            console.log(marksComboBox)
                            if(newData)
                                newData = false
                            if(Transport_company.getOrderIndex(0) > 0)
                            {
                                Transport_company.setOrder_vector(Database.getDataVector(Transport_company.getOrderIndex(-1),"Orders","id_order"));

                                Transport_company.invoice_clearVector()
                                volume = []
                                power = []
                                cost = []
                                my_food_list_repeater.model = 0

                            Transport_company.setInvoiceIndex(Database.getIndexOrder(Transport_company.getInvoiceIndex(0),false));
                            indexVector =  Transport_company.getInvoiceIndex(0)
                            Transport_company.setInvoice_vector(Database.getInvoiceDataVector("Invoice","id_order",Transport_company.getInvoiceIndex(0)));
                            comboBox_clients.currentIndex = Database.getIndexClients(clients_vector_order,Transport_company.Order_vector[1])
                            client_text.text = comboBox_clients.currentText

                            comboBox_driver.currentIndex = Database.getIndexDrivers(drivers_vector_order,Transport_company.Order_vector[2])
                            text_driver.text = comboBox_driver.currentText
                             my_food_list_repeater.model = marksComboBox.length+1
                                cost_text_sum.text = vectorPlus(vectorSum)
                            }
                            break;
                        case 1:
                            newData = true;
                            Transport_company.order_clearVector();
                            Transport_company.invoice_clearVector()
                            kolText = []
                            saleText = []
                            volume = []
                            power = []
                            cost = []
                            vectorSum = []
                            indexVector = 0;
                            client_text.text = "Выберете клиента"
                            text_driver.text = "Выберете водителя"
                            my_food_list_repeater.model = 1;
                            cost_text_sum.text = 0
                            break;
                        case 2:
                            console.log(Transport_company.Order_vector[1])
                            Transport_company.Order_vector[6] = vectorPlus(vectorSum)
                            Transport_company.Order_vector[1] = Database.getIdClientName(comboBox_clients.textAt(comboBox_clients.currentIndex))
                            Transport_company.Order_vector[2] = Database.getIdDriverName(comboBox_driver.textAt(comboBox_driver.currentIndex))
                            console.log(Transport_company.Order_vector[1])
                            var temp_vector  = Database.getIdInvoice(Transport_company.Order_vector[0])
                            while(temp_vector.length < marksComboBox.length)
                                temp_vector.push("-1")
                            if(newData)
                            {
                                Database.orders_createNewData(Transport_company.Order_vector)
                                var indexTemp = Database.getLastIndexOrder()
                                for(let i = 0; i < marksComboBox.length; i++)
                                    Database.invoices_createNewData(Database.getSupplierId(marksComboBox[i]),Database.getIdMaterialsName(modelsComboBox[i]),kolText[i],saleText[i], indexTemp)

                            }
                            else
                            {
                                Database.orders_addNewData(Transport_company.Order_vector)
                                for(let i = 0; i < marksComboBox.length; i++)
                                {
                                    if(temp_vector[i] !== "-1")
                                        Database.invoices_addNewData(Database.getSupplierId(marksComboBox[i]),Database.getIdMaterialsName(modelsComboBox[i]),kolText[i],saleText[i], temp_vector[i])
                                    else
                                        Database.invoices_createNewData(Database.getSupplierId(marksComboBox[i]),Database.getIdMaterialsName(modelsComboBox[i]),kolText[i],saleText[i], Transport_company.Order_vector[0])
                                }
                            }
                            break;
                        case 3:
                            Database.invoice_truncate(Transport_company.Order_vector[0])
                            Database.delete_Data(Transport_company.Order_vector[0], "Orders","id_order");
                            if(Transport_company.getOrderIndex(0) < Transport_company.getOrderMaxIndex()-1)
                                Transport_company.setOrder_vector(Database.getDataVector(Transport_company.getOrderIndex(1),"Orders","id_order"));
                            else
                                Transport_company.setOrder_vector(Database.getDataVector(Transport_company.getOrderIndex(-1),"Orders","id_order"));
                            Transport_company.setOrderMaxIndex(Transport_company.getOrderMaxIndex()-1)
                            break;
                        case 4:
                            if(newData)
                                newData = false
                            if(Transport_company.getOrderIndex(0) < Transport_company.getOrderMaxIndex()-1)
                            {
                                 Transport_company.setOrder_vector(Database.getDataVector(Transport_company.getOrderIndex(1),"Orders","id_order"));
                                Transport_company.invoice_clearVector()
                                volume = []
                                power = []
                                cost = []
                                vectorSum = []
                                my_food_list_repeater.model = 0
                            Transport_company.setInvoiceIndex(Database.getIndexOrder(Transport_company.getInvoiceIndex(0),true));
                            indexVector =  Transport_company.getInvoiceIndex(0)
                            Transport_company.setInvoice_vector(Database.getInvoiceDataVector("Invoice","id_order",Transport_company.getInvoiceIndex(0)));
                                comboBox_clients.currentIndex = Database.getIndexClients(clients_vector_order,Transport_company.Order_vector[1])
                                client_text.text = comboBox_clients.currentText

                                comboBox_driver.currentIndex = Database.getIndexDrivers(drivers_vector_order,Transport_company.Order_vector[2])
                                text_driver.text = comboBox_driver.currentText
                                my_food_list_repeater.model = marksComboBox.length+1
                                cost_text_sum.text = vectorPlus(vectorSum)
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}
