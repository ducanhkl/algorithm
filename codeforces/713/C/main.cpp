#include <bits/stdc++.h>

using namespace std;

const int maxn = 3010;

long long a[maxn];
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] -= i;
    }
    int f_opt = a[1];
    multiset <int> s;
    s.insert(a[1]);
    long long ans = 0;
    for (int i = 2; i <= n; i++)
    {
        s.insert(a[i]);
        int opt = *s.rbegin();
        if (opt > a[i])
        {
            s.erase(--s.end());
            s.insert(a[i]);
            ans += opt - a[i];
        }
    }
    cout << ans << endl;
    return 0;
}
