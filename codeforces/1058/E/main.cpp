#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

long long ans = 0, s = 0;
long long a[maxn], n,dem1 = 1, dem2 = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        a[i] =  __builtin_popcountll(x);
    }
    for (int i = n; i >= 1; i--)
    {
        long long sum = 0, ma = 0;
        for (int j = i; j <= n && j-i <= 65; j++)
        {
            sum += a[j];
            ma = max(ma, a[j]);
            if (ma > sum - ma && sum%2 == 0)
                ans --;
        }
        s += a[i];
        if (s%2==0)
            ans += dem1;
        else
            ans += dem2;
        if (s%2 == 0)
            dem1++;
        else dem2++;
    }
    cout << ans;
    return 0;
}
