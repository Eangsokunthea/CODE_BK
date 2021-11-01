#include <cstdio>
#include <map>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
	map<char,int> m;
	m['('] = 1;//????
	m[')'] = -1;
	m['['] = 2;
	m[']'] = -2;
	char str[100000+22];
	int l;
	int ans;
	while (~scanf ("%s",str))
	{
		l = strlen(str);
		stack<int> s;
		ans = 0;
		for (int i = 0 ; i < l ; i++)
		{
			if (m[str[i]] == 1 || m[str[i]] == 2)//??????
				s.push(i);
			else if (s.empty())
				s.push(i);
			else if (m[str[i]] + m[str[s.top()]] == 0)		//????,??
				s.pop();
			else		//????,??
				s.push(i);
		}
		if (s.empty())		//??????
		{
			for (int i = 0 ; i < l ; i++)
				if (m[str[i]] == 2)
					ans++;
			printf ("%d\n%s\n",ans,str);
		}
		else//?????
		{
			int st,endd;
			int ans_st,ans_endd;		//????????????
			int ant;
			s.push(l);
			while (s.size() != 1)
			{
				endd = s.top() - 1;
				s.pop();
				st = s.top() + 1;
				ant = 0;
				for (int i = st ; i <= endd ; i++)
					if (m[str[i]] == 2)
						ant++;
				if (ant > ans)
				{
					ans = ant;
					ans_st = st;
					ans_endd = endd;
				}
			}
			st = 0;
			endd = s.top() - 1;
			ant = 0;
			for (int i = st ; i <= endd ; i++)
				if (m[str[i]] == 2)
					ant++;
			if (ant > ans)
			{
				ans = ant;
				ans_st = st;
				ans_endd = endd;
			}
			if (ans)
			{
				printf ("%d\n",ans);
				for (int i = ans_st ; i <= ans_endd ; i++)
					printf ("%c",str[i]);
				printf ("\n");
			}
			else
				printf ("0\n\n");
		}
	}
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//
//int Dung (char first,char second)
//{
//	if(first == '(' && second == ')') return 1;
//	else if(first == '[' && second == ']') return 1;
//	return 0;
//}
//int Check(string s) {
//	stack<char> S;
//	for(int i = 0 ; i < s.length() ; i++) {
//		if(s[i] == '(' || s[i] == '{' || s[i] == '[')
//			S.push(s[i]);
//		else if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
//			if( S.empty() || ! Dung(S.top() , s[i]))
//				return 0;
//			else
//				S.pop();
//		}
//	}
//	return S.empty() ? 1 : 0;
//}
//
//
//int main() {
//	string xau;
//	cin>>xau;
//	if(Testing(xau))
//		cout<<"1" << endl << xau;
//	else
//		cout<<"0";
//}
