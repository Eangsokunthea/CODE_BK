#include<bits/stdc++.h>

using namespace std;

int n,k;
int l[5005],r[5005],dem[5005],ma,res;

int main() {
	int t1 = 0,t2 = 0;
	cin >> n >> k;
	
	for(int i = 1; i <= k; i++) {
		cin >> l[i] >> r[i];
	}
	
	for(int i = 1; i <= k; i++) {
		for(int j = l[i]; j <= r[i]; j++) {
			dem[j]++;
			if(dem[j] == 1) ma++;
		}
	}
	
	for(int i = 1; i <= k; i++) {
		for(int j = l[i]; j <= r[i]; j++) {
			dem[j]--;
			if(dem[j] == 0) t1++;
		}
		if(ma - t1 > res){
			for(int j = i + 1; j <= k; j++) {
				for(int x = l[j]; x <= r[j]; x++) {
					dem[x]--;
					if(dem[x] == 0) t2++;
				}
				res = max(res,ma-t1-t2);
				for(int x = l[j]; x <= r[j]; x++){
					dem[x]++;
				}			
			}		
			
		}
				
		for(int j = l[i]; j <= r[i]; j++) {
			dem[j]++;
		}	
	}
	
	cout << res;
	return 0;
}
