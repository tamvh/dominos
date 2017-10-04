import QtQuick 2.0

Item  {
    id: timerCountdown
    width: 30

    property int fontSize: fntsize //mainController.getConfigBillItemFontsize()
    property double delayTimer: 90000; //1000 milisecond = 1 second
    property double startTime: 0
    property int minutesElapsed: 0
    property int secondsElapsed: 0
    property var parentId:0

    function restartTimerCounter()  {
        timerCountdown.startTime = 0;
        timerCountdown.minutesElapsed = 0;
        timerCountdown.secondsElapsed = 0;

        elapsedTimer.running = true;
    }

    function stopTimerCounter() {
        elapsedTimer.running = false;
    }

    function timeChanged()  {
        if(timerCountdown.startTime<=0)
        {
            //returns the number of milliseconds since the epoch (1970-01-01T00:00:00Z);
            timerCountdown.startTime = new Date().getTime() + delayTimer;
        }
        var timeCounter = (startTime - new Date().getTime())/1000;

        if (timeCounter < 0) {
            startTime = 0;
            if (parentId === 1) {
                payZaloDialog.doCancelBill();
            }
            else if (parentId === 2) {
                getBillAlert.close();
            }
            else if (parentId === 3) {
                mainController.idleClearup();
                systemIdleAlert.close();
                idProfilePage.close();
                deleteItemDialog.close();
                window.window_enable = true
                mainController.closeThanhtoan(0);
            }
            else if(parentId === 4) {
                getErrAlert.close();
            }
        }

        timerCountdown.minutesElapsed = (timeCounter)/60;
        timerCountdown.secondsElapsed = (timeCounter - (timerCountdown.minutesElapsed*60));
    }

    Timer  {
        id: elapsedTimer
        interval: 1000;
        running: false;
        repeat: true;
        onTriggered: timerCountdown.timeChanged()
    }

    Text {
        id: counterText
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        // conver one-number-digit >> two-number-digit; 9 >> 09 ...
        text: ("0" + timerCountdown.minutesElapsed).slice(-2) + ":" + ("0"+timerCountdown.secondsElapsed).slice(-2)
        font.pixelSize: fontSize
    }
}
