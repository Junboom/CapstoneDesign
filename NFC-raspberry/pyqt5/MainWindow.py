import sys
import subprocess
import time
import serial
import spidev

from multiprocessing import Process
from PyQt5.QtWidgets import QWidget, QApplication, QMainWindow, QFrame, QLabel, QPushButton, QMessageBox
from PyQt5.QtGui import QFont, QPixmap
from PyQt5.QtCore import Qt, QCoreApplication  # 이벤트 처리 해결
from PyQt5 import uic


class TagDevice(object):
   def setupUI(self, MainWindow):
      self.centralwidget = QWidget(MainWindow)

      self.mainLabel = QPushButton("종 이 순 번\n\n대 기 표", self.centralwidget)
      self.mainLabel.setGeometry(80, 100, 280, 280)
      mainFont = QFont()
      mainFont.setPointSize(20)
      mainFont.setBold(True)
      self.mainLabel.setFont(mainFont)

      self.subLabelUI()
      self.nfcButtonUI()
      self.closeButtonUI(MainWindow)

      MainWindow.setCentralWidget(self.centralwidget)

   def subLabelUI(self):
      subLabel = QLabel("iPhone사용자는 종이순번대기표를 터치해주세요", self.centralwidget)
      subLabel.setGeometry(440, 440, 345, 25)
      subFont = QFont()
      subFont.setPointSize(12)
      subLabel.setFont(subFont)

   def nfcButtonUI(self):
      self.nfcButton = QPushButton("A n d r o i d\n\n사 용 자", self.centralwidget)
      self.nfcButton.setGeometry(440, 100, 280, 280)
      nfcFont = QFont()
      nfcFont.setPointSize(20)
      nfcFont.setBold(True)
      self.nfcButton.setFont(nfcFont)
      self.nfcButton.clicked.connect(lambda: self.nfc_tag())

   def closeButtonUI(self, MainWindow):
      closeButton = QPushButton("사용 종료", self.centralwidget)
      closeButton.resize(closeButton.sizeHint())
      closeButton.move(700, 10)
      closeButton.clicked.connect(MainWindow.close)

   def nfc_tag(self):
      number_nfc = "./tag.py"
      subprocess.call(number_nfc, shell=True)


class SelectAction(object):
   def setupUI(self, MainWindow):
      self.centralwidget = QWidget(MainWindow)

      self.select1ButtonUI()
      self.select2ButtonUI()

      self.backButton = QPushButton("되돌아가기", self.centralwidget)
      self.backButton.resize(self.backButton.sizeHint())
      self.backButton.move(690, 440)

      self.closeButtonUI(MainWindow)

      MainWindow.setCentralWidget(self.centralwidget)

   def select1ButtonUI(self):
      self.select1Button = QPushButton(self.centralwidget)
      self.select1Button.setGeometry(80, 100, 280, 280)
      self.select1Button.setStyleSheet('QPushButton {background-image: url("created_button1.jpg")}')
      self.select1Button.clicked.connect(lambda: self.print_saju(MainWindow))

      select1Label = QLabel("사  주", self.centralwidget)
      select1Label.setGeometry(190, 380, 150, 50)
      select1Font = QFont()
      select1Font.setPointSize(20)
      select1Font.setBold(True)
      select1Label.setFont(select1Font)

   def select2ButtonUI(self):
      self.select2Button = QPushButton(self.centralwidget)
      self.select2Button.setGeometry(440, 100, 280, 280)
      self.select2Button.setStyleSheet('QPushButton {background-image: url("created_button2.jpg")}')
      self.select2Button.clicked.connect(lambda: self.print_taro(MainWindow))

      select2Label = QLabel("타  로", self.centralwidget)
      select2Label.setGeometry(550, 380, 150, 50)
      select2Font = QFont()
      select2Font.setPointSize(20)
      select2Font.setBold(True)
      select2Label.setFont(select2Font)

   def closeButtonUI(self, MainWindow):
      closeButton = QPushButton("사용 종료", self.centralwidget)
      closeButton.resize(closeButton.sizeHint())
      closeButton.move(700, 10)
      closeButton.clicked.connect(MainWindow.close)

   def print_saju(self, MainWindow):
      number_print = "./number_saju.py"
      subprocess.call(number_print)

   def print_taro(self, MainWindow):
      number_print = "./number_taro.py"
      subprocess.call(number_print)


class MainWindow(QMainWindow):
   def __init__(self, parent=None):
      super(MainWindow, self).__init__(parent)

      self.setGeometry(0, -1, 800, 480)
      self.frameUI()
      self.imgLabelUI()
      self.nameLabelUI()

      self.tagDevice = TagDevice()
      self.selectAction = SelectAction()
      self.startTagDevice()

   def frameUI(self):
      frame = QFrame(self)
      frame.setGeometry(0, -1, 800, 480)
      frame.setWindowTitle("free_time")
      frame.setStyleSheet('QFrame {background-image: url("background.jpg")}')

   def imgLabelUI(self):
      imgLabel = QLabel(self)
      imgLabel.setGeometry(20, 20, 50, 50)
      logoImg = QPixmap('freetime.png')
      scaledLogoImg = logoImg.scaled(imgLabel.size(), Qt.KeepAspectRatio)
      imgLabel.setPixmap(scaledLogoImg)

   def nameLabelUI(self):
      nameLabel = QLabel("자 유 시 간", self)
      nameLabel.setGeometry(80, 20, 200, 40)
      nameFont = QFont()
      nameFont.setPointSize(30)
      nameFont.setBold(True)
      nameLabel.setFont(nameFont)

   def startTagDevice(self):
      self.tagDevice.setupUI(self)
      self.tagDevice.mainLabel.clicked.connect(self.startSelectAction)
      self.show()

   def startSelectAction(self):
      self.selectAction.setupUI(self)
      self.selectAction.backButton.clicked.connect(self.startTagDevice)
      self.show()

   def closeEvent(self, QCloseEvent):
      ans = QMessageBox.question(self, "사용 종료", "종료하시겠습니까?",
                  QMessageBox.Yes|QMessageBox.No, QMessageBox.No)
      if ans == QMessageBox.Yes:
         QCoreApplication.instance().quit   # 프로그램 종료
      else:
         QCloseEvent.ignore()


if __name__ == '__main__':
   app = QApplication(sys.argv)   # 객체 생성
   w = MainWindow()   # 창을 띄워줌
   # subprocess.call("./Write.py", shell=True)
   # subprocess.call("./nfc-poll")
   # subprocess.call("./nfc-tag.py", shell=True)
   sys.exit(app.exec_())  # 메인 루프 종료 시 창을 닫음
