#include <iostream>
using namespace std;

#include <math.h>

int main(){
	int long long a, b;
	cin >> a >> b;
	int long long kq = pow(10,9);
	
	cout << (a+b)%(kq+7) << endl;
}
//#include<bits/stdc++.h>
//using namespace std;
//#define N 1005
//
//int main(){
//	ios_base::sync_with_stdio(0);//doc du lieu nhanh hon;
//	int T;
//	cin >> T;   
//	vector < pair<int,int> > a, b;
//	int  L , C, res=0;
//	int cnt[2*N][2*N] = {};
//	while(T--){
//		//vector < pair<int,int> > a, b;
//	//int  L , C, res=0;
//	//int cnt[2*N][2*N] = {};
//		int u, v;
//		cin >> L >> C;
//		for(int i = 0; i < L; i++)
//			for(int j =0; j < C ; j++){
//				cin >> u;
//				if(u) a.push_back({i, j});
//			}
//		for(int i = 0; i < L; i++)
//			for(int j =0; j < C ; j++){
//				cin >> u;
//				if(u) b.push_back({i,j});
//			}	
//		for(auto &u: a)	
//			for(auto &v: b){
//				int delta_x = v. first - u.first + N;
//				int delta_y = v.secend - u.secend + N;
//				cnt[delta_x][delta_y]++;	
//			}
//		for(int i = 0; i < 2*N; i++)
//			for(int j = 0; j < 2*N; j++)
//				res = max(res, cnt[i][j]);
//		cout << res << endl;		
//	}
//	return 0;
//}
