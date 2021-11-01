# include <iostream>
using namespace std;

int counteven(int* arr, int size);

int counteven(int* arr, int size){
    int *p;
    p = arr;
	int count = 0;
     for (int i=0; i<size; i++) {
        if(*p%2 == 0) 
		{
			count+=1;
		}
		p += 1;
    }
	    
    return count;    
}
int main(){
	cout << " Ho Va Ten: EANG SOKUNTHEA" << endl; 
    cout << " MSSV: 20180280" << endl; 
	int arr[] = {1, 5, 4, 8, 10, 6, 7, 2};
	cout << counteven(arr, 8);
		
}
