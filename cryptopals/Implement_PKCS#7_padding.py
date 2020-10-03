#!/usr/bin/python
# coding: utf-8

bintohex = {'0000': '0', '0001': '1', '0010': '2', '0011': '3', '0100': '4', '0101': '5', '0110': '6', '0111': '7', '1000': '8', '1001': '9', '1010': 'a', '1011': 'b', '1100': 'c', '1101': 'd', '1110': 'e', '1111': 'f'};

# Works from 0 to 255 byte padding only

t=int(raw_input())
for i in xrange(t):
    bytes=int(raw_input())
    blocksize=int(raw_input())
    if(bytes):
        blocksize=blocksize*8
    notation=int(raw_input())
    numberofline=int(raw_input())
    text=''
    for j in xrange(numberofline-1):
        text+=raw_input()+"\n"
    text+=raw_input()

    textlength=len(text)
    if(notation==1):
        textlength=textlength*4
    elif(notation==2):
        textlength=textlength*8

    padding=textlength % blocksize
    padding=blocksize-padding
    if(padding==blocksize):
        print padding/8, "byte padded. Text was already in multiple of block size."
        print "Extra block added containing only padded byte."
    else:
        print padding/8, "byte padded."
    
    padding=padding/8
    pad=''
    for j in xrange(padding):
        pad+=format(padding, '08b')
    padlength=len(pad)

    padtext=''

#Regardless of the original text format, the padding will always be in hex format.
    for j in xrange(0,padlength,4):
        s=str(pad[j:j+4])
        padtext+=bintohex[s]

#If original text in binary, hex, or decimal format then padding will also be in binary, hex or decimal respectively.
#    if(notation==0):
#        padtext=pad
#    else:
#        if(notation==1):
#            for j in xrange(0,padlength,4):
#                s=str(pad[j:j+4])
#                padtext+=bintohex[s]
#        elif(notation==2):
#            for j in xrange(0,padlength,8):
#                s=str(pad[j:j+8])
#                pint=int(s,2)
#                padtext+=str(pint)

    print "Original text:                   ", text
    text=text+padtext
    print "Padded text (in hex format):     ", text
    print "\n\n"

'''

A block cipher transforms a fixed-sized block (usually 8 or 16 bytes) of plaintext into ciphertext. But we almost never want to transform a single block; we encrypt irregularly-sized
messages.

One way we account for irregularly-sized messages is by padding, creating a plaintext that is an even multiple of the blocksize. The most popular padding scheme is called PKCS#7.

So: pad any block to a specific block length, by appending the number of bytes of padding to the end of the block. For instance,

"YELLOW SUBMARINE"
... padded to 20 bytes would be:
"YELLOW SUBMARINE\x04\x04\x04\x04"


"4f6e63652075706f6e20612074696d65"
would be:
"4f6e63652075706f6e20612074696d6510101010101010101010101010101010"

"7468657265666f7265"
would be:
"7468657265666f726507070707070707"

1 test case
1 for byte, 0 for bits (block size in bits or bytes)
16 block size
1 for hex, 0 for binary, 2 for decimal representation of text
1 number of lines in text
7468657265666f7265

'''
