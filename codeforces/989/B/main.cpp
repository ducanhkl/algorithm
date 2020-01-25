#include <bits/stdc++.h>

using namespace std;

char s[2001];
int n, p;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        if (s[i] != '.')
            s[i] = s[i] - '0';
    for (int i = 1; i <= n-p; i++)
        if (s[i] != s[i+p] || s[i] == '.' || s[i+p] == '.')
    {
        for (int j = 1; j <= n-p; j++)
        {

            if (s[j] == '.' && s[j+p] == '.')
                s[j] = 1, s[j+p] = 0;
            if (s[j] == '.')
                s[j] = (s[j+p]+1)%2;
            if (s[j+p] == '.')
                s[j+p] = (s[j]+1)%2;
        }
        for (int j = 1; j <= n; j++)
            if (s[j] == '.')
                cout << '0';
            else
                cout << (char)(s[j]+'0');
        return 0;
    }
    cout << "No";
    return 0;
}
