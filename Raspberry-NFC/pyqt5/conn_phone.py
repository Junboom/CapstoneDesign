import nfc
import ndef

from threading import Thread


def beam(llc):
    #send_octets = ndef.message_encoder(records)
    #rcvd_octets = snep_client.get_octets(send_octets, timeout)
    #records = list(ndef.message_decoder(rcvd_octets))

    snep_client = nfc.snep.SnepClient(llc)
    snep_client.put_records([ndef.UriRecord('http://naver.com')])

def connected(llc):
    Thread(target=beam, args=(llc,)).start()
    return True

with nfc.ContactlessFrontend('usb') as clf:
    # timeOut = lambda: time.time()-started > (10*60)
    # started = time.time()
    clf.connect(llcp={'on-connect': connected}, terminate=timeOut)
