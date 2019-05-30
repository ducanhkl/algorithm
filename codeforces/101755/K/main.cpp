#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+100;
int n, m;
int a[maxn];
int ans;

bool check(int mid)
{
    int res = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
        if (res >= a[i])
            res++;
        else
            if (cnt < mid)
                cnt ++, res++;
    return res >= m;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    ans = n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 0, r =2e6+100;
    while (l <= r)
    {
        int mid = (l+r)>>1;
        if (check(mid))
            ans = mid, r = mid-1;
        else
            l = mid+1;
    }
    cout << ans;
    return 0;
}
