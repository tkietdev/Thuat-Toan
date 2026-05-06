#include <stdio.h>

int n;
int x[100];

void In()
{
    for (int i = 1; i <= n; i++)
        printf("%d", x[i]);
    printf("\n");
}
// backtrack
void Try(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        if (i == 1 || !(x[i - 1] == 0 && j == 0))
        {
            x[i] = j;
            if (i == n)
                In();
            else
                Try(i + 1);
        }
    }
}
int main()
{
    scanf("%d", &n);
    Try(1);
}
/*
Vi du: Input: 3
Output: 010
011
101
110
111
-> O(n)
*/