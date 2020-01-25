#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> s;
    int dem = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '?')
            dem ++;
    if (dem == 0)
        return cout << "NO", 0;
    for (int i = 1; i < s.length(); i++)
        if (s[i] == s[i-1] && s[i] != '?')
            return cout << "NO", 0;
    if (s[0] == '?' || s[s.length()-1] == '?')
        return cout << "YES", 0;
    for (int i = 1; i < s.length(); i++)
        if (s[i] == '?' && s[i-1] == '?')
            return cout << "YES", 0;
    for (int i = 1; i < s.length()-1; i++)
        if (s[i] == '?' && s[i-1] == s[i+1])
            return cout << "YES", 0;
    for (int i = 1; i < s.length()-1; i++)
            if (s[i] == '?' && s[i+1] != '?' && s[i-1] != '?' && (s[i+1] != s[i-1]))
                return cout << "NO", 0;
    cout << "YES";
    return 0;
}
