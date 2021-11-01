#include <iostream>
#include <climits>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 32;
int n, b;
int a[N], c[N], a1[N], c1[N];
int x[N], x1[N];
int sum_c = 0, sum_a = 0;
int max_c = 0;

void TRY(int i){
    for(int v = 1; v >= 0; v--){
        if(sum_a + a1[i]*v <= b){
            x[i] = v;
            sum_c += c1[i]*x[i];
            sum_a += a1[i]*x[i];
            if(i == n) max_c = max(sum_c, max_c);
            else if((double)sum_c + (double)c1[i+1]*(b-sum_a)/a1[i+1] > max_c) TRY(i+1);
            sum_c -= c1[i]*x[i];
            sum_a -= a1[i]*x[i];
        }
    }
}

int main()
{
    cin >> n >> b;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
    }

    vector<pair<double, int> > v;
    for(int i = 1; i <= n; i++){
        v.push_back(make_pair((double)c[i]/a[i], i));
    }

    sort(v.begin(), v.end(), greater<pair<double, int> >());

    for(int i = 1; i <= n; i++){
        a1[i] = a[v[i-1].second];
        c1[i] = c[v[i-1].second];
    }

    a1[n+1]=1; c1[n+1] = 0;

    TRY(1);
    cout << max_c;

    return 0;
}
