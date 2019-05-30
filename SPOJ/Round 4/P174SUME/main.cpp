#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000001

using namespace std;

string s;
int n, k;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
        s += "a";
    if (k == 1 && n != 1)
        return cout << -1, 0;
	if (k > n)
        return cout << -1, 0;
    for (int i = 0; i < n -k+2; i ++)
        if (i%2 == 0)
            s[i] = 'a'; else s[i] = 'b';
    for (int i = 2, j = n - k +2; i < k && j < n; i++, j++)
        s[j] = i+'a';
    cout << s;
    return 0;
}
