#include <stdio.h>
int main(){
    int x;
    short int y;
    long z;
    uint8_t a;
    uint16_t b;
    uint32_t c;
    uint64_t d;
    printf("Size of int      : %d\n",sizeof(x));
    printf("Size of short int: %d\n",sizeof(y));
    printf("Size of long     : %d\n",sizeof(z));
    printf("Size of uint8_t  : %d\n",sizeof(a));
    printf("Size of uint16_t : %d\n",sizeof(b));
    printf("Size of uint32_t : %d\n",sizeof(c));
    printf("Size of uint64_t : %d\n",sizeof(d));
}
