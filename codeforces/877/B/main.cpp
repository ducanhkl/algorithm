#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 5001

using namespace std;

int a = 0, ab = 0, aba = 0;
int ans = INT_MIN;

int main()
{
    freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	string s;
	cin >> s;
	for (int i = 0; i < s.length();i++)
        {
            if (s[i] == 'a')
                a ++, aba ++;
            else ab ++;
            ab = max(a, ab);
            aba = max(ab, aba);
        }
    cout << max(a, max(ab, aba));
	return 0;
}
