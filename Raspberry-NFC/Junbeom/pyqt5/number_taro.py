#!/usr/bin/python
#-*-coding:utf-8-*-

import mysql.connector
import insert_taro

from Adafruit_Thermal import *
from mysql.connector import errorcode


config = {
    'user': 'woojae',
    'password': 'YBJ11111',
    'host': 'ybj.cghzrrdlqojc.ap-northeast-2.rds.amazonaws.com',
    'database': 'free_time',
    'port': '3306'
}
conn = mysql.connector.connect(**config)
cursor = conn.cursor()

printer = Adafruit_Thermal("/dev/serial0", 19200, timeout=5)
printer.wake()       # Call wake() before printing again, even if reset
printer.setDefault() # Restore printer to defaults

cur_num = 0
next_num = 0
lead_time = 0


try:
    sql0 = """SELECT waiting_num FROM number WHERE date=CURRENT_DATE() AND
              store_id='1' AND counter_id='2' AND calling_end IS NULL
              ORDER BY waiting_num ASC limit 1"""
    sql1 = """SELECT waiting_num FROM number WHERE date=CURRENT_DATE() AND
              store_id='1' AND counter_id='2' ORDER BY waiting_num
              DESC limit 1"""
    sql2 = """SELECT lead_time FROM counter WHERE
              counter_id='2' AND store_id='1'"""

    cursor.execute(sql0)
    res = cursor.fetchall()
    for row in res:
        cur_num = row[0]
        print("\n\tCurrent number: " + str(cur_num))

    cursor.execute(sql1)
    res = cursor.fetchall()
    for row in res:
        next_num = row[0]+1
        print("\tWaiting number: " + str(next_num))

    cursor.execute(sql2)
    res = cursor.fetchall()
    for row in res:
        lead_time = row[0]
        print("\tLead time per 1 person: " + str(lead_time) + "\n")


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
    conn.close()


insert_taro.insert_db(next_num)

waiting_num = str(next_num)
if len(waiting_num) == 1:
    waiting_num = "   " + waiting_num[0] + "   "
elif len(waiting_num) == 2:
    waiting_num = waiting_num[0] + "   " + waiting_num[1]
elif len(waiting_num) == 3:
    waiting_num = waiting_num[0] + " " + waiting_num[1] + " " + waiting_num[2]

lead_time = (int(next_num)-int(cur_num)) * int(lead_time)
lead_time = str(lead_time)


printer.setLineHeight(40)
printer.justify('L')
printer.setSize('S')
printer.println("Let's free time!")
printer.boldOn()
printer.println("\t< T A R O >")
printer.boldOff()
printer.println()

printer.justify('C')
printer.setSize('M')
printer.println("I^ ^ ^ ^ ^ ^ ^ ^ ^ ^ I")
printer.println("I  Y o u r  w a i t  I")
printer.println("I    N U M B E R     I")
printer.println("I        i s         I")
printer.println("I                    I")
printer.boldOn()
printer.setSize('L')
printer.println("I  ", waiting_num, "  I")
printer.boldOff()
printer.println("I                    I")
printer.println(" ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^")
printer.println()

printer.justify('L')
printer.setSize('S')
printer.println("Expected wait time")
printer.println("is about ", lead_time, " mins.")
printer.println()

printer.justify('R')
printer.println("Made by YBJ in 2018")
printer.println()
printer.println()
printer.println()

printer.sleep()      # Tell printer to sleep
