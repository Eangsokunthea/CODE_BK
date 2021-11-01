#include<iostream>
#include<stack>
using namespace std;
int getArea(int hist[], int n)
{
   stack<int> st;
   int largest_area = 0;
   int top;
   int toparea;
   int i = 0;
   while (i < n)
   {
      if (st.empty() || hist[st.top()] <= hist[i])
      st.push(i++);
      else
      {
         top = st.top();
         st.pop();
         toparea = hist[top] * (st.empty() ? i :
         i - st.top() - 1);
         if (largest_area < toparea)
         largest_area = toparea;
      }
   }
   while (st.empty() == false)
   {
      top = st.top();
      st.pop();
      toparea = hist[top] * (st.empty() ? i :
      i - st.top() - 1);
      if (largest_area < toparea)
      largest_area = toparea;
   }
   return largest_area;
}
int main()
{
	printf("HoTen: EANG SOKUNTHEA\n");
	printf("MSSV: 20180280\n");

	int u; 
	cin >> u;
    int hist[u];
    for (int i=0; i<u; i++) {
        cin >> hist[i];
    } 	
   int n = sizeof(hist)/sizeof(hist[0]);
   cout << getArea(hist, n);
   return 0;
}
