#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5+100;

int n;
int a[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 32; i >= 0; i--)
    {
        long long num = (1LL << i);
        for (int j = 1; j <= n; j++)
        {
            a[j] = a[j]%(num*2);
        }
        sort(a+1, a+n+1);
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            long long h = num*2-1, l = num;
            cnt += upper_bound(a+1, a+j, h-a[j]) - lower_bound(a+1, a+j, l-a[j]);
            h = (num<<3)-2, l = num*2+num;
            cnt += upper_bound(a+1, a+j, h-a[j]) - lower_bound(a+1, a+j, l-a[j]);
        }
        if (cnt%2)
            ans |= (1<<i);
    }
    cout << ans;
    return 0;
}
