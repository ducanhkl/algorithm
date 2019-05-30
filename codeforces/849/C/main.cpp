#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

vector <int> v;
int n;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	if (n == 0)
        return cout << "ab", 0;
	while (n)
    {
        int x = 0;
        while (x*(x+1)/2 < n)
            x ++;
        n -= x*(x+1)/2;
        if (n<0)
        {
            n += x;
            v.push_back(x-1);
            continue;
        }
        v.push_back(x);
    }
    for (int x = 0; x  < v.size(); x++)
        for (int i = 0; i <= v[x]; i++)
            cout << (char) ('a'+x);
	return 0;
}
