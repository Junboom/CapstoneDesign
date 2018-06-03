import datetime
import mysql.connector

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

dt = datetime.datetime.now()
dt = dt.strftime("%Y%M%D")


def insert_db(next_num):
    try:
        sql = """INSERT INTO number (waiting_num, date,
                                     user_state, phone_id,
                                     counter_id, store_id)
                 VALUES (%s, %s, %s, %s, %s, %s)"""
        cursor.execute(sql, (str(next_num), dt, 2, 100, 1, 1))
        conn.commit()

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
