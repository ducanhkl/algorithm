#include <bits/stdc++.h>

using namespace std;

string s;

bool check(char x)
{
    if (x == 'a' || x == 'o' || x == 'u' || x == 'i' || x == 'e')
        return true;
    else return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s;
    for (int i  = 0; i < s.length()-1; i++)
    {
        if (check(s[i]))
            continue;
        if (s[i] == 'n')
            continue;
        if (check(s[i+1]))
            continue;
        cout << "NO";
        return 0;
    }
    if (check(s[s.length()-1]) || s[s.length()-1] == 'n')
        return cout << "YES", 0;
    cout << "NO";
    return 0;
}
