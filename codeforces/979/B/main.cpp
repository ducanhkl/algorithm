#include <bits/stdc++.h>

using namespace std;

int n, dd[4][400], res, ans = 0, d;
string a[5];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> a[1] >> a[2] >> a[3];
    for (int i = 1; i <= 3; i++)
        for (int j = 0; j < a[i].size(); j++)
            dd[i][a[i][j]] ++;
    for (int i = 1; i <= 3; i++)
    {
        res = 1;
        for (int j = 'A'; j <= 'z'; j++)
            if (n + dd[i][j] <= a[i].size())
                res = max(res, n + dd[i][j]);
            else
            {
                if (dd[i][j] == a[i].size() && n%2)
                    res = max(res, (int)a[i].size()-1);
                else res = max(res, (int)a[i].size());
            }
        if (ans == res)
            d = 0;
        if (ans < res)
            d = i, ans = res;
    }
    if (d == 1)
        return cout << "Kuro", 0;
    if (d == 2)
        return cout << "Shiro", 0;
    if (d == 3)
        return cout << "Katie", 0;
    cout << "Draw";
    return 0;
}
