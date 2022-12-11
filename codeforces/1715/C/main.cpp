#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;

int m;
long long n;
long long ans = 0;
int a[maxn], b[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != a[i-1])
        {
            ans += (n-i + 1)*(i-1);
        }
    }

    ans += n*(n+1)/2;

    while (m--)
    {
        int pos, val;
        cin >> pos >> val;
        ans -= (a[pos] != a[pos-1])*(n-pos+1)*(pos-1);
        ans -= (a[pos] != a[pos+1])*(n-pos)*(pos);
        a[pos] = val;
        ans += (a[pos] != a[pos-1])*(n-pos+1)*(pos-1);
        ans += (a[pos] != a[pos+1])*(n-pos)*(pos);
        cout << ans << endl;
    }
    return 0;
}
