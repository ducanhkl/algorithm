#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	string s1, s2;
	cin >> n;
	cin >> s1 >> s2;
	int i = 0;
	while (s1[i] == s2[i])
        i++;
    if (s1.length() + s2.length() - 2*i > n)
        return cout << "NO", 0;
    cout << "YES";
	return 0;
}
