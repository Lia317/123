#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buff[80];
    gets(buff);
    getchar();
    if(strcmp(buff, "Harina Natalia I993") == 0)
        printf("OK\n");
    else 
        printf("NOT OK\n");
    return 0;
}