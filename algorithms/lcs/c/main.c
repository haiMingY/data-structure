#include <stdio.h>
#include <string.h>
#include "lcs.h"
int main(int argc, char const *argv[])
{
    /* code */

    // char *x = "AGGTAB";
    // char *y = "GXTXAYB";
    char *x = "acadb";
    char *y = "cbda";
    int maxLen = lcs_length(x, y, strlen(x), strlen(y));

    printf("len = %d \n", maxLen);
    char *sub = lcs(x, y, strlen(x), strlen(y));
    printf("longest-common-subsequence = %s \n", sub);
    return 0;
}
