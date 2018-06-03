#!/usr/bin/python
#!/bin/bash

import subprocess
import time
import insert_id
import number_id
import insert_random


try:
    while True:
        print("\n\tTag was started!")
        print("\tWait for searching your phone ...")

        myLines = subprocess.check_output("/usr/bin/nfc-poll", stderr=open('/dev/null', 'w'))
        buffer = []

        for line in myLines.splitlines():
            line_content = line.split()
            if(not line_content[0] == 'UID'):
                pass
            else:
                buffer.append(line_content)

        all_str = buffer[0]
        id_str = all_str[2] + all_str[3] + all_str[4] + all_str[5]
        # print(id_str)

        id_int = int(id_str, 16)
        print("\n\tYour phone id is: " + str(id_int))
        number_id.number_db(id_int)
        insert_id.insert_db(id_int)
        insert_random.insert_db(id_int)

        if id_int > 0:
            quit()

except KeyboardInterrupt:
    pass
