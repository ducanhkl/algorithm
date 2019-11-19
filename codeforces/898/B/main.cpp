#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair

using namespace std;

ll a, b, n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> a >> b;
    if (a == b && b == 0)
            return cout << "YES\n1 1", 0;
    if (a == 0)
        if (n % b == 0)
            return cout << "YES" << endl << 0 << " " << n/b, 0;
        else return cout << "NO", 0;
    if (b == 0)
        if (n%a == 0)
            return cout << "YES" << endl << n/a << " " << 0, 0;
        else return cout << "NO", 0;
    for (int i = 0; i <= n; i += a)
        if ((n-i) % b == 0)
            return cout << "YES" << endl << i/a << " " << (n-i)/b, 0;
    cout << "NO";
    return 0;
}
