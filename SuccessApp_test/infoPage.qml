import QtQuick 2.0

Item {

    Image {
        id: backGroundTP
        source: "qrc:/trustedBack.png"
        anchors.fill: parent
        // opacity: 0.9

        Flickable{
            id: trustedFlick
            width: backGroundTP.width
            height: backGroundTP.height
            anchors.horizontalCenter: backGroundTP.horizontalCenter
            contentHeight: aboutTxt.height + e_mail.height + 200
            contentWidth: parent.width
            smooth: true
            boundsBehavior: Flickable.StopAtBounds
            interactive: true
            maximumFlickVelocity: 1000000
            clip: true

            Text {
                id: aboutTxt
                anchors.top: parent.top
                anchors.topMargin: 10
                width: backGroundTP.width * 0.9
                height: backGroundTP.height * 0.9
                anchors.horizontalCenter: parent.horizontalCenter
                horizontalAlignment: Text.AlignHCenter

                text: "Успех личный кабинет код версии: 24_ARMv7 <br>
                           Данное приложение бесплатно <br>
                           и может быть использовано Вами <br>
                           в любых законных целях и любым <br>
                           законным способом.<br>
                           В случае, если Вы хотите получить <br>
                           экземпляр исходного кода, напишите <br>
                           об этом разработчику на: <br>
                           errorgrisha@gmail.com <br>
                           Картографические материалы <br>
                           используются под открытой лицензией <br>
                           сообщества creativecommons.org, <br>
                           и являются частью открытого проекта <br>
                           opendatacommons.org.<br>
                           Подробнее: www.openstreetmap.org/copyright <br>

                           This app is absolutely free for using <br>
                           in any legal purposes. <br>
                           In case you want to get a source code <br>
                           of the application please feel free <br>
                           to ask developer about it: <br>
                           errorgrisha@gmail.com <br>
                           The cartographical materials <br>
                           are licensed under <br>
                           the creativecommons.org community <br>
                           and are part of <br>
                           the open source project opendatacommons.org. <br>
                           Details: www.openstreetmap.org/copyright
                           <br> Любые Ваши вопросы и предложения:"
                color: "white"
            }

            Text {
                id: e_mail
                anchors.top: aboutTxt.bottom
                anchors.topMargin: 10
                anchors.horizontalCenter: parent.horizontalCenter
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 25
                color: "white"
                text: "errorgrisha@gmail.com"
            }
        }
    }

}
