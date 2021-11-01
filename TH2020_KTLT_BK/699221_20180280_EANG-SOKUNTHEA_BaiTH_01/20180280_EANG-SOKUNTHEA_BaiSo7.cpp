#include <stdio.h>
#include <stdlib.h>

int *a;
int n, tmp;

int main(){
	printf("Ho Va Ten: EANG SOKUNTHEA\n"); 
   	printf("MSSV: 20180280\n\n"); 
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    a = (int*)malloc(n*sizeof(int));    
    
    for(int i = 0; i < n; i++)
        scanf("%d", a + i); 
    
    printf("The input array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    
    for (int i = 0; i < n; i++) { 
        for (int j = i + 1; j < n; j++) {
            if (*(a + j) < *(a + i)) { 
                int t = *(a + i); 
                *(a + i) = *(a + j); 
                *(a + j) = t; 
            } 
        } 
    } 
    
    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    
    free(a);
    return 0;
}
