import serial



from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import QTimer




class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.setStyleSheet("QLabel\n"
"{\n"
"    \n"
"    color: #fcfdfc;\n"
"}\n"
"")
        self.wrapper = QtWidgets.QWidget(MainWindow)
        self.wrapper.setMinimumSize(QtCore.QSize(1000, 403))
        self.wrapper.setMaximumSize(QtCore.QSize(100051, 16777215))
        self.wrapper.setObjectName("wrapper")
        self.Background = QtWidgets.QLabel(self.wrapper)
        self.Background.setGeometry(QtCore.QRect(9, 9, 982, 600))
        self.Background.setMinimumSize(QtCore.QSize(0, 600))
        self.Background.setText("")
        self.Background.setPixmap(QtGui.QPixmap(":/back.jpg"))
        self.Background.setScaledContents(True)
        self.Background.setObjectName("Background")
        self.Header = QtWidgets.QFrame(self.wrapper)
        self.Header.setGeometry(QtCore.QRect(0, 10, 1000, 100))
        self.Header.setMinimumSize(QtCore.QSize(1000, 0))
        self.Header.setMaximumSize(QtCore.QSize(16777215, 100))
        self.Header.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.Header.setFrameShadow(QtWidgets.QFrame.Raised)
        self.Header.setObjectName("Header")
        self.logo = QtWidgets.QLabel(self.Header)
        self.logo.setGeometry(QtCore.QRect(10, 10, 71, 80))
        self.logo.setText("")
        self.logo.setPixmap(QtGui.QPixmap(":/iti.png"))
        self.logo.setScaledContents(True)
        self.logo.setObjectName("logo")
        self.GroupName = QtWidgets.QLabel(self.Header)
        self.GroupName.setGeometry(QtCore.QRect(340, 0, 281, 100))
        self.GroupName.setMinimumSize(QtCore.QSize(0, 100))
        font = QtGui.QFont()
        font.setFamily("Haettenschweiler")
        font.setPointSize(24)
        self.GroupName.setFont(font)
        self.GroupName.setAlignment(QtCore.Qt.AlignCenter)
        self.GroupName.setObjectName("GroupName")
        self.Readings = QtWidgets.QFrame(self.wrapper)
        self.Readings.setGeometry(QtCore.QRect(0, 100, 1000, 500))
        self.Readings.setMinimumSize(QtCore.QSize(1000, 500))
        self.Readings.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.Readings.setFrameShadow(QtWidgets.QFrame.Raised)
        self.Readings.setObjectName("Readings")
        self.horizontalLayout = QtWidgets.QHBoxLayout(self.Readings)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.Distance = QtWidgets.QLabel(self.Readings)
        self.Distance.setAlignment(QtCore.Qt.AlignCenter)
        self.Distance.setObjectName("Distance")
        self.horizontalLayout.addWidget(self.Distance)
        self.Speed = AnalogGaugeWidget(self.Readings)
        self.Speed.setObjectName("Speed")
        self.Speed.setDisplayValueColor(252,253,252,255)
        self.Speed.setScaleValueColor(252,253,252,255)
        font = QtGui.QFont('Seven Segment', 24,QtGui.QFont.Bold)
        self.GroupName.setFont(font)
        self.Distance.setFont(font)
        self.Speed.setFont(font)
        self.Speed.setNeedleCenterColor(color1 = "#011159", color2 = "#4c67e0",
                                        color3 = "#131314")
        self.Speed.setOuterCircleColor(color1 = "#000", color2 = "#ffffff",
                                        color3 = "#011159")
        self.Speed.setScalePolygonColor(color1 = "#020226", color2 = "#48494a",
                                        color3 = "#fff")
        self.horizontalLayout.addWidget(self.Speed)
        self.Update = QtWidgets.QFrame(self.wrapper)
        self.Update.setGeometry(QtCore.QRect(10, 550, 120, 80))
        self.Update.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.Update.setFrameShadow(QtWidgets.QFrame.Raised)
        self.Update.setObjectName("Update")
        MainWindow.setCentralWidget(self.wrapper)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.GroupName.setText(_translate("MainWindow", " New Capital\n"
" Group 1.1"))
        self.Distance.setText(_translate("MainWindow", "Distance Ahead\n"
""))
    
    def update(self):
        ser.reset_input_buffer()
        response = ser.read_until(b'\r\n')
        input = response.decode('utf-8')
        input = input[:-2].split(' ')
        #print the input
        print(input)
        if len(input) > 1:
            if (input[1].replace('.','',1)).isdigit():
                if input[0] == 'S':
                    speedFile = open('/home/moazromih/Desktop/project/speed.txt','w')
                    speedFile.write(input[1])
                    speedFile.close()
                elif input[0] == '':
                    distanceFile = open('/home/moazromih/Desktop/project/distance.txt', 'w')
                    distanceFile.write(str(round(float(input[1]),2)))
                    distanceFile.close()
        SpeedFile = open("/home/moazromih/Desktop/project/speed.txt",'r')
        speed = float(SpeedFile.read())
        SpeedFile.close()
        distanceFile = open("/home/moazromih/Desktop/project/distance.txt",'r')
        distance = float(distanceFile.read())
        distanceFile.close()
        self.Speed.updateValue(speed)
        self.Distance.setText("Distance Ahead\n"+str(distance)+" cm")




from analoggaugewidget import AnalogGaugeWidget
import source_rc


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.timer = QTimer(MainWindow)
    MainWindow.setWindowTitle("New Capital Group 1.1 Project")
    MainWindow.showMaximized()
    MainWindow.timer.timeout.connect(ui.update)
    MainWindow.show()
    ser = serial.Serial('/dev/ttyAMA0', 9600, timeout=None, rtscts = True)
    ser.readline()
    MainWindow.timer.start(1)
    sys.exit(app.exec_())
