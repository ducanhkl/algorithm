#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n, d = -1, k;
string s1, s;
char _s[maxn];
char a[maxn];

string flus(string h)
{
    int _n = h.length()-1, du = 1;
    for (int i = _n; i >= 0 && du != 0; i--)
    {
        h[i] += 1;
        if (h[i] > d)
            h[i] = 0, du=1;
        else du = 0;
    }
    return h;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    cin >> s;
    if (s.length() < k)
    {
        char minn = CHAR_MAX;
        cout << s;
        for (int i = 0; i < s.length(); i++)
            minn = min(minn, s[i]);
        for (int i = 1; i <= k-s.length(); i++)
            cout << (char)minn;
        return 0;
    }
    string s1 = s;
    for (int i = 0; i < n; i++)
        _s[i] = s[i];
    sort(_s, _s+n);
    a[++d] = _s[0];
    for (int i = 1; i < n; i++)
        if (_s[i] != _s[i-1])
            a[++d] = _s[i];
    for (int i = 0; i < s1.length(); i++)
        s1[i] = lower_bound(a, a+d, s1[i])-a;
    for (int i = 0; i < s1.length(); i++)
        cout << (int)s1[i];
    cout << endl;
    string k1 = "";
    for (int i = 0; i < k; i++)
        k1 = k1 + (char)s1[i];
    s1 = k1;
    s1 = flus(s1);
    for (int i = 0; i < k; i++)
        cout << char(a[s1[i]]);
    return 0;
}
