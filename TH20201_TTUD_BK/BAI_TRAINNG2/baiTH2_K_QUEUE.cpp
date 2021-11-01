#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <queue>
#include <typeinfo>
#include <fstream>
#include <map>
#include <stack>
typedef long long ll;
using namespace std;
//freopen("D.in","r",stdin);
//freopen("D.out","w",stdout);
#define sspeed ios_base::sync_with_stdio(0);cin.tie(0)
#define maxn 2000001
#define mod 1000000007
#define eps 1e-9
int Num;
char CH[20];
const int inf=0x3f3f3f3f;
inline ll read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//**************************************************************************************
int tr[maxn];
int a[maxn];
int ans[maxn];
int tmp;
void build(int x,int l,int r)
{
    if(l==r)
    {
        tr[x]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    tr[x]=min(tr[x<<1],tr[x<<1|1]);
}
void query(int x,int l,int r,int t)
{
    if(l==r)
    {
        ans[tmp++]=l-t-1;
        return;
    }
    int mid=(l+r)>>1;
    if(tr[x<<1|1]<a[t])
        query(x<<1|1,mid+1,r,t);
    else
        query(x<<1,l,mid,t);
}
void update(int x,int l,int r,int t)
{
    if(l==r)
    {
        tr[x]=inf;
        return;
    }
    int mid=(l+r)>>1;
    if(t<=mid)
        update(x<<1,l,mid,t);
    else
        update(x<<1|1,mid+1,r,t);
    tr[x]=min(tr[x<<1],tr[x<<1|1]);
}
int main()
{
    int n=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        if(tr[1]>=a[i])
            ans[tmp++]=-1;
        else
            query(1,1,n,i);
        update(1,1,n,i);
    }
    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);
}
