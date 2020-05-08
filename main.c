#include <stdio.h>
#include <stdlib.h>
int findTreasure(int n, int m, int m2, int (*a)[m2], int (*r)[m2], int k)
{
    if (n == 0 && m == 0){
        **r = 1;
        return **a;
    }

    int t[n+1][m2], t2[n+1][m2];
    for (int i =0; i <= n; i++)
        for (int j = 0; j <= m; j++){
            *(*(t + i) + j) = 0;
            *(*(t2 + i) + j) = 0;
        }

    int u = -1, l = -1;
    if (n != 0) u = findTreasure(n-1, m, m2, a, t, k-1);
    if (m != 0) l = findTreasure(n, m-1, m2, a, t2, k-1);

    *(*(t + n) + m) = k;
    *(*(t2 + n) + m) = k;

    if (u > l){

        for (int i =0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                *(*(r + i) + j) = *(*(t + i) + j);
        return *(*(a + n) + m) + u;
    }
    else{

        for (int i =0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                *(*(r + i) + j) = *(*(t2 + i) + j);
        return *(*(a + n) + m) + l;
    }
}

int main()
{
    freopen("map", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    int r[n][m];
    for (int i =0; i < n; i++)
        for (int j = 0; j < m; j++){
            scanf("%d", (*(a+i)+j));
            *(*(r + i) + j) = 0;
        }

    printf("%d\n", findTreasure(n-1, m-1, m, a, r, n+m-1));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%d ", *(*(r+i)+j));
        }
        putchar('\n');
    }
    return 0;
}
