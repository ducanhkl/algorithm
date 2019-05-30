/*
#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[30];
vector <string> ans;

void check()
{
    int b[20];
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; i++)
        b[i] = !a[i];
    for (int i = 1; i <= n; i++)
        if (b[i] == 1)
            b[i] += b[i-1];
        else
            b[i] = 0;
    int check = true;
    for (int i = 1; i <= n; i++)
        if (b[i] > k)
            return ;
        else
            if (b[i] == k)
        {
            if (check == false)
                return;
            check = false;
        }
    if (check)
        return;
    string s;
    for (int i = 1; i <= n; i++)
        if (a[i] == 1)
            s = s+"B";
        else
            s = s+"A";
    //cout << s << endl;
    ans.push_back(s);
}

bool isFinal()
{
    for (int i = 1; i <= n; i++)
        if (a[i] == 0)
            return false;
    return true;
}

void next_per()
{
    int i;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == 0)
            {
                a[i] = 1;
                return;
            }
        a[i] = 0;
    }
    return ;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    memset(a, 0, sizeof(a));
    while (!isFinal())
    {
        check();
        next_per();
    }
    check();
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}
*/

#include <iostream>
#include <cstring>

using namespace std;
int n, k, dem=0;
char B[100], kq[1000][100];
void inkq()
{
    printf("%d \n", dem);
    for (int i = 1; i <= dem; i++)
        printf("%s\n", kq[i]+1);
}
void update()
{
    dem++;
    for (int i = 1; i <= n; i++)
        kq[dem][i] = B[i];
}
bool check()
{
	int t=0, d = 0;
	for(int i=1; i<=n; i++)
		if(B[i] == 'A')
		{
			t++;
            if (t == k)
                d++;
            if (t > k)
                return false;
		} else
            t = 0;
	if(d==1)
            return true;
	return false;
}
void Try( int i )
{
	for(char j='A'; j<='B'; j++ )
	{
		B[i] = j;
		if(i==n)
		{
			if(check())
				update();
		}
		else Try(i+1);
	}
}
int main()
{
    memset(kq, 0, sizeof(kq));
	cin>>n>>k;
	Try(1);
	inkq();
	return 0;
}
