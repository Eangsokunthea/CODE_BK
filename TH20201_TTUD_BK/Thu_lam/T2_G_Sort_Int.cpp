//ok

#include<bits/stdc++.h>

using namespace std;

#define MAX 1000005

int n;
int a[MAX];

int main(){
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	sort(a,n+a+1);
	
	for(int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
