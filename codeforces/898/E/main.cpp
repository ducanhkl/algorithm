#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair

using namespace std;

vector <int> v;
int counter0 = 0, countersq = 0;
int n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n ; i++)
    {
        int x;
        cin >> x;
        if (x == 0)
            counter0 ++;
        int k = sqrt(x);
        v.push_back(min(x-k*k, (k+1)*(k+1)-x));
        if (k*k == x)
            countersq++;
    }
    ll ans = 0;
    sort(v.begin(), v.end());
    if (countersq < n/2)
    {
        for (int i = 0; i < n/2; i++)
            ans += v[i];
    }
    else
    {
        ans = countersq - n/2;
        if (counter0 > n/2)
            ans += counter0 - n/2;
    }
    cout << ans;
    return 0;
}
