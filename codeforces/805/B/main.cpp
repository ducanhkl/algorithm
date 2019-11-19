#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

int n;
string s;

int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	if (n == 2)
        return cout << "aa", 0;
    for (int i = 0; i < n; i++)
        if ((i/2)%2)
            cout << "b";
        else cout << "a";
	return 0;
}
