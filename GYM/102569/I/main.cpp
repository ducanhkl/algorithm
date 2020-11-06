#include <bits/stdc++.h>

using namespace std;


const int maxn = 2e5+100;
vector <int> mau[maxn];
int n;
int a[maxn], c[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
        mau[c[i]].push_back(a[i]);
    }
    for (int i = 1; i < maxn; i++)
    {
        for (int j = 1; j < mau[i].size(); j++)
        {
            if (mau[i][j] < mau[i][j-1])
                {
                    cout << "NO";
                    return 0;
                }
        }
    }
    cout << "YES";
    return 0;
}
