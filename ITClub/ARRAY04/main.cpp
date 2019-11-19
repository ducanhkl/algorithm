#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

int a[20];
int n;
int dem = 0;
int dequy(int x)
{
    if (n < 3)
        n = 3;
    if (x > n)
    {
        int check = true;
        for (int i = 2; i <= n; i++)
            if (a[i] < a[i-1])
                check = false;
        if (check)
        {
            for(int i = 1; i <= n; i++)
                cout << a[i] << " ";
            cout << endl;
            dem ++;
        }
        return 0;
    }
    for (int i = 1; i <= n; i++)
        {
            a[x] = i;
            dequy(x+1);
        }
}
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	dequy(1);
	cout << dem;
	return 0;
}
