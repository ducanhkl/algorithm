#include <bits/stdc++.h>
#define maxn 100006

using namespace std;

const long long mod = 1000000007;
int t;
int n;
pair <long long, int> a[maxn];
long long ans[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    scanf("%d", &t);
    while (t--)
    {
        memset(ans, 0, sizeof(ans));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%I64d", &a[i]), a[i].second = i, a[i].first = a[i].first % mod;
        sort(a+1, a+n+1);
        for (int i = 1; i <= n; i++)
        {
            long long res = 0;
            int pos1 = lower_bound(a+1, a+n+1, (pair <long long, int>){mod-a[i].first, -1})-a;
            int pos2 = lower_bound(a+1, a+n+1, (pair <long long, int>){2*mod-a[i].first, -1})-a;
            if (pos1 > n)
                pos1--;
            if (pos2 > n)
                pos2--;
            if (pos1 == 0)
                pos1++;
            if (pos2 == 0)
                pos2 ++;
            for (int j = max(pos1-10, 1); j <= min(pos1+10, n); j++)
                if (a[i].second != a[j].second)
                    res = max(res, (a[i].first + a[j].first)%mod);
            for (int j = max(pos2-10, 1); j <= min(pos2+10, n); j++)
                if (a[i].second != a[j].second)
                    res = max(res, (a[i].first + a[j].first)%mod);
           ans[a[i].second] = res;
        }
        for (int i = 1; i <= n; i++)
            printf("%I64d ", ans[i]);
        printf("\n");
    }
    return 0;
}
