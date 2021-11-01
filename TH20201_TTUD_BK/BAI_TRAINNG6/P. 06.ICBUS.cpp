/*
You should output on a single line an unique integer that is the minimum value of the sum of the fare necessary for Quang to go to the town N from the town 1
6 6
400 2
200 1
500 3
900 1
400 4
200 5
1 2
1 5
2 3
2 4
3 6
4 6
output: 800;
*/
#include<bits/stdc++.h>

using  namespace std;

const int NMAX = 5005;
const long long oo = 1e9;

int n, k;
int c[NMAX], d[NMAX];

vector<int> adj[NMAX];
int dist[NMAX][NMAX];
bool flag[NMAX];
int I[NMAX];
//

vector<pair<int, int>> a[NMAX];
//a[u] danh  sach
void bfs(int i) {
	queue<int>q;
	//dist[i][i] = 0;
	memset(flag,false, sizeof(flag));
	flag[i] = true;
	dist[i][i] = 0;
	q.push(i);
	
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(auto v : adj[u]) {
			if(!flag[v]) {
				dist[i][v] = dist[i][u] + 1;
				q.push(v);
				flag[v] = true;
			}
		}
	}
}

void constructGraph(){
	for (int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(dist[i][i] <= d[i]) {
				a[i].push_back(make_pair(j,c[i]));
			}
		}
	}
}

int dijktra() {
	I[1] = 0;
	for(int i = 2; i <= n; i++) {
		I[i] = oo;
	}
	memset(flag,false, sizeof(flag));
	while (true){
		int u = -1;
		long long _min = oo;
		for (int i = 1; i<= n; i++) {
			if(!flag[i] && (I[i] < _min)) {
				u = i;
				_min = I[i];
			}
			if(u == n) {
				return I[u];				
			}else {
				flag[u] = true;
				for(auto v : a[u]) {
					if(!flag[v.first]
					&& (I[v.first] > I[u] + v.second)) {
						I[v.first] = I[u] + v.second;
					}
				}
			}
		}
	}
}
int main(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> c[i] >> d[i];
	}
	int u,v;
	for (int i = 1; i <= k; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i = 1; i <= n; i++) {
		bfs(i);
	}
	constructGraph();
	//cout << d[NMAX];
	return 0;
	
}
