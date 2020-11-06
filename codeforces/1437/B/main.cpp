#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e5+100;
char s[maxn];

int main()
{
    ios::sync_with_stdio(false);
    int test;
    cin >> test ;
    while (test --)
    {
        int n;
        int ans1 = 0, ans2 = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> s[i];
        }
        for (int i = 1;  i < n; i++)
        {
            if (s[i] == '0' && s[i] == s[i+1])
            {
                ans1 ++;
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '1' && s[i] == s[i+1])
            {
                ans2 ++;
            }
        }
        cout << max(ans1, ans2) << endl;
    }
    return 0;
}
