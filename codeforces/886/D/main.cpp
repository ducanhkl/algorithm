#include <bits/stdc++.h>

using namespace std;

string s[100005];
int n;
int pre[400], after[400], dd[400];

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(dd, 0, sizeof(dd));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 'a'; i <= 'z'; i++)
        pre[i] = -1, after[i] = -1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < s[i].size(); j++)
            dd[s[i][j]] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < s[i].size()-1; j++)
        {
            char x = s[i][j];
            char y = s[i][j+1];
            if (after[x] != -1 && pre[y] != x)
                return cout << "NO", 0;
            if (pre[y] != -1 && pre[y] != x)
                return cout << "NO", 0;
            after[x] = y;
            pre[y] = x;
        }
    }
    for (int i = 'a'; i <= 'z' ; i++)
        if (dd[i] != 0)
            {
                int j = i;
                while (1)
                {
                    j = after[j];
                    if (j == -1)
                        break;
                    if (j == i)
                        return cout << "NO", 0;
                }
            }
    for (int i = 'a'; i <= 'z'; i++)
        if (dd[i] != 0 && pre[i] == -1)
            {
                int j = i;
                cout << (char)i;
                while (1)
                {
                    j = after[j];
                    if (j == -1)
                        break;
                    cout << (char)j;
                }
            }
    return 0;
}
