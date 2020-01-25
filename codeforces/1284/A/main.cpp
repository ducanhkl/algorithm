#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;

int n, m;
string s[maxn], t[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("inp.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= m; i++)
        cin >> t[i];
    int q;
    cin >> q;
    while (q--)
    {
        int y;
        cin >> y;
        cout << s[(y-1)%n+1]  << t[(y-1)%m+1] << endl;
    }
    return 0;
}
