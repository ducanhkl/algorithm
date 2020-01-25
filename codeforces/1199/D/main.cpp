#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e6;
int n;
int a[maxn], m[maxn], lst[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int p, v;
            cin >> p >> v;
            a[p] = v;
            lst[p] = i;
        } else
        {
            int v;
            cin >> v;
            m[i] = v;
        }
    }
    for (int i = q; i >= 0; i--)
    {
        m[i] = max(m[i+1], m[i]);
    }
    for (int i = 1; i <= n; i++)
        cout << max(a[i], m[lst[i]]) << " ";
    return 0;
}
