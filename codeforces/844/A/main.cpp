#include <bits/stdc++.h>
#define maxn 1000

using namespace std;
string s;
int n, dem = 0, a[maxn], d[maxn], ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> s;
    cin >> n;
    sort(s.begin(), s.end());
    if (s.length() < n)
        return cout << "impossible", 0;
    s = " " + s;
    for (int i = 1; i < s.length(); i++)
        if (s[i] != s[i-1])
            dem ++;
    cout << max(0, n-dem);
    return 0;
}
