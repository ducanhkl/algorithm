#include <bits/stdc++.h>

using namespace std;


const int maxn  = 1e6;
int n, m;
int a[maxn], dd[maxn], cnt[maxn], sl[maxn];

int main()
{
    memset(sl, 0, sizeof(sl));
    memset(cnt, 0, sizeof(cnt));
    memset(dd, 0, sizeof(dd));
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        cnt[a[i]] ++;
        sl[cnt[a[i]]]++;
        if (sl[cnt[a[i]]] == n)
            dd[i] = 1;
    }
    for (int i = 1; i <= m; i++)
        cout << dd[i];
    return 0;
}
