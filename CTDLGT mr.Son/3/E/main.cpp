#include <bits/stdc++.h>

using namespace std;

int sum(string s, string t)
{
    int first = 0, second = 0;
    for (int i = 0; i < s.size(); i++)
        first = (first*10+s[i]-'0');
    for (int i = 0; i < t.size(); i++)
        second = (second*10+t[i]-'0');
    int ans = first + second;
    return ans;
}
int main()
{
    string s, t;
    ios_base::sync_with_stdio(false);
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '6' )
            s[i] = '5';
    for (int i = 0; i < t.size(); i++)
        if (t[i] == '6')
            t[i] = '5';
    cout << sum(s, t) << " ";
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '5' )
            s[i] = '6';
    for (int i = 0; i < t.size(); i++)
        if (t[i] == '5')
            t[i] = '6';
    cout << sum(s, t);
    return 0;
}
