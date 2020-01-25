#include <bits/stdc++.h>

using namespace std;

typedef pair <long long, long long> pii;
const int maxn = 1e5+100;

int n;
long long res1 = 0, res2 = 0;
pii a[maxn];

bool cmp1(pii a, pii b)
{
    return a.first-a.second > b.first-b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    sort (a+1, a+n+1, cmp1);
    for (int i = 1; i <= n; i++)
        res1 += a[i].first*(i-1) + a[i].second*(n-i);
    cout << res1;
    return 0;
}
