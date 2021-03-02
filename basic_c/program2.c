/* Program 2 Calculate something and display the result 
 * Author: Luis Alfonso Maeda Nunez
 * Email: luis.maeda@tec.mx
 * */
#include <stdio.h>              // This is a preprocessor directive


int main(void)                  // This identifies the function main()
{                               // This marks the beginning of main()
    int op1, op2, res1, res2;   // Variable declaration. Always declare before using.
    op1 = 20;                   // op1 assignment
    op2 = 35;                   // op2 assignment
    res1 = op1 + op2;           // res1 calculation
    res2 = op2 - op1;           // res2 calculation 
    printf("op1: %d\n",op1);    // Print quotation using a variable
    printf("op2: %d\n",op2);    // Print quotation using a variable
    printf("res1: %d\n",res1);  // Print res1
    printf("res2: %d\n",res2);  // Print res2
    printf("const: %d\n",60);   // Print constant.
    printf("calc 5+%d: %d\n", op2, 5+op2);
    return 0;                   // This returns control to the operating system
}                               // This marks the end of main()

