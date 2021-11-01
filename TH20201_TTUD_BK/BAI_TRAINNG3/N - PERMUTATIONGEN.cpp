#include<iostream>

using namespace std;

int n, a[10005], mark=0;

int findMin(int l, int r, int val){
	int min=a[l], index=l;
	for(int i=l; i<=r; i++){
		if(a[i]<min && a[i]>val){
			min=a[i];
			index=i;
		}
	}
	return index;
}

void print(){
	for(int i=1; i<=n; i++){
		cout << a[i] << " ";
	}
	cout << "\n";
}
void DaoMang(int l, int r){
	while(l<r){
		swap(a[l],a[r]);
		l=l+1; 
		r=r-1;
	}
}

void solve(){
	int tem;
	for(int i=n;i>=1;i--){
		if(a[i]>a[i-1]){
			tem=i-1;
			mark=1;
			break;
		}
	}
	int val=a[tem];
	int min = findMin(tem+1, n, val);
	swap(a[tem], a[min]);
	DaoMang(tem+1,n);
	if(mark!=0){
		print();
	}else{
		cout << -1;
	}
	
}

int main(){
	cin >> n;
	a[0]=INT_MAX;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	solve();
	return 0;
}
