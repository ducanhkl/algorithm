#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
    cin >> s;
    if (s.length() < 2)
        return cout << "No", 0;
    for (int i = 0; i < s.length()-2; i++)
        if (s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2] && s[i] != '.' && s[i+2] != '.' && s[i+1] != '.')
            return cout << "Yes", 0;
    cout << "No";
    return 0;
}
