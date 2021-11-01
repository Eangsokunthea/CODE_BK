#include<iostream>

using namespace std;

int n, c[23][23], a[12], f=99999, sum=0, d[12], c_min;

void Try(int k){
	int i;
	for(i=1;i<=n;i++){
		if(d[i]!=1){
			a[k]=i;
			d[i]=1;
			if(k==1){
				sum+=c[a[k-1]][i]+c[i][i+n];
			}else{
				sum+=c[a[k-1]+n][i]+c[i][i+n];
			}
			if(k==n){
				if(sum+c[a[k]+n][0]<f){
					f=sum+c[a[k]+n][0];
				}
			}else if((sum+c_min*(2*n+1-2*k)) < f){
				Try(k+1);
			}
			d[i]=0;
			if(k==1){
				sum-=c[a[k-1]][a[k]]+c[a[k]][a[k]+n];
			}else{
				sum-=c[a[k-1]+n][a[k]]+c[a[k]][a[k]+n];
			}
		}
	}
}


int main(){
	cin >> n;
	a[0]=0;
	for(int i=0;i<=2*n;i++){
		for(int j=0;j<=2*n;j++){
			cin >> c[i][j];
		}
	}
	c_min=9999;
	for(int i=0;i<=2*n;i++){
		for(int j=0;j<=2*n;j++){
			if(c_min>c[i][j] && c[i][j]!=0){
				c_min=c[i][j];
			}
		}
	}
	Try(1);
	cout << f; 
	return 0;
}
