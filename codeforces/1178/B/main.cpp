#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;
string s;
int le[maxn], ri[maxn], cnt[maxn];
long long ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> s;
    int n = s.length();
    s = " " + s + " ";
    for (int i = 1; i <= n; i++)
        if (s[i] == 'v')
            cnt[i] = cnt[i-1] + 1;
        else
            cnt[i] = 0;
    for (int i = 1; i <= n; i++)
        if (cnt[i] == 0 && cnt[i-1] != 0)
            le[i] = le[i-1] + cnt[i-1] - 1;
        else
            le[i] = le[i-1];
    memset(cnt, 0, sizeof(cnt));
    for (int i = n; i >= 1; i--)
        if (s[i] == 'v')
            cnt[i] = cnt[i+1] + 1;
        else
            cnt[i] = 0;
    for (int i = n-1; i >= 1; i--)
        if (cnt[i] == 0 && cnt[i+1] != 0)
            ri[i] = ri[i+1] + cnt[i+1] - 1;
        else
            ri[i] = ri[i+1];
    for (int i = 1; i <= n; i++)
        if (s[i] == 'o')
            ans += 1LL*le[i]*ri[i];
    cout << ans;
    return 0;
}
