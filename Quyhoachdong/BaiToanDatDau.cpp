#include <stdio.h>

int n, S;
int a[100], x[100];
int ktra = 0;

void In()
{
    ktra = 1;
    printf("%d", a[1]);
    for (int i = 2; i <= n; i++)
    {
        if (x[i] == 1)
            printf(" + %d", a[i]);
        else
            printf(" - %d", a[i]);
    }
    printf(" = %d\n", S);
}

void Try(int i, int sum)
{
    if (i > n)
    {
        if (sum == S)
            In();
        return;
    }

    // chon +
    x[i] = 1;
    Try(i + 1, sum + a[i]);

    // chon -
    x[i] = 0;
    Try(i + 1, sum - a[i]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &S);
    Try(2, a[1]);
    if (!ktra)
        printf("Khong co phuong an\n");
    return 0;
}

/*
Ví du:
Input:
4
1 2 3 4
0

Output:
1 + 2 + 3 - 4 = 0
*/