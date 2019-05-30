#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair

using namespace std;

ll k, p, ans = 0;
vector <ll> v;
ll dao(ll x)
{
    int res = 0;
    while (x!=0)
        res = res*10+ x%10, x/=10;
    return res;
}

ll mu(int x, int y)
{
    ll res = 1;
    for (int i = 1; i <= y; i ++)
        res *= 10;
    return res;
}
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> k >> p;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j < pow(10, i); j++)
    {
        if (j == 10)
            ll h = 1;
        ll h = dao(j);
        ll k = (ll)(log10(j))+1;
        ll e = mu(10, 2*i-k);
        h = h*e;
        ll m = log10(h+j);
        if (m+1==i*2)
            v.push_back(j+h);
        if (v.size() > 100005)
            break;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
    for (int i= 0; i < k; i++)
        ans = (ans + v[i]) % p;
    cout << ans;
    return 0;
}
