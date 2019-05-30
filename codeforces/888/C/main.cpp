#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000006

using namespace std;

char a[maxn];
int t[maxn], dd[maxn];
string s;

int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> s;
	for (int i = 0; i < s.length(); i++)
        a[i+1] = s[i];
    int n = s.length()+1;
    a[n+1] = '.';
    memset(dd, 0, sizeof(dd));
    memset(t,0, sizeof(t));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 256; j++) t[j] = max(t[j], i - dd[j]);
        dd[a[i]] = i;
    }
    cout << *min_element(t+1,t+250);
	return 0;
}
