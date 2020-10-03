#!/usr/bin/python
# coding: utf-8
import base64
import string

def hamming_distance(s1, s2):
    assert len(s1) == len(s2)
    return sum(ch1 != ch2 for ch1, ch2 in zip(s1, s2))

english={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9',',','.','-','+',';',':','"','?','<','>','+','=','_','(',')','[',']','{','}',' ','\'','\n','!'}

t=int(raw_input())
for i in xrange(t):
    numberofline=int(raw_input())
    base64encoded=''
    for i in xrange(numberofline-1):
        base64encoded+=raw_input('')
    base64encoded+=raw_input('')
    cipher=base64.b64decode(base64encoded)

    ciphertext=''.join('{0:08b}'.format(ord(x), 'b') for x in cipher)
    tmp_ciphertext=ciphertext
    cipherlength=len(ciphertext)

    normalise_hd=[]
    for keysize in xrange(2,41):
        num_of_bits=keysize*4*8     #taking hamming distance for the (*4) times of keysize (i.e. 4 times KEYSIZE worth of bytes) and converting them to bits (*8)
        mul2=num_of_bits*2
        hd=0
        times=0
        for j in xrange(0,cipherlength,num_of_bits):
            if((j+mul2)<cipherlength):
                times+=1
                cipher1=ciphertext[j:j+num_of_bits]
                cipher2=ciphertext[j+num_of_bits:j+mul2]
                hd+=hamming_distance(cipher1,cipher2)
        average=hd/times
        normalise=average/keysize
        normalise_hd.append((normalise,keysize))

    normalise_hd.sort()

    keysize_in_bytes=normalise_hd[0][1]
    keysize=keysize_in_bytes*8      #converting keysize into bits

    block=[]
    for j in xrange(keysize_in_bytes):
        block.append('')

    for j in xrange(0,cipherlength,keysize):
        for k in xrange(keysize_in_bytes):
            ind=(j+k)%keysize_in_bytes
            block[ind]+=ciphertext[j+(k*8):j+(k*8)+8]   #transposing, bringing 0th,8th,16th in one column (in this case in one index of array), similarly 1st,9th,17th in other.

    key=''
    for ciphertext in block:
        cipherlength=len(ciphertext)
        for j in xrange(256):
            out=''
            ind=0
            bin=format(j,'08b')
            for k in xrange(0,cipherlength,8):
                for l in xrange(8):
                    ind+=1
                    out+=str( int(bin[l]) ^ int(ciphertext[k+l]) )
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
                    key+=chr(j)
                    break
    print "Key: ",key
    print "\nPlain Text:"

    # Decrypt the given base64 encoded cipher text with calculated key
    ciphertext=tmp_ciphertext
    cipherlength=len(ciphertext)

    cipherintbits=[]
    for j in ciphertext:
        cipherintbits.append( int(j) )

    keystrbits=''
    for j in key:
        keystrbits+=format( ord(j),'08b' )

    keyintbits=[]
    for j in keystrbits:
        keyintbits.append( int(j) )

    plainstrbits=''
    ind=0
    for j in xrange(0,cipherlength,keysize):
        for k in xrange(keysize):
            ind+=1
            plainstrbits+=str( cipherintbits[j+k] ^ keyintbits[k] )
            if(ind==cipherlength):
                break

    if(ind!=cipherlength):
        j=0
        for k in xrange(ind,cipherlength):
            plainstrbits+=str( cipherintbits[k] ^ keyintbits[j] )
            j+=1

    plain=''
    for j in xrange(0,cipherlength,8):
        s=str(plainstrbits[j:j+8])
        pint=int(s,2)
        plain+=chr(pint)
    print plain


'''

str1="this is a test"
str2="wokka wokka!!!"
str3=' '.join('{0:08b}'.format(ord(x), 'b') for x in str1)
str4=' '.join('{0:08b}'.format(ord(x), 'b') for x in str2)
print hamming_distance(str3,str4)

'''

'''

There's a file Break_repeating_key_XOR.txt. It's been base64'd after being encrypted with repeating-key XOR.

Decrypt it.

Here's how:

1. Let KEYSIZE be the guessed length of the key; try values from 2 to (say) 40.

2. Write a function to compute the edit distance/Hamming distance between two strings. The Hamming distance is just the number of differing bits. The distance between:

    this is a test
        and
    wokka wokka!!!

is 37. Make sure your code agrees before you proceed.

3. For each KEYSIZE, take the first KEYSIZE worth of bytes, and the second KEYSIZE worth of bytes, and find the edit distance between them. Normalize this result by dividing by 
KEYSIZE.

4. The KEYSIZE with the smallest normalized edit distance is probably the key. You could proceed perhaps with the smallest 2-3 KEYSIZE values. Or take 4 KEYSIZE blocks instead of 2 
and average the distances.

5. Now that you probably know the KEYSIZE: break the ciphertext into blocks of KEYSIZE length.

6. Now transpose the blocks: make a block that is the first byte of every block, and a block that is the second byte of every block, and so on.

7. Solve each block as if it was single-character XOR. You already have code to do this.

8. For each block, the single-byte XOR key that produces the best looking histogram is the repeating-key XOR key byte for that block. Put them together and you have the key.

This code is going to turn out to be surprisingly useful later on. Breaking repeating-key XOR ("Vigenere") statistically is obviously an academic exercise, a "Crypto 101" thing. But 
more people "know how" to break it than can actually break it, and a similar technique breaks something much more important.

No, that's not a mistake:
We get more tech support questions for this challenge than any of the other ones. We promise, there aren't any blatant errors in this text. In particular: the "wokka wokka!!!" edit 
distance really is 37.

'''
