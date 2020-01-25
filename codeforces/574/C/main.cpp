#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n;
long long a[maxn];

bool ck(long long x)
{
    while (x%2 == 0)
        x /= 2;
    while (x%3 == 0)
        x /= 3;
    if (x == 1)
        return false;
    return true;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
    {
        long long k = __gcd(a[i], a[i-1]);
        k = a[i]*a[i-1]/k;
        if (ck(k/a[i]))
            return cout << "No", 0;
        if (ck(k/a[i-1]))
            return cout << "No", 0;
    }
    cout << "Yes";
    return 0;
}
