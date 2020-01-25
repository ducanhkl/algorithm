#include <bits/stdc++.h>
#define maxn 6001

using namespace std;

int a[maxn], n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        int u = a[i];
        int v = a[u];
        if (a[v] == i)
            return cout << "YES", 0;
    }
    cout << "NO";
    return 0;
}
