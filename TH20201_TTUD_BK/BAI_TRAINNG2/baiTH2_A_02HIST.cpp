#include<iostream>
using namespace std;
long long findMAX(int n){
    int* a= new int[n];
    long long  MAX=0;
    for (int i=0; i<n; i++)
        cin>>a[i];
    for (int i=0; i<n; i++){
        if (a[i]==0) continue;
        int count=1;
        for (int l=i-1; l>=0; l--){
            if (a[l]>=a[i]) count++;
            else break;
        }
        for (int r=i+1; r<n; r++){
            if (a[r]>=a[i] ) count++;
            else break;
        }
        long long t=count*a[i];
        if (MAX<t) MAX=t;
    }
    return MAX;
}
int main(){
    int n;
    cin>>n;
    while(n!=0){
        cout<<findMAX(n)<<endl;
        cin>>n;
    }
}
//input
//2 0 0
//3 0 0 0
//4 0 1 0 1
//5 1 0 1 0 1
//6 2 0 1 0 1 0

//output
//0
//0
//0
//1
//1
//2

