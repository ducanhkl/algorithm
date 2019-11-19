#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

string s;
int ans = 0;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	int test;
	cin >> test;
	while (test--)
	{
	    cin >> s;
	    ans = 0;
        int d = 0;
        for (int i =0; i< s.length(); i++)
        {
            if (s[i] == '(')
                    d  ++;
            else d--;
            if (d<0)
            {
                ans ++;
                d += 2;
            }
        }
        ans += d/2;
        cout << ans << endl;
	}
	return 0;
}
