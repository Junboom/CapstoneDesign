#!/usr/bin/python

import mysql.connector
import insert_saju

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

next_num = 0


try:
    sql = """SELECT waiting_num, number.store_id, number.counter_id,
             lead_time FROM number LEFT JOIN counter ON
             number.counter_id = counter.counter_id LEFT JOIN store ON
             number.store_id = store.store_id WHERE calling_end = NULL
             AND number.counter_id = '1'"""
    cursor.execute(sql)

    res = cursor.fetchall()
    for row in res:
        next_num = row[0]+1
        print("Waiting number: " + str(next_num))

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


insert_saju.insert_db(next_num)

waiting_num = str(next_num)
if len(waiting_num) == 1:
    waiting_num = waiting_num[0]
elif len(waiting_num) == 2:
    waiting_num = waiting_num[0] + "  " + waiting_num[1]
elif len(waiting_num) == 3:
    waiting_num = waiting_num[0] + "  " + waiting_num[1] + "  " + waiting_num[2]

printer.println()

printer.setLineHeight(50)
printer.justify('C')
printer.setSize('M')

printer.println()
printer.println("You Beom Jae")
printer.println("[ S A J U ]")
printer.println()

printer.println("Y O U R")
printer.println("W A I T I N G")
printer.println("N U M B E R")
printer.println("i s")

printer.println()
printer.println()

printer.boldOn()
printer.setSize('L')
printer.println(waiting_num)
printer.boldOff()

printer.println()
printer.println()
printer.println()
printer.println()
printer.println()

#printer.justify('L')
#printer.setSize('S')
#printer.println("We calculate the")
#printer.println("expected waiting time")
#printer.println("relatively accurately.")
#printer.println("So, you can do other")
#printer.println("activities freely during")
#printer.println("the waiting time.")

#printer.println()
#printer.println()

printer.sleep()      # Tell printer to sleep
