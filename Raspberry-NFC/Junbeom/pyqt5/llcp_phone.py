import nfc
import ndef

from threading import Thread

server = None


def beam(llc):
    snep_client = nfc.snep.SnepClient(llc)

    records = ndef.Record('/message.txt', 'id', 'imei')
    #send_octets = ndef.message_encoder(records)
    #rcvd_octets = snep_client.get_records(send_octets)
    #records = list(ndef.message_decorder(rcvd_octets))

    snep_client.get_octets(records)

    snep_client.put_records([ndef.UriRecord('http://naver.com')])

def connected(llc):
    Thread(target=beam, args=(llc,)).start()
    return True

with nfc.ContactlessFrontend('tty') as clf:
    clf.connect(llcp={'on-connect': connected})
