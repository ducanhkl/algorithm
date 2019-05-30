#include <iostream>

using namespace std;

long long n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
            if (s[i] > '1')
        {
            for (int j = i; j < s.length(); j++)
                s[j] = '1';
            break;
        }
        long long res = 0;
        for (int i = 0; i < s.length(); i++)
            res += (s[i]-'0')*(1LL<<(s.length()-i-1));
        cout << res << endl;
    }
    return 0;
}
