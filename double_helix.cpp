#include <bits/stdc++.h>
using namespace std;
long long max(long long x, long long y)
{
    if (x > y)
        return x;
    return y;
}
int main()
{
    long long n, k, ar[100009], br[100009], i, j, y, z, u, m, sum;
    while (1)
    {
        sum = 0;
        y = 0;
        z = 0;
        scanf("%lld", &n);
        if (n == 0)
        {
            break;
        }
        for (i = 0; i < n; i++)
        {
            scanf("%lld", &ar[i]);
        }
        scanf("%lld", &m);
        for (i = 0; i < m; i++)
        {
            scanf("%lld", &br[i]);
        }
        for (i = 0, j = 0;;)
        {
            // printf("111");
            if (i == n)
            {
                // printf("dddddd\n");
                for (; j < m; j++)
                {
                    z += br[j];
                    //printf("z = %lld\n",z);
                }
                sum += max(y, z);
                break;
            }
            else if (j == m)
            {
                // printf("ssss\n");
                for (; i < n; i++)
                {
                    y += ar[i];
                    //printf("y %lld\n",y);
                }
                sum += max(y, z);
                break;
            }
            else if (br[j] == ar[i])
            {
                sum += max(y, z) + ar[i];
                y = 0;
                z = 0;
                i++;
                j++;
            }
            else if (br[j] > ar[i])
            {
                y += ar[i];
                i++;
            }
            else
            {
                z += br[j];
                j++;
            }
            // printf("%lld\n",sum);
        }
        printf("%lld\n", sum);
    }
    return 0;
}