#include <stdio.h>

int n, m;
int a[105][105];
int f[105][105];
int u[105][105];
int x[105];

// Lap Bang
void LapBang()
{
    for (int s = 1; s <= n; s++)
    {
        for (int r = 0; r <= m; r++)
        {
            if (s == 1)
            {
                f[r][s] = a[r][1];
                u[r][s] = r;
            }
            else
            {
                f[r][s] = 0;
                u[r][s] = 0;
                for (int v = 0; v <= r; v++)
                {
                    int temp = a[v][s] + f[r - v][s - 1];
                    if (temp > f[r][s])
                    {
                        f[r][s] = temp;
                        u[r][s] = v;
                    }
                }
            }
        }
    }
}

// Truy vet
void TongHopKetQua()
{
    int r = m;
    for (int s = n; s >= 1; s--)
    {
        x[s] = u[r][s];
        r = r - x[s];
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    for (int j = 1; j <= n; j++)
    {
        for (int i = 0; i <= m; i++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    LapBang();
    TongHopKetQua();

    printf("Tong diem lon nhat: %d\n", f[m][n]);
    printf("Phan bo so ngay:\n");

    for (int i = 1; i <= n; i++)
    {
        printf("Mon %d: %d ngay\n", i, x[i]);
    }

    return 0;
}

/*
Do phuc tap:
- Thoi gian: O(n * m^2)
- Bo nho: O(n * m)
2 5
0 3 5 6 7 8
0 2 4 7 10 12
Tong diem lon nhat: 13
Phan bo so ngay:
Mon 1: 1 ngay
Mon 2: 4 ngay

*/