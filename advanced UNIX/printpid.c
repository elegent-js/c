/**
 * print pid of current process
 * 
 * @author liupj
 */

#include "apue.h"

int main(int argc, char *argv[])
{

    printf("hello world for processID: %ld\n", (long) getpid());

    return 0;
    
}