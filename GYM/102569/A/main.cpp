#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 6e5+100;
int q;
int n;
long long a[maxn];
long long res = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = n, j = 1; i >= 1; i --)
    {
         res += j*a[i];
         j *= -1;
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int l, r, v;
        cin >> l >> r >> v;
        if ((n-r)%2 && (n-l)%2)
            res -= v;
        if ((n+1-r)%2 && (n+1-l)%2)
            res += v;
        cout << res << endl;
    }
    return 0;
}
