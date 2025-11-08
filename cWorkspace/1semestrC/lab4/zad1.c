#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    char buff[50];
    char num1[50];
    char num2[50];

    printf("Wpisz operacje do obliczenia: \n");

    scanf("%s",buff);

    char eq;
    int cont = 1;

    for (int i=0; i<50 && cont==1; i++)
    {
        if (buff[i] == '-' || buff[i] == '+' || buff[i] == '*' || buff[i] == '/')
        {
            eq = buff[i];
            strncpy(num1, buff, i+1);
            strcpy(num2, buff+i+1);
            cont = 0;
        }
    }

    double number1 = atof(num1);
    double number2 = atof(num2);

    printf("%.2f num1\t%.2f num2\t%c eq\n",number1, number2, eq);

    switch (eq)
    {
        case '+':
            printf("Wynik: %.2f", number1+number2);
            break;
        case '-':
            printf("Wynik: %.2f", number1-number2);
            break;
        case '*':
            printf("Wynik: %.2f", number1*number2);
            break;
        case '/':
            printf("Wynik: %.2f", number1/number2);
            break;
        default:
            printf("nie rozpoznano dzialania!\n");
    }
    
    
    return 0;
}
