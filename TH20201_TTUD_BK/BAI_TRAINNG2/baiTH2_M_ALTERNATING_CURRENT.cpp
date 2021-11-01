#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
char a[100500];
int main()
{
    while(~scanf("%s",a))
    {
        stack<char >s;
        int n=strlen(a);
        for(int i=0;i<n;i++)
        {
            if(s.size()==0)
            {
                s.push(a[i]);
            }
            else
            {
                if(s.top()==a[i])s.pop();
                else s.push(a[i]);
            }
        }
        if(s.size()==0)printf("Yes\n");
        else printf("No\n");
    }
}
