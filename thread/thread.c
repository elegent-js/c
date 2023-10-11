#include <stdio.h>
#include <pthread.h>

typedef struct myarg_t {
    int a;
    int b;
} myarg_t;


void *mythread(void *arg)
{
    myarg_t *m = (myarg_t *) arg;

    printf("a: %d, b: %d \n", m -> a, m -> b);
}

int main(int argc, char* argv[])
{
    pthread_t p;

    myarg_t arg;

    arg.a = 1;
    arg.b = 2;

    int rc = pthread_create(&p, NULL, mythread, &arg);
    rc = pthread_join(p, NULL);

    return 0;
}

