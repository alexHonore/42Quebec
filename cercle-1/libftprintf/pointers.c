#include "libftprintf.h"
#include "function.c"

int main()
{
    char *test;
    char * const MYCONST = "BozoBozoBozoBozoBozo BozoBozoBozoBozoBozoBozoBozo";
    printf("%p\n",(void *)MYCONST);
    ft_address((unsigned long)MYCONST);
}