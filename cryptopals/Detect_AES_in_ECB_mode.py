#!/usr/bin/python
# coding: utf-8

blocksize=128 #bits. 16 Bytes. key size also same
hexencoded=32 #bits. 128/4 bits. 4 Bytes
t=int(raw_input())
for i in xrange(t):
    f=0
    hash={}
    ciphertext=raw_input()
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


'''

In Detect_AES_in_ECB_mode.txt file are a bunch of hex-encoded ciphertexts.

One of them has been encrypted with ECB.

Detect it.

Remember that the problem with ECB is that it is stateless and deterministic; the same 16 byte plaintext block 
will always produce the same 16 byte ciphertext.

'''
