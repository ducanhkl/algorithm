#include<iostream>

#define M 1000000007
using namespace std;
long long powM(int n, long long k){
	if(k==1) return n;
	long long x=powM(n,k/2);
	if(k%2==0) return x*x%M;
	else return x*x%M*n%M;	//co dau ngoac
}
int main(){
	long long k;
	int n,t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		cout<< powM(n,k)<<endl;
	}
	
}
// Hoang Hue
