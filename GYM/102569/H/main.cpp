#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+200;
int n;
int cnt[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >>u >> v;
        cnt[u] ++;
        cnt[v] ++;
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == 1)
        {
            res ++;
        }
    }

    cout << (res + 1)/2;
    return 0;
}
