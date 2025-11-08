#include <stdio.h>
#include <math.h>


int main()
{
    unsigned int num;

    printf("Podaj liczbe:\n");
    scanf("%d",&num);

    int len = 0;

    unsigned int num1 = num;

   while (num1 > 0)
   {
    num1>>=1;
    len++;
   }

  
    unsigned int mask = 0;

    
    for (int i = len - 1; i >= len - len/2; i--) {
        mask |= (1u << i);
    }

    num = num ^ mask;

    printf("%d\n", num);




    return 0;
}


