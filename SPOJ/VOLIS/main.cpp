#include "bits/stdc++.h"

using namespace std;

const int maxn = 1e3+100;
const long long maxc = 1e9+1e5;

int n, d;
long long a[maxn], last[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);   
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        last[i] = maxc;
    }
    last[0] = -maxc;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j --)
        {
            if (a[i]-d >= last[j-1])
            {
                last[j] = min(last[j], a[i] - d);
            } else
            {
                if (a[i] + d >= last[j-1])
                {
                    last[j] = min(last[j], last[j-1]);
                }
            }
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (last[i] != maxc)
        {
            cout << i;
            return 0;
        }
    }
}