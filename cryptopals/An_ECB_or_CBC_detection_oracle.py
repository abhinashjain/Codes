#!/usr/bin/python
# coding: utf-8
import os
import base64
import binascii
from random import randint
from Crypto.Cipher import AES

def detect_AES_mode(blocksize,ciphertext): #blocksize in bits
    hexencoded=blocksize/4 #bits. 128/4 bits. 4 Bytes
    f=0
    hash={}
    length=len(ciphertext)
    for j in xrange(0,length,hexencoded):
        data_in_block=ciphertext[j:j+hexencoded]
        tmp=ciphertext.count(data_in_block)
        if(tmp>1):
            f=1
            if(data_in_block in hash):
                hash[data_in_block]+=1;
            else:
                hash[data_in_block]=1
                print "Line: ",i+1,"\nNumber Of Times: ",tmp,"\nRepeated Data Block:",data_in_block
    if(f):
        print "Cipher Text: ",ciphertext
        return 1
    return 0

def xor_for_cbc(previous,current):
    length1=len(previous)
    length2=len(current)
    xor=''
    if(length1==length2):
        for i in xrange(length1):
            xor+=chr(ord(previous[i]) ^ ord(current[i]))
    else:
        print "length of blocks used in xor are not equal"
    return xor

def cbc_encrypt(IV,key,plaintext):
    keylength=len(key)
    plainlength=len(plaintext)

    keytext=''
    for i in xrange(0,keylength,8):
        s=str(key[i:i+8])
        keyint=int(s,2)
        keytext+=chr(keyint)
    key=keytext

    IVtext=''
    IVlength=len(IV)
    for i in xrange(0,IVlength,8):
        s=str(IV[i:i+8])
        IVint=int(s,2)
        IVtext+=chr(IVint)
    IV=IVtext

    cipher=''
    prevcipher=IV
    for j in xrange(0,plainlength,keylength):
        plain=plaintext[j:j+keylength]

        ptext=''
        plength=len(plain)
        for i in xrange(0,plength,8):
            s=str(plain[i:i+8])
            pint=int(s,2)
            ptext+=chr(pint)
        plain=ptext

        intermediate=xor_for_cbc(prevcipher,plain)
        obj=AES.new(key, AES.MODE_ECB)
        prevcipher=obj.encrypt(intermediate)
        cipher+=prevcipher
    hexencodedcipher=binascii.hexlify(cipher)
    return hexencodedcipher


def ecb_encrypt(key,plaintext):
    keylength=len(key)
    plainlength=len(plaintext)

    keytext=''
    for i in xrange(0,keylength,8):
        s=str(key[i:i+8])
        keyint=int(s,2)
        keytext+=chr(keyint)
    key=keytext

    ciphertext=''
    for j in xrange(0,plainlength,keylength):
        plain=plaintext[j:j+keylength]

        ptext=''
        plength=len(plain)
        for i in xrange(0,plength,8):
            s=str(plain[i:i+8])
            pint=int(s,2)
            ptext+=chr(pint)
        plain=ptext

        obj=AES.new(key, AES.MODE_ECB)
        ciphertext+=obj.encrypt(plain)

    hexencodedcipher=binascii.hexlify(ciphertext)
    return hexencodedcipher

def encryption_oracle(blocksize,plaintext):
    tmp=os.urandom(randint(5,10))
    prefix=''.join(format(ord(x), '08b') for x in tmp)

# If you want to pad with same random text before and after the plain text then comment next two lines. And also change variable in line 120 from "suffix" to "prefix".
    tmp=os.urandom(randint(5,10))
    suffix=''.join(format(ord(x), '08b') for x in tmp)

# current approach is to first append the plain text with two different random text, then repeat and then use padding.
# If you want to first pad, then add different random text before and after the plain text and then again pad. Then uncomment line 165-170 and comment 122-126.

    plaintext = prefix + plaintext + suffix

    times=randint(3,50)     #more the repetition, more accurate the detection. Because ECB have same ciphertext for same plain text
    origtext=plaintext
    for j in xrange(times):
        plaintext+=origtext
    plaintext = pkcs7_padding(blocksize,plaintext)

    tmp=os.urandom(blocksize/8)
    key=''.join(format(ord(x), '08b') for x in tmp)

    ciphertext=''
    if(randint(0,1)):
        tmp=os.urandom(blocksize/8)
        IV=''.join(format(ord(x), '08b') for x in tmp)

        ciphertext=cbc_encrypt(IV,key,plaintext)
    else:
        ciphertext=ecb_encrypt(key,plaintext)
    return detect_AES_mode(blocksize,ciphertext)

def pkcs7_padding(blocksize,plaintext): # both in bits
    plaintextlength=len(plaintext)
    
    padding=plaintextlength % blocksize
    padding=blocksize-padding
    if(padding==blocksize):
        print padding/8, "byte padded. Text was already in multiple of block size."
        print "Extra block added containing only padded byte."
    else:
        print padding/8, "byte padded."
    
    padding=padding/8
    padtext=''
    for j in xrange(padding):
        padtext+=format(padding, '08b')
    return plaintext+padtext

t=int(raw_input())
for i in xrange(t):
    blocksize=int(raw_input()) # in bytes
    plain=raw_input()

    blocksize=blocksize*8
    plaintext=''.join(format(ord(x), '08b') for x in plain)
#    plaintext = pkcs7_padding(blocksize,plaintext)     #to first pad, then append additional random bytes and then again pad in encryption_oracle()

#    times=randint(3,50)     #more the repetition, more accurate the detection. Because ECB have same ciphertext for same plain text
#    origtext=plaintext
#    for j in xrange(times):
#        plaintext+=origtext
    mode=encryption_oracle(blocksize,plaintext)
    if(mode):
        print "\n", i+1, ": AES in ECB\n\n"
    else:
        print "\n", i+1, ": AES in CBC\n\n"


'''

Now that you have ECB and CBC working:

Write a function to generate a random AES key; that's just 16 random bytes.

Write a function that encrypts data under an unknown key --- that is, a function that generates a random key and encrypts under it.

The function should look like:

encryption_oracle(your-input):
    => [MEANINGLESS JIBBER JABBER]

Under the hood, have the function append 5-10 bytes (count chosen randomly) before the plaintext and 5-10 bytes after the plaintext.

Now, have the function choose to encrypt under ECB 1/2 the time, and under CBC the other half (just use random IVs each time for CBC). Use rand(2) to decide which to use.

Detect the block cipher mode the function is using each time. You should end up with a piece of code that, pointed at a block box that might be encrypting ECB or CBC, tells you which 
one is happening.

'''
