#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair

using namespace std;

ll n, s;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    n *= n;
    for (ll i = 1; i <= sqrt(n); i++)
        if (n%i == 0)
    {
        ll t = n/i;
        if ((t+i)%2)
            continue;
        ll c = (t+i)/2;
        ll b = t-c;
        if (b <sqrt(n) || c < sqrt(n))
            continue;
        s ++;
    }
    cout << s;
    return 0;
}
