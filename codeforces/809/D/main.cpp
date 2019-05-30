#include<bits/stdc++.h>
int x,y,n,r,f[300001];

int main()
{
    freopen("inp.txt", "r", stdin);
	for(scanf("%d",&n);scanf("%d%d",&x,&y),n--;)
	{
		int*a=std::lower_bound(f+1,f+r+1,y);
		if(a-f>r)++r,f[r]=2e9;
		for(;a-->f&&f+r-a<4000;)
            if(*a>=x)
                *(a+1)=*a+1;
            else break;
		if(*a<x&&*(a+1)>x)*(a+1)=x;
    }
	printf("%d",r);
}
// Chua lam
