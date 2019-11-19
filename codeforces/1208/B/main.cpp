#include <bits/stdc++.h>

using namespace std;

const int maxn = 3000;
int n;
map <int, int> m;
int a[maxn];
int cnt = 0, ans = INT_MAX;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
        if (m[a[i]] == 2)
            cnt++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (cnt == 0)
        {
            return cout << 0, 0;
        }
        for (int j = i; j >= 1; j--)
        {
            m[a[j]] --;
            if (m[a[j]] == 1)
                cnt--;
            if (cnt == 0)
                ans = min(ans, i-j+1);
        }
        for (int j = 1; j <= i; j++)
        {
            m[a[j]]++;
            if (m[a[j]] == 2)
                cnt++;
        }
    }
    cout << ans;
    return 0;
}
