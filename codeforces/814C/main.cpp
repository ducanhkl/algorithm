#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

int n, q;
string s;

int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> s >> q;
	while (q--)
    {
        char a;
        int m, ans = 0, d = 0, l = 0;
        cin >> m >> a;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != a)
                l++;
            while (l > m)
            {
                if (s[d] != a)
                    l--;
                d++;
            }
            ans = max(ans, i-d+1);
        }
        cout << ans <<endl;
    }
	return 0;
}
