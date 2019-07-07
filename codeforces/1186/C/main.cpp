#include <bits/stdc++.h>

using namespace std;

string s, t;
int cnt = 0, val = 0, ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> s >> t;
    for (int i = 0; i < t.size(); i++)
        if (s[i] != t[i])
            cnt++;
    for (int i = 1; i < t.size(); i++)
        if (t[i] != t[i-1])
            val ++;
    ans += (cnt+1)%2;
    for (int i = 1; i <= s.size()-t.size(); i++)
        {
            cnt += val;
            if (s[i-1] != t[0])
                cnt--;
            if (s[i+t.size()-1] != t[t.size()-1])
                cnt++;
            cnt = abs(cnt);
            ans += (cnt+1)%2;
        }
    cout << ans;
    return 0;
}
