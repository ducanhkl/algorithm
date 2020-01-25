#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005

using namespace std;

int main()
{
    int n;
    ios_base::sync_with_stdio(false), cin.tie(false);
    cin >> n;
    int a[] = {0, 1, 1, 0}, vt = 3;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (a[x] == 0)
            return cout << "NO", 0;
        int t = 6 - x - vt;
        a[vt] = 1;
        vt = t;
        a[t] = 0;
    }
    cout << "YES";
    return 0;
}
