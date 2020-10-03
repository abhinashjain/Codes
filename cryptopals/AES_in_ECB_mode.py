#!/usr/bin/python
# coding: utf-8
import base64
from Crypto.Cipher import AES

t=int(raw_input())
for i in xrange(t):
    keytext=raw_input()
    numberofline=int(raw_input())
    encoded=''
    for j in xrange(numberofline-1):
        encoded+=raw_input()+"\n"
    encoded+=raw_input()
    cipher=base64.b64decode(encoded)

    ciphertext=''.join(format(ord(x), '08b') for x in cipher)
    cipherlength=len(ciphertext)

    key=''.join(format(ord(x), '08b') for x in keytext)
    keylength=len(key)
    keytext=''
    for i in xrange(0,keylength,8):
        s=str(key[i:i+8])
        keyint=int(s,2)
        keytext+=chr(keyint)
    key=keytext

    plain=''
    # Instead of decrypting full cipher text at once. We are decrypting one block at a time.
    for j in xrange(0,cipherlength,keylength):
        cipher=ciphertext[j:j+keylength]

        ctext=''
        clength=len(cipher)
        for i in xrange(0,clength,8):
            s=str(cipher[i:i+8])
            cint=int(s,2)
            ctext+=chr(cint)
        cipher=ctext

        obj=AES.new(key, AES.MODE_ECB) # AES takes key in bytes (not bits). Hence, instead of dealing at bit level, this code is woring on byte level
        plain+=obj.decrypt(cipher)
    print plain


'''

The Base64-encoded content in the file AES_in_ECB_mode.txt has been encrypted via AES-128 in ECB mode under the key

"YELLOW SUBMARINE".
(case-sensitive, without the quotes; exactly 16 characters; I like "YELLOW SUBMARINE" because it's exactly 16 bytes long, and now you do too).

Decrypt it. You know the key, after all.

Easiest way: use OpenSSL::Cipher and give it AES-128-ECB as the cipher.

Do this with code.
You can obviously decrypt this using the OpenSSL command-line tool, but we're having you get ECB working in code for a reason. You'll need it a lot later on, and not just for 
attacking ECB.

'''


'''

from Crypto.Cipher import AES
obj = AES.new('This is a key123', AES.MODE_CBC, 'This is an IV456')
message = "The answer is no"
ciphertext = obj.encrypt(message)
print ciphertext ###### ---------> '\xd6\x83\x8dd!VT\x92\xaa`A\x05\xe0\x9b\x8b\xf1'
obj2 = AES.new('This is a key123', AES.MODE_CBC, 'This is an IV456')
obj2.decrypt(ciphertext) ###### ---------> 'The answer is no'

obj3 = AES.new('This is a key123', AES.MODE_ECB)


t=int(raw_input())
for i in xrange(t):
    numberofline=int(raw_input())
    encoded=''
    for i in xrange(numberofline-1):
        encoded+=raw_input()+"\n"
    encoded+=raw_input()
    key=raw_input()
    ciphertext=base64.b64decode(encoded)
#    print ciphertext
    obj=AES.new(key, AES.MODE_ECB)
    plain=obj.decrypt(ciphertext)
    print plain

'''
