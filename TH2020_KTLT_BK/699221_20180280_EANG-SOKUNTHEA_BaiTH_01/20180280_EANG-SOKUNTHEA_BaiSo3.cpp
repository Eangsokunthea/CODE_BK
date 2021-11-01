# include <iostream>
using namespace std;

int counteven(int* arr, int size);

int counteven(int* arr, int size){
    int *p;
    p = arr;
    printf("Ho Va Ten: EANG SOKUNTHEA\n"); 
   	printf("MSSV: 20180280\n\n"); 
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
