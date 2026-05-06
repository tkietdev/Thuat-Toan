#include <stdio.h>
#include <math.h>

#define MAX 205

int n;
double x[MAX], y[MAX];
double f[MAX][MAX];
int u[MAX][MAX];

double KhoangCach(int r, int s)
{
    return sqrt((x[r] - x[s]) * (x[r] - x[s]) +
                (y[r] - y[s]) * (y[r] - y[s]));
}

void LapBang()
{
    for (int i = 1; i <= n; i++)
        f[i][i] = 0;

    for (int len = 2; len <= n; len++)
    {
        for (int r = 1; r + len <= n; r++)
        {
            int s = r + len;

            if (s - r < 2)
            {
                f[r][s] = 0;
                continue;
            }

            f[r][s] = 1e18;

            for (int k = r + 1; k < s; k++)
            {
                double tam = f[r][k] + f[k][s];

                if (k - r > 1)
                    tam += KhoangCach(r, k);

                if (s - k > 1)
                    tam += KhoangCach(k, s);

                if (tam < f[r][s])
                {
                    f[r][s] = tam;
                    u[r][s] = k;
                }
            }
        }
    }
}

void TongHopKetQua(int r, int s)
{
    if (s - r < 2)
        return;

    int k = u[r][s];

    if (k - r > 1)
        printf("%d %d\n", r, k);

    if (s - k > 1)
        printf("%d %d\n", k, s);

    TongHopKetQua(r, k);
    TongHopKetQua(k, s);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lf %lf", &x[i], &y[i]);
    LapBang();
    printf("Tong do dai duong cheo nho nhat = %.6lf\n", f[1][n]);
    TongHopKetQua(1, n);

    return 0;
}
/*
5
0 0
2 0
3 1
1.5 3
0 1

Ouput: Tong do dai duong cheo nho nhat = 5.236068
2 5
3 5

độ phức tạp:O(n ^ 3)
*/