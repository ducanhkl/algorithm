#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 1000000007

using namespace std;

string s;
ll ans = 0, res = 0;

int main()
{
    freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> s;
	for (ll i = 0; i < s.length(); i++)
           ans = (ans*10*1LL + (s[i]-'0')*(i+1)) % maxnum, res += ans, res = res%maxnum;
    cout << res;
	return 0;
}
