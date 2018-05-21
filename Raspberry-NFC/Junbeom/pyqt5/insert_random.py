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
# dt = dt.strftime("%Y%M%D")


def insert_db(id_num):
    try:
        sql = """INSERT INTO number (date, phone_id, store_id, counter_id)
                 VALUES (%s, %s, %s, %s)"""
        cursor.execute(sql, (dt, id_num, 1, 1))
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
