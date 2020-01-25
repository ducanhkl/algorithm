#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

typedef pair <long long, long long> pii;

int n, A, B;
pii a[maxn];
long long ans = 0;

bool cmp1(pii x, pii y)
{
    return x.first*(1LL<<(A))  - x.second > y.first*(1LL<<A) - y.second;
}

bool cmp2(pii x, pii y)
{
    return x.first - x.second > y.first - y.second;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> A >> B;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    sort (a+1, a+n+1, cmp1);
    int f = 1;
    if (a[1].first*a[1].first > a[1].second && min(A, B) != 0)
        ans += (1LL<<(A))*a[1].first, f = 2, A = 0, B--;
    sort (a+f, a+n+1, cmp2);
    for (int i = f; i <= n; i++)
    {
        if (a[i].first > a[i].second && A < B)
            ans += a[i].first, B--;
        else ans += a[i].second;
    }
    cout << ans;
    return 0;
}
