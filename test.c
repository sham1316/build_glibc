#include <stdio.h>

int main()
{
    printf("in %s - %p\n", __FUNCTION__, __ctype_b_loc());
    const unsigned short int *tablep=__ctype_b_loc();
    printf("%p\n",tablep);
    printf("%p\n",*tablep);
    printf("%o\n",tablep[0]);
    printf("%s\n",toupper("a"));
    return 0;
}

