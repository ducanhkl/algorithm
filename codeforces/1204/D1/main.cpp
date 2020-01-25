#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int cnt = 0;
    cin >> s;
    for (int i = s.length()-1; i >= 0; i--)
    {
        if (cnt == 0 && s[i] == '1')
        {
            s[i] = '0';
            continue;
        }
        cnt += 1-2*(s[i] == '1');
    }
    cout << s;
    return 0;
}
