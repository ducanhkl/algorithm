#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

//ll n;

ll get1(ll n)
{
    if (n == 1) return 1;
    if (n & 1) return n - get1(n - 1);
    return n - get1(n / 2);
}

ll get2(ll n)
{
    if (n == 4)
        return 2;
    if (n == 1) return 1;
    if (n & 1)
    {
        return n - get2(n - 1);
    }
    if (n%2 == 0 && ((n/2)%2 == 0))
        return n - get2(n - 1);
    ll res = get2(n/2);
    return res;
}

void Solve()
{
//  cin >> n;
//  for (int n = 1; n <= 100; n++) {
//    if (get1(n) != get2(n)) {
//      cout << n << " " << get1(n) << " " << get2(n) << endl;
//      break;
//    }
//  }
    cout << get2(12);

}


int main()
{
//  ios::sync_with_stdio(false); cin.tie(0);
//  freopen("1.txt", "r", stdin);

    int T = 1;
//  cin >> T;
    while (T--)
    {
        Solve();
    }

    return 0;
}
