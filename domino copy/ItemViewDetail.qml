import QtQuick 2.7

Item {
    id: itemView
    x: 0
    y: 0
    width: parent.width/2
    height: width

    property string name
    property string price
    property string image
    property string oriprace
    property string promtype

    property int cell: width/16

    MouseArea {
        anchors.fill: parent

        onClicked: {
            mainController.insertItem(name, price, oriprice, promtype)
        }
    }

    Image {
        id: image
        x: cell*2
        y: cell*2
        width: parent.width - 4*cell
        height: width
        source: itemView.image
    }

    Text {
        id: textName
        anchors.top: image.bottom
        width: parent.width
        text: name
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 16
    }

    Text {
        id: textPrice
        anchors.top: textName.bottom
        width: parent.width
        text: price
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 16
    }
}

