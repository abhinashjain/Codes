#!/usr/bin/python
# coding: utf-8
from sys import stdin, stdout

ascii = {32: ' ', 33: '!', 34: '"', 35: '#', 36: '$', 37: '%', 38: '&', 39: '\'', 40: '(', 41: ')', 42: '*', 43: '+', 44: ',', 45: '-', 46: '.', 47: '/', 48: '0', 49: '1', 50: '2', 51: '3', 52: '4', 53: '5', 54: '6', 55: '7', 56: '8', 57: '9', 58: ':', 59: ';', 60: '<', 61: '=', 62: '>', 63: '?', 64: '@', 65: 'A', 66: 'B', 67: 'C', 68: 'D', 69: 'E', 70: 'F', 71: 'G', 72: 'H', 73: 'I', 74: 'J', 75: 'K', 76: 'L', 77: 'M', 78: 'N', 79: 'O', 80: 'P', 81: 'Q', 82: 'R', 83: 'S', 84: 'T', 85: 'U', 86: 'V', 87: 'W', 88: 'X', 89: 'Y', 90: 'Z', 91: '[', 92: '\\', 93: ']', 94: '^', 95: '_', 96: '`', 97: 'a', 98: 'b', 99: 'c', 100: 'd', 101: 'e', 102: 'f', 103: 'g', 104: 'h', 105: 'i', 106: 'j', 107: 'k', 108: 'l', 109: 'm', 110: 'n', 111: 'o', 112: 'p', 113: 'q', 114: 'r', 115: 's', 116: 't', 117: 'u', 118: 'v', 119: 'w', 120: 'x', 121: 'y', 122: 'z', 123: '{', 124: '|', 125: '}', 126: '~'};
base32 = {'A': '00000', 'B': '00001', 'C': '00010', 'D': '00011', 'E': '00100', 'F': '00101', 'G': '00110', 'H': '00111', 'I': '01000', 'J': '01001', 'K': '01010', 'L': '01011', 'M': '01100', 'N': '01101', 'O': '01110', 'P': '01111', 'Q': '10000', 'R': '10001', 'S': '10010', 'T': '10011', 'U': '10100', 'V': '10101', 'W': 10110, 'X': 10111, 'Y': 11000, 'Z': '11001', '2': '11010', '3': '11011', '4': '11100', '5': '11101', '6': '11110', '7': '11111', '=': ''};
base64 = {'000000': 'A', '000001': 'B', '000010': 'C', '000011': 'D', '000100': 'E', '000101': 'F', '000110': 'G', '000111': 'H', '001000': 'I', '001001': 'J', '001010': 'K', '001011': 'L', '001100': 'M', '001101': 'N', '001110': 'O', '001111': 'P', '010000': 'Q', '010001': 'R', '010010': 'S', '010011': 'T', '010100': 'U', '010101': 'V', '010110': 'W', '010111': 'X', '011000': 'Y', '011001': 'Z', '011010': 'a', '011011': 'b', '011100': 'c', '011101': 'd', '011110': 'e', '011111': 'f', '100000': 'g', '100001': 'h', '100010': 'i', '100011': 'j', '100100': 'k', '100101': 'l', '100110': 'm', '100111': 'n', '101000': 'o', '101001': 'p', '101010': 'q', '101011': 'r', '101100': 's', '101101': 't', '101110': 'u', '101111': 'v', '110000': 'w', '110001': 'x', '110010': 'y', '110011': 'z', '110100': '0', '110101': '1', '110110': '2', '110111': '3', '111000': '4', '111001': '5', '111010': '6', '111011': '7', '111100': '8', '111101': '9', '111110': '+', '111111': '/'};
t=int(raw_input())
list=stdin.readlines()
for arr in list:
    j=0
    plain=''
    str32=''
    bin32=''
    arr = map(lambda s: s.strip(), arr)
    for i in arr:
        if(i != ''):
            bin32+=str(base32[str(i)])
    for i in bin32:
        j+=1
        str32+=i
        if(j%8==0):
            dec=int(str32,2)
            plain+=ascii[dec]
            str32=''
            j=0
    pad=0
    bin64=''
    for i in plain:
        bin64+=str(format(ord(str(i)),'b').zfill(8))
    unpadlen=len(bin64)
    while(len(bin64)%6!=0):
        bin64+='00000000'
        pad=1
    j=0
    iter=0
    str64=''
    encode64=''
    for i in bin64:
        j+=1
        iter+=1
        str64+=i
        if(j%6==0):
            if(unpadlen>=iter):
                encode64+=str(base64[str(str64)])
            else:
                if(pad==1):
                    encode64+=str(base64[str(str64)])
                    pad=2
                else:
                    encode64+='='
            str64=''
            j=0
    print encode64



'''

To ship data across a network various encoding formats are used; one such router in Cisco gets data in Base32 encoded format. The router has to then transfer the data, converting it to 
Base64.

Your task is to write a code that converts Base32 encoded strings to Base64.

Note Encoding has to be manually written, and use of such an external library will lead to disqualification.

Input Format
The first line of input contains N; N lines follow, each containing a Base32 encoded string.

Output Format
For each Base32 encoded string, print the Base64 encoded string of the same in a newline.

Constraints
1≤N≤10
Each encoded string is maximum 200 characters in length.

Sample Input
3
NBQWG23FOJZGC3TL
ORXXAY3PMRSXE===
MNXWIZLGN5ZGGZLT

Sample Output
aGFja2VycmFuaw==
dG9wY29kZXI=
Y29kZWZvcmNlcw==

Explanation
On decoding the 3 Base32 encoded strings, we get
hackerrank
topcoder
codeforces

Their Base64 representations are
hackerrank - aGFja2VycmFuaw==
topcoder - dG9wY29kZXI=
codeforces - Y29kZWZvcmNlcw==

'''