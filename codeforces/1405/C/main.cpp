#include <bits/stdc++.h>

using namespace std;


const int maxn = 4e5+100;

int n, k;
char s[maxn];

void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int cnt0 = 0, cnt1 = 0, cnth = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?')
            continue;
        if (s[i%k] == '?')
        {
            s[i%k] = s[i];
        }
        if (s[i%k] != s[i])
        {
            cout << "NO";
            return;
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (s[i] == '0')
            cnt0 ++;
        if (s[i] == '1')
            cnt1 ++;
        if (s[i] == '?')
            cnth ++;
    }
    if (!(abs(cnt0 - cnt1) <= cnth))
    {
        cout << "NO";
        return ;
    }
    cout << "YES";
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        solve();
        cout << endl;
    }
    return 0;
}
