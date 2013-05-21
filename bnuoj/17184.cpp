#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long
using namespace std;
struct node
{
    LL fa, l;
}d[100010];
LL n, m;
node father(LL v)
{
    node now = d[v];
    LL sum = 0, root = v;
    while (d[root].fa != root)
    {
        sum += d[root].l;
        root = d[root].fa;
    }
    LL i = v;
    while (i != root)
    {
        LL ni = i;
        LL ts = d[ni].l;
        d[ni].l = sum;
        sum -= ts;
        i = d[i].fa;
        d[ni].fa = root;
    }
    return d[v];
}
int main()
{
    while (~scanf("%lld%lld", &n, &m))
    {
        memset(d, 0, sizeof(d));
        for (LL i = 1; i <= n + 1; ++i)
            d[i].fa = i;
        for (LL i = 1; i <= m; ++i)
        {
            LL x, y, z;
            scanf("%lld%lld%lld", &x, &y, &z);
            y++;
            node fx = father(x);
            node fy = father(y);
            if (fx.fa != fy.fa)
            {
                d[fx.fa].fa = fy.fa;
                d[fx.fa].l = z + fy.l - fx.l;
                printf("Accepted!\n");
            }
            else
            {
                LL res = fx.l - fy.l;
                if (z != res) printf("Error!\n");
                else printf("Accepted!\n");
            }
        }
        for (LL i = 1; i <= n; ++i)
        {
            node fx = father(i);
            node fy = father(i + 1);
            if (fx.fa != fy.fa)
            {
                printf("Unknown!\n");
            }
            else
            {
                LL res = fx.l - fy.l;
                printf("%lld\n", res);
            }
        }
    }
    return 0;
}
