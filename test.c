#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int i;

    i = atoi("0");
    printf("the number is : %d\n", i);

    i = atoi("-0");
    printf("the number is : %d\n", i);

    i = atoi("+958");
    printf("the number is : %d\n", i);

    i = atoi("99999999999999999999");
    printf("the number is : %d\n", i);

    i = atoi("-111111111111111111111");
    printf("the number is : %d\n", i);

    return 0;
}

