#include <bits/stdc++.h>

using namespace std;

map <char, string> m;
int n;
string s[5300];

bool check(int x)
{
    for (int i = 0; i < n; i += x)
        for (int j = 0; j < n; j += x)
    {
        char t = s[i][j];
        for (int ii = 0; ii < x; ii++)
            for (int jj = 0; jj < x; jj++)
                if (t != s[i+ii][j+jj])
                    return false;
    }
    return true;
}

int main()
{
    m['0'] = "0000";
    m['1'] = "0001";
    m['2'] = "0010";
    m['3'] = "0011";
    m['4'] = "0100";
    m['5'] = "0101";
    m['6'] = "0110";
    m['7'] = "0111";
    m['8'] = "1000";
    m['9'] = "1001";
    m['A'] = "1010";
    m['B'] = "1011";
    m['C'] = "1100";
    m['D'] = "1101";
    m['E'] = "1110";
    m['F'] = "1111";
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        {
            string x;
            cin >> x;
            for (int j = 0; j < x.length(); j++)
                s[i] += m[x[j]];;
        }
    for (int i = n; i >= 1; i--)
        if (n%i == 0)
            if (check(i))
    {
        cout << i;
        return 0;
    }
    return 0;
}
