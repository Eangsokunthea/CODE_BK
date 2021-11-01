#include<iostream>

using namespace std;

int n;
string s;

string Solve(){
	for(int i = n-1; i >= 0; i--){
		if(s[i] == '0'){
			s[i] = '1';
			for(int j = i; j <= n; j++){
				if(s[j]!='0' && j!=i){
					s[j]='0';
				}
			}
			return s;
		}
	}
	return "-1";
}

int main(){
	cin >> n >> s;
	cout << Solve();
	return 0;
}



