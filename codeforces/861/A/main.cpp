#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

ll n, k, dem = 1;

int main()
{
    freopen("inp.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        dem *= 10;
    for (int i = 1; i  <= dem; i++)
    {
        ll d = i*n;
        if (d % dem ==0)
            return cout << d, 0;
    }
}
