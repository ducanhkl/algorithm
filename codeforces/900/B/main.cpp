#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair

using namespace std;

ll a, b, c;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> a >> b >> c;
    ll t = __gcd(a, b);
    a = a/t;
    b = b/t;
    for (int i = 1; i < 1000006; i++)
    {
        if ((a*10/b)%10 == c)
            return cout << i, 0;
        a = (a*10)%b;
    }
    cout << -1;
    return 0;
}
