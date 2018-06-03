#!/usr/bin/python3

import sys
import subprocess
import time
import serial
import spidev
import pymysql

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
   cur_num1 = 0
   next_num1 = 0
   lead_time1 = 0
   cur_num2 = 0
   next_num2 = 0
   lead_time2 = 0

   def setupUI(self, MainWindow):
      self.centralwidget = QWidget(MainWindow)
      self.databaseConnect()

      self.select1ButtonUI()
      self.select2ButtonUI()

      self.backButton = QPushButton("되돌아가기", self.centralwidget)
      self.backButton.resize(self.backButton.sizeHint())
      self.backButton.move(700, 440)

      self.closeButtonUI(MainWindow)

      MainWindow.setCentralWidget(self.centralwidget)

   def databaseConnect(self):
      conn = pymysql.connect(host='ybj.cghzrrdlqojc.ap-northeast-2.rds.amazonaws.com', port=3306, user='woojae', passwd='YBJ11111', db='free_time', charset='utf8')
      cursor = conn.cursor()

      try:
         sql0 = """SELECT waiting_num FROM number WHERE date=CURRENT_DATE() AND
                   store_id='1' AND counter_id='1' AND calling_end IS NULL
                   ORDER BY waiting_num ASC limit 1"""
         sql1 = """SELECT waiting_num FROM number WHERE date=CURRENT_DATE() AND
                   store_id='1' AND counter_id='1' ORDER BY waiting_num
                   DESC limit 1"""
         sql2 = """SELECT lead_time FROM counter WHERE
                   counter_id='1' AND store_id='1'"""
         sql3 = """SELECT waiting_num FROM number WHERE date=CURRENT_DATE() AND
                   store_id='1' AND counter_id='2' AND calling_end IS NULL
                   ORDER BY waiting_num ASC limit 1"""
         sql4 = """SELECT waiting_num FROM number WHERE date=CURRENT_DATE() AND
                   store_id='1' AND counter_id='2' ORDER BY waiting_num
                   DESC limit 1"""
         sql5 = """SELECT lead_time FROM counter WHERE
                   counter_id='2' AND store_id='1'"""

         cursor.execute(sql0)
         res = cursor.fetchall()
         for row in res:
            global cur_num1
            cur_num1 = row[0]
            print("\n\t사주의 current number: " + str(self.cur_num1))

         cursor.execute(sql1)
         res = cursor.fetchall()
         for row in res:
            global next_num1
            next_num1 = row[0]+1
            print("\t사주의 waiting number: " + str(next_num1))

         cursor.execute(sql2)
         res = cursor.fetchall()
         for row in res:
            global lead_time1
            lead_time1 = row[0]
            print("\t사주의 lead time per 1 person: " + str(lead_time1) + "\n")

         cursor.execute(sql3)
         res = cursor.fetchall()
         for row in res:
            global cur_num2
            cur_num2 = row[0]
            print("\t타로의 current number: " + str(cur_num2))

         cursor.execute(sql4)
         res = cursor.fetchall()
         for row in res:
            global next_num2
            next_num2 = row[0]+1
            print("\t타로의 waiting number: " + str(next_num2))

         cursor.execute(sql5)
         res = cursor.fetchall()
         for row in res:
            global lead_time2
            lead_time2 = row[0]
            print("\t타로의 lead time per 1 person: " + str(lead_time2) + "\n")

      except mysql.connector.Error as err:
         if err.errno == errorcode.ER_ACCESS_DENIED_ERROR:
            print('id or password error')
         elif err.errno == errorcode.ER_BAD_DB_ERROR:
            print('db connection error')
         else:
            print('etc error', err)
         conn.rollback()

      finally:
         cursor.close()

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

      select3Label = QLabel("<font color='red'>대기인원: "+str(next_num1-cur_num1)+"명", self.centralwidget)
      select3Label.setGeometry(100, 410, 150, 50)
      select3Font = QFont()
      select3Font.setPointSize(10)
      select3Font.setBold(True)
      select3Label.setFont(select3Font)

      select4Label = QLabel("<font color='red'>예상대기시간: "+str((next_num1-cur_num1)*lead_time1)+"분", self.centralwidget)
      select4Label.setGeometry(200, 410, 150, 50)
      select4Font = QFont()
      select4Font.setPointSize(10)
      select4Font.setBold(True)
      select4Label.setFont(select4Font)

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

      select5Label = QLabel("<font color='red'>대기인원: "+str(next_num2-cur_num2)+"명", self.centralwidget)
      select5Label.setGeometry(470, 410, 150, 50)
      select5Font = QFont()
      select5Font.setPointSize(10)
      select5Font.setBold(True)
      select5Label.setFont(select5Font)

      select6Label = QLabel("<font color='red'>예상대기시간: "+str((next_num2-cur_num2)*lead_time2)+"분", self.centralwidget)
      select6Label.setGeometry(570, 410, 150, 50)
      select6Font = QFont()
      select6Font.setPointSize(10)
      select6Font.setBold(True)
      select6Label.setFont(select6Font)

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
      imgLabel.setGeometry(10, 10, 70, 70)
      logoImg = QPixmap('logo.png')
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
      self.selectAction.select1Button.clicked.connect(self.startTagDevice)
      self.selectAction.select2Button.clicked.connect(self.startTagDevice)
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
