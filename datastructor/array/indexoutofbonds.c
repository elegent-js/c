#include <stdio.h>

int main(int argc, char* argv[]) 
{
    int arr[3] = {0};
    int i = 0;

    printf("i: %p \n", &i);
    printf("arr: %p \n", arr);

    for (; i <= 3; i ++) 
    {
        arr[i] = 0;
        printf("arr[%d] : %d \n", i, arr[i]);
    }

    return 0;
}