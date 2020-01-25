#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e4+100;
int n;
char s[maxn], t[maxn];
int v[maxn];
int cnt = 0;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> s[i];
        for (int i = 1; i <= n; i++)
            cin >> t[i];
        cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] != t[i])
            {
                v[++cnt] = i;
            }
        }
        if (cnt == 0)
        {
            cout << "Yes" << endl;
            continue;
        }
        if (cnt == 2)
        {
            if (s[v[1]] == s[v[2]] && t[v[2]] == t[v[1]])
            {
                cout << "YES" << endl;
                continue;
            }
        }
        cout << "No" << endl;
    }
    return 0;
}
