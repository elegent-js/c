#include <stdio.h>

int main() 
{
    int a = 10;
    int b = 20;
    int *p;

    printf("a = %d, addr: %p\n", a, &a);
    printf("b = %d, addr: %p\n", b, &b);
    printf("p = %p\n", p);
    printf("p addr: %p\n", &p);

    p = &a;

    printf("p = %p\n", p);
    printf("p addr: %p\n", &p);

    return 0;
}
