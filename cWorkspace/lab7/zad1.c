#include "../my_functions/functions_1d.h"
#include "../my_functions/functions_0d.h"

#include <ctype.h>
#include <stdarg.h>


// %d %s %f
void my_printf(const char *format, ...)
{
    va_list argptr;
    va_start(argptr, format);

    while (*format)
    {
        if (*format == '%')
        {
            
            format++;
            
            if (*format && *format == 'd')
            {
                int i = va_arg(argptr, int);
                
                printf("%d", i);
            } else if (*format && *format == 'f') {
                double d = va_arg(argptr, double);
                printf("%f", d);
            } else if (*format && *format == 's') {
                char *str = va_arg(argptr, char*);
                printf("%s", str);
                
            } else {
                putchar('%');
                putchar(*format);
            }

        } else {
            putchar(*format);  
            
        }



        format++;

    }
    va_end(argptr);
}

int main()
{

    const char *text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    double pi = 3.14159265358979323846;
    int ten = 10;    

    my_printf("");
    my_printf("Bez specyfikatorow\n");
    my_printf("%f", pi);
    my_printf("\t%s", text);
    my_printf("Tekst: %s\n", text);
    my_printf("Tekst: %s\nliczba calkowita: %d, liczba pi: %f, %d * %f = %f\n", text, ten, pi, ten, pi, ten * pi);
 
    return 0;
}
