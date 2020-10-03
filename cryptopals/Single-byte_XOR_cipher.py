#!/usr/bin/python
# coding: utf-8
import string

hex = {'0': '0000', '1': '0001', '2': '0010', '3': '0011', '4': '0100', '5': '0101', '6': '0110', '7': '0111', '8': '1000', '9': '1001', 'a': '1010', 'b': '1011', 'c': '1100', 'd': '1101', 'e': '1110', 'f': '1111'};

english={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9',',','.','-','+',';',':','"','?','<','>','+','=','_','(',')','[',']','{','}',' ','\'','\n','!'}

t=int(raw_input())
for i in xrange(t):
    c=''
    inp=raw_input('')
    for j in inp:
        c+=str(hex[j])
    cipherlength=len(c)
    cipher=[]
    for j in xrange(cipherlength):
        cipher.append( int(c[j]) )
    for j in xrange(256):
        out=''
        ind=0
        bin=format(j,'08b')
        for k in xrange(0,cipherlength,8):
            for l in xrange(8):
                ind+=1
                out+=str( int(bin[l]) ^ cipher[k+l] )
#        if(ind!=cipherlength):
#            l=0
#            for k in xrange(ind,cipherlength):
#                out+=str( int(bin[l]) ^ cipher[k] )
#                l+=1
        plain=''
        plainlength=len(out)
        for k in xrange(0,plainlength,8):
            p=''
            for l in xrange(8):
                p+=str(out[k+l])
            pint=int(p,2)
            plain+=chr(pint)
        if( all(val in string.printable for val in plain) ):
            f=0
            for s in plain:
                if(s in english):
                    f+=1
                else:
                    f=-1
                    break
            if(f != -1):
                print plain
                print "\n"


'''

The hex encoded string:

1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736

... has been XOR'd against a single character. Find the key, decrypt the message.

You can do this by hand. But don't: write code to do it for you.

How? Devise some method for "scoring" a piece of English plaintext. Character frequency is a good metric. Evaluate each output and choose the one with the best score.

Answer: Cooking MC's like a pound of bacon

'''
