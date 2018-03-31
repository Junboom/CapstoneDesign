import sys
from PyQt5 import QtWidgets
from PyQt5 import QtGui
from PyQt5 import uic
from PyQt5 import QtCore
from PyQt5.QtCore import pyqtSlot

class Form(QtWidgets.QDialog):
	def __init__(self, parent=None):
		QtWidgets.QDialog.__init__(self, parent)
		self.ui = uic.loadUi("dong.ui", self)	# ui와 파이썬 코드 연결
		self.ui.show()

	@pyqtSlot()
	def add_number(self):	# 함수이름 자기맘대로 self 라는 매개변수를받음
		# self.ui.pushButton
		# self.ui.number.text()	# 문자열
		added_count = int(self.ui.number.text()) + 1	# 숫자
		self.ui.number.setText(str(added_count))

if __name__ == '__main__':
	app = QtWidgets.QApplication(sys.argv)
	w= Form()
	sys.exit(app.exec())
