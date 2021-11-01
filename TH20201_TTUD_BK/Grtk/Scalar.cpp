/*
. Hãy tìm tích vô hu?ng nh? nh?t có th?
có. C? th? hon, c?n tính giá tr? nh? nh?t c?a 
2
3
1 3 -5
-2 4 1
5
1 2 3 4 5
1 0 1 0 1

Case #1: -25
Case #2: 6
*/
#include <vector>
#include <algorithm>
#include <stdlib.h> 
#include <iostream>

using namespace std;

int Scalar(vector<int> x, vector<int> y, int n){
	int total_vector = 0;
	
	for (int i=0; i< n ; i++) {
		total_vector += (x[i] + y[i]);
	}
	
	return total_vector;
}

int main(){
	
	int test, n;
	cin >> test;
	
	int Case[test];
	
	for (int i=0; i < test ; i++){
		cin >> n;
		
		vector<int> x;
		for (int i=0; i<n; i++) {
			int num;
			cin>> num;
			x.push_back(num);
		}
		
		vector<int> y;
		for (int i=0; i<n; i++) {
			int num;
			cin>> num;
			y.push_back(num);
		}
		
		sort(x.begin(), x.end());
		sort(y.begin(), y.end(), greater<int>());
//		Case[test] = Scalar( x, y, n);) work not
		
		int rs =0 ;
		for (int i =0; i<n ; i++){
			rs += (x[i] * y[i]);
		}
		Case[i] = rs;
		
	}
	
	for (int i=0; i<test; i++) {
		cout << "Case #" << i+1 << ": " << Case[i] << endl;
	}
	
	
	return 0;
}
