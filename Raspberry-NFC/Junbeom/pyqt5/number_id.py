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
    snep_client.put_records([ndef.UriRecord("time://free?param1=test$param2=test2")])

def connected_first(llc):
    Thread(target=beam_first, args=(llc,)).start()
    return True

def connected_user(llc):
    Thread(target=beam_user, args=(llc,)).start()
    return True


def number_db(id_num):
    exist = 0

    try:
        sql = "SELECT phone_id FROM user"
        cursor.execute(sql)

        res = cursor.fetchall()
        for row in res:
            # print(row)
            # print(str(row[0])+" "+str(id_num)+" "+str(exist))
            if str(row[0]) == str(id_num):
                exist = 1

        if exist == 0:
            with nfc.ContactlessFrontend('tty') as clf:
                print("\tThe download will be start shortly.\n")
                clf.connect(llcp={'on-connect': connected_first})
        else:
            print("\tThat is already registered.\n")
            with nfc.ContactlessFrontend('tty') as clf:
                print("\tSo, the application will be turned on.\n")
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
        print("\tIt's all over.\n")
        cursor.close()
        conn.close()
