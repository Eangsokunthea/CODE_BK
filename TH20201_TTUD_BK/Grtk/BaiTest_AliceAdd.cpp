#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int arr[n][2];
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> arr[i][0] >> arr[i][1];
	}
	
	for(int i=0; i<n; i++){
		cout << arr[i][0] + arr[i][1] << endl;
	}
}
/*#include<bits/stdc++.h>
using namespace std;

int main(){
int test;
unsigned long long a,b;
cin>>test;
while(test--){
cin>>a>>b;
cout<<a+b<<endl;
}
}*/





