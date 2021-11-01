#include <stdio.h>
int main(){
	printf("Ho Va Ten: EANG SOKUNTHEA\n"); 
   	printf("MSSV: 20180280\n\n"); 
    int a[7]= {13, -355, 235, 47, 67, 943, 1222}; 
    printf("address of first five elements in memory.\n");
    for (int i=0; i<5; i++)  printf("a[%d] \t\t",i);
    printf("\n");      
    for (int i = 0; i < 5; i++)
        printf("%d\t", a[i]);
    return 0;
}

