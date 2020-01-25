#include <bits/stdc++.h>

using namespace std;

long long f[30][2][2],a[30],b[30];

long long calc(int pos,int upa,int upb)
{
    if(pos==-1)
        return 1;
    long long &ans = f[pos][upa][upb];
    if(ans!=-1)
        return ans;
    ans = 0;
    int max1 = (upa?a[pos]:1);
    int max2 = (upb?b[pos]:1);
    for(int i=0; i<= max1; i++)
    {
        for(int j=0; j<= max2; j++)
        {
            if(i+j==2)
                continue;
            ans += calc(pos-1,upa&&i==a[pos],upb&&j==b[pos]);
        }
    }
    return ans;
}
long long solve(long long A,long long B)
{
    if(A<0||B<0)
        return 0;
    for(int i=0; i<30; i++)
        a[i] = A >> i & 1, b[i] = B >> i & 1;
    memset(f,-1,sizeof(f));
    return calc(30-1,1,1);
}
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        int l,r;
        cin>>l>>r;
        long long ans = solve(r,r) - 2 * solve(l-1,r) + solve(l-1,l-1);
        cout<<ans<<endl;
    }
}
