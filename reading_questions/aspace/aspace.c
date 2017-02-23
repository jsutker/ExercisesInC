/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int global;

int main ()
{
    int local = 5;
    char local2;
    void *p = malloc(128);
    void *q = malloc(128);

    char test1[19];
    char test2[19];

    printf ("Address of main is %p\n", main);
    printf ("Address of global is %p\n", &global);
    printf ("Address of local is %p\n", &local);
    printf ("Address of local2 is %p\n", &local2);
    printf ("Address of p is %p\n", p);
    printf ("Address of q is %p\n", q);
    printf ("Address of test1 is %p\n", &test1);
    printf ("Address of test2 is %p\n", &test2);
    
    return 0;
}
