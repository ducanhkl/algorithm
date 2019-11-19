#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+10;
int n;
long long a[maxn], ans, vt, b[maxn], res = 0, cnt = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(b, 0, sizeof(b));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            res += abs(a[i]-i);
            b[(a[i]-i+n)%n] ++;
            if (a[i] < i)
                cnt ++;
            else
                cnt--;
        }
    ans = res, vt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += 2*(b[i]-1);
        res += abs(a[n-i]-1) - abs(a[n-i]-n)+1+cnt;
        if (res < ans)
        {
            ans = res;
            vt = i+1;
        }
    }
    cout << ans << " " << vt;
}
