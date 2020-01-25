#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair

using namespace std;

int n, m;
string s;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= m; i++)
        {
            int l, r;
            char x, y;
            cin >> l >> r >> x >> y;
            for (int j = l; j <= r; j++)
                if (s[j] == x)
                    s[j] = y;
        }
    for (int i = 1; i <= n; i++)
        cout << s[i];
    return 0;
}
