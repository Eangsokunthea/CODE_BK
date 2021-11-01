#include<iostream>

using namespace std;

int m, n, a[10005], mark=0;

void solve(){
	int b[10005];
	for(int i=0; i<m;i++){
		b[i]=n-m+1+i;
	}
	for(int i=m-1;i>=0;i--){
		if(a[i]!=b[i]){
			a[i]=a[i]+1;
			for(int j=i+1;j<=m;j++){
				a[j]=a[i]+j-i;
			}
			mark=1;
			break;
		}	
			
	}
}	


int main(){
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> a[i];
	}
	solve();
	if(mark!=0){
		for(int i=0;i<m;i++){
		cout << a[i] << " ";
	}
	}else{
		cout << -1;
	}
	return 0;
}
