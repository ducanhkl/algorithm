#include <bits/stdc++.h>

using namespace std;



int dd[20];
int ans = 0;
string s[40];
int n;

void solve()
{
    ans = 0;
    memset(dd, 0, sizeof(dd));
    for (int i = 1; i <= n; i++)
        dd[s[i][0]-'0'] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i-1; j >= 1; j--)
        {
            if (s[i] == s[j])
            {
                for (int k = 0; k <= 9; k++)
                {
                    if (dd[k] == 0)
                    {
                        dd[k] = 1;
                        s[i][0] = k+'0';
                        break;
                    }
                }
                ans ++;
                break;
            }
        }
        dd[s[i][0]-'0'] = 1;
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        cout << s[i] << endl;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> s[i];
        solve();
    }
    return 0;
}
