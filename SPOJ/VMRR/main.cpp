#include <bits/stdc++.h>

using namespace std;

string s;
char a, b;
long long ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> s;
    cin >> a >> b;
    int demb = 0;
    for (int i = s.length()-1; i >= 0; i--)
    {
        if (s[i] == a)
            ans += demb;
        if (s[i] == b)
            demb++;
    }
    cout << ans;
    return 0;
}
