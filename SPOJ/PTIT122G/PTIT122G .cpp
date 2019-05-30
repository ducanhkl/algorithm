#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

string s;

bool check(string k)
{
    for (int i = 0; i < k.length(); i++)
        if (k[i] != k[k.length()-i-1])
            return false;
    return true;
}

ll calc(string k)
{
    ll ans = 0;
    for (int i = 0; i < k.length(); i++)
        ans = ans *10 + (k[i] - '0');
    return ans;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	while (cin >> s)
    {
        if (s == "0")
            return 0;
        string h = s;
        int n = s.length();
        while (!check(s))
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] > s[n-i-1])
                    s[n-i-1] = s[i];
                if (s[i] < s[n-i-1])
                {
                    s[n-i-1] = s[i];
                    int r = 1;
                    for (int j = n-i-1-1; j >= 0; j--)
                    {
                        s[j] ++;
                        r = 0;
                        if (s[j] > '9')
                            s[j] = '0', r = 1;
                        if (r == 0)
                            break;
                    }
                    break;
                }
            }
        cout << calc(s) - calc(h) << endl;
    }
	return 0;
}
