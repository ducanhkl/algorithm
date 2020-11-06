#include <bits/stdc++.h>

using namespace std;

int n;
int dd[300], b[300];


void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
}

void solve()
{
    vector <int> ans;
    memset(dd, 0, sizeof(dd));
    for (int i = 1; i <= n; i++)
        dd[b[i]] = 1;
    for (int i = 1; i <= n; i++)
    {
        int p = b[i];
        ans.push_back(p++);
        int ck = 0;
        while( p <= 2*n )
        {
            if (dd[p] == 0)
            {
                ans.push_back(p);
                dd[p] = 1;
                ck = 1;
                break;
            }
            p++;
        }
        if (ck == 0)
        {
            cout << -1;
            return ;
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        input();
        solve();
        cout << endl;
    }
    return 0;
}
