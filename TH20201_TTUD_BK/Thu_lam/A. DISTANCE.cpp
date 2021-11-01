#include<bits/stdc++.h>

using namespace std;

#define MAX 1000

int f = 0;
int c[MAX][MAX];
int n,m;
int traval[MAX];

void FTraVal(int a, int b) {
	f = f + c[a][b];
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> c[i][j];
		}
	}
	
	cin >> m;
	
	for(int i = 0; i < m; i++) {
		cin >> traval[i];
	}
	
	for(int i = 0; i < m - 1; i++) {
		FTraVal(traval[i],traval[i+1]);
	}
	
	cout << f;
	return 0; 
}

/*
for(int i = 1; i <= m; i++){
	res += c[a[i]a[i+1]];
}
cout << res;

*/










