#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;
int n, k;
int a[maxn], ans = 0;

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >>n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    ans = a[n/2+1];
    for (int i = n/2+2; i <= n; i++)
    {
        long long res = 1LL*((long long)a[i] - a[i-1])*(i-n/2-1);
        if (k < res)
        {
            ans += k/(i-n/2-1);
            k = 0;
            break;
        }
        k -= res;
        ans = a[i];
    }
    if (k > 0)
        ans += k/(n-n/2);
    cout << ans;
    return 0;
}
