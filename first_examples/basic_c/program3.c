/* Program 3 Calculate something using functions and display the result */
#include <stdio.h>              // This is a preprocessor directive

int calcAdd(int x, int y){
    int res;
    res = x + y;
    return res;
}

// Write calcSub function
// Receives 2 ints
// Returns the result of int1 - int2;
int calcSub(int x, int y){
    return x - y;
}

float calcDiv(int x, int y){
    return (float)((float)x / (float)y);
}

void printVal(char * name, int val){
    printf("%s: %d\n",name,val);
}

int main(void)                  // This identifies the function main()
{                               // This marks the beginning of main()
    int op1, op2, res1, res2;   // Variable declaration. Always declare before using.
    float res4;
    op1 = 20;                   // op1 initialization
    op2 = 35;                   // op2 initialization
    res1 = calcAdd(op1,op2);    // Call calcAdd function
    printVal("op1",op1);        // Call printVal function with op1
    printVal("op2",op2);        // Call printVal function with op2
    printVal("res1",res1);      // Call printVal function with res1
    res2 = calcSub(op2,op1);    // Call calcSub function
    printVal("res2",res2);      // Call printVal function with res2
    printVal("constant",10);    // Call printVal with constant=10
    printVal("res3",calcAdd(7,8));       // Call printVal with call to calcAdd with const1=7 and const2=8
    res4 = calcDiv(40,6);
    printf("res4: %0.20f\n",res4);
    return 0;                   // This returns control to the operating system
}                               // This marks the end of main()

