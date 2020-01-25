#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5+100;

int dd[maxn], p[maxn], t[maxn];
int n, k, ans = 0, cnt = 0;
set <int> s;


int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(dd, 0, sizeof(dd));
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    int cnt = 0;
    for (int i = 2; i < k; i++)
    {
        if (p[i] < p[i-1])
            cnt++;
    }
    for (int i = 1; i <= n-k+1; i++)
    {
        cnt += (p[i+k-1] < p[i+k-2]);
        if (cnt == 0)
            ans = 1;
        t[i] = cnt;
        cnt -= (p[i+1] < p[i]);
    }
    for (int i = 1; i < k; i++)
        s.insert(p[i]);
    for (int i = 2; i <= n-k+1; i++)
    {
        s.insert(p[i+k-1]);
        if (*s.begin() == p[i-1] && *s.rbegin() == p[i+k-1])
        {
            dd[i] = 1;
        }
        s.erase(p[i-1]);
    }
    for (int i = 1; i <= n-k+1; i++)
        if (dd[i] == 0)
    {
        if (t[i])
            ans ++;
    }
    cout << ans;
}
