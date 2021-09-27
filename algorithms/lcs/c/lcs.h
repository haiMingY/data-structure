
#include <stdio.h>
#include <stdlib.h>
// 返回大值
int max(const int a, const int b);

// 获取公共子序列长度
int lcs_length(char *x, char *y, unsigned int m, unsigned int n);

// 获取公共子序列
char *lcs(char *x, char *y, unsigned int m, unsigned int n);

int max(const int a, const int b)
{
    return a > b ? a : b;
};

// 获取公共子序列长度
int lcs_length(char *x, char *y, unsigned int m, unsigned int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (x[m - 1] == y[n - 1])
    {
        return 1 + lcs_length(x, y, m - 1, n - 1);
    }

    return max(lcs_length(x, y, m, n - 1), lcs_length(x, y, m - 1, n));
};

// 获取公共子序列
char *lcs(char *x, char *y, unsigned int m, unsigned int n)
{
    int temp[m + 1][n + 1];

    int i, j;

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {

            if (i == 0 || j == 0)
            {
                temp[i][j] = 0;
            }
            else if (x[i - 1] == y[j - 1])
            {
                temp[i][j] = temp[i - 1][j - 1] + 1;
            }
            else
            {
                temp[i][j] = max(temp[i][j - 1], temp[i - 1][j]);
            }
        }
    }

    int index = temp[m][n];
    char *lcsAlgo = (char *)malloc(sizeof(char) * (index + 1));
    lcsAlgo[index] = '\0';
    i = m;
    j = n;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            lcsAlgo[index - 1] = x[i - 1];
            i--;
            j--;
            index--;
        }
        else if (temp[i - 1][j] > temp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    return lcsAlgo;
};
