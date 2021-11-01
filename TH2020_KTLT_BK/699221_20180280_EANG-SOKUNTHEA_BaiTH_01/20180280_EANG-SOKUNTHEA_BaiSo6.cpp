#include <stdio.h>
void reversearray(int arr[], int size){
    int l = 0, r = size - 1, tmp;
	for (int i=0; i<=(l+r)/2; ++i) {
        tmp = arr[l+i];
        arr[l+i] = arr[r-i];
        arr[r-i] = tmp;
    }
    printf("\nRevertArray: \n");
    for (int i=0; i<=r; ++i) {
        printf("%d ", arr[i]);
    }
}
void ptr_reversearray(int *arr, int size){
    int l = 0, r = size - 1, tmp;
    for (int i=l; i<=(l+r)/2; ++i) {
        tmp = *(arr+(l+i));
        *(arr+l+i) = *(arr+r-i);
        *(arr+r-i) = tmp;
    }
    printf("\nRevertArray pointer: \n");
    for (int i=0; i<=r; ++i) {
        printf("%d ", *(arr+i));
    }
}
int main() {
    int size;
    printf("Ho Va Ten: EANG SOKUNTHEA\n"); 
   	printf("MSSV: 20180280\n\n"); 
    int arr[] = {9, 3, 5, 6, 2, 5};
	reversearray(arr, 6);
	for(int i = 0; i < 6; i++) 
	printf(" ",arr[i]);
	
	int arr2[] = {4, -1, 5, 9};
	ptr_reversearray(arr2, 4);
	for(int i = 0; i < 4; i++) 
	printf(" ",arr2[i]);
	
	int arr3[] = {4,-1,5,9,9,3,5,6,2,5};
    reversearray(arr3, 10);
    for(int i = 0; i < 10; i++) 
    printf(" ",arr3[i]);
    return 0;
}
