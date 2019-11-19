#include<iostream>

using namespace std;

int n, dem=0, colum[100], xuoi[100], nguoc[100], a[100];


void init()
{
	cin >> n;
	for(int i=1; i<=n; i++){
		colum[i]=1;
	}
	for(int i=1; i<2*n; i++){
		xuoi[i]=1;
		nguoc[i]=1;
	}
}

void tang(){
	++dem;
}
void backtrack(int i){
	for(int j=1; j<=n; j++){
		if(colum[j] && xuoi[i-j+n] && nguoc[i+j-1]){
			a[i]=j;
			colum[j]=0;
			xuoi[i-j+n]=0;
			nguoc[i+j-1]=0;
			if(i==n){
				tang();
			}
			else{
				backtrack(i+1);
			}
			colum[j]=1;
			xuoi[i-j+n]=1;
			nguoc[i+j-1]=1;
		}
	}
}
main(){
	init();
	backtrack(1);
	cout << dem;
	return 0;
}

