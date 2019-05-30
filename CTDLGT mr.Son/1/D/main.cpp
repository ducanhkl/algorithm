#include<iostream>
#include<string>
using namespace std;
char x[100];
int t,a;
int sinh()
{
	int n=0;
	while(x[n]!='\0')
	{
		n++;
	}
	n--;
	int i=n-1;
	while(i >= 0 && x[i]>=x[i+1])
        i--;
	if(i<0)
	{
		cout<<"BIGGEST" << endl;
		return 0;
	}
	int j=n;
	while(x[j]<=x[i]) j--;
	int m = x[j];
	x[j] = x[i];
	x[i] = m;
	int d = i+1, c = n;
	while(d<=c)
	{
		int m = x[d];
		x[d] = x[c];
		x[c] = m;
		d++;
		c--;
	}
	for( int i = 0; i<=n; i++)
	{
		cout<<x[i];
	}
	cout<<endl;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
	cin>>t;
	while(t--)
	{
		cin>>a>>x;
		cout<<a<<" ";
		sinh();
	}
}
