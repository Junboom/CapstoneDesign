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


def insert_db(id_num):
    try:
        sql = """INSERT INTO user (phone_id, vip)
                 VALUES (%s, %s)"""
        cursor.execute(sql, (id_num, 0))
        conn.commit()

    except mysql.connector.Error as err:
        if err.errno == errorcode.ER_ACCESS_DENIED_ERROR:
            print('id or password error')
        elif err.errno == errorcode.ER_BAD_DB_ERROR:
            print('db connection error')
        else:
            # print('etc error', err)

        conn.rollback()

    finally:
        cursor.close()
        conn.close()
