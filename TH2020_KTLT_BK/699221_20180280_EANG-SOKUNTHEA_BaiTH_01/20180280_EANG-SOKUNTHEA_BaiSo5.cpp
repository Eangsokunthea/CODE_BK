# include <iostream>
using namespace std;

double* maximum(double* a, int size){
	if(a==NULL){
		return NULL;
	}
	else{
		double *p;
   		p = a;
   		double max = *p;
   		for (int i = 0; i < size; i++) {
        	if (max < *(p+i)){
        		max = *(p+i);
			} 
   		}
    	p=&max;
    	return p;
	}
}
int main(){
	double arr[] = {1., 10., 2., -7., 25., 3.};
	double* max = maximum(arr, 6);
	printf("%.0f", *max);
}
