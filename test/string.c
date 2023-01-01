#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char *sliceString(char *str, int start, int end)
{

    int i;
    int size = (end - start) + 2;
    char *output = (char *)malloc(size * sizeof(char));

    for (i = 0; start <= end; start++, i++)
    {
        output[i] = str[start];
    }

    // output[size] = '\0';

    return output;
}


int main(int argc, char const *argv[])
{
    char s[] = "GPIO15 : ON";
   printf("%d",strlen(s));
    printf("%s",sliceString(s,1,3));
    return 0;
}
