#include <bits/stdc++.h>

using namespace std;

struct data
{
    double x, y;
};

data a[5], dinh[5];
int n, d[5];

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n;
    while(n--)
    {
        for (int i = 1; i <= 4; i++)
            cin >>a[i].x >> a[i].y;
        for (int i = 1;i <= 4; i++)
            d[i] = i;
        bool kt = true;
        do
        {
            for (int i = 1; i <= 4; i++)
                dinh[i].x = a[d[i]].x, dinh[i].y = a[d[i]].y;
			if (dinh[1].x==dinh[4].x && dinh[1].y!=dinh[4].y && dinh[2].x==dinh[3].x && dinh[2].y!=dinh[3].y && dinh[1].y==dinh[2].y && dinh[1].x!=dinh[2].x && dinh[4].y==dinh[3].y && dinh[4].x!=dinh[3].x)
			{
			    cout << "YES" << endl;
				kt = 0;
				break;
			}
        } while (next_permutation(d+1, d+5));
        if (kt)
                cout << "NO" << endl;
    }
    return 0;
}
