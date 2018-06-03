import pymysql

conn = pymysql.connect(host='ybj.cghzrrdlqojc.ap-northeast-2.rds.amazonaws.com', port=3306, user='woojae', passwd='YBJ11111', db='free_time', charset='utf8')
cursor = conn.cursor()

cur_num1 = 0
next_num1 = 0
lead_time1 = 0
cur_num2 = 0
next_num2 = 0
lead_time2 = 0


def main_db():
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
            cur_num1 = row[0]
            print("\n\t사주의 current number: " + str(cur_num1))

        cursor.execute(sql1)
        res = cursor.fetchall()
        for row in res:
            next_num1 = row[0]+1
            print("\t사주의 waiting number: " + str(next_num1))

        cursor.execute(sql2)
        res = cursor.fetchall()
        for row in res:
            lead_time1 = row[0]
            print("\t사주의 lead time per 1 person: " + str(lead_time1) + "\n")

        cursor.execute(sql3)
        res = cursor.fetchall()
        for row in res:
            cur_num2 = row[0]
            print("\t타로의 current number: " + str(cur_num2))

        cursor.execute(sql4)
        res = cursor.fetchall()
        for row in res:
            next_num2 = row[0]+1
            print("\t타로의 waiting number: " + str(next_num2))

        cursor.execute(sql5)
        res = cursor.fetchall()
        for row in res:
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
        conn.close()

def cur_num1():
    return cur_num1

def next_num1():
    return next_num1

def lead_time1():
    return lead_time1

def cur_num2():
    return cur_num2

def next_num2():
    return next_num2

def lead_time2():
    return lead_time2
