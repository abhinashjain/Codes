#!/usr/bin/python
# coding: utf-8
from sys import stdin, stdout

hextobin = {'0': '0000', '1': '0001', '2': '0010', '3': '0011', '4': '0100', '5': '0101', '6': '0110', '7': '0111', '8': '1000', '9': '1001', 'a': '1010', 'b': '1011', 'c': '1100', 'd': '1101', 'e': '1110', 'f': '1111'};
hex = {'0000': '0', '0001': '1', '0010': '2', '0011': '3', '0100': '4', '0101': '5', '0110': '6', '0111': '7', '1000': '8', '1001': '9', '1010': 'a', '1011': 'b', '1100': 'c', '1101': 'd', '1110': 'e', '1111': 'f'};
binary = {'0': 0, '1': 1};

t=int(raw_input())
for i in xrange(t):
    arr1=''
    arr2=''
    out=''
    input1=map(str, raw_input(''))
    input2=map(str, raw_input(''))
    for j in input1:
        arr1+=str(hextobin[str(j)])
    for j in input2:
        arr2+=str(hextobin[str(j)])
    len1=len(arr1)
    len2=len(arr2)
    if(len1==len2):
        for j in xrange(len1):
            out+=str(binary[arr1[j]] ^ binary[arr2[j]])
        k=0
        tmp=''
        ans=''
        for j in xrange(len1):
            k+=1
            tmp+=str(out[j])
            if(k%4==0):
                ans+=str(hex[tmp])
                tmp=''
                k=0
        print ans


'''

Write a function that takes two equal-length buffers and produces their XOR combination.

If your function works properly, then when you feed it the string:
1c0111001f010100061a024b53535009181c

... after hex decoding, and when XOR'd against:
686974207468652062756c6c277320657965

... should produce:
746865206b696420646f6e277420706c6179

'''
