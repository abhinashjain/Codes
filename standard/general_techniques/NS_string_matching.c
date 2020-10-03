#include "stdio.h"
#define HTTP_OR_TO_LOWERCASE	((sizeof(long) == 8)? 0x2020202020202020UL : 0x20202020UL)

int str_nocase_match(const char* str1, const char* str2, unsigned int len)
{
    unsigned long xor;
    unsigned long to_lowercase = HTTP_OR_TO_LOWERCASE;
    do
    {
        xor = *(const unsigned long*)str1 | to_lowercase;
//        printf("%lu\n",xor);
        xor ^= *(const unsigned long*)str2 | to_lowercase;
//        printf("%s\n",str1);
//        printf("%s\n",str2);
        printf("%lu\n",xor);
//        printf("sddsds %lu\n",*(const unsigned long*)str2);
        if (len <= sizeof(long))
            goto done;
        len -= sizeof(long);
        str1 += sizeof(long);
        str2 += sizeof(long);
    }   while(xor == 0);
    return 1;  /* No match */
    done:
        /* Remaining number of bytes here can be 1..sizeof(long) (0 when that's passed) */
        xor <<= (sizeof(long) - len) * 8; /* shift out bytes beyond length */
        return (xor != 0);
}

int main()
{
        char str[10];
    int a=1234;
        sprintf(str, "Value%d",a);
        puts(str);
    const char* s1 ="AAAAAAAA";
    const char* s2 ="AAAABAAA";
    printf("\n%d\n",str_nocase_match(s1,s2,6));
	return 0;
}
