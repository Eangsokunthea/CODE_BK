
#include<iostream> 
   
using namespace std;  
  
int countSubStr(char str[])  
{  
int res = 0;  
    
for (int i=0; str[i] !='\0'; i++)  
{  
        if (str[i] == '0')  
        {    
            for (int j=i+1; str[j] !='\0'; j++)  
            if (str[j] == '1')  
                res++;  
        }  
}  
return res;  
}  

int main()  
{  
	printf("HoVaTen: EANG SOKUNTHEA\n");
	printf("MSSV: 20180280\n");
	
	char str[] = {0};
	cin >> str;
	cout << countSubStr(str);  
	return 0;  
}  
