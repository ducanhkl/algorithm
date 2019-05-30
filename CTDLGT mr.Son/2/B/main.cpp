#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+7;
int n, k, t;
int a[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int pos = lower_bound(a+1, a+n+1, k) - a;
        if (a[pos] != k)
            cout << "NO";
        else
            cout << pos;
        cout << endl;
    }
    return 0;
}
