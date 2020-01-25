#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    string s;
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n >> s;
        if (n == 2 && s[0] >= s[1])
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl << 2 << endl;
        cout << s[0] << " ";
        for (int i = 1; i < s.length(); i++)
            cout << s[i];
        cout << endl;
    }
    return 0;
}
