#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;
string s, t;
int c1[maxn], c2[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        memset(c1, 0, sizeof(c1));
        int ans = 0;
        memset(c2, 0, sizeof(c2));
        cin >> s >> t;
        for (int i = 0; i < s.size(); i++)
        {
            c1[s[i]] = 1;
            c2[t[i]] = 1;
        }
        for (int i = 0; i < maxn; i++)
            ans |= (c1[i] && c2[i]);
        if (ans)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}
