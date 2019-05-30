#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 150

using namespace std;

int a[maxn], n, d[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
        cin >> a[i], d[a[i]] = i;
    int x = 1, y = n;
    for (int i = 1; i <= n; i++)
        if (i%2 == 0)
    {
        int dem = 0;
        for (int j = d[y]; j < y; j++)
        {
            swap(a[j], a[j+1]);
            d[a[j]] = j;
            d[a[j+1]] = j+1;
            dem ++;
        }
        cout << dem << " ";
        y--;
    }
    else
    {
        int dem = 0;
        for (int j = d[x]; j > x; j--)
        {
            dem ++;
            swap(a[j], a[j-1]);
            d[a[j]] = j;
            d[a[j-1]] = j-1;
        }
        cout << dem <<  " ";
        x++;
    }
	return 0;
}

