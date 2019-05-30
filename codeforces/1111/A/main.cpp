#include <bits/stdc++.h>

using namespace std;

string s, t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s;
    cin >> t;
    if (s.size() != t.size())
        return cout << "No", 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != t[i])
    {
        bool ck1 = 0, ck2 = 0;
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'i')
            ck1 = 1;
        if (t[i] == 'a' || t[i] == 'e' || t[i] == 'o' || t[i] == 'u' || t[i] == 'i')
            ck2 = 1;
        if (ck1 != ck2)
            return cout << "No", 0;
    }
    cout << "Yes";
    return 0;
}
