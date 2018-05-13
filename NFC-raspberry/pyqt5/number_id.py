#!/usr/bin/python

import mysql.connector
import nfc
import ndef

from threading import Thread


config = {
    'user': 'woojae',
    'password': 'YBJ11111',
    'host': 'ybj.cghzrrdlqojc.ap-northeast-2.rds.amazonaws.com',
    'database': 'free_time',
    'port': '3306'
}
conn = mysql.connector.connect(**config)
cursor = conn.cursor()


def beam_first(llc):
    snep_client = nfc.snep.SnepClient(llc)
    snep_client.put_records([ndef.UriRecord('http://nfcpy.org')])

def beam_user(llc):
    snep_client = nfc.snep.SnepClient(llc)
    snep_client.put_records([ndef.UriRecord('http://naver.com')])

def connected_first(llc):
    Thread(target=beam_first, args=(llc,)).start()
    return True

def connected_user(llc):
    Thread(target=beam_user, args=(llc,)).start()
    return True


exist = 0

def number_db(id_num):
    try:
        sql = "SELECT phone_id FROM user"
        cursor.execute(sql)

        res = cursor.fetchall()
        for row in res:
            # print(row)
            if row[0] == id_num:
                exist = 1

        if exist == 0:
            with nfc.ContactlessFrontend('tty') as clf:
                clf.connect(llcp={'on-connect': connected_first})
        else:
            print("\tYour phone id was already registered.\n")
            with nfc.ContactlessFrontend('tty') as clf:
                clf.connect(llcp={'on-connect': connected_user})

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
