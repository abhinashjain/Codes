#!/usr/bin/python
# coding: utf-8
import base64
from Crypto.Cipher import AES

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
    base64encodedcipher=base64.b64encode(cipher)
    return base64encodedcipher

def cbc_decrypt(IV,key,ciphertext):
    keylength=len(key)
    cipherlength=len(ciphertext)
    
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

    plain=''
    prevcipher=IV
    for j in xrange(0,cipherlength,keylength):
        cipher=ciphertext[j:j+keylength]
        
        ctext=''
        clength=len(cipher)
        for i in xrange(0,clength,8):
            s=str(cipher[i:i+8])
            cint=int(s,2)
            ctext+=chr(cint)
        cipher=ctext
        
        obj=AES.new(key, AES.MODE_ECB)
        intermediate=obj.decrypt(cipher)
        plain+=xor_for_cbc(prevcipher,intermediate)
        prevcipher=cipher
    return plain

def pkcs7_padding(blocksize,plaintext):
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
    encrypt_or_decrypt=int(raw_input())
    IVtext=raw_input()
    keytext=raw_input()
    numberofline=int(raw_input())

    blocksize=len(keytext)*8
    key=''.join(format(ord(x), '08b') for x in keytext)
    IV=''.join(format(int(x), '08b') for x in IVtext)   #In this case IV is NULL hence used int. Otherwise, depending on the given IV, may have to change int to ord.

    if(encrypt_or_decrypt):
        encoded=''
        for j in xrange(numberofline-1):
            encoded+=raw_input()+"\n"
        encoded+=raw_input()
        
        cipher=base64.b64decode(encoded)
        ciphertext=''.join(format(ord(x), '08b') for x in cipher)
        print cbc_decrypt(IV,key,ciphertext)
    else:
        text=''
        for j in xrange(numberofline-1):
            text+=raw_input()+"\n"
        text+=raw_input()

        plaintext=''.join(format(ord(x), '08b') for x in text)
        plaintext=pkcs7_padding(blocksize,plaintext)
        print cbc_encrypt(IV,key,plaintext)


'''

CBC mode is a block cipher mode that allows us to encrypt irregularly-sized messages, despite the fact that a block cipher natively only transforms individual blocks.

In CBC mode, each ciphertext block is added to the next plaintext block before the next call to the cipher core.

The first plaintext block, which has no associated previous ciphertext block, is added to a "fake 0th ciphertext block" called the initialization vector, or IV.

Implement CBC mode by hand by taking the ECB function you wrote earlier, making it encrypt instead of decrypt (verify this by decrypting whatever you encrypt to test), and using your 
XOR function from the previous exercise to combine them.

The file Implement_CBC_mode.txt is intelligible (somewhat) when CBC decrypted against "YELLOW SUBMARINE" with an IV of all ASCII 0 (\x00\x00\x00 &c)

Don't cheat.
Do not use OpenSSL's CBC code to do CBC mode, even to verify your results. What's the point of even doing this stuff if you aren't going to learn from it?


1 number of testcases
1 for decryption, 0 for encryption
0000000000000000 - IV in decimal format
YELLOW SUBMARINE - key
64 - number of lines of data
plain or cipher text

'''
