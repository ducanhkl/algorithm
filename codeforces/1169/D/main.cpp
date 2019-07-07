#include <bits/stdc++.h>

using namespace std;

long long ans = 0;
string s;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> s;
    int id = -1;
    for (int i = 0; i < (int)s.length(); i++)
    {
        for (int j = 1; j <= 4 && i - 2*j >= 0; j++)
            if (s[i] == s[i-j] && s[i-j] == s[i-2*j])
                id = max(id, i-2*j);
        ans += id+1;
    }
    cout << ans;
    return 0;
}
