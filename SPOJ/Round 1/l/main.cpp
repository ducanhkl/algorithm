#include <bits/stdc++.h>
#define maxn 259

using namespace std;

int d[maxn], n;
string s;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    //freopen("inp.txt", "r", stdin);
    cin >> n;
    while (n--)
    {
        memset(d, 0, sizeof(d));
        cin >> s;
        int dem = 0;
        for (int i = 0; i < s.length(); i++)
            d[s[i]] ++;
        for (int i = 97; i <= 122; i++)
            if (d[i] % 2 == 1)
            dem ++;
        if (dem >= 4)
            cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
