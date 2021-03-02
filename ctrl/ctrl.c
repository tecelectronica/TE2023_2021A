
// If-Else
#include <stdio.h>

void ifelse()
{
  int cows = 6;
   
  printf("\n\nIf-Else example:\n");

  if (cows > 1)
    printf("We have cows\n");

  if (cows > 10)
    printf("loads of them!\n");
  else
    printf("Executing else part...!\n");

  if (cows == 5 )
  {
    printf("We have 5 cows\n");
  }
  else if (cows == 6 )
  {
    printf("We have 6 cows\n");
  }
}



//Ternary operator
#include <stdio.h>

void ternary() {
   int a , b;
   printf("\n\nTernary operator example:\n");

   a = 10;
   printf( "Value of b is %d\n", (a == 1) ? 20: 30 );

   printf( "Value of b is %d\n", (a == 10) ? 40: 50 );
}

//Switch case
#include <stdio.h>

void switchcase()
{
    int  Grade = 'A';
    printf("\n\nSwitch Case example:\n");

    switch( Grade )
    {
        //FIXME: All statements are executed
        case 'A' : printf( "A\n" );
        case 'B' : printf( "B\n" );
        case 'C' : printf( "C\n" );
        case 'D' : printf( "D\n" );
        case 'E' : printf( "E\n" );    
        default  : printf( "Anything else.\n" );
    }	
}

// While loop
//FIXME: Add break statement
#include <stdio.h>

void whileloop()
{
    int i = 10;
    printf("\n\nWhile loop example:\n");

    while ( i > 0 )
    {
       printf("Hello %d\n", i );
       i = i -1;
    }
}

// For Loop
#include <stdio.h>

void forloop()
{
    int i;
    int j = 10;
    printf("\n\nFor loop example:\n");

    for( i = 0; i <= j; i ++ )
    {
       printf("Hello %d\n", i );
    }
}

//Do while loop
#include <stdio.h>

void dowhileloop()
{
    int i = 10;
    printf("\n\nDo while loop example:\n");

    do{
       printf("Hello %d\n", i );
       i = i -1;
    }while ( i > 0 );
}

// Continue
#include <stdio.h> 

void continuestatement()
{
    int i;
    int j = 10;
    printf("\n\nContinue example:\n");

    for( i = 0; i <= j; i ++ )
    {
       if( i == 5 )
       {
          continue;
       }
       printf("Hello %d\n", i );
    }
}

int main(){
    ifelse();
    ternary();
    switchcase();
    whileloop();
    forloop();
    dowhileloop();
    continuestatement();
}
