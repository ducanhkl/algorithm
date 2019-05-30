#include <bits/stdc++.h>
#define maxn 5000005

using namespace std;


int a[maxn], f[maxn];
int n, res = 0, k, l = 0, r  = INT_MAX;

bool check (int x)
{
    memset(f, 0, sizeof(f));
    int ff = 0;
    for (int i = k; i <= n; i++)
    {
        if (a[i] - a[f[i-k]+1] <= x)
            ff = i;
        f[i] = ff;
    }
    return f[n] == n;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    a[n+1] = INT_MAX;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort (a+1, a+n+1);
    while (l <= r)
    {
        int mid = (l+r) >> 1;
        if (check(mid))
            res = mid, r = mid-1;
        else l = mid+1;
    }
    cout << res;
    return 0;
}
