#include<bits/stdc++.h>
#include<string.h>

using namespace std;

#define MAX 100000

string S;
int k;

void solve() {
	int i = 0;
	int position = 0;
	string final;
	
	while(i < k) {
		char temp = S[position];
		
		for(int i = position + 1; i <= S.length(); i++) {
			if(temp - S[i] < 0) {
				temp = S[i];
				position = i + 1;
			}
		}
		final += temp;
		i++;
	}	
	cout << final << endl;
}

int main() {
	
	cin >> S;
	cin >> k;
	solve(); 
}














