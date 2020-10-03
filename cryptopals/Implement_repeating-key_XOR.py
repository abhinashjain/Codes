#!/usr/bin/python
# coding: utf-8
import string

hextobin = {'0000': '0', '0001': '1', '0010': '2', '0011': '3', '0100': '4', '0101': '5', '0110': '6', '0111': '7', '1000': '8', '1001': '9', '1010': 'a', '1011': 'b', '1100': 'c', '1101': 'd', '1110': 'e', '1111': 'f'};

t=int(raw_input())
for i in xrange(t):
    key=raw_input()
    numberofline=int(raw_input())
    plain=''
    for i in xrange(numberofline-1):
        plain+=raw_input()+"\n"
    plain+=raw_input()

    plainstrbits=''
    for j in plain:
        plainstrbits+=format( ord(j),'08b' )

    plainintbits=[]
    for j in plainstrbits:
        plainintbits.append( int(j) )

    plainlength=len(plainintbits)

    keystrbits=''
    for j in key:
        keystrbits+=format( ord(j),'08b' )

    keyintbits=[]
    for j in keystrbits:
        keyintbits.append( int(j) )

    keylength=len(keyintbits)

    cipherstrbits=''
    ind=0
    for j in xrange(0,plainlength,keylength):
        for k in xrange(keylength):
            ind+=1
            cipherstrbits+=str( plainintbits[j+k] ^ keyintbits[k] )
            if(ind==plainlength):
                break

    if(ind!=plainlength):
        j=0
        for k in xrange(ind,plainlength):
            cipherstrbits+=str( plainintbits[k] ^ keyintbits[j] )
            j+=1

    cipher=''
    for j in xrange(0,plainlength,4):
        s=''
        for k in xrange(4):
            s+=cipherstrbits[j+k]
        cipher+=hextobin[s]
    print cipher


'''

Here is the opening stanza of an important work of the English language:
Burning 'em, if you ain't quick and nimble
I go crazy when I hear a cymbal

Encrypt it, under the key "ICE", using repeating-key XOR.

In repeating-key XOR, you'll sequentially apply each byte of the key; the first byte of plaintext will be XOR'd against I, the next C, the next E, then I again for the 4th byte, and 
so on.

It should come out to:
0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272
a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f

Encrypt a bunch of stuff using your repeating-key XOR function. Encrypt your mail. Encrypt your password file. Your .sig file. Get a feel for it. I promise, we aren't wasting your 
time with this.

'''
