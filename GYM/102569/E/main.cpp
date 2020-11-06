#include <bits/stdc++.h>

using namespace std;


const int maxn = 5e5+100;
int n;
long long a[maxn];

int main()
{
    // freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i-1];
    }
    long long m = *min_element(a+1, a+n+1);
    if (m > 0)
        cout << 0;
    else
        cout << -m;
    return 0;
}
