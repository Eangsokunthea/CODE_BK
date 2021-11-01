//tinh tong chi phi nho nhat trong cac thanh pho
/*
2 2
1 2 3
2 1 2

output: 5
*/ 

#include<iostream>
 
using namespace std;
 
int n,c[100][100],a[100],d[100],cmin,f=9999999, sum=0,g;
 
void Try(int k){
	int i;
	for(int i=2;i<=n;i++){
		if(d[i]!=1 && c[a[k-1]][i]!=0){
			a[k]=i;
			d[i]=1;
			sum+=c[a[k-1]][i];
			g=sum+cmin*(n-k);
			if(k==n-1){
				if(c[a[k]][1]!=0 && sum+c[a[k]][1]<f){
					f=sum+c[a[k]][1];
				}
				
			}else if(g<f){
				Try(k+1);
			}
			d[i]=0;
			sum-=c[a[k-1]][a[k]];
		}
	}
}
 
int main(){
	int T;
	cin >> n >> T;
	a[0]=1;
	int k,l,m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c[i][j]=0;
		}
	}
	int count=0;
	while(true){
		cin >> k >> l >> m;
		c[k][l]=m;
		count++;
		if(count==T){
			break;
		}
	}
	
	
	cmin=999999;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(cmin>c[i][j] && c[i][j]!=0){
				cmin=c[i][j];
			}
		}
	}
	Try(1);
	cout << f;
	return 0;
	
}
