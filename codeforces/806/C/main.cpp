#include <bits/stdc++.h>

using namespace std;

int n;
int cnt1[100], cnt2[100], ans = 0;

bool check(int cnt)
{
    if (cnt > cnt1[0])
        return 0;
    int re = cnt1[0] - cnt;
    for (int i = 1; i <= 64; i++)
    {
        if (cnt >= cnt1[i])
            re -= min(re, cnt - cnt1[i]),cnt = cnt1[i];
        else
            re += cnt1[i] - cnt;
        re += cnt2[i];
    }
    return re <= cnt;
}

int main()
{
    //freopen("inp.txt",  "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        {
            long long x;
            cin >> x;
            int k = log2((long double)x);
            if (1LL << k == x)
                cnt1[k]++;
            else
                cnt2[k]++;
        }
    int r = cnt1[0]+1, l = 0;
    while (l <= r)
    {
        int mid = (l+r)/2;
        if(check(mid))
            r = mid-1, ans = mid;
        else
            l = mid+1;
    }
    if (check(ans))
        {
            for (int i = ans; i <= cnt1[0]; i++)
                cout << i << " ";
        }
    else
        cout << -1;
    return 0;
}
