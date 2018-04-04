import sys

from PyQt5.QtWidgets import QWidget, QApplication, QMainWindow, QFrame, QLabel, QPushButton, QMessageBox
from PyQt5.QtGui import QFont, QPixmap
from PyQt5.QtCore import Qt, QCoreApplication	# 이벤트 처리 해결

class TagDevice(object):
	def setupUI(self, MainWindow):
		MainWindow.setGeometry(200, 100, 1940, 1100)	# 화면 위치
		MainWindow.setWindowTitle("자유시간")
		self.centralwidget = QWidget(MainWindow)
		self.frameUI()
		self.imgLabelUI()
		self.nameLabelUI()
		self.mainLabelUI()
		self.subLabelUI()
		self.closeButtonUI()
		MainWindow.setCentralWidget(self.centralwidget)
	
	def frameUI(MainWindow):
		frame = QFrame(MainWindow.centralwidget)
		frame.setGeometry(100, 50, 1740, 1000)
		frame.setStyleSheet('QFrame {background-image: url("images.jpg")}')
	
	def imgLabelUI(MainWindow):
		imgLabel = QLabel(MainWindow.centralwidget)
		imgLabel.setGeometry(50, 25, 200, 200)
		img = QPixmap('images.jpg')
		scaledImg = img.scaled(imgLabel.size(), Qt.KeepAspectRatio)
		imgLabel.setPixmap(scaledImg)
	
	def nameLabelUI(self):
		self.nameLabel = QLabel("자 유 시 간", self)
		self.nameLabel.setGeometry(300, 25, 600, 200)
		nameFont = QFont()
		nameFont.setPointSize(30)
		nameFont.setBold(True)
		self.nameLabel.setFont(nameFont)
	
	def mainLabelUI(self):
		self.mainLabel = QPushButton("태 그 를  해 주 세 요", self)
		self.mainLabel.setGeometry(200, 300, 1600, 600)
		mainFont = QFont()
		mainFont.setPointSize(50)
		mainFont.setBold(True)
		self.mainLabel.setFont(mainFont)
	
	def subLabelUI(self):
		self.subLabel = QLabel("태그를 못 한다면 터치를 해주세요", self)
		self.subLabel.setGeometry(1200, 950, 650, 200)
		subFont = QFont()
		subFont.setPointSize(12)
		self.subLabel.setFont(subFont)
	
	def closeButtonUI(self):
		closeButton = QPushButton("사용 종료", self)
		closeButton.resize(closeButton.sizeHint())
		closeButton.move(1700, 50)
		closeButton.clicked.connect(self.close)
	
	def closeEvent(self, QCloseEvent):
		ans = QMessageBox.question(self, "사용 종료", "종료하시겠습니까?",
						QMessageBox.Yes|QMessageBox.No, QMessageBox.No)
		if ans == QMessageBox.Yes:
			QCoreApplication.instance().quit	# 프로그램 종료
		else:
			QCloseEvent.ignore()


class SelectAction(object):
	def setupUI(self, MainWindow):
		self.setGeometry(200, 100, 1940, 1100)	# 화면 위치
		self.setWindowTitle("자유시간")
		self.select1ButtonUI()
		self.select2ButtonUI()
		self.backButtonUI()
		self.show()
	
	def select1ButtonUI(self):
		select1Button = QPushButton("사  주", self)
		select1Button.setGeometry(200, 300, 700, 600)
		select1Font = QFont()
		select1Font.setPointSize(50)
		select1Font.setBold(True)
		select1Button.setFont(select1Font)
	
	def select2ButtonUI(self):
		select2Button = QPushButton("타  로", self)
		select2Button.setGeometry(1100, 300, 700, 600)
		select2Font = QFont()
		select2Font.setPointSize(50)
		select2Font.setBold(True)
		select2Button.setFont(select2Font)
	
	def backButtonUI(self):
		backButton = QPushButton("되돌아가기", self)
		backButton.resize(backButton.sizeHint())
		backButton.move(1700, 950)


class MainWindow(QMainWindow):
	def __init__(self, parent=None):
		super(MainWindow, self).__init__(parent)
		self.tagDevice = TagDevice()
		self.selectAction = SelectAction()
		self.startTagDevice()
	
	def startTagDevice(self):
		self.tagDevice.setupUI(self)
		self.tagDevice.mainLabel.clicked.connect(self.startSelectAction)
		self.show()
	
	def startSelectAction(self):
		self.selectAction.setupUI(self)
		self.selectAction.backButton.clicked.connect(self.startTagDevice)


if __name__ == '__main__':
	app = QApplication(sys.argv)	# 객체 생성
	w = MainWindow()	# 창을 띄워줌
	sys.exit(app.exec_())	# 메인 루프 종료 시 창을 닫음
